/*
 * TIMER2_config.h
 *
 * Created: 02-Jan-24 10:23:19 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_


/* TIMER2 Mode options
*	1- TIMER2_NORMAL_MODE 
*	2- TIMER2_CTC_MODE
	3- TIMER2_FAST_PWM
	4- TIMER2_PHASE_CORRECT_PWM
*/
#define TIMER2_MODE TIMER2_NORMAL_MODE


/* TIMER2 Prescalar Options*/
/*
*  1- PRESCALER_1
*  2- PRESCALER_8			
*  3- PRESCALER_64		
*  4- PRESCALER_256		
*  5- PRESCALER_1024		

*/
#define TIMER2_PRESCALER PRESCALER_8

/*
	OC2 options in CTC mode
		1-CTC_OC2_DISABLE
		2-CTC_OC2_TOOGLE
		3-CTC_OC2_CLEAR
		4-CTC_OC2_SET
*/
#define CTC_OC2_PIN				CTC_OC2_DISABLE

/* OC2 pin options in PWM_MODE
		1-PWM_OC2_DISABLE
		2-PWM_OC2_NON_INVERTED
		3-PWM_OC2_INVERTED
*/
#define PWM_OC2_PIN			PWM_OC2_INVERTED



#endif /* TIMER2_CONFIG_H_ */