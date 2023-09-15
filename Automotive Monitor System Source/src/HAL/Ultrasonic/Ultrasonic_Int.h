/*
 * Ultrasonic_Int.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Ultrasonic_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INT_H_
#define HAL_ULTRASONIC_ULTRASONIC_INT_H_


#include "Ultrasonic_Private.h"
#include "Ultrasonic_Config.h"

/*****************************************_PROTOTYPES_******************************************/
void H_VUltrasonicInit(void);
u32  H_u16USRead(void);


#endif /* HAL_ULTRASONIC_ULTRASONIC_INT_H_ */
