/*
 * DC_Motor_Prog.c
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : DC_MOTOR_Driver
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

#include "DC_Motor_Config.h"
#include "DC_Motor_Int.h"



/**************************************   APIs   ********************************************/

/*
 return type = void
 input parameters = VOID
 functionality : Initialize the DC motor
 */
void H_DC_MOTOR_Void_DCMotorInit(void)
{
	MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN1 , MODE_OUTPUT );
	MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN2 , MODE_OUTPUT );
	MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_ENA , MODE_ANALOG );
	MGPIO_vSetPullType(DC_MOTOR_PORT, DC_MOTOR_ENA, _PULL_UP);

	MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN1 , _HIGH);
	MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN2 , _HIGH);
	MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_ENA , _HIGH);
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = DC Motor Mode
 functionality : Control DC Motor Rotation
*/

void H_DC_MOTOR_Void_RotationControl(DC_MODE Mode)
{
	switch(Mode)
	{
		case ROTATE_CLOCKWISE:
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN1 , _LOW);
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN2 , _HIGH);
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_ENA , _LOW);
			break;

		case ROTATE_ANTI_CLOCKWISE:
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN1 , _HIGH);
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN2 , _LOW);
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_ENA , _LOW);
			break;

		case STOP:
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN1 , _HIGH);
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_IN2 , _HIGH);
			MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_ENA , _HIGH);
			break;

		default:
			/* DO NOTHING */
			break;
	}
}

