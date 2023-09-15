/*
 * LCD_Config.h
 *
 *  Created on: Sep 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : LCD_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_



/*LCD_MODE_OPTIONS: _4_BIT_MODE,_8_BIT_MODE*/
#define LCD_MODE _8_BIT_MODE


/**********************************************SELECT MC PIN*****************************************************/
#define LCD_PORT      _GPIOA_PORT

#define LCD_D0_PIN	  GPIO_PIN_4
#define LCD_D1_PIN	  GPIO_PIN_5
#define LCD_D2_PIN    GPIO_PIN_6
#define LCD_D3_PIN	  GPIO_PIN_7
#define LCD_D4_PIN	  GPIO_PIN_8
#define LCD_D5_PIN	  GPIO_PIN_9
#define LCD_D6_PIN	  GPIO_PIN_10
#define LCD_D7_PIN	  GPIO_PIN_11
#define LCD_Rs_PIN	  GPIO_PIN_2
#define LCD_En_PIN	  GPIO_PIN_3


#endif /* HAL_LCD_LCD_CONFIG_H_ */
