/*
 * EXI_int.h
 *
 * Created: 8/29/2022 1:26:14 PM
 *  Author: MICHAEL
 */ 


#ifndef EXI_INT_H_
#define EXI_INT_H_

#define INT0_ID 0
#define INT1_ID 1
#define INT2_ID 2

void EXI_vInit0();

void EXI_vInit1();

void EXI_vInit2();

static void(*G_ISR0_Ptr)(void);
static void(*G_ISR1_Ptr)(void);
static void(*G_ISR2_Ptr)(void);

void Reg_Func(void (*ISR_Ptr)(void),u8 A_u8IntId);

#endif /* EXI_INT_H_ */