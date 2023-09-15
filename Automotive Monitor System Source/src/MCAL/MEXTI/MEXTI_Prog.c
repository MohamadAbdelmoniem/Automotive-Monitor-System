/*
 * MEXTI_Prog.c
 *
 *  Created on: Aug 14, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : EXTI_Driver
 *  File    : Program File
 *  Version :1.0
 */

/************************************   Includes   *************************************/
#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"

#include "MEXTI_Int.h"
#include "MEXTI_Private.h"
#include "MEXTI_Config.h"


/************************************   Global Pointers   *************************************/
static void (*Global_EXTI_CallBack[16])(void)= {NULL_val};
/******************************************************************************************
******************************************************************************************/

/**************************************   APIs   ******************************************/

/*
 return type = void
 input parameters = LineNo
 functionality : enable the external interrupt on a line
 */

void MEXTI_vEnableExternalInterrupt(MEXTI_LineNo copy_uddLineNo)
{
	SET_BIT( EXTI -> IMR, copy_uddLineNo );
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = LineNo
 functionality : disable the external interrupt on a line
 */


void MEXTI_vDisableExternalInterrupt(MEXTI_LineNo copy_uddLineNo)
{
	CLR_BIT( EXTI -> IMR, copy_uddLineNo );
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = LineNo
 functionality : select the trigger type
 */

void MEXTI_vSetTrigger( MEXTI_TrigType copy_uddTrigType, MEXTI_LineNo copy_uddLineNo )
{
	switch(copy_uddTrigType){

		case MEXTI_FALLING_EDGE:
			SET_BIT(EXTI -> FTSR, copy_uddLineNo);
			break;

		case MEXTI_RISING_EDGE:
			SET_BIT(EXTI -> RTSR, copy_uddLineNo);
			break;

		case MEXTI_ANY_CHANGE:
			SET_BIT(EXTI -> FTSR, copy_uddLineNo);
			SET_BIT(EXTI -> RTSR, copy_uddLineNo);
			break;

		default:
			/*do nothing*/
			break;
	}
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = LineNo
 functionality : enable the software interrupt event on a line
 */

void MEXTI_vEnableSoftwareInterruptEvent(MEXTI_LineNo copy_uddLineNo)
{
	SET_BIT( EXTI -> SWIER, copy_uddLineNo );
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = LineNo, GPIO portNo
 functionality : enable the software interrupt event on a line
 */

void MEXTI_vSetExtiConfig(MEXTI_LineNo copy_uddLineNo, MEXTI_PORT copy_uddGpioPortNo)
{
	switch(copy_uddLineNo)
	{

	case MEXTI_LINE0:
		SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK1;
		SYSCFG -> EXTICR1 |= copy_uddGpioPortNo;
		break;

	case MEXTI_LINE1:
		SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK2;
	    SYSCFG -> EXTICR1 |= copy_uddGpioPortNo <<  4;
	    break;

	case MEXTI_LINE2:
		SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK3;
		SYSCFG -> EXTICR1 |= copy_uddGpioPortNo <<  8;
		break;

	case MEXTI_LINE3:
		SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK4;
		SYSCFG -> EXTICR1 |= copy_uddGpioPortNo << 12;
		break;

	case MEXTI_LINE4:
		SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK1;
		SYSCFG -> EXTICR2 |= copy_uddGpioPortNo;
		break;

	case MEXTI_LINE5:
		SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK2;
		SYSCFG -> EXTICR2 |= copy_uddGpioPortNo <<  4;
		break;

	case MEXTI_LINE6:
		SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK3;
		SYSCFG -> EXTICR2 |= copy_uddGpioPortNo <<  8;
		break;

	case MEXTI_LINE7:
		SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK4;
		SYSCFG -> EXTICR2 |= copy_uddGpioPortNo << 12;
		break;

		default:
			/*do nothing*/
			break;
	}
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = pointer
 functionality : call back function (make the code generic -> don't depend in the app)
 */

void MEXTI0_vCallBack(void (*ptr)(void))
{
	Global_EXTI_CallBack[0] = ptr;
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = pointer
functionality : call back function (make the code generic -> don't depend in the app)
 */

void MEXTI1_vCallBack(void (*ptr)(void))
{
	Global_EXTI_CallBack[1] = ptr;
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = void
 functionality : control the occurrence of interrupt
 */

void EXTI0_IRQHandler(void)
{
	Global_EXTI_CallBack[0]();
	SET_BIT(EXTI -> PR, 0);   //without that it will do interrupt always (this bit is cleared by programming it)
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = void
 functionality : control the occurrence of interrupt
 */

void EXTI1_IRQHandler(void)
{
	Global_EXTI_CallBack[1]();
	SET_BIT(EXTI -> PR, 1);
}
