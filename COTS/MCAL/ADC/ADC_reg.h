/*
 * ADC_reg.h
 *
 * Created: 8/31/2022 12:06:49 PM
 *  Author: MICHAEL
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_


/* ADMUC Register */
#define ADMUX  *( (u8 *) 0x27)

#define MUX0   0
#define MUX1   1
#define MUX2   2
#define MUX3   3
#define MUX4   4
#define ADLAR  5
#define REFS0  6 
#define REFS1  7

/*ADCSRA Control and Status Register */
#define ADCSRA *( (volatile u8 *) 0x26)

#define ADPS0	0
#define ADPS1	1
#define ADPS2	2
#define ADIE	3
#define ADIF	4
#define ADATE	5
#define ADSC	6
#define ADEN	7

/* ADCH Data Register */
#define ADCH   *( (volatile u8 *) 0x25)
/* Other bits are not used */
#define ADC8
#define ADC9

/* ADCL Data Register */
#define ADCL   *( (volatile u8 *) 0x24)

#define ADC0   0
#define ADC1   1
#define ADC2   2
#define ADC3   3
#define ADC4   4
#define ADC5   5
#define ADC6   6
#define ADC7   7

/* To read 10 bits */
#define ADC_DATA *( (volatile u16 *) 0x24)

/* Special FunctionIO Register */
#define SFIOR  *( (u8 *) 0x50)
/* Other bits are not used */ 
#define ADTS0  5 
#define ADTS1  6
#define ADTS2  7
		

#endif /* ADC_REG_H_ */