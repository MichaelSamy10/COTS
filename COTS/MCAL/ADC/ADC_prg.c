/*
 * ADC_prg.c
 *
 * Created: 9/1/2022 10:24:02 AM
 *  Author: MICHAEL
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_reg.h"
#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_pri.h"

void ADC_vInit(){
	/* Rference , enable , Auto trigger , adjustment , Prescalar */
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,ADLAR);
	
	SET_BIT(ADCSRA,ADEN);
	CLR_BIT(ADCSRA,ADATE);
	ADCSRA = (ADCSRA & 0b11111000) | PRESCALAR_128 ;
	
}

u16 ADC_u16GetDigValSync(u8 A_u8ChannelId){
	/* Select channel */ 
	ADMUX = (ADMUX & 0b11100000) | A_u8ChannelId ;
	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	/* Busy Wait */
	while(GET_BIT(ADCSRA,ADIF) == 0);
	/* ADIF is cleared by writing a logical one */
	SET_BIT(ADCSRA,ADIF);
	return ADC_DATA;
}

void ADC_vGetDigValAsync(ptr_func A_ptr_func,u8 A_u8ChannelId){
	/* Select Channel */
	ADMUX = (ADMUX & 0b11100000) | A_u8ChannelId ;
	/* Enable ADC Interrupt */
	SET_BIT(ADCSRA,ADIE);
	G_ptr_func = A_ptr_func ;
	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	
}

void __vector_16(void){
	G_ptr_func(ADC_DATA);
	CLR_BIT(ADCSRA,ADIE);
}