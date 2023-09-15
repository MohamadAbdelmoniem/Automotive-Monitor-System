/*
 * MNVIC_Int.h
 *
 *  Created on: Aug 13, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : NVIC_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef MCAL_MNVIC_MNVIC_INT_H_
#define MCAL_MNVIC_MNVIC_INT_H_

typedef unsigned char u8;

typedef enum
{
	MNVIC_G16_SG0 = 3,
	MNVIC_G8_SG2,
	MNVIC_G4_SG4,
	MNVIC_G2_SG8,
	MNVIC_G0_SG16
}Group_mode;


void MNVIC_vInterruptEnable(u8 Copy_u8InterruptId);
void MNVIC_vInterruptDisable(u8 Copy_u8InterruptId);
void MNVIC_SetGroupMode(Group_mode Copy_GroupMode);
void MNVIC_vSetInterruptPriority (u8 Copy_u8InterruptId, u8 Copy_GroupId, u8 Copy_SubGroupId);
void MNVIC_voidGenerateSoftwareInterrupt(u8 copy_u8InterruptId);


#endif /* MCAL_MNVIC_MNVIC_INT_H_ */
