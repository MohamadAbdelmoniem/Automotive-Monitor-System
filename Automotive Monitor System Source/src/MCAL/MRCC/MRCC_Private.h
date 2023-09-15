/*
 * MRCC_private.h
 *
 *  Created on: Aug 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : RCC_Driver
 *  File    : Private File
 *  Version :1.0
 */

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_


/* RCC -> CR */
#define HSEON  16
#define HSEBYP 18
#define CSSON  19
#define HSION  0
#define PLLON  24

/* RCC -> CFGR */
#define SW0 0
#define SW1 1

/* RCC -> APB1ENR */
#define PWREN    28
#define I2C3EN   23
#define I2C2EN   22
#define I2C1EN   21
#define USART2EN 17
#define SPI3EN   15
#define SPI2EN   14
#define WWDGEN   11
#define TIM5EN   3
#define TIM4EN   2
#define TIM3EN   1
#define TIM2EN   0

/* RCC -> APB2ENR */
#define TIM11EN  18
#define TIM10EN  17
#define TIM9EN   16
#define SYSCFGEN 14
#define SPI4EN   13
#define SPI1EN   12
#define SDIOEN   11
#define ADC1EN   8
#define USART6EN 5
#define USART1EN 4
#define TIM1EN   0

/* RCC-> AHB1ENR */
#define DMA2EN  22
#define DMA1EN  21
#define CRCEN   12
#define GPIOHEN 7
#define GPIOEEN 4
#define GPIODEN 3
#define GPIOCEN 2
#define GPIOBEN 1
#define GPIOAEN 0

/* RCC-> AHB2ENR */
#define OTGFSEN 7


/******************* RCC BASE ADDRESS *******************/

#define RCC_BASE_ADDR 0x40023800

typedef struct{

	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSRT;
	u32 APB2RSRT;
	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 Reserved7;
	u32 Reserved8;

}RCC_MemMap_t;

#define RCC ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
