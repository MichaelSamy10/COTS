/*
 * GIE_prg.c
 *
 * Created: 8/29/2022 1:03:48 PM
 *  Author: MICHAEL
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_int.h"
#include "GIE_reg.h"

void GIE_vEnable(){
	SET_BIT(SREG,I);
}

void GIE_vDisable(){
	CLR_BIT(SREG,I);
}