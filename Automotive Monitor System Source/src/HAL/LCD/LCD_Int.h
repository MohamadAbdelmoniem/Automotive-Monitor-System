/*
 * LCD_Int.h
 *
 *  Created on: Sep 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : LCD_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#include "LCD_Config.h"
#include "LCD_Private.h"

/****************************************PROTOTYPES***********************************************************************/
void H_Lcd_void_LcdInit(void);
void H_Lcd_void_LcdSendCommand(u8);
void H_Lcd_void_LcdSendCharacter(u8);
void H_Lcd_void_LcdSendString(u8*);
void H_Lcd_void_LcdSendNumberU(u64);
void H_Lcd_void_LcdSendNumberF(f64);
void H_Lcd_void_LcdClear(void);
void H_Lcd_void_LcdGoTo(u8,u8);



#endif /* HAL_LCD_LCD_INT_H_ */
