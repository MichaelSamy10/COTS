/*
 * ADC_pri.h
 *
 * Created: 8/31/2022 1:08:07 PM
 *  Author: MICHAEL
 */ 


#ifndef ADC_PRI_H_
#define ADC_PRI_H_


#define PRESCALAR_2    0
#define PRESCALAR_4    2
#define PRESCALAR_8    3
#define PRESCALAR_16   4
#define PRESCALAR_32   5
#define PRESCALAR_64   6
#define PRESCALAR_128  7


void (*G_ptr_func)(u16);

void __vector_16(void) __attribute__((signal));



#endif /* ADC_PRI_H_ */