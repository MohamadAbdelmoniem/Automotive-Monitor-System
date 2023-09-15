/*
 * LED_Prog.c
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : LED_Driver
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
#include "LED_Int.h"

void H_Led_Init(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case GREEN_LED: MGPIO_vSetPinMode(LED_PORT, GRN_LED_PIN,MODE_OUTPUT);   break;
		case RED_LED:   MGPIO_vSetPinMode(LED_PORT, RED_LED_PIN,MODE_OUTPUT);   break;
		default:                                                                break;
	}
}

void H_Led_On(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case GREEN_LED: MGPIO_vWriteData(LED_PORT, GRN_LED_PIN, _HIGH);   break;
		case RED_LED:   MGPIO_vWriteData(LED_PORT, RED_LED_PIN, _HIGH);   break;
		default:                                                          break;
	}
}

void H_Led_Off(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case GREEN_LED: MGPIO_vWriteData(LED_PORT, GRN_LED_PIN, _LOW);   break;
		case RED_LED:   MGPIO_vWriteData(LED_PORT, RED_LED_PIN, _LOW);   break;
		default:                                                         break;
	}
}

void H_Led_BlinkOnce(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case GREEN_LED:
			MGPIO_vWriteData(LED_PORT , GRN_LED_PIN, _HIGH);
			Delay_vUsIn16MHzint(BLINK_TIME);
		    MGPIO_vWriteData(LED_PORT , GRN_LED_PIN, _LOW);
		break;

		case RED_LED:
			MGPIO_vWriteData(LED_PORT , RED_LED_PIN, _HIGH);
			Delay_vUsIn16MHzint(BLINK_TIME);
		    MGPIO_vWriteData(LED_PORT , RED_LED_PIN, _LOW);
		break;

		default:
		break;
	}
}
