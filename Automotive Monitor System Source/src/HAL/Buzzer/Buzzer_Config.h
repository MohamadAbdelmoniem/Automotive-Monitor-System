/*
 * Buzzer_Config.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Buzzer_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef HAL_BUZZER_BUZZER_CONFIG_H_
#define HAL_BUZZER_BUZZER_CONFIG_H_


#define BUZZER_PORT   _GPIOB_PORT

#define BUZZER_PIN     GPIO_PIN_13

/**************************************************_SELECT_LED_DELAY_TIME_***********************/
#define BUZZER_ON_DELAY_TIME            60
#define BUZZER_OFF_DELAY_TIME           80
#define BUZZER_ON_LONG_DELAY_TIME      100


#endif /* HAL_BUZZER_BUZZER_CONFIG_H_ */
