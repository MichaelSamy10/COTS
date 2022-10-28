/*
 * ADC_int.h
 *
 * Created: 8/31/2022 12:27:36 PM
 *  Author: MICHAEL
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

#define CHANNEL0_ID 0
#define CHANNEL1_ID	1
#define CHANNEL2_ID	2
#define CHANNEL3_ID	3
#define CHANNEL4_ID	4
#define CHANNEL5_ID	5
#define CHANNEL6_ID	6
#define CHANNEL7_ID 7

void ADC_vInit();

u16 ADC_u16GetDigValSync(u8 A_u8ChannelId);

void ADC_vGetDigValAsync(ptr_func G_ptr_func,u8 A_u8ChannelId);


#endif /* ADC_INT_H_ */