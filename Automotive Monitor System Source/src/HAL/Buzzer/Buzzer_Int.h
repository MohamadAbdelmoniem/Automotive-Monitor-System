/*
 * Buzzer_Int.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Buzzer_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_BUZZER_BUZZER_INT_H_
#define HAL_BUZZER_BUZZER_INT_H_

#include "Buzzer_Private.h"
#include "Buzzer_Config.h"


/*******************************************************_PROTOTYPES_*****************************/
void H_Buzzer_Void_BuzzerInit(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void H_Buzzer_Void_BuzzerOn(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void H_Buzzer_Void_BuzzerOff(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void H_Buzzer_Void_BuzzerTog(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void H_Buzzer_Void_BuzzerOnce(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void H_Buzzer_Void_BuzzerTwice(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void H_Buzzer_Void_BuzzerTriple(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void H_Buzzer_Void_BuzzerOnceLong(u8 Copy_u8PortName ,u8 Copy_u8PinNum);

#endif /* HAL_BUZZER_BUZZER_INT_H_ */
