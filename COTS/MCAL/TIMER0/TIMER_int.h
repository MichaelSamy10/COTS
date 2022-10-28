/*
 * TIMER_int.h
 *
 * Created: 9/13/2022 11:59:23 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER_INT_H_
#define TIMER_INT_H_

/* Timer Init Steps:
	1- Enable timer 
	2- set prescalar 
	3- Mode 
	4- set OCO pin State 
*/
void TIM0_vInit();

/* Set Preload to count from the preload value */
void TIM0_vSetPreload(u8 A_u8PreloadVal);

/* Set OCR Value to be the TOP counts to generate CTC flag */
void TIM0_vSetOcrVal(u8 A_u8OcrVal);

/* Set call back to execeute ISR related with OVF event*/
void TIM0_vCallBack_OVF(void(*Fptr)(void));

/* Set call back to execeute ISR related with CTC event*/
void TIM0_vCallBack_CTC(void(*Fptr)(void));


#endif /* TIMER_INT_H_ */