/*
 * TIMER1_reg.h
 *
 * Created: 9/13/2022 11:28:33 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#define TCCR1A *((volatile u8*) 0x4F)

#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7


#define TCCR1B *((volatile u8*) 0x4E)

#define CS10   0
#define CS11   1
#define CS12   2
#define WGM12  3
#define WGM13  4
#define ICES1  6
#define ICNC1  7


#define OCR1A  *((volatile u16*) 0x4A)

#define OCR1B  *((volatile u16*) 0x48)

#define ICR1   *((volatile u16*) 0x46)		/* address of low */

#define TIMSK  *((volatile u16*) 0x59)
#define TOIE1	2
#define TICIE1  5


#endif /* TIMER1_REG_H_ */