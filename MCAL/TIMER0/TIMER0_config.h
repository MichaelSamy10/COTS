/*
 * TIMER0_config.h
 *
 * Created: 19-Dec-23 2:01:36 PM
 *  Author: MICHAEL
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/* Options:
	TIMER
	COUNTER
 */
#define TIMER0_COUNTER_MODE	TIMER


/* TIMER0 Mode options
*	1- TIMER0_NORMAL_MODE 
*	2- TIMER0_CTC_MODE
	3- TIMER0_FAST_PWM
	4- TIMER0_PHASE_CORRECT_PWM
*/
#define TIMER0_MODE TIMER0_NORMAL_MODE


/* TIMER0 Prescalar Options*/
/*
*  1- PRESCALER_1
*  2- PRESCALER_8			
*  3- PRESCALER_64		
*  4- PRESCALER_256		
*  5- PRESCALER_1024		

*/
#define TIMER0_PRESCALER PRESCALER_8

/*
Counter options:
	1-COUNTER0_SENSE_RISING
	2-COUNTER0_SENSE_FALLING
*/
#define COUNTER0_SENSE	COUNTER0_SENSE_RISING

/*
	OC0 options in CTC mode
		1-CTC_OC0_DISABLE
		2-CTC_OC0_TOOGLE
		3-CTC_OC0_CLEAR
		4-CTC_OC0_SET
*/
#define CTC_OC0_PIN				CTC_OC0_DISABLE

/* OC0 pin options in PWM_MODE
		1-PWM_OC0_DISABLE
		2-PWM_OC0_NON_INVERTED
		3-PWM_OC0_INVERTED
*/
#define PWM_OC0_PIN			PWM_OC0_NON_INVERTED


#endif /* TIMER0_CONFIG_H_ */