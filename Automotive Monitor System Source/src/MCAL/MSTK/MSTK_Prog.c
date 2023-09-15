/*
 * MSTK_Prog.c
 *
 *  Created on: Aug 15, 2023
 *  Author: Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : SYSTICK_Driver
 *  File    : Program File
 *  Version :1.0
 */

/************************************   Includes   *************************************/

#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "MSTK_Config.h"
#include "MSTK_Int.h"
#include "MSTK_Private.h"


/************************************   Global Pointers   *************************************/
void (*STK_CallBack)(void) = NULL_ptr;


/**************************************   APIs   ******************************************/

/*
 return type = void
 input parameters = void
 functionality : select clock source of STk timer
 */

void MSTK_vInit(void)
{
	// Enable Systick Interrupt  -  Clock = AHB / 8 - Stop Systic
	STK -> CTRL = 0x00000002;
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = void
 functionality : select STK timer interrupt state (1: ENABLE STK INTERRUPTS , 0: DISABLE STK INTERRUPTS)
 */

void MSTK_vIntState(u8 Copy_u8Status)
{
	STK -> CTRL &= ~( 1 << 1 );
	STK -> CTRL |=  ( Copy_u8Status << 1 );

}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = u32 Copy_u32PreloadValue
 functionality : start STK timer
 */

void MSTK_vStart(u32 Copy_u32PreloadValue)
{
	STK -> LOAD = Copy_u32PreloadValue - 1;
	STK -> VAL = 0;
	SET_BIT(STK -> CTRL, STK_ENABLE);
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = u8
 input parameters = void
 functionality : read COUNTFLAG from CTRL register of STK timer (1: the timer counted down to 0)
 */

u8 MSTK_u8ReadFlag(void)
{
	return ( GET_BIT(STK-> CTRL , COUNTFLAG) );
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = u32 Copy_u32DelayUsec
 functionality : count down while COUNTFLAG != 0
 */
void MSTK_vDelayUsec(u32 Copy_u32DelayUsec)
{
	MSTK_vIntState(DISABLE);
	MSTK_vStart(Copy_u32DelayUsec*1000000);
	while(MSTK_u8ReadFlag() == 0);
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = u32 Copy_u32DelayMsec
 functionality : count down while COUNTFLAG != 0
 */
void MSTK_vDelayMsec(u32 Copy_u32DelayMsec)
{
	MSTK_vIntState(DISABLE);
	MSTK_vStart( Copy_u32DelayMsec*1000);
	while(MSTK_u8ReadFlag() == 0);
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = u32
 input parameters = void
 functionality : calculate Elapsed time
 */

u32 MSTK_u32GetElapsedTime(void)
{
	u32 local_u32ElapsedTime;
	local_u32ElapsedTime = (STK -> LOAD) - (STK -> VAL);
	return local_u32ElapsedTime;
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = u32
 input parameters = void
 functionality : calculate Remaining time
 */

u32 MSTK_u32GetRemainingTime(void)
{
	u32 local_u32RemainingTime;
	local_u32RemainingTime = (STK -> VAL);
	return local_u32RemainingTime;
}

/******************************************************************************************
******************************************************************************************/
/*
 return type = void
 input parameters = pointer
functionality : call back function (make the code generic -> don't depend in the app)
 */


void CALLBACKSYS(void(*callback)(void))
{
	STK_CallBack = callback;
}

void Systick_IRQHandler(void)
{
	STK_CallBack();
}
