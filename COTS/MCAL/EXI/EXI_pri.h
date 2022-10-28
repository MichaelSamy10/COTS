/*
 * EXI_pri.h
 *
 * Created: 8/29/2022 1:49:41 PM
 *  Author: MICHAEL
 */ 


#ifndef EXI_PRI_H_
#define EXI_PRI_H_

/* Connections are not important in this driver */
#define INT0_PORT PORTD_ID
#define INT0_PIN  PIN2_ID

#define INT1_PORT PORTD_ID
#define INT1_PIN  PIN3_ID

#define INT2_PORT PORTB_ID
#define INT2_PIN  PIN2_ID


#define INT0_FALLING_EDGE 2
#define INT0_RISING_EDGE  3

#define INT1_FALLING_EDGE 2
#define INT1_RISING_EDGE  3

#define INT2_FALLING_EDGE 0
#define INT2_RISING_EDGE  0b01000000

/*number 1 for external interrupt 0 in vector table */
void __vector_1(void) __attribute__((signal));

/*number 2 for external interrupt 0 in vector table */
void __vector_2(void) __attribute__((signal));

/*number 3 for external interrupt 0 in vector table */
void __vector_3(void) __attribute__((signal));


#endif /* EXI_PRI_H_ */