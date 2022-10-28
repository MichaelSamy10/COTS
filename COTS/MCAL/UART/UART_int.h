/*
 * UART_int.h
 *
 * Created: 9/21/2022 1:55:53 PM
 *  Author: MICHAEL
 */ 


#ifndef UART_INT_H_
#define UART_INT_H_

void UART_vInit(void);

void UART_vSendChar(u8 data);

u8 UART_vGetData(void);

void UART_vSendString(u8 * copy_u8Data);


#endif /* UART_INT_H_ */