/*
 * Switch_Prog.c
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Switch_Driver
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
#include "Switch_Int.h"

void H_Switch_Void_SwitchInit(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{
    MGPIO_vSetPinMode(Copy_u8PortName, Copy_u8PinNum, MODE_INPUT);
    MGPIO_vSetPinOutPutType(Copy_u8PortName, Copy_u8PinNum, _OUTPUT_TYPE_PUSH_PUL);
    MGPIO_vSetPinOutSpeed(Copy_u8PortName, Copy_u8PinNum, _OUTPUT_SPEED_LOW);
    MGPIO_vSetPullType(Copy_u8PortName, Copy_u8PinNum, ACTIVE_LOW);
}

u8   H_Switch_U8_SwitchRead(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{

#if   SWITCH_MODE   ==   ACTIVE_LOW
#define CLOSE       0
#define OPEN        1

#elif SWITCH_MODE   ==   ACTIVE_HIGH
#define CLOSE       1
#define OPEN        0
#endif

	u8 Local_u8_Reading = OPEN;
	Local_u8_Reading = MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum);
	if(Local_u8_Reading == CLOSE)
	{
		if(MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum) == CLOSE)
		{
			Local_u8_Reading = CLOSE;
		}
	}
	return Local_u8_Reading;
}


