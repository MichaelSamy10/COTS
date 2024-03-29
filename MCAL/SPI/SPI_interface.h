/*
 * SPI_interface.h
 *
 * Created: 24-Dec-23 9:18:07 PM
 *  Author: MICHAEL
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_voidInit();

u8 SPI_u8TransReceive(u8 Copy_u8Data);

void SPI_voidTransmitAsynch(u8 Copy_u8Data,void(*PtrFunc)(void));

u8 SPI_u8ReceiveAsynch();

void SPI_voidCallBack(void(*PtrFunc)(void));

void SPI_voidEnableInterrupt();

void SPI_voidDisableInterrupt();

#define MASTER_MODE		0
#define SLAVE_MODE		1


#endif /* SPI_INTERFACE_H_ */