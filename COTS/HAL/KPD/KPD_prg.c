/*
 * KPD_prg.c
 *
 * Created: 8/24/2022 11:44:39 AM
 *  Author: MICHAEL
 */ 
#include <avr/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "KPD_int.h"
#include "KPD_cfg.h"
#include "KPD_pri.h"


void KPD_vInit(){
	
	for (u8 i=ROW_START;i<=ROW_END;i++){
		DIO_vSetPinDir(KPD_PORT,i,DIR_INPUT);
		DIO_vSetPinVal(KPD_PORT,i,VAL_HIGH);
	}
	for (u8 i=COL_START;i<=COL_END;i++){
		DIO_vSetPinDir(KPD_PORT,i,DIR_OUTPUT);
		DIO_vSetPinVal(KPD_PORT,i,VAL_HIGH);
	}
	
}

u8 KPD_u8GetPressedKey(){
	u8 L_u8PressedKey=NO_PRESSED_KEY,L_u8Pinval;
	const u8 L_KeypadVal[ROWS_NUM][COLS_NUM] = {
				{'7','8','9','/'},
				{'4','5','6','*'},
				{'1','2','3','-'},
				{'C','0','=','+'}
			};
	for(u8 i=COL_START;i<=COL_END;i++){
		DIO_vSetPinVal(KPD_PORT,i,VAL_LOW);
		for (u8 j=ROW_START;j<=ROW_END;j++){
			L_u8Pinval = DIO_u8GetPinVal(KPD_PORT,j);
			if(L_u8Pinval == 0){
				L_u8PressedKey = L_KeypadVal[j-ROW_START][i-COL_START];
				while(L_u8Pinval == 0){
					L_u8Pinval = DIO_u8GetPinVal(KPD_PORT,j);
				}
				_delay_ms(20);
				break;
			}
		}
		DIO_vSetPinVal(KPD_PORT,i,VAL_HIGH);
	}	
	
	return L_u8PressedKey;
	
}
