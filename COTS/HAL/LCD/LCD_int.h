/*
 * LCD_int.h
 *
 * Created: 8/22/2022 12:56:54 PM
 *  Author: MICHAEL
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

#define ROW0_ID 0
#define ROW1_ID 1

#define COL0_ID  0
#define COL1_ID  1
#define COL2_ID  2
#define COL3_ID  3
#define COL4_ID  4
#define COL5_ID  5
#define COL6_ID  6
#define COL7_ID  7
#define COL8_ID  8
#define COL9_ID  9
#define COL10_ID 10
#define COL11_ID 11
#define COL12_ID 12
#define COL13_ID 13
#define COL14_ID 14
#define COL15_ID 15


void LCD_vInit();

void LCD_vDispChar(u8 A_u8Char);

void LCD_vDispString(u8 *A_u8Str);

void LCD_vDispNum(u32 A_u32Num);

void LCD_vClrScreen();

void LCD_vGoToRowCol(u8 A_u8RowId,u8 A_u8ColId);



#endif /* LCD_INT_H_ */