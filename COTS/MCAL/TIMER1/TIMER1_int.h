/*
 * TIMER_int.h
 *
 * Created: 9/13/2022 11:59:23 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#define FALLING_EDGE	0
#define RISING_EDGE		1

/* Timer Init Steps:
	1- Enable timer 
	2- set prescalar 
	3- Mode 
	4- set OCO pin State 
*/
void TIM1_vInit();

/* Set Preload to count from the preload value */
void TIM1_vSetPreload(u8 A_u8PreloadVal);

/* Set OCR Value to be the TOP counts to generate CTC flag */
void TIM1_vSetOcr1aVal(u16 copy_u16Val);

/* Set call back to execeute ISR related with OVF event*/
void TIM1_vCallBack_OVF(void(*Fptr)(void));

/* Set call back to execeute ISR related with CTC event*/
void TIM1_vCallBack_CTC(void(*Fptr)(void));

void TIM1_vIcuMode();

u16 TIM1_u16ReadICR1();

void TIM1_vCallBack(void(*Fptr)(void));

void TIM1_vSetTriggering(u8 copy_u8Triggering);

void TIM1_vDisableInt();


#endif /* TIMER_INT_H_ */