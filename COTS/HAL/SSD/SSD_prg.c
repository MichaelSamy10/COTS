/*
 * SSD_prg.c
 *
 * Created: 8/17/2022 11:54:28 AM
 *  Author: MICHAEL
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_pri.h"
#include "SSD_cfg.h"
#include "SSD_int.h"

void SSD_vInit(u8 A_u8Ssd_ID){
	switch(A_u8Ssd_ID){
		case SSD0_ID:{
			DIO_vsetPortDir(SSD0_DATA_PORT,DIR_OUTPUT_ALL);
			DIO_vSetPinDir(SSD0_EN_PORT,SSD0_EN_PIN,DIR_OUTPUT);
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSD0_EN_PORT,SSD0_EN_PIN,VAL_HIGH);
			#else
				DIO_vSetPinVal(SSD0_EN_PORT,SSD0_EN_PIN,VAL_LOW);
			#endif
			break;	
		}
		case SSD1_ID:{
			DIO_vsetPortDir(SSD1_DATA_PORT,DIR_OUTPUT_ALL);
			DIO_vSetPinDir(SSD1_EN_PORT,SSD0_EN_PIN,DIR_OUTPUT);
			#if (SSD_COM == COM_CATHODE)
			DIO_vSetPinVal(SSD1_EN_PORT,SSD0_EN_PIN,VAL_HIGH);
			#else
			DIO_vSetPinVal(SSD1_EN_PORT,SSD0_EN_PIN,VAL_LOW);
			#endif
			break;
		}
	}
}

void SSD_vTurnOn(u8 A_u8Ssd_ID){
	switch(A_u8Ssd_ID){
		case SSD0_ID:{
			#if (SSD_COM == COM_CATHODE)
			DIO_vSetPinVal(SSD0_EN_PORT,SSD0_EN_PIN,VAL_LOW);
			#else
			DIO_vSetPinVal(SSD0_EN_PORT,SSD0_EN_PIN,VAL_HIGH);
			#endif
			break;
		}
		case SSD1_ID:{
			#if (SSD_COM == COM_CATHODE)
			DIO_vSetPinVal(SSD1_EN_PORT,SSD0_EN_PIN,VAL_LOW);
			#else
			DIO_vSetPinVal(SSD1_EN_PORT,SSD0_EN_PIN,VAL_HIGH);
			#endif
			break;
		}
	}
}

void SSD_vTurnOff(u8 A_u8Ssd_ID){
		switch(A_u8Ssd_ID){
			case SSD0_ID:{
				#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSD0_EN_PORT,SSD0_EN_PIN,VAL_HIGH);
				#else
				DIO_vSetPinVal(SSD0_EN_PORT,SSD0_EN_PIN,VAL_LOW);
				#endif
				break;
			}
			case SSD1_ID:{
				#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSD1_EN_PORT,SSD1_EN_PIN,VAL_HIGH);
				#else
				DIO_vSetPinVal(SSD1_EN_PORT,SSD1_EN_PIN,VAL_LOW);
				#endif
				break;
			}
		}
}

void SSD_vDispNum(u8 A_u8Ssd_ID,u8 A_u8Val){
	static u8 L_u8SsdDecToSegArr[10] = {0b00111111,   /* 0 */
		0b00000110,   /* 1 */
		0b01011011,   /* 2 */
		0b01001111,   /* 3 */
		0b01100110,   /* 4 */
		0b01101101,   /* 5 */
		0b01111101,   /* 6 */
		0b00000111,   /* 7 */
		0b01111111,   /* 8 */
		0b01101111    /* 9 */
	};
	switch(A_u8Ssd_ID){
		case SSD0_ID:{
			#if (SSD_COM == COM_CATHODE)
				DIO_vsetPortVal(SSD0_DATA_PORT,L_u8SsdDecToSegArr[A_u8Val]);
			#else
				DIO_vsetPortVal(SSD0_DATA_PORT,~L_u8SsdDecToSegArr[A_u8Val]);
			#endif
			break;
		}
		case SSD1_ID:{
			#if (SSD_COM == COM_CATHODE)
			DIO_vsetPortVal(SSD1_DATA_PORT,L_u8SsdDecToSegArr[A_u8Val]);
			#else
			DIO_vsetPortVal(SSD1_DATA_PORT,~L_u8SsdDecToSegArr[A_u8Val]);
			#endif
			break;
		}
	}
}

