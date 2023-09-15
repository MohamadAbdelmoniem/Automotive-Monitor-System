/*
 * MSTK_Int.h
 *
 *  Created on: Aug 15, 2023
 *  Author: Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : SYSTICK_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef MCAL_MSTK_MSTK_INT_H_
#define MCAL_MSTK_MSTK_INT_H_


#define STK_AHB				1
#define STK_AHB_DIV_8		2

#define STK_ENABLE  0
#define TICKINT		1
#define CLKSOURCE	2
#define COUNTFLAG	16

#define ENABLE		1
#define DISABLE		0


void MSTK_vInit(void);

void MSTK_vIntState(u8 Copy_u8Status);

void MSTK_vStart(u32 Copy_u32PreloadValue);

u8 MSTK_u8ReadFlag(void);

void MSTK_vDelayUsec(u32 Copy_u32DelayUsec);

void MSTK_vDelayMsec(u32 Copy_u32DelayMsec);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);

void CALLBACKSYS(void(*callback)(void));


#endif /* MCAL_MSTK_MSTK_INT_H_ */
