/*
 * MGPIO_Private.h
 *
 *  Created on: Aug 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : GPIO_Driver
 *  File    : Private File
 *  Version :1.0
 */

#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_

typedef struct
{
volatile u32 GPIO_MODER		   ;
volatile u32 GPIO_OTYPER       ;
volatile u32 GPIO_OSPEEDR      ;
volatile u32 GPIO_PUPDR        ;
volatile u32 GPIO_IDR          ;
volatile u32 GPIO_ODR          ;
volatile u32 GPIO_BSRR         ;
volatile u32 GPIO_LCKR         ;
volatile u32 GPIO_AFR[2]       ;
} GPIO_Reg_t;


/******************* GPIO BASE ADDRESS *******************/
#define GPIOA_BASS_ADD	0x40020000
#define GPIOB_BASS_ADD	0x40020400
#define GPIOC_BASS_ADD	0x40020800

#define _LUCKED_PIN		16U


#define MGPIOA       ((GPIO_Reg_t*) GPIOA_BASS_ADD )
#define MGPIOB       ((GPIO_Reg_t*) GPIOB_BASS_ADD )
#define MGPIOC       ((GPIO_Reg_t*) GPIOC_BASS_ADD )


#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
