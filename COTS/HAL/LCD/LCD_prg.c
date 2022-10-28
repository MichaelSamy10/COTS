/*
 * LCD_prg.c
 *
 * Created: 8/22/2022 1:06:01 PM
 *  Author: MICHAEL
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_pri.h"
#include <avr/delay.h>


/*RW=0 RS=0 EN=1 Send_Command EN=0*/
static void LCD_vSendCmd(u8 A_u8Cmd){
	DIO_vSetPinVal(EN_PORT,EN_PIN,VAL_HIGH);
	DIO_vSetPinVal(RW_PORT,RW_PIN,VAL_LOW);
	DIO_vSetPinVal(RS_PORT,RS_PIN,VAL_LOW);
	
	DIO_vSetPortVal(DATA_PORT,A_u8Cmd);
	DIO_vSetPinVal(EN_PORT,EN_PIN,VAL_LOW);
	_delay_ms(2);
}

void LCD_vInit(){
		_delay_ms(30);
	DIO_vSetPortDir(DATA_PORT,DIR_OUTPUT_ALL);
	DIO_vSetPinDir(EN_PORT,EN_PIN,DIR_OUTPUT);
	DIO_vSetPinDir(RW_PORT,RW_PIN,DIR_OUTPUT);
	DIO_vSetPinDir(RS_PORT,RS_PIN,DIR_OUTPUT);
	
	_delay_ms(30);
	LCD_vSendCmd(EIGHT_BIT_MODE);
	_delay_us(39);
	LCD_vSendCmd(DISPLAY_ON);
	_delay_us(39);
	LCD_vSendCmd(CLR);
	_delay_ms(1.53);
	LCD_vSendCmd(ENTRY_MODE);

}

void LCD_vDispChar(u8 A_u8Char){
	_delay_us(20);
	DIO_vSetPinVal(EN_PORT,EN_PIN,VAL_HIGH);
	DIO_vSetPinVal(RW_PORT,RW_PIN,VAL_LOW);
	DIO_vSetPinVal(RS_PORT,RS_PIN,VAL_HIGH);
	
	DIO_vSetPortVal(DATA_PORT,A_u8Char);
	DIO_vSetPinVal(EN_PORT,EN_PIN,VAL_LOW);
	_delay_ms(2);
}

/* pointer to receive array in parameter */
void LCD_vDispString(u8 *A_u8Str){
	u8 L_u8Iterator=0;
	while (A_u8Str[L_u8Iterator] != '\0'){
		LCD_vDispChar(A_u8Str[L_u8Iterator]);
		L_u8Iterator++;
	}
}

void LCD_vDispNum(u32 A_u32Num){
	u32 L_u32Digit,temp[10],arr[10];
	s8 i=0;
	while(A_u32Num != 0){
		L_u32Digit = A_u32Num % 10 ;
		L_u32Digit = L_u32Digit + 0x30;
		A_u32Num = A_u32Num / 10;
		temp[i] = L_u32Digit;
		i++;
	}
	i--;
	while(i >=0 ){
		LCD_vDispChar(temp[i]);
		i--;
	}
	
}

void LCD_vClrScreen(){
	LCD_vSendCmd(CLR);
}

void LCD_vGoToRowCol(u8 A_u8RowId,u8 A_u8ColId){
	u8 L_u8Address;
	switch(A_u8RowId){
		case ROW0_ID: L_u8Address = 0x00 + A_u8ColId; break;
		case ROW1_ID: L_u8Address = 0x40 + A_u8ColId; break;
	}
	
	LCD_vSendCmd(0x80 + L_u8Address);
	
}
