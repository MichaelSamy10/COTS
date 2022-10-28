/*
 * GIE_reg.h
 *
 * Created: 8/29/2022 1:03:36 PM
 *  Author: MICHAEL
 */ 


#ifndef GIE_REG_H_
#define GIE_REG_H_

/* Status Register Definition */

#define SREG *( (volatile u8 *) 0x5F)

#define C	0	/*		Carry Flag		 	  */
#define Z	1	/*		Zero Flag		 	  */
#define N	2	/*		Negative Flag         */
#define V	3	/*	 Two's Complement Flag	  */
#define S	4	/*		Sign Flag		 	  */
#define H	5	/*		Half carry Flag 	  */
#define T	6	/*	  Bit copy Storage 		  */
#define I	7	/*	Global Interrupt Enable   */

#endif /* GIE_REG_H_ */