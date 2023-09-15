/*
 * Buzzer_Prog.c
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Buzzer_Driver
 *  File    : Program File
 *  Version :1.0
 */

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/
#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"
#include "../src/LIB/Delay/Delay_Interface.h"

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "../src/MCAL/MGPIO/MGPIO_Int.h"
#include "Buzzer_Int.h"


void H_Buzzer_Void_BuzzerInit(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
    MGPIO_vSetPinMode(Copy_u8PortName,Copy_u8PinNum,MODE_OUTPUT);
    MGPIO_vSetPinOutPutType(Copy_u8PortName,Copy_u8PinNum,_OUTPUT_TYPE_PUSH_PUL);
    MGPIO_vSetPinOutSpeed(Copy_u8PortName,Copy_u8PinNum,_OUTPUT_SPEED_LOW);
    MGPIO_vSetPullType(Copy_u8PortName,Copy_u8PinNum,_PULL_OFF);
}

void H_Buzzer_Void_BuzzerOn(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, _HIGH);
}

void H_Buzzer_Void_BuzzerOff(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, _LOW);
}

void H_Buzzer_Void_BuzzerOnce(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, _HIGH);
	Delay_vMsIn16MHz(BUZZER_ON_DELAY_TIME);
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, _LOW);
}
void H_Buzzer_Void_BuzzerTwice(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	H_Buzzer_Void_BuzzerOnce(Copy_u8PortName, Copy_u8PinNum);
	Delay_vMsIn16MHz(BUZZER_OFF_DELAY_TIME);
	H_Buzzer_Void_BuzzerOnce(Copy_u8PortName, Copy_u8PinNum);
}

void H_Buzzer_Void_BuzzerTriple(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	H_Buzzer_Void_BuzzerOnce(Copy_u8PortName, Copy_u8PinNum);
	Delay_vMsIn16MHz(BUZZER_OFF_DELAY_TIME);
	H_Buzzer_Void_BuzzerOnce(Copy_u8PortName, Copy_u8PinNum);
	Delay_vMsIn16MHz(BUZZER_OFF_DELAY_TIME);
	H_Buzzer_Void_BuzzerOnce(Copy_u8PortName, Copy_u8PinNum);
}

void H_Buzzer_Void_BuzzerOnceLong(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, _HIGH);
	Delay_vMsIn16MHz(BUZZER_ON_LONG_DELAY_TIME);
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, _LOW);
}
