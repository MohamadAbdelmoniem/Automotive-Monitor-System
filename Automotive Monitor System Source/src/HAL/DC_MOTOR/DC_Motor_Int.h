/*
 * DC_Motor_Int.h
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : DC_MOTOR_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INT_H_
#define HAL_DC_MOTOR_DC_MOTOR_INT_H_



/** DC Motor Rotation Mode **/
typedef enum
{
	ROTATE_CLOCKWISE,
	ROTATE_ANTI_CLOCKWISE,
	STOP

}DC_MODE;

/************************************************** APIs ************************************************/
void H_DC_MOTOR_Void_DCMotorInit(void);
void H_DC_MOTOR_Void_RotationControl(DC_MODE Mode);



#endif /* HAL_DC_MOTOR_DC_MOTOR_INT_H_ */
