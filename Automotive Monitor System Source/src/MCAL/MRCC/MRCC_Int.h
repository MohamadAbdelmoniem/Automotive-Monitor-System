/*
 * MRCC_int.h
 *
 *  Created on: Aug 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : RCC_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef MCAL_MRCC_MRCC_INT_H_
#define MCAL_MRCC_MRCC_INT_H_

typedef unsigned char u8;

/** Configurations **/
#define ENABLE  1
#define DISABLE 0

/** Clock Source **/
#define RCC_HSI 1
#define RCC_HSE 2
#define RCC_PLL 3

/* Buses */
#define APB1_BUS 1
#define APB2_BUS 2
#define AHB1_BUS 3
#define AHB2_BUS 4


typedef enum{
	MCO_1_Div_1= 0U,
	MCO_1_Div_2    ,
	MCO_1_Div_3    ,
	MCO_1_Div_4    ,
	MCO_1_Div_5    ,
}MCO_1_Pre_t;

/* Peripherals */

/** APB1 **/
#define APB1_Power_Interface 1
#define APB1_I2C3            2
#define APB1_I2C2            3
#define APB1_I2C1            4
#define APB1_USART2          5
#define APB1_SPI3            6
#define APB1_SPI2            7
#define APB1_WWDG            8
#define APB1_TIM5            9
#define APB1_TIM4            10
#define APB1_TIM3            11
#define APB1_TIM2            12

/** APB2 **/
#define APB2_TIM11                    1
#define APB2_TIM10                    2
#define APB2_TIM9                     3
#define APB2_System_Config_controller 4
#define APB2_SPI4                     5
#define APB2_SPI1                     6
#define APB2_SDIO                     7
#define APB2_ADC1                     8
#define APB2_USART6                   9
#define APB2_USART1                   10
#define APB2_TIM1                     11

/** AHB1 **/
#define AHB1_DMA2  1
#define AHB1_DMA1  2
#define AHB1_CRC   3
#define AHB1_GPIOH 4
#define AHB1_GPIOE 5
#define AHB1_GPIOD 6
#define AHB1_GPIOC 7
#define AHB1_GPIOB 8
#define AHB1_GPIOA 9

/**AHB2 **/
#define AHB2_USB_OTG_FS 1

void MRCC_vInit(void);
void MRCC_vEnableClock(u8 copy_u8Bus, u8 copy_u8Peripheral);
void MRCC_vDisableClock(u8 copy_u8Bus, u8 copy_u8Peripheral);
void MRCC_vOutMCO_1Pre(MCO_1_Pre_t PreMco_1 );

#endif /* MCAL_MRCC_MRCC_INT_H_ */
