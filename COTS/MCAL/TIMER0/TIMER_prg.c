/*
 * TIMER_prg.c
 *
 * Created: 9/13/2022 12:24:43 PM
 *  Author: MICHAEL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TIMER_cfg.h"
#include "TIMER_int.h"
#include "TIMER_pri.h"
#include "TIMER_reg.h"

static void(*G_PTRF_TIM0_OVF)(void) = ADDRESS_NULL;
static void(*G_PTRF_TIM0_CTC)(void) = ADDRESS_NULL;

/* Timer Init Steps:
	1- Enable timer 
	2- set prescalar 
	3- Mode 
	4- set OCO pin State 
*/
void TIM0_vInit(){
	/* 1- Set Timer Mode */
	   #if TIM0_MODE == TIM0_OVF__MODE
			CLR_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);	
			/* Timer OVerflow Interrupt enable */
			SET_BIT(TIMSK,TOIE0);
	   #elif TIM0_MODE == TIM0_CTC_MODE
			#if TIMER0_SET_CTC_INTERRUPT == TIMER0_CTC_INTERRUPT_ENABLED
				SET_BIT(TIMSK,OCIE0);
			#elif TIMER0_SET_CTC_INTERRUPT == TIMER0_CTC_INTERRUPT_DISABLED
				CLR_BIT(TIMSK,OCIE0);
			#else
			#error      "TIMER0 CTC Mode INTERRUPT is not valid ..."
			#endif
				CLR_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
			#if TIM0_PIN_MODE == TIM0_0C0_DISCONNECTED
				CLR_BIT(TCCR0,COM00);
				CLR_BIT(TCCR0,COM01);				
			#elif TIM0_PIN_MODE == TIM0_OC0_TOGGLE
				SET_BIT(TCCR0,COM00);
				CLR_BIT(TCCR0,COM01);
			#elif TIM0_PIN_MODE == TIM0_OC0_CLR
				CLR_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);			
			#elif TIM0_PIN_MODE == TIM0_OC0_SET
				SET_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
			#endif
			
	   #elif TIM0_MODE == TIM0_FAST_PWM
				SET_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);			
			#if TIM0_PWM_MODE == TIM0_PWM_NON_INVERTING
				CLR_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
			#elif TIM0_PWM_MODE == TIM0_PWM_INVERTING
				SET_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);		
			#endif
	   #elif TIM0_PHASE_CORRECT_PWM
				SET_BIT(TCCR0,WGM00);
				CLR_BIT(TCCR0,WGM01);	   
			#if TIM0_PWM_MODE == TIM0_PWM_NON_INVERTING
				CLR_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
			#elif TIM0_PWM_MODE == TIM0_PWM_INVERTING
				SET_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);			
			#endif
			
	   #else 
	   #warning "Invalid Timer MOde Option"
	   #endif
	   
	    
	   /* 3- Set prescalar */ 
		/* Select the suitable prescalar */
			TCCR0 = (TCCR0 & 0b11111000) | TIM0_SET_PRESCALAR;     //clear 3 bits which related with Prescaler
	
	 
	
}

/* Set Preload to count from the preload value */
void TIM0_vSetPreload(u8 A_u8PreloadVal){
	TCNT0 = A_u8PreloadVal;
}

/* Set OCR Value to be the TOP counts to generate CTC flag */
void TIM0_vSetOcrVal(u8 A_u8OcrVal){
	OCR0 = A_u8OcrVal;
}

/* Set call back to execeute ISR related with OVF event*/
void TIM0_vCallBack_OVF(void(*Fptr)(void)){
	G_PTRF_TIM0_OVF = Fptr;
}

/* Set call back to execeute ISR related with CTC event*/
void TIM0_vCallBack_CTC(void(*Fptr)(void)){
	G_PTRF_TIM0_CTC = Fptr;
}


/* ISR for CTC Event */
void __vector_10(void){
	/*Execute The  ISR [User Routine] */
	G_PTRF_TIM0_CTC();
}

/* ISR for OVF Event */
void __vector_11(void){
	/*Execute The  ISR [User Routine] */
	G_PTRF_TIM0_OVF();
}
