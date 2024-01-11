/*
 * TIMER2_program.c
 *
 * Created: 02-Jan-24 10:23:52 AM
 *  Author: MICHAEL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TIMER2_register.h"
#include "TIMER2_config.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"


void(*GlobalOvPtrFuncTimer2)(void) = NULL;
void(*GlobalCtcPtrFuncTimer2)(void) = NULL;
u16 G_u16OvfCounts;
u16 G_u16CtcCounts;

void TIMER2_voidInit()
{
	/* Choose TIMER Mode using bit masking*/
	TCCR2 &= 0xB7;	// 0b10110111
	TCCR2 |= TIMER2_MODE;
		
	#if TIMER2_MODE == TIMER2_CTC_MODE
	/* Control OC2 pin in CTC mode */
	TCCR2 &= 0xCF;	// 0b11001111
	TCCR2 |= CTC_OC2_PIN;
					
	#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM	
		/* Control OC2 pin in Phase correct PWM mode */
		TCCR2 &= 0xCF;	// 0b11001111
		TCCR2 |= PWM_OC2_PIN;
			
	#elif TIMER2_MODE == TIMER2_FAST_PWM
		/* Control OC2 pin in Fast PWM mode */
		TCCR2 &= 0xCF;	// 0b11001111
		TCCR2 |= PWM_OC2_PIN;
	#endif

}

void TIMER2_voidOVSetIntervalSynchronous(u16 Copy_16Counts)
{
	for(u16 Local_Iterator=0;Local_Iterator<Copy_16Counts;Local_Iterator++)
	{
		while(GET_BIT(TIFR,TOV2) != 1);
		SET_BIT(TIFR,TOV2);
	}
}

void TIMER2_voidOVSetIntervalSynchronousMS(u16 Copy_u16MilliSec)
{
	/* prescaler 8*/
	u16 L_u16Counts = (Copy_u16MilliSec / 256 )* 1000 ;

	for(u16 Local_Iterator=0;Local_Iterator<L_u16Counts;Local_Iterator++)
	{
		while(GET_BIT(TIFR,TOV2) != 1);
		SET_BIT(TIFR,TOV2);
	}
}

void TIMER2_voidOVSetIntervalASynchronous(u16 Copy_u16Counts , void(*PtrFunc)(void))
{
	SET_BIT(TIMSK,TOIE2);
	GlobalOvPtrFuncTimer2 = PtrFunc;
	G_u16OvfCounts = Copy_u16Counts;
}

void TIMER2_voidOVSetIntervalASynchronousMS(u16 Copy_u16MilliSec,void(*PtrFunc)(void))
{
	u16 L_u16Counts = (Copy_u16MilliSec / 256 )* 1000 ;
	
	SET_BIT(TIMSK,TOIE2);
	GlobalOvPtrFuncTimer2 = PtrFunc;
	G_u16OvfCounts = L_u16Counts;

}

void TIMER2_voidCTCSetIntervalASynchronous(u16 Copy_u16Counts , void(*PtrFunc)(void))
{
	SET_BIT(TIMSK,OCIE2);
	GlobalCtcPtrFuncTimer2 = PtrFunc;
	G_u16CtcCounts = Copy_u16Counts;
}

void TIMER2_voidCTCSetIntervalASynchronousMS(u16 Copy_u16MilliSec , void(*PtrFunc)(void))
{
	u16 L_u16Counts = (Copy_u16MilliSec / 256 )* 1000 ;
	SET_BIT(TIMSK,OCIE2);
	GlobalCtcPtrFuncTimer2 = PtrFunc;
	G_u16CtcCounts = L_u16Counts;
}

void TIMER2_voidSetCompareValue(u16 Copy_u16CompVal)
{
	OCR2 = Copy_u16CompVal;
}

void TIMER2_voidSetPreloadValue(u16 Copy_u16PreloadVal)
{
	TCNT2 = Copy_u16PreloadVal;
}

void TIMER2_voidStart(void)
{
	/* Set prescaler ,so TIMER2 starts counting*/
	
	/* bit Masking */
	TCCR2  &= 0xF8; //0b11111000
	TCCR2 |= TIMER2_PRESCALER;
		
}

void TIMER2_voidStop(void)
{
		CLR_BIT(TCCR2,CS20);
		CLR_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS22);
}


/* TODO callback functions for over flow and CTC*/

void TIMER2_voidCallBack_OVF(void(*PtrFunc)(void)){
	GlobalOvPtrFuncTimer2 = PtrFunc;
}


void TIMER2_voidCallBack_CTC(void(*PtrFunc)(void)){
	GlobalCtcPtrFuncTimer2 = PtrFunc;
}



/* Normal Mode ISR */
void __vector_5(void)__attribute__((signal));

void __vector_5(void){
	static u16 LS_Iterator=0;

	if(LS_Iterator == G_u16OvfCounts)
	{
		if(GlobalOvPtrFuncTimer2 != NULL)
		{
			GlobalOvPtrFuncTimer2();
			LS_Iterator = 0;
		}
	}
	LS_Iterator++;
}


/* CTC ISR */
void __vector_4(void)__attribute__((signal));

void __vector_4(void){
	static u16 LS_Iterator=0;

	if(LS_Iterator == G_u16CtcCounts)
	{
		if(GlobalCtcPtrFuncTimer2 != NULL)
		{
			GlobalCtcPtrFuncTimer2();
			LS_Iterator = 0;
		}
	}
	LS_Iterator++;
}