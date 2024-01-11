/*
 * TIMER2_register.h
 *
 * Created: 02-Jan-24 10:23:07 AM
 *  Author: MICHAEL
 */ 


#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_


#define TCCR2 *( (volatile u8 *) 0x45)

#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7


#define TCNT2 *( (volatile u8 *) 0x44)

#define OCR2 *( (volatile u8 *) 0x43)

#define TIMSK *( (volatile u8 *) 0x59)

#define TOIE2	6
#define OCIE2	7

#define TIFR *( (volatile u8 *) 0x58)

#define TOV2	6
#define OCF2	7


#endif /* TIMER2_REGISTER_H_ */