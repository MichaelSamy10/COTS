/*
 * TIMER1_pri.h
 *
 * Created: 9/14/2022 12:22:56 PM
 *  Author: MICHAEL
 */ 


#ifndef TIMER1_PRI_H_
#define TIMER1_PRI_H_

/*Prescalar Options*/

 #define TIM1_STOP_TIMER					0	
 #define TIM1_NO_PRESCALAR					1
 #define TIM1_8PRESCALAR					2
 #define TIM1_64PRESCALAR					3
 #define TIM1_256PRESCALAR					4
 #define TIM1_1024PRESCALAR					5
 #define TIM1_EXTERNAL_CLK_FALLING_EDGE		6
 #define TIM1_EXTERNAL_CLK_RISING_EDGE		7


/* Timer Mode Options */

#define TIM1_OVF_MODE	0
#define FAST_PWM_ICR1	13
#define FAST_PWM_OCR1A	14
	

/* Timer OC0 Pin Options */

#define TIM1_0C1_DISCONNECTED  0
#define TIM1_OC1_TOGGLE		   1
#define TIM1_OC1_CLR		   2
#define TIM1_OC1_SET		   3


/* PWM Mode Option*/
#define TIM1_PWM_NON_INVERTING 0
#define TIM1_PWM_INVERTING     1


/*Timer0 CTC Interrupt Options*/
#define TIMER1_CTC_INTERRUPT_ENABLED                0
#define TIMER1_CTC_INTERRUPT_DISABLED               1


void __vector_6(void)__attribute__((signal));
void __vector_7(void)__attribute__((signal));
void __vector_8(void)__attribute__((signal));
void __vector_9(void)__attribute__((signal));

#endif /* TIME1R_PRI_H_ */