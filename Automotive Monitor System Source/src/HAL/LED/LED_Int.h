/*
 * LED_Int.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : LED_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#include "LED_Private.h"
#include "LED_Config.h"


/*******************************************_MACROS_********************************************/
#define GREEN_LED       1
#define RED_LED         2

/*****************************************_PROTOTYPES_******************************************/
void H_Led_Init(u8);
void H_Led_On(u8);
void H_Led_Off(u8);
void H_Led_BlinkOnce(u8);


#endif /* HAL_LED_LED_INT_H_ */
