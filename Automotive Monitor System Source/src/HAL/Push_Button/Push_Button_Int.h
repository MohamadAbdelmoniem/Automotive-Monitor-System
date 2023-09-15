/*
 * Push_Button_Int.h
 *
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Push_Button_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_PUSH_BUTTON_PUSH_BUTTON_INT_H_
#define HAL_PUSH_BUTTON_PUSH_BUTTON_INT_H_


#include "Push_Button_Private.h"
#include "Push_Button_Config.h"

/*********************************************************_MACROS_*******************************/
#define ACTIVE_LOW      1
#define ACTIVE_HIGH     2

/*******************************************************_PROTOTYPES_*****************************/
void H_PushButton_Void_PushButtonInit(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
u8   H_PushButton_U8_PushButtonRead(u8 Copy_u8PortName ,u8 Copy_u8PinNum);


#endif /* HAL_PUSH_BUTTON_PUSH_BUTTON_INT_H_ */
