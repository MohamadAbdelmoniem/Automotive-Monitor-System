/*
 * MEXTI_Private.h
 *
 *  Created on: Aug 14, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : EXTI_Driver
 *  File    : Private File
 *  Version :1.0
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_


#define EXTI_BASE_ADDR   0x40013C00
#define SYSCFG_BASE_ADDR 0x40013800

#define EXTI_CONFG_MASK1 0xFFFFFFF0UL
#define EXTI_CONFG_MASK2 0xFFFFFF0FUL
#define EXTI_CONFG_MASK3 0xFFFFF0FFUL
#define EXTI_CONFG_MASK4 0xFFFF0FFFUL



typedef struct {

	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;

}EXTI_MemMap_t;


typedef struct {

	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR1;
	u32 EXTICR2;
	u32 EXTICR3;
	u32 EXTICR4;
	u32 Reserved1;
	u32 Reserved2;
	u32 EXTICMPCR;

}SYSCFG_MemMap_t;


#define EXTI ((volatile EXTI_MemMap_t*)(EXTI_BASE_ADDR))
#define SYSCFG ((volatile SYSCFG_MemMap_t*)(SYSCFG_BASE_ADDR))




#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
