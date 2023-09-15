/*
 * KeyPad_Int.h
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : KeyPad_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

#include "KeyPad_Config.h"
#include "KeyPad_Private.h"

/*********************************************************_MACROS_*******************************/
#define MODEL_A                 1
#define MODEL_B                 2
#define MODEL_C                 3
#define PRESSED                 0

/*******************************************************_PROTOTYPES_*****************************/
void H_KeyPad_Void_KeyPadInit(void);
u8   H_KeyPad_U8_KeyPadRead(void);


#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
