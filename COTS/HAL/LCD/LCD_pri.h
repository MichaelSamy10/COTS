/*
 * LCD_pri.h
 *
 * Created: 8/22/2022 1:43:25 PM
 *  Author: MICHAEL
 */ 


#ifndef LCD_PRI_H_
#define LCD_PRI_H_


#define CLR				 0b00000001
#define RETURN_HOME		 0b00000010
#define ENTRY_MODE		 0b00000110
#define DISPLAY_OFF		 0b00001000
#define DISPLAY_ON		 0b00001100
#define EIGHT_BIT_MODE   0b00111000
#define FOUR_BIT_MODE    0b00101000

/*Available modes*/
#define FOUR_BIT 1
#define EIGHT_BIT 0

static void LCD_vSendCmd(u8 A_u8Cmd);

#endif /* LCD_PRI_H_ */