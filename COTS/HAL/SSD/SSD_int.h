/*
 * SSD_int.h
 *
 * Created: 8/17/2022 11:14:49 AM
 *  Author: MICHAEL
 */ 


#ifndef SSD_INT_H_
#define SSD_INT_H_

#define SSD0_ID 0
#define SSD1_ID 1

void SSD_vInit(u8 A_u8Ssd_ID);

void SSD_vTurnOn(u8 A_u8Ssd_ID);

void SSD_vTurnOff(u8 A_u8Ssd_ID);

void SSD_vDispNum(u8 A_u8Ssd_ID,u8 A_u8Val);


#endif /* SSD_INT_H_ */