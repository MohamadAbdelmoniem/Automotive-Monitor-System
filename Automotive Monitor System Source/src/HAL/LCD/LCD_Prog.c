/*
 * LCD_Prog.c
 *
 *  Created on: Sep 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : LCD_Driver
 *  File    : Program File
 *  Version :1.0
 */

#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"
#include "../src/LIB/Delay/Delay_Interface.h"

#include "../src/MCAL/MGPIO/MGPIO_Int.h"
#include "LCD_Int.h"



void H_Lcd_void_LcdInit(void)
{
#if LCD_MODE == _8_BIT_MODE
	MGPIO_vSetPinMode(LCD_PORT, LCD_D0_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_D1_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_D2_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_D3_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_D4_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_D5_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_D6_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_D7_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_Rs_PIN, MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_PORT, LCD_En_PIN, MODE_OUTPUT);
	Delay_vMsIn16MHz(1000);
	H_Lcd_void_LcdSendCommand(LCD_8_BIT_MODE_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);
#elif LCD_MODE == _4_BIT_MODE
	MGPIO_vSetPinMode(LCD_D4_PIN,MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_D5_PIN,MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_D6_PIN,MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_D7_PIN,MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_Rs_PIN,MODE_OUTPUT);
	MGPIO_vSetPinMode(LCD_En_PIN,MODE_OUTPUT);
	Delay_vMsIn16MHz(1000);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_3);
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);
#endif
}

void H_Lcd_void_LcdSendCommand(u8 Copy_u8_Command)
{
	MGPIO_vWriteData(LCD_PORT,LCD_Rs_PIN,_LOW);
#if LCD_MODE == _8_BIT_MODE
	MGPIO_vWriteData(LCD_PORT,LCD_D0_PIN,Copy_u8_Command >> 0 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D1_PIN,Copy_u8_Command >> 1 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D2_PIN,Copy_u8_Command >> 2 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D3_PIN,Copy_u8_Command >> 3 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_LOW);
#elif LCD_MODE == _4_BIT_MODE
	MGPIO_vWriteData(LCD_PORT,LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_LOW);
	Copy_u8_Command = Copy_u8_Command << 4;
	MGPIO_vWriteData(LCD_PORT,LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_LOW);
#endif
}

void H_Lcd_void_LcdSendCharacter(u8 Copy_u8_Character)
{
	MGPIO_vWriteData(LCD_PORT,LCD_Rs_PIN,_HIGH);
#if LCD_MODE == _8_BIT_MODE
	MGPIO_vWriteData(LCD_PORT,LCD_D0_PIN,Copy_u8_Character >> 0 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D1_PIN,Copy_u8_Character >> 1 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D2_PIN,Copy_u8_Character >> 2 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D3_PIN,Copy_u8_Character >> 3 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_LOW);
#elif LCD_MODE == _4_BIT_MODE
	MGPIO_vWriteData(LCD_PORT,LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_LOW);
	Copy_u8_Character = Copy_u8_Character << 4;
	MGPIO_vWriteData(LCD_PORT,LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_PORT,LCD_En_PIN,_LOW);
#endif
}

void H_Lcd_void_LcdClear(void)
{
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);
}

void H_Lcd_void_LcdSendString(u8 *Copy_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Copy_u8_Ptr[Local_u8_Counter]!= '\0')
	{
		H_Lcd_void_LcdSendCharacter(Copy_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}

void H_Lcd_void_LcdSendNumberU(u64 Copy_u64_Number)
{
	u8 Local_u8_Integer[11];
	u8 Local_u8_Decimal[11];
	s8 Local_u8_Counter = 0;
	if((u32)Copy_u64_Number<0)
	{
		H_Lcd_void_LcdSendCharacter('-');
		Copy_u64_Number*=-1;
	}
	do
	{
		Local_u8_Integer[Local_u8_Counter] = (u32)Copy_u64_Number%10;
		Copy_u64_Number/=10;
		Local_u8_Counter++;
	}while((u32)Copy_u64_Number !=0);
	Local_u8_Counter--;
	for(;Local_u8_Counter>=0;Local_u8_Counter--)
	{
		H_Lcd_void_LcdSendCharacter(Local_u8_Integer[Local_u8_Counter]+48);
	}
	Local_u8_Counter=0;
	while((u32)Copy_u64_Number != Copy_u64_Number)
	{
		Copy_u64_Number*=10;
		Local_u8_Decimal[Local_u8_Counter] = (u32)Copy_u64_Number%10;
		H_Lcd_void_LcdSendCharacter(Local_u8_Decimal[Local_u8_Counter]+48);
		Local_u8_Counter++;
	}
	Local_u8_Counter--;
}

void H_Lcd_void_LcdSendNumberF(f64 Copy_f64_Number)
{
	u8 Local_u8_Integer[11];
	u8 Local_u8_Decimal[11];
	s8 Local_u8_Counter = 0;
	if((u32)Copy_f64_Number<0)
	{
		H_Lcd_void_LcdSendCharacter('-');
		Copy_f64_Number*=-1;
	}
	do
	{
		Local_u8_Integer[Local_u8_Counter] = (u32)Copy_f64_Number%10;
		Copy_f64_Number/=10;
		Local_u8_Counter++;
	}while((u32)Copy_f64_Number !=0);
	Local_u8_Counter--;
	for(;Local_u8_Counter>=0;Local_u8_Counter--)
	{
		H_Lcd_void_LcdSendCharacter(Local_u8_Integer[Local_u8_Counter]+48);
	}
	Local_u8_Counter=0;
	while((u32)Copy_f64_Number != Copy_f64_Number)
	{
		Copy_f64_Number*=10;
		Local_u8_Decimal[Local_u8_Counter] = (u32)Copy_f64_Number%10;
		H_Lcd_void_LcdSendCharacter(Local_u8_Decimal[Local_u8_Counter]+48);
		Local_u8_Counter++;
	}
	Local_u8_Counter--;
}



void H_Lcd_void_LcdGoTo(u8 Copy_u8_Row,u8 Copy_u8_Col)
{
	u8 Local_u8_arr[2] = {0x80,0xC0};
	H_Lcd_void_LcdSendCommand(Local_u8_arr[Copy_u8_Row]+Copy_u8_Col);
}

