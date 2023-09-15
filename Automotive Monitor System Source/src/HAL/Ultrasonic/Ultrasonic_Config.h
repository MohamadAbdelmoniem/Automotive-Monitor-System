/*
 * Ultrasonic_Config.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Ultrasonic_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_
#define HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_


#define TRIGER_PORT _GPIOB_PORT
#define TRIGER_PIN	GPIO_PIN_12

#define ECHO_PORT  _GPIOB_PORT
#define ECHO_PIN   GPIO_PIN_10


#endif /* HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_ */
