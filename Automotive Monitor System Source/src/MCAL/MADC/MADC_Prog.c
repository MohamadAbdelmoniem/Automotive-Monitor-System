/*
 * MADC_Prog.c
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : ADC_Driver
 *  File    : Program File
 *  Version :1.0
 */

#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"

#include "../src/MCAL/MGPIO/MGPIO_Int.h"
#include "MADC_Int.h"


void MADC_Init(void)
{
	if (ADC_Conversion_Mode==ADC_CONVERSION_MODE_SINGLE) {
		ADC1->CR2 &= ~(1 << 1); //CONT bit disabled
	}
	else if (ADC_Conversion_Mode==ADC_CONVERSION_MODE_CONTINUOUS) {
		ADC1->CR2 |= (1 << 1); //CONT bit enabled
	}
	switch (ADC_Resolution_Mode) {
		case ADC_RESOLUTION_12BIT:
			ADC1->CR1 &= ~(1 << 24);
			ADC1->CR1 &= ~(1 << 25);
			break;
		case ADC_RESOLUTION_10BIT:
			ADC1->CR1 |= (1 << 24);
			ADC1->CR1 &= ~(1 << 25);
			break;
		case ADC_RESOLUTION_8BIT:
			ADC1->CR1 &= ~(1 << 24);
			ADC1->CR1 |= (1 << 25);
			break;
		case ADC_RESOLUTION_6BIT:
			ADC1->CR1 |= (1 << 24);
			ADC1->CR1 |= (1 << 25);
			break;
		default:
			ADC1->CR1 &= ~(1 << 24);
			ADC1->CR1 &= ~(1 << 25);
		}
	ADC1->CR2 |= (1 << 0);
	ADC1->CR2 &= ~(1 << 11);
}

void MADC_StartConv(u8 ChannelNumber){
	ADC1->SQR1 &= ~(1 << 20);
	ADC1->SQR1 &= ~(1 << 21);
	ADC1->SQR1 &= ~(1 << 22);
	ADC1->SQR1 &= ~(1 << 23);
	ADC1->SQR3 &=
			~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)); //clear bits chosen for for first channel number
	ADC1->SQR3 |= (ChannelNumber); //choose the channel number
	ADC1->CR2 |= (1 << 30); //start conversion
}

void MADC_ReadData(float* DataPtr){
	*DataPtr = ADC1->DR;
}
