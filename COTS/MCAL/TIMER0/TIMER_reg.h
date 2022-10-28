/*
 * TIMER_reg.h
 *
 * Created: 9/13/2022 11:28:33 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TCCR0 *( (volatile u8 *) 0x53)

#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7


#define TCNT0 *( (volatile u8 *) 0x52)

#define OCR0 *( (volatile u8 *) 0x5C)

#define TIMSK *( (volatile u8 *) 0x59)
/* other bits are not used */
#define TOIE0 0
#define OCIE0 1


#define TIFR *( (volatile u8 *) 0x58)
/* other bits are not used */
#define TOV0 0
#define OCF0 1

#endif /* TIMER_REG_H_ */