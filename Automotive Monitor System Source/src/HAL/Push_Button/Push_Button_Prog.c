/*
 * Push_Button_Prog.c
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Push_Button_Driver
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
#include "Push_Button_Int.h"


void H_PushButton_Void_PushButtonInit(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{
    MGPIO_vSetPinMode(Copy_u8PortName, Copy_u8PinNum, MODE_INPUT);
    MGPIO_vSetPinOutPutType(Copy_u8PortName, Copy_u8PinNum, _OUTPUT_TYPE_PUSH_PUL);
    MGPIO_vSetPinOutSpeed(Copy_u8PortName, Copy_u8PinNum, _OUTPUT_SPEED_LOW);
    MGPIO_vSetPullType(Copy_u8PortName, Copy_u8PinNum, ACTIVE_LOW);
}

u8   H_PushButton_U8_PushButtonRead(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{

#if   PUSHBUTTON_MODE   ==   ACTIVE_LOW
#define PRESSED         0
#define RELEASED        1

#elif PUSHBUTTON_MODE   ==   ACTIVE_HIGH
#define PRESSED         1
#define RELEASED        0
#endif

	u8 Local_u8_Reading = RELEASED;
	Local_u8_Reading = MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum);
	if(Local_u8_Reading == PRESSED)
	{
		Delay_vMsIn16MHz(PUSHBUTTON_DEBOUNCING_TIME);
		if(MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum) == PRESSED)
		{
			while(MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum) == PRESSED);
			Local_u8_Reading = PRESSED;
		}
	}
	return Local_u8_Reading;
}
