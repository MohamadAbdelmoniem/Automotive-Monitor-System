/*
 * Delay_Prog.c
 *
 *  Created on: Sep 9, 2023
 *  MICRO   : STM32F401CCU6
 *  LAYER   : LIB
 *  DRIVER  : Delay Driver
 *  File    : Program File
 *  Version :1.0
 */

/*============= INCLUDE LIB ==============*/
#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"

/*===========  INCLUDE MCAL  ===========*/
#include "Delay_Interface.h"
	

/*================================================================================================================*/
/*
*		Function To Delay By Milliseconds ( 16MHz CPU CLK )
*/
extern void Delay_vMsIn16MHz(u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 3180  ; u16Local_Count2 ++ )
	{}
}


/*================================================================================================================*/
/*
*		Function To Delay By Microseconds ( 16MHz CPU CLK )
*/

extern void Delay_vUsIn16MHzint (u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 3  ; u16Local_Count2 ++ )
	{}
}
