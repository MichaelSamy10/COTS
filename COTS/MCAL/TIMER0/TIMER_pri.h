/*
 * TIMER_pri.h
 *
 * Created: 9/14/2022 12:22:56 PM
 *  Author: MICHAEL
 */ 


#ifndef TIMER_PRI_H_
#define TIMER_PRI_H_

/*Prescalar Options*/

 #define TIM0_STOP_TIMER					0	
 #define TIM0_NO_PRESCALAR					1
 #define TIM0_8PRESCALAR					2
 #define TIM0_64PRESCALAR					3
 #define TIM0_256PRESCALAR					4
 #define TIM0_1024PRESCALAR					5
 #define TIM0_EXTERNAL_CLK_FALLING_EDGE		6
 #define TIM0_EXTERNAL_CLK_RISING_EDGE		7


/* Timer Mode Options */

#define TIM0_OVF_MODE			0
#define TIM0_PHASE_CORRECT_PWM	1
#define TIM0_CTC_MODE			2
#define TIM0_FAST_PWM			3
#define TIM0_MODE_MASK		0b10110111


/* Timer OC0 Pin Options */

#define TIM0_0C0_DISCONNECTED  0
#define TIM0_OC0_TOGGLE		   1
#define TIM0_OC0_CLR		   2
#define TIM0_OC0_SET		   3

/* PWM Mode Option*/
#define TIM0_PWM_NON_INVERTING 0
#define TIM0_PWM_INVERTING     1


/*Timer0 CTC Interrupt Options*/
#define TIMER0_CTC_INTERRUPT_ENABLED                0
#define TIMER0_CTC_INTERRUPT_DISABLED               1



void __vector_10(void)__attribute__((signal));
void __vector_11(void)__attribute__((signal));

#endif /* TIMER_PRI_H_ */