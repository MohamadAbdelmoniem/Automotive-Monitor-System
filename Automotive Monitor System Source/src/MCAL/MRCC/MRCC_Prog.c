/*
 * MRCC_Prog.h
 *
 *  Created on: Aug 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : RCC_Driver
 *  File    : Program File
 *  Version :1.0
 */

/************************************   Includes   *************************************/
#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"


/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "MRCC_Int.h"
#include "MRCC_Private.h"
#include "MRCC_Config.h"


/**************************************   APIs   ******************************************/
void MRCC_vInit(void)
{
	/** CSS(ON/OFF) **/
#if (RCC_CSS_ENABLE == ENABLE)
	 SET_BIT(RCC -> CR,CSSON);
#elif (RCC_CSS_ENABLE == DISABLE)
	 CLR_BIT(RCC -> CR,CSSON);
#endif

	/* HSE_BYP CLR-> Oscillator Enable (not bypassed), SET -> Oscillator Disable (bypassed) */
	CLR_BIT(RCC -> CR,HSEBYP);

	/* Select Clock switch (HSI/HSE/PLL) */
	 /*
	  * 00   HSI
	  * 01   HSE
	  * 10   PLL
	  * 11   NONE
	  */


#if RCC_SYS_CLK == RCC_HSE
	 SET_BIT(RCC-> CFGR, SW0);
	 CLR_BIT(RCC-> CFGR, SW1);

#elif RCC_SYS_CLK == RCC_HSI
	 CLR_BIT(RCC-> CFGR, SW0);
	 CLR_BIT(RCC-> CFGR, SW1);

#elif RCC_SYS_CLK == RCC_PLL
	 CLR_BIT(RCC-> CFGR, SW0);
	 SET_BIT(RCC-> CFGR, SW1);
#endif


	/* Bus pre-scalers */

	/* PLL Configuration */

	/* Enable the selected clock source (HSI ON/HSE ON/PLL ON) */

#if (RCC_HSE_ENABLE == ENABLE)
	 SET_BIT(RCC -> CR,HSEON);

#elif (RCC_HSI_ENABLE == ENABLE)
	 SET_BIT(RCC -> CR,HSION);

#elif (RCC_PLL_ENABLE == ENABLE)
	 SET_BIT(RCC -> CR,PLLON);
#endif
}

/* Enable the selected clock source on different peripherals */
void MRCC_vEnableClock(u8 copy_u8Bus, u8 copy_u8Peripheral)
{
	if( copy_u8Bus == APB1_BUS)
	{
		switch(copy_u8Peripheral)
		{
			case APB1_Power_Interface:
				SET_BIT(RCC -> APB1ENR, PWREN);
				break;

			case APB1_I2C3:
				SET_BIT(RCC -> APB1ENR, I2C3EN);
				break;

			case APB1_I2C2:
				SET_BIT(RCC -> APB1ENR, I2C2EN);
				break;

			case APB1_USART2:
				SET_BIT(RCC -> APB1ENR, USART2EN);
				break;

			case APB1_SPI3:
				SET_BIT(RCC -> APB1ENR, SPI3EN);
				break;

			case APB1_SPI2:
				SET_BIT(RCC -> APB1ENR, SPI2EN);
				break;

			case APB1_WWDG:
				SET_BIT(RCC -> APB1ENR, WWDGEN);
				break;

			case APB1_TIM5:
				SET_BIT(RCC -> APB1ENR, TIM5EN);
				break;

			case APB1_TIM4:
				SET_BIT(RCC -> APB1ENR, TIM4EN);
				break;

			case APB1_TIM3:
				SET_BIT(RCC -> APB1ENR, TIM3EN);
				break;

			case APB1_TIM2:
				SET_BIT(RCC -> APB1ENR, TIM2EN);
				break;

			default:
				break;
		}
	}

	else if( copy_u8Bus == APB2_BUS )
	{
		switch(copy_u8Peripheral)
		{
			case APB2_TIM11:
				SET_BIT(RCC -> APB2ENR, TIM11EN);
				break;

			case APB2_TIM10:
				SET_BIT(RCC -> APB2ENR, TIM10EN);
				break;

			case APB2_TIM9:
				SET_BIT(RCC -> APB2ENR, TIM9EN);
				break;

			case APB2_System_Config_controller:
				SET_BIT(RCC -> APB2ENR, SYSCFGEN);
				break;

			case APB2_SPI4:
				SET_BIT(RCC -> APB2ENR, SPI4EN);
				break;

			case APB2_SPI1:
				SET_BIT(RCC -> APB2ENR, SPI1EN);
				break;

			case APB2_SDIO:
				SET_BIT(RCC -> APB2ENR, SDIOEN);
				break;

			case APB2_ADC1:
				SET_BIT(RCC -> APB2ENR, ADC1EN);
				break;

			case APB2_USART6:
				SET_BIT(RCC -> APB2ENR, USART6EN);
				break;

			case APB2_USART1:
				SET_BIT(RCC -> APB2ENR, USART1EN);
				break;

			case APB2_TIM1:
				SET_BIT(RCC -> APB2ENR, TIM1EN);
				break;

			default:
				break;
			}
		}

	else if( copy_u8Bus == AHB1_BUS )
	{
		switch(copy_u8Peripheral)
		{
			case AHB1_DMA2:
				SET_BIT(RCC -> AHB1ENR, DMA2EN);
				break;

			case AHB1_DMA1:
				SET_BIT(RCC -> AHB1ENR, DMA1EN);
				break;

			case AHB1_CRC:
				SET_BIT(RCC -> AHB1ENR, CRCEN);
				break;

			case AHB1_GPIOH:
				SET_BIT(RCC -> AHB1ENR, GPIOHEN);
				break;

			case AHB1_GPIOE:
				SET_BIT(RCC -> AHB1ENR, GPIOEEN);
				break;

			case AHB1_GPIOD:
				SET_BIT(RCC -> AHB1ENR, GPIODEN);
				break;

			case AHB1_GPIOC:
				SET_BIT(RCC -> AHB1ENR, GPIOCEN);
				break;

			case AHB1_GPIOB:
				SET_BIT(RCC -> AHB1ENR, GPIOBEN);
				break;

			case AHB1_GPIOA:
				SET_BIT(RCC -> AHB1ENR, GPIOAEN);
				break;

			default:
				break;
		}
	}

	else if( copy_u8Bus == AHB2_BUS )
	{
		switch(copy_u8Peripheral)
		{
			case AHB2_USB_OTG_FS:
				SET_BIT(RCC -> AHB2ENR, OTGFSEN);
				break;

			default:
				break;
		}
	}
}

void MRCC_vDisableClock(u8 copy_u8Bus, u8 copy_u8Peripheral)
{
	if( copy_u8Bus == APB1_BUS)
	{
		switch(copy_u8Peripheral)
		{
			case APB1_Power_Interface:
				CLR_BIT(RCC -> APB1ENR, PWREN);
				break;

			case APB1_I2C3:
				CLR_BIT(RCC -> APB1ENR, I2C3EN);
				break;

			case APB1_I2C2:
				CLR_BIT(RCC -> APB1ENR, I2C2EN);
				break;

			case APB1_USART2:
				CLR_BIT(RCC -> APB1ENR, USART2EN);
				break;

			case APB1_SPI3:
				CLR_BIT(RCC -> APB1ENR, SPI3EN);
				break;

			case APB1_SPI2:
				CLR_BIT(RCC -> APB1ENR, SPI2EN);
				break;

			case APB1_WWDG:
				CLR_BIT(RCC -> APB1ENR, WWDGEN);
				break;

			case APB1_TIM5:
				CLR_BIT(RCC -> APB1ENR, TIM5EN);
				break;

			case APB1_TIM4:
				CLR_BIT(RCC -> APB1ENR, TIM4EN);
				break;

			case APB1_TIM3:
				CLR_BIT(RCC -> APB1ENR, TIM3EN);
				break;

			case APB1_TIM2:
				CLR_BIT(RCC -> APB1ENR, TIM2EN);
				break;

			default:
				break;
		}
	}

	else if( copy_u8Bus == APB2_BUS )
	{
		switch(copy_u8Peripheral)
		{
			case APB2_TIM11:
				CLR_BIT(RCC -> APB2ENR, TIM11EN);
				break;

			case APB2_TIM10:
				CLR_BIT(RCC -> APB2ENR, TIM10EN);
				break;

			case APB2_TIM9:
				CLR_BIT(RCC -> APB2ENR, TIM9EN);
				break;

			case APB2_System_Config_controller:
				CLR_BIT(RCC -> APB2ENR, SYSCFGEN);
				break;

			case APB2_SPI4:
				CLR_BIT(RCC -> APB2ENR, SPI4EN);
				break;

			case APB2_SPI1:
				CLR_BIT(RCC -> APB2ENR, SPI1EN);
				break;

			case APB2_SDIO:
				CLR_BIT(RCC -> APB2ENR, SDIOEN);
				break;

			case APB2_ADC1:
				CLR_BIT(RCC -> APB2ENR, ADC1EN);
				break;

			case APB2_USART6:
				CLR_BIT(RCC -> APB2ENR, USART6EN);
				break;

			case APB2_USART1:
				CLR_BIT(RCC -> APB2ENR, USART1EN);
				break;

			case APB2_TIM1:
				CLR_BIT(RCC -> APB2ENR, TIM1EN);
				break;

			default:
				break;
		}
	}

	else if( copy_u8Bus == AHB1_BUS )
	{
		switch(copy_u8Peripheral)
		{
			case AHB1_DMA2:
				CLR_BIT(RCC -> AHB1ENR, DMA2EN);
				break;

			case AHB1_DMA1:
				CLR_BIT(RCC -> AHB1ENR, DMA1EN);
				break;

			case AHB1_CRC:
				CLR_BIT(RCC -> AHB1ENR, CRCEN);
				break;

			case AHB1_GPIOH:
				CLR_BIT(RCC -> AHB1ENR, GPIOHEN);
				break;

			case AHB1_GPIOE:
				CLR_BIT(RCC -> AHB1ENR, GPIOEEN);
				break;

			case AHB1_GPIOD:
				CLR_BIT(RCC -> AHB1ENR, GPIODEN);
				break;

			case AHB1_GPIOC:
				CLR_BIT(RCC -> AHB1ENR, GPIOCEN);
				break;

			case AHB1_GPIOB:
				CLR_BIT(RCC -> AHB1ENR, GPIOBEN);
				break;

			case AHB1_GPIOA:
				CLR_BIT(RCC -> AHB1ENR, GPIOAEN);
				break;

			default:
				break;
		}
	}

	else if( copy_u8Bus == AHB2_BUS )
	{
		switch(copy_u8Peripheral)
		{
			case AHB2_USB_OTG_FS:
				CLR_BIT(RCC -> AHB2ENR, OTGFSEN);
				break;

			default:
				break;
		}
	}
}

void MRCC_vOutMCO_1Pre(MCO_1_Pre_t PreMco_1 )
{
	switch(PreMco_1)
	{
		case MCO_1_Div_1:
				CLR_BIT(RCC ->CFGR,24U);
				CLR_BIT(RCC ->CFGR,25U);
				CLR_BIT(RCC ->CFGR,26U);
		break;

		case MCO_1_Div_2:
				CLR_BIT(RCC ->CFGR,24U);
				CLR_BIT(RCC ->CFGR,25U);
				SET_BIT(RCC ->CFGR,26U);
		break;

		case MCO_1_Div_3:
				SET_BIT(RCC ->CFGR,24U);
				CLR_BIT(RCC ->CFGR,25U);
				SET_BIT(RCC ->CFGR,26U);
		break;

		case MCO_1_Div_4:
				CLR_BIT(RCC ->CFGR,24U);
				SET_BIT(RCC ->CFGR,25U);
				SET_BIT(RCC ->CFGR,26U);
		break;

		case MCO_1_Div_5:
				SET_BIT(RCC ->CFGR,24U);
				SET_BIT(RCC ->CFGR,25U);
				SET_BIT(RCC ->CFGR,26U);
		break;

		default:
		break;
	}
}
