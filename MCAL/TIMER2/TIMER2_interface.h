/*
 * TIMER2_interface.h
 *
 * Created: 02-Jan-24 10:23:29 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


void TIMER2_voidInit();

/* 
	Function parameters -> number of overflows 
	Function polling to Normal mode (No interrupt)
*/
void TIMER2_voidOVSetIntervalSynchronous(u16 Copy_u16Counts);

/* 
	Function parameters -> number of overflows , pointer to function
	Function to enable TIMER2 normal mode interrupt 
*/

void TIMER2_voidOVSetIntervalSynchronousMS(u16 Copy_u16MilliSec);

void TIMER2_voidOVSetIntervalASynchronous(u16 Copy_u16Counts , void(*PtrFunc)(void));

void TIMER2_voidOVSetIntervalASynchronousMS(u16 Copy_u16MilliSec,void(*PtrFunc)(void));

/* 
	Function parameters -> number of overflows , pointer to function
	Function to enable TIMER2 CTC mode interrupt 
*/
void TIMER2_voidCTCSetIntervalASynchronous(u16 Copy_u16Counts , void(*PtrFunc)(void));

void TIMER2_voidCTCSetIntervalASynchronousMS(u16 Copy_u16MilliSec , void(*PtrFunc)(void));

void TIMER2_voidSetCompareValue(u16 Copy_u16CompVal);

void TIMER2_voidSetPreloadValue(u16 Copy_u16PreloadVal);

/* Start TIMER2 peripheral by setting the prescaler*/
void TIMER2_voidStart(void);

/* Stop TIMER2 peripheral */
void TIMER2_voidStop(void);


/* 
 * Normal mode call back function 
 * Function paramters -> pointer to function 
 * Function set call back to exceute ISR of normal mode
*/
void TIMER2_voidCallBack_OVF(void(*PtrFunc)(void));

/* 
 * CTC mode call back function 
 * Function paramters -> pointer to function
 * Function set call back to exceute ISR of CTC mode
*/
void TIMER2_voidCallBack_CTC(void(*PtrFunc)(void));





#endif /* TIMER2_INTERFACE_H_ */