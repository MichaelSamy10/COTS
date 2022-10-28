/*
 * EXI_prg.c
 *
 * Created: 8/29/2022 1:26:36 PM
 *  Author: MICHAEL
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "EXI_reg.h"
#include "EXI_pri.h"
#include "EXI_cfg.h"
#include "EXI_int.h"

#include <avr/delay.h>


void EXI_vInit0(){
	/* Configure Pin I/P pull up */
	DIO_vSetPinDir(INT0_PORT,INT0_PIN,DIR_INPUT);
	DIO_vSetPinVal(INT0_PORT,INT0_PIN,VAL_HIGH);
	/*
	#if (INT0_MODE == INT0_FALLING_EDGE)
		CLR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);

	#else
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
	#endif	
	*/
	/* Configure Pin Mode */
	MCUCR = (MCUCR & 0b11111100) | INT0_MODE;
	/* Enable Peripheral interrupt*/
	SET_BIT(GICR,INT0);

}

void EXI_vInit1(){
	DIO_vSetPinDir(INT1_PORT,INT1_PIN,DIR_INPUT);
	DIO_vSetPinVal(INT1_PORT,INT1_PIN,VAL_HIGH);
		/*
		#if (INT1_MODE == INT1_FALLING_EDGE)
		CLR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);

		#else
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		#endif
		*/
	MCUCR = (MCUCR & 0b11110011) | INT1_MODE;

	SET_BIT(GICR,INT1);
}

void EXI_vInit2(){
	DIO_vSetPinDir(INT2_PORT,INT2_PIN,DIR_INPUT);
	DIO_vSetPinVal(INT2_PORT,INT2_PIN,VAL_HIGH);

	MCUCSR = (MCUCSR & 0b11111100) | INT2_MODE;

	SET_BIT(GICR,INT2);
}


void Reg_Func(void (*ISR_Ptr)(void),u8 A_u8IntId){
	switch(A_u8IntId){
		case INT0_ID: 	G_ISR0_Ptr = ISR_Ptr; break;
		case INT1_ID: 	G_ISR1_Ptr = ISR_Ptr; break;
		case INT2_ID: 	G_ISR2_Ptr = ISR_Ptr; break;
	}
}

void __vector_1(void){
	G_ISR0_Ptr();
}

void __vector_2(void){
	G_ISR1_Ptr();
}

void __vector_3(void){
	G_ISR2_Ptr();
}