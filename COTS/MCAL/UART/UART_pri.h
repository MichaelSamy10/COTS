/*
 * UART_pri.h
 *
 * Created: 9/22/2022 10:19:54 AM
 *  Author: MICHAEL
 */ 


#ifndef UART_PRI_H_
#define UART_PRI_H_


#define UART_ASYNCHRONOUS_MODE 0
#define UART_SYNCHRONOUS_MODE  1


#define UART_DISABLED_PARITY   0
#define UART_EVEN_PARITY	   1
#define UART_ODD_PARITY        2


#define UART_STOP_ONE_BIT	   0
#define UART_STOP_TWO_BIT	   1


#define UART_CHR_SIZE_5		   0
#define UART_CHR_SIZE_6		   1
#define UART_CHR_SIZE_7		   2
#define UART_CHR_SIZE_8		   3
#define UART_CHR_SIZE_9		   4

#endif /* UART_PRI_H_ */