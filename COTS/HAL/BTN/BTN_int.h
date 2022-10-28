/*
 * BTN_int.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Mohamed.Aboelrous
 */

#ifndef HAL_BTN_BTN_INT_H_
#define HAL_BTN_BTN_INT_H_

#define BTN0_ID 0
#define BTN1_ID 1
#define BTN2_ID 2
#define BTN3_ID 3
#define BTN4_ID 4
#define BTN5_ID 5
#define BTN6_ID 6
#define BTN7_ID 7

#define BTN_ON  1
#define BTN_OFF 0

void BTN_vInit(u8 A_u8BtnId);

u8 BTN_u8GetState(u8 A_u8BtnId);

#endif /* HAL_BTN_BTN_INT_H_ */
