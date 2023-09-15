/*
 * Push_Button_Config.h
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Push_Button_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef HAL_PUSH_BUTTON_PUSH_BUTTON_CONFIG_H_
#define HAL_PUSH_BUTTON_PUSH_BUTTON_CONFIG_H_


#define PUSH_BUTTON_PORT   _GPIOB_PORT

#define PUSH_BUTTON_PIN     GPIO_PIN_0

/******************************************************_SELECT_PB_MODE_***************************/
/*_OPTION_1 -> [ ACTIVE_LOW  ]   */
/*_OPTION_2 -> [ ACTIVE_HIGH ]   */
#define PUSHBUTTON_MODE                    ACTIVE_LOW

/**********************************************_SELECT_PUSHBUTTON_DEBOUNCING_TIME_***************************/
/*_SELECT_TIME_IN_MILLI_SECONDS_*/
#define PUSHBUTTON_DEBOUNCING_TIME            160



#endif /* HAL_PUSH_BUTTON_PUSH_BUTTON_CONFIG_H_ */
