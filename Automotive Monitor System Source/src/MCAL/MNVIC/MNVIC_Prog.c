/*
 * MNVIC_Prog.c
 *
 *  Created on: Aug 13, 2023
 *  Author: Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : NVIC_Driver
 *  File    : Program File
 *  Version :1.0
 */

/************************************   Includes   *************************************/
#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"

#include "MNVIC_Int.h"
#include "MNVIC_Private.h"
#include "MNVIC_Config.h"


/************************************   Global Pointer   *************************************/
u32 Global_u32SetGroupPriority;


/**************************************   APIs   ********************************************/

/*
 return type = void
 input parameters = interrupt id
 functionality : Enable External interrupt (Peripheral interrupts
 */

void MNVIC_vInterruptEnable(u8 Copy_u8InterruptId)
{
	if ( Copy_u8InterruptId <= 84)
	{
		u8 Register = Copy_u8InterruptId / Register_Bits; // GET REGISTER ID
		u8 BIT_NO =  Copy_u8InterruptId % Register_Bits;  //GET BIT NUMBER
		NVIC -> ISER[Register] |= (1<<BIT_NO);
	}
}

/******************************************************************************************
******************************************************************************************/

/********************ASSIGNMENT*******************************/
/*
 return type = void
 input parameters = interrupt id
 functionality : Disable External interrupt (Peripheral interrupts
 */
void MNVIC_vInterruptDisable(u8 Copy_u8InterruptId)
{
	u8 Register = Copy_u8InterruptId / Register_Bits ;
	u8 BIT_NO = Copy_u8InterruptId % Register_Bits ;
	NVIC -> ICER[Register] |= (1<<BIT_NO);
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = COPY_GROUPMODE
 functionality : set group mode in SCB (AIRCR)
 */

void MNVIC_SetGroupMode(Group_mode Copy_GroupMode)
{
	Global_u32SetGroupPriority = Copy_GroupMode;
	u32 set_group;
	set_group = MNVIC_VECTKEY | (Copy_GroupMode << 8);
	SCB_AIRCR = set_group;
}

/******************************************************************************************
******************************************************************************************/

/*
 return type = void
 input parameters = u8 COPY_u8InterruptId, u8 COPY_GroupId, u8 COPY_SubGroupId
 functionality : set group mode in SCB (AIRCR)
 */

void MNVIC_vSetInterruptPriority (u8 Copy_u8InterruptId, u8 Copy_GroupId, u8 Copy_SubGroupId)
{
	switch(Global_u32SetGroupPriority)
	{
		case MNVIC_G16_SG0:
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_GroupId << 4);
			break;

		case MNVIC_G8_SG2:
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_GroupId << 5);
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_SubGroupId << 4);
			break;

		case MNVIC_G4_SG4:
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_GroupId << 6);
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_SubGroupId << 4);
			break;

		case MNVIC_G2_SG8:
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_GroupId << 7);
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_SubGroupId << 4);
			break;

		case MNVIC_G0_SG16:
			NVIC -> IPR [Copy_u8InterruptId] = (Copy_SubGroupId << 4);
			break;

		default:
			break;
	}
}

void MNVIC_voidGenerateSoftwareInterrupt(u8 Copy_u8InterruptId)
{
	NVIC -> STIR = (Copy_u8InterruptId << 4);
}
