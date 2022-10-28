/*
 * DC_MOTOR_prg.c
 *
 * Created: 8/28/2022 12:07:42 PM
 *  Author: MICHAEL
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DC_MOTOR_cfg.h"
#include "DC_MOTOR_int.h"
#include "../../MCAL/DIO/DIO_int.h"

void DC_MOTOR_vInit(){
	DIO_vSetPinDir(DC_MOTOR_PORT,DC_MOTOR_PIN0,DIR_OUTPUT);
	DIO_vSetPinDir(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIR_OUTPUT);	
}

void DC_MOTOR_vClockwise(){
	DIO_vSetPinVal(DC_MOTOR_PORT,DC_MOTOR_PIN0,VAL_HIGH);
	DIO_vSetPinVal(DC_MOTOR_PORT,DC_MOTOR_PIN1,VAL_LOW);
}

void DC_MOTOR_vAntiClockwise(){
	DIO_vSetPinVal(DC_MOTOR_PORT,DC_MOTOR_PIN0,VAL_LOW);
	DIO_vSetPinVal(DC_MOTOR_PORT,DC_MOTOR_PIN1,VAL_HIGH);
}

void DC_MOTOR_vTurnOff(){
	DIO_vSetPinVal(DC_MOTOR_PORT,DC_MOTOR_PIN0,VAL_LOW);
	DIO_vSetPinVal(DC_MOTOR_PORT,DC_MOTOR_PIN1,VAL_LOW);
}

