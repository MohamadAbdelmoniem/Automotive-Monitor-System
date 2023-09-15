/*
 * Switch_Config.h
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Switch_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef HAL_SWITCH_SWITCH_CONFIG_H_
#define HAL_SWITCH_SWITCH_CONFIG_H_

#define SWITCH_PORT   _GPIOA_PORT

#define SWITCH_PIN     GPIO_PIN_15

/******************************************************_SELECT_Switch_MODE_***************************/
/*_OPTION_1 -> [ ACTIVE_LOW  ]   */
/*_OPTION_2 -> [ ACTIVE_HIGH ]   */
#define SWITCH_MODE                    ACTIVE_LOW


#endif /* HAL_SWITCH_SWITCH_CONFIG_H_ */
