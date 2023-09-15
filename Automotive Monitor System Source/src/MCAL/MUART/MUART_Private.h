/*
 * MUART_Private.h
 *
 *  Created on: Aug 23, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : UART_Driver
 *  File    : Private File
 *  Version :1.0
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_


#define MUSART1_BASE_ADDR 0x40011000

/* access bits using BitField */
typedef struct
{
	u32 SBK       :1 ;
	u32 RWU       :1 ;
	u32 RE 		  :1 ;
	u32 TE     	  :1 ;
	u32 IDLEIE 	  :1 ;
	u32 RXNEIE 	  :1 ;
	u32 TCIE 	  :1 ;
	u32 TXEIE 	  :1 ;
	u32 PEIE 	  :1 ;
	u32 PS 		  :1 ;
	u32 PCE 	  :1 ;
	u32 WAKE 	  :1 ;
	u32 M 		  :1 ;
	u32 UE        :1 ;
	u32 Reserved1 :1 ;
	u32 OVER8     :1 ;
	u32 Reserved2 :16;
}USART_CR1;


typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	USART_CR1 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USART_MemMap_t;


#define USART1 ((volatile USART_MemMap_t*) (MUSART1_BASE_ADDR))



#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
