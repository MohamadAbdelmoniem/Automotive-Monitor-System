/*
 * LCD_Private.h
 *
 *  Created on: Sep 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : LCD_Driver
 *  File    : Private File
 *  Version :1.0
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

/**************************************LCD MODES*********************************************************************/
#define _8_BIT_MODE 							   8
#define _4_BIT_MODE 							   4
/**************************************LCD COMMANDS***************************************************************/
#define LCD_8_BIT_MODE_COMMAND 					0x38
#define LCD_DISPLAY_ON_COMMAND 					0x0C
#define LCD_CLEAR_COMMAND						0x01
#define LCD_4_BIT_MODE_COMMAND_1                0x33
#define LCD_4_BIT_MODE_COMMAND_2                0x32
#define LCD_4_BIT_MODE_COMMAND_3                0x28


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
