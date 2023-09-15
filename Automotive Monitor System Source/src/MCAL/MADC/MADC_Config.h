/*
 * MADC_Config.h
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : ADC_Driver
 *  File    : Configuration File
 *  Version :1.0
 */

#ifndef MCAL_MADC_MADC_CONFIG_H_
#define MCAL_MADC_MADC_CONFIG_H_


#define ADC_Conversion_Mode		ADC_CONVERSION_MODE_SINGLE
#define ADC_Resolution_Mode		ADC_RESOLUTION_12BIT

#define ADC_REFERENCE_VOLTAGE 		5
#define ADC_RESOLUTION 4096         // For a 12-bit ADC


#endif /* MCAL_MADC_MADC_CONFIG_H_ */
