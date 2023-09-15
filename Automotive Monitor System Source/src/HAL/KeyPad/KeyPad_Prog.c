/*
 * KeyPad_Prog.c
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : KeyPad_Driver
 *  File    : Program File
 *  Version :1.0
 */


#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"
#include "../src/LIB/Delay/Delay_Interface.h"

#include "../src/MCAL/MGPIO/MGPIO_Int.h"
#include "KeyPad_Int.h"

void H_KeyPad_Void_KeyPadInit(void)
{
	u8 i;
	for (i = 1; i <= 3; i++)
	{
		MGPIO_vSetPinMode(KEYPAD_PORT, i, MODE_INPUT);
		MGPIO_vSetPinOutPutType(KEYPAD_PORT, i, _OUTPUT_TYPE_PUSH_PUL);
		MGPIO_vSetPinOutSpeed(KEYPAD_PORT, i, _OUTPUT_SPEED_LOW);
		MGPIO_vSetPullType(KEYPAD_PORT, i, _PULL_UP);
	}

	for (i = 4; i <= 7; i++)
	{
		MGPIO_vSetPinMode(KEYPAD_PORT, i, MODE_OUTPUT);
		MGPIO_vSetPinOutPutType(KEYPAD_PORT, i, _OUTPUT_TYPE_PUSH_PUL);
		MGPIO_vSetPinOutSpeed(KEYPAD_PORT, i, _OUTPUT_SPEED_LOW);
		MGPIO_vSetPullType(KEYPAD_PORT, i, _PULL_OFF);
		MGPIO_vWriteData(KEYPAD_PORT, i, _HIGH);
	}
}

u8   H_KeyPad_U8_KeyPadRead(void)
{
#if   KEYPAD_MODEL   ==   MODEL_A
	u8 Local_u8_Arr [4][4] = {{'1' , '2' , '3' , 'A'},
							  {'4' , '5' , '6' , 'B'},
							  {'7' , '8' , '9' , 'C'},
							  {'*' , '0' , '#' , 'D'}};

#elif KEYPAD_MODEL   ==   MODEL_B
	u8 Local_u8_Arr [4][4] = {{'7' , '8' , '9' , '/'},
							  {'4' , '5' , '6' , '*'},
							  {'1' , '2' , '3' , '-'},
							  {'C' , '0' , '=' , '+'}};

#elif KEYPAD_MODEL   ==   MODEL_C
	u8 Local_u8_Arr [4][3] = {{'1' , '2' , '3'},
			                  {'4' , '5' , '6'},
			                  {'7' , '8' , '9'},
			                  {'*' , '0' , '#'}};
#endif

	u8 Local_u8_Col     = 0;
	u8 Local_u8_Row     = 0;
	u8 Local_u8_Reading = 0;
	for(Local_u8_Row=KEYPAD_R0_PIN;Local_u8_Row<=KEYPAD_R3_PIN;Local_u8_Row++)
	{
		MGPIO_vWriteData(KEYPAD_PORT, Local_u8_Row, _LOW);
		for(Local_u8_Col=KEYPAD_C0_PIN;Local_u8_Col<=KEYPAD_C2_PIN;Local_u8_Col++)
		{
			if(MGPIO_u8ReadData(KEYPAD_PORT,Local_u8_Col) == PRESSED)
			{
				Delay_vMsIn16MHz(KEYPAD_DEBOUNCING_TIME);
				if(MGPIO_u8ReadData(KEYPAD_PORT,Local_u8_Col) == PRESSED)
				{
					Local_u8_Reading = Local_u8_Arr[Local_u8_Row - KEYPAD_R0_PIN][Local_u8_Col - KEYPAD_C0_PIN];
					while(MGPIO_u8ReadData(KEYPAD_PORT,Local_u8_Col) == 0);
				}
			}
		}
		MGPIO_vWriteData(KEYPAD_PORT,Local_u8_Row,_HIGH);
	}
	return Local_u8_Reading;
}
