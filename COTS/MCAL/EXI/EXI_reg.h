/*
 * EXI_reg.h
 *
 * Created: 8/29/2022 1:26:25 PM
 *  Author: MICHAEL
 */ 


#ifndef EXI_REG_H_
#define EXI_REG_H_

/* MCU Control Register */
#define MCUCR *( ( u8 *) 0x55)
/* Bits number 7:4 are not used in this driver */
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/* MCU Control and Status Register */
#define MCUCSR *( ( u8 *) 0x54)
/* Bit 5 is reserved , Other bits are not used in this driver */
#define ISC2 6

/* GICR Register */
#define GICR *( ( u8 *) 0x5B)
/* bits 4,3,2 are reserved , bits 1,0 are for another peripheral */
#define INT2 5 
#define INT1 7
#define INT0 6

/*GIFR Register */
#define GIFR *( ( volatile u8 *) 0x5A)
/* Other bits are not used in this driver */
#define INTF0 6
#define INTF1 7
#define INTF2 5


#endif /* EXI_REG_H_ */