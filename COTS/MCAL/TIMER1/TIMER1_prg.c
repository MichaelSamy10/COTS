/*
 * TIMER1_prg.c
 *
 * Created: 9/13/2022 12:24:43 PM
 *  Author: MICHAEL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TIMER1_cfg.h"
#include "TIMER1_int.h"
#include "TIMER1_pri.h"
#include "TIMER1_reg.h"

static void(*G_PTRF_TIM1_FAST_PWM_ICR1)(void) = ADDRESS_NULL;
static void(*G_PTRF_TIM1_ICF)(void) = ADDRESS_NULL;
static void(*G_PTRF_TIM1_OVF)(void) = ADDRESS_NULL;


void TIM1_vInit(){
	/* 1. Set pin state OC1A --> non inverting mode */
	/* clear on compare */
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	/*2. Set Mode 14 fast pwm with top control*/
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	/*3. set ICR1 19999 as a top to make frequency = 50 Hz Tp = 20 ms*/
	ICR1 = 19999;
	
	/* 4. set Inital position for servo = zero */
	OCR1A = 750;  /* range 750 : 2500 to map to 0:180 degree
	
	/* 5. prescalar as 8 */
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
}

/* Set Preload to count from the preload value */
void TIM1_vSetOcr1aVal(u16 copy_u16Val){
	OCR1A = copy_u16Val;
}


/* Set call back to execeute ISR related with CTC event*/
void TIM1_vCallBack_FAST_PWM_ICR1(void(*Fptr)(void)){
	G_PTRF_TIM1_FAST_PWM_ICR1 = Fptr;
}


/* ISR for OVF Event */
void __vector_7(void){
	/*Execute The  ISR [User Routine] */
	G_PTRF_TIM1_FAST_PWM_ICR1();
}

/* ICU in Timer1 */
void TIM1_vIcuMode(){
	/* 1. Init Timer1 in normal mode */
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	/* 2. Setup trigger for ICU event at rising edge */
		SET_BIT(TCCR1B,ICES1);
	/* 3. Enable Interrupt of ICU */
		SET_BIT(TIMSK,TICIE1);
	/* 4. set the timer prescalar = 8 for tick time 1 microsecond*/
		CLR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
	/* 5. Enable Interrupt of OVF */
		SET_BIT(TIMSK,TOIE1);
}

u16 TIM1_u16ReadICR1(){
	return ICR1;
}

void TIM1_vCallBack(void(*Fptr)(void)){
	G_PTRF_TIM1_ICF = Fptr;
}

void TIM1_vCallBack_OVF(void(*Fptr)(void)){
	G_PTRF_TIM1_OVF = Fptr;
}

void TIM1_vSetTriggering(u8 copy_u8Triggering){
	if(copy_u8Triggering == RISING_EDGE){
		SET_BIT(TCCR1B,ICES1);
	}
	else{
		CLR_BIT(TCCR1B,ICES1);
	}
}
void TIM1_vDisableInt(){
	CLR_BIT(TIMSK,TICIE1);
}

/* ISR for ICR event */
void __vector_6(void){
	/*Execute The  ISR [User Routine] */
	G_PTRF_TIM1_ICF();
}
/* ISR for OVF event */
void __vector_9(void){
	/*Execute The  ISR [User Routine] */
	G_PTRF_TIM1_OVF();
}