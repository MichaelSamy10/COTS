/*
 * I2C_prg.c
 *
 * Created: 9/28/2022 10:01:38 AM
 *  Author: MICHAEL
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "I2C_cfg.h"
#include "I2C_int.h"
#include "I2C_pri.h"
#include "I2C_reg.h"



void TWI_Init(void)
{
    /* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
    TWBR  = 2;
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	
    /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
       General Call Recognition: Off */
	TWAR = 0x02;
	CLR_BIT(TWAR,TWGCE);
   /* enable TWI */
   
}

void TWI_Start(void)
{
    /* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
	
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

	
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	while((TWCR & 0b10000000) == 0);
	
}

void TWI_Stop(void)
{
    /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
    
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

void TWI_Write(u8 data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 

	TWCR = (1<<TWINT) | (1<<TWEN);

    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
	while((TWCR & 0b10000000) == 0);
	
}

u8 TWI_Read_With_ACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 

	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);

    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while((TWCR & 0b10000000) == 0);


    /* Read Data */
	return TWDR;
}

u8 TWI_Read_With_NACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
	SET_BIT(TWCR, TWINT);
	SET_BIT(TWCR, TWEN);
		TWCR = (1<<TWINT) | (1<<TWEN) ;

	
	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while((TWCR & 0b10000000) == 0);

    /* Read Data */
	return TWDR;

}

u8 TWI_u8Get_Status(void)
{
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	u8 status = (TWSR & 0b11111000);
	return status;
}