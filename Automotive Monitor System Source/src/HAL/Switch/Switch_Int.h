/*
 * Switch_Int.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Switch_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_

#include "Switch_Private.h"
#include "Switch_Config.h"


/*********************************************************_MACROS_*******************************/
#define ACTIVE_LOW      1
#define ACTIVE_HIGH     2

#define CLOSE           0
#define OPEN            1

/*******************************************************_PROTOTYPES_*****************************/
void H_Switch_Void_SwitchInit(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
u8   H_Switch_U8_SwitchRead(u8 Copy_u8PortName ,u8 Copy_u8PinNum);


#endif /* HAL_SWITCH_SWITCH_INT_H_ */
