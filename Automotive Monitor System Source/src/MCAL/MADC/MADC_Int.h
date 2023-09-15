/*
 * MADC_Int.h
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : ADC_Driver
 *  File    : Interface File
 *  Version :1.0
 */


#include "MADC_Private.h"
#include "MADC_Config.h"

#ifndef MCAL_MADC_MADC_INT_H_
#define MCAL_MADC_MADC_INT_H_



#define ADC_CONVERSION_MODE_SINGLE         0x00 // Single conversion mode
#define ADC_CONVERSION_MODE_CONTINUOUS     0x01 // Continuous conversion mode

#define ADC_RESOLUTION_12BIT               0x00 // 12-bit resolution
#define ADC_RESOLUTION_10BIT               0x01 // 10-bit resolution
#define ADC_RESOLUTION_8BIT                0x02 // 8-bit resolution
#define ADC_RESOLUTION_6BIT                0x03 // 6-bit resolution


// Function to initialize the ADC peripheral
void MADC_Init(void);

// Function to start an ADC conversion
void MADC_StartConv(u8 ChannelNumber);


// Function to read the ADC conversion result
void MADC_ReadData(float* DataPtr);


#endif /* MCAL_MADC_MADC_INT_H_ */
