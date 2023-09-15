/*
 * LED_Config.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : LED_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

/***************************************_SELECT_MC_PINS_****************************************/
#define LED_PORT               _GPIOB_PORT
#define RED_LED_PIN             GPIO_PIN_8
#define GRN_LED_PIN             GPIO_PIN_9

/**************************************_SELECT_BLINK_TIME_**************************************/
#define BLINK_TIME     100



#endif /* HAL_LED_LED_CONFIG_H_ */
