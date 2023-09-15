/*
 * MUART_Prog.c
 *
 *  Created on: Aug 23, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : UART_Driver
 *  File    : Program File
 *  Version :1.0
 */

/************************************   Includes   *************************************/
#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"


/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "MUART_Int.h"
#include "MUART_Private.h"
#include "MUART_Config.h"

/************************************   Global Pointers   *************************************/
void (*Global_USART1_CallBack)(void) = NULL_ptr;


/**************************************   APIs   ******************************************/
/*
 return type = void
 input parameters = void
 functionality : UART Initialization
 */

void MUART_vInit(void)
{
	/* Set Baud Rate */
	USART1 -> BRR = 0X0000080B; //baud rate = 115200 bps, BRR = system clock(HSI = 16MHZ) / (16*baud rate)

	/* Select Sampling Rate */
	USART1 -> CR1.OVER8 = 0;  // (0 -> 16 samples , 1 -> 8 samples)

	/* Select Word Size */
	USART1 -> CR1.M = 0;  // (0 -> 8 bit word size, 1 -> 9 bit word size)

	/*Parity Configuration */
	USART1 -> CR1.PCE = 0; //(0 -> Disable Parity Check, 1 -> Enable Parity Check)

	/* Transmitter Enable */
	USART1 -> CR1.TE = 1;

	/* Receiver Enable */
	USART1 -> CR1.RE = 1;

	/* Stop Bit Configuration */
	// (bit[13:12] -> 00: 1 Stop bit, 10: 2 Stop bits)

	CLR_BIT(USART1 -> CR2, 12);
	CLR_BIT(USART1 -> CR2, 13);
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = void
 functionality : Enable UART
 */

void MUART_vEnable(void)
{
	USART1 -> CR1.UE = 1;
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = void
 functionality : Disable UART
 */

void MUART_vDisable(void)
{
	USART1 -> CR1.UE = 0;
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = u8 data and u8 data length
 functionality : Send Data from Transmitter
 */

void MUART_vSendData(u8* copy_u8Data, u8 copy_u8Length)
{
	for (u8 copy_u8Iterator = 0 ; copy_u8Iterator < copy_u8Length ; copy_u8Iterator++)
	{
		USART1 -> DR = copy_u8Data[copy_u8Iterator]; //Send Data Byte
		while(GET_BIT(USART1 -> SR, 7) == 0);        //wait until transmitter register is empty
	}
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = u8 data and u8 data length
 functionality : Send String from Transmitter
 */

void MUART_vSendString(u8* copy_u8Data)
{
	for (u8 copy_u8Iterator = 0 ; copy_u8Iterator != '\0' ; copy_u8Iterator++)
	{
		USART1 -> DR = copy_u8Data[copy_u8Iterator]; //Send Data
		while(GET_BIT(USART1 -> SR, 6) == 0);        //wait until transmission complete (string is complete frame)
	}
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = u8 (Data)
 input parameters = void
 functionality : Read Data at Receiver
 */

u8 MUART_vReceiveData(void)
{
	u8 Local_u8ReceivedData = 0;
	while(GET_BIT(USART1 -> SR, 5) == 0)
	{
		/* do nothing */
	}
	Local_u8ReceivedData = (u8) USART1 -> DR;
	return Local_u8ReceivedData;
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = pointer
functionality : call back function (make the code generic -> don't depend in the app)
 */

void MUSART1_vCallBack(void (*ptr)(void))
{
	Global_USART1_CallBack = ptr;
}

void USART1_IRQHandler(void)
{
	Global_USART1_CallBack();
}
