/*
 * KeyPad_Config.h
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : KeyPad_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/*************************************************_SELECT_KEYPAD_DATA_PORT_***************************/
#define KEYPAD_PORT  _GPIOB_PORT

/****************************************************_SELECT_KEYPAD_PIN_***************************/
#define KEYPAD_R0_PIN                    GPIO_PIN_4
#define KEYPAD_R1_PIN                    GPIO_PIN_5
#define KEYPAD_R2_PIN                    GPIO_PIN_6
#define KEYPAD_R3_PIN                    GPIO_PIN_7
#define KEYPAD_C0_PIN                    GPIO_PIN_1
#define KEYPAD_C1_PIN                    GPIO_PIN_2
#define KEYPAD_C2_PIN                    GPIO_PIN_3


/***************************************************_SELECT_KEYPAD_MODEL_****************************/
/*_OPTION_1 -> [ MODEL_A ]   */
/*_OPTION_2 -> [ MODEL_B ]   */
/*_OPTION_2 -> [ MODEL_C ]   */
#define KEYPAD_MODEL                 MODEL_C

/**********************************************_SELECT_PUSHBUTTON_DEBOUNCING_TIME_***************************/
/*_SELECT_TIME_IN_MILLI_SECONDS_*/
#define KEYPAD_DEBOUNCING_TIME          1


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
