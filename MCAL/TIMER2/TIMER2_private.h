/*
 * TIMER2_private.h
 *
 * Created: 02-Jan-24 10:23:41 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_


/* TIMER2 Mode Options */
#define TIMER2_NORMAL_MODE			0
#define TIMER2_PHASE_CORRECT_PWM	0b01000000
#define TIMER2_CTC_MODE				0b00001000
#define TIMER2_FAST_PWM				0b01001000


/*Prescalar Options*/
#define PRESCALER_1								1
#define PRESCALER_8								2
#define PRESCALER_32							3
#define PRESCALER_64							4
#define PRESCALER_128							5
#define PRESCALER_256							6
#define PRESCALER_1024							7


/* OC2 pin options in CTC mode */
#define  CTC_OC2_DISABLE						0
#define  CTC_OC2_TOOGLE							0b00010000
#define  CTC_OC2_CLEAR							0b00100000
#define  CTC_OC2_SET							0b00110000

/* OC2 pin options in PWM mode */
#define PWM_OC2_DISABLE							0
#define PWM_OC2_NON_INVERTED					0b00100000
#define PWM_OC2_INVERTED						0b00110000



#endif /* TIMER2_PRIVATE_H_ */