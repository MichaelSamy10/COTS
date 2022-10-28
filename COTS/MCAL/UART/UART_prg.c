/*
 * UART_prg.c
 *
 * Created: 9/21/2022 1:56:08 PM
 *  Author: MICHAEL
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "UART_cfg.h"
#include "UART_reg.h"
#include "UART_int.h"


void UART_vInit(void){
	u8 L_u8UCSRC = 0;
	#if UART_SET_MODE == UART_ASYNCHRONOUS_MODE 
		CLR_BIT(L_u8UCSRC,UMSEL);
	#else 
		SET_BIT(L_u8UCSRC,UMSEL);
	#endif
	
	#if UART_SET_PARITY == UART_DISABLED_PARITY
		CLR_BIT(L_u8UCSRC,UPM0);
		CLR_BIT(L_u8UCSRC,UPM1);
	#elif UART_SET_PARITY == UART_EVEN_PARITY
		CLR_BIT(L_u8UCSRC,UPM0);
		SET_BIT(L_u8UCSRC,UPM1);
	#elif UART_SET_PARITY == UART_ODD_PARITY
		SET_BIT(L_u8UCSRC,UPM0);
		SET_BIT(L_u8UCSRC,UPM1);
	#endif
	
	#if UART_SET_STOP_BIT == UART_STOP_ONE_BIT
		CLR_BIT(L_u8UCSRC,USBS);
	#else 
		SET_BIT(L_u8UCSRC,USBS);
	#endif
	
	#if UART_SET_CHR_SIZE == UART_CHR_SIZE_8
		SET_BIT(L_u8UCSRC,UCSZ0);
		SET_BIT(L_u8UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
	
	#endif
	SET_BIT(L_u8UCSRC,URSEL);
	UCSRC = L_u8UCSRC;
	/* Select Baud rate = 9600 b/sec */
	UBRRL = 51;
	/* Enable Tx and Rx */
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	
	
}

void UART_vSendChar(u8 data)
{
	// Wait until transmission Register Empty
	while((UCSRA & 0b00100000) == 0);
	UDR = data;
}

u8 UART_vGetData(void)
{
	// Wait until Reception Complete
	while((UCSRA & 0b10000000) == 0);
	
	return UDR;
	
}


void UART_vSendString(u8 * copy_u8Data){
		u8 L_u8Iterator=0;
		while (copy_u8Data[L_u8Iterator] != '\0'){
			UART_vSendChar(copy_u8Data[L_u8Iterator]);
			L_u8Iterator++;
		}
}


