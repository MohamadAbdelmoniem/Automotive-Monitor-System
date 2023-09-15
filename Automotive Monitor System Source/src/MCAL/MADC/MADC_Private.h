/*
 * MADC_Private.h
 *
 *  Created on: Sep 11, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : ADC_Driver
 *  File    : Private File
 *  Version :1.0
 */

#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_


typedef struct
{
    volatile u32 SR;     // Status Register
    volatile u32 CR1;    // Control Register 1
    volatile u32 CR2;    // Control Register 2
    volatile u32 SMPR1;  // Sample Time Register 1
    volatile u32 SMPR2;  // Sample Time Register 2
    volatile u32 JOFR1;  // Injected Channel Data Offset Register 1
    volatile u32 JOFR2;  // Injected Channel Data Offset Register 2
    volatile u32 JOFR3;  // Injected Channel Data Offset Register 3
    volatile u32 JOFR4;  // Injected Channel Data Offset Register 4
    volatile u32 HTR;    // Watchdog Higher Threshold Register
    volatile u32 LTR;    // Watchdog Lower Threshold Register
    volatile u32 SQR1;   // Regular Sequence Register 1
    volatile u32 SQR2;   // Regular Sequence Register 2
    volatile u32 SQR3;   // Regular Sequence Register 3
    volatile u32 JSQR;   // Injected Sequence Register
    volatile u32 JDR1;   // Injected Data Register 1
    volatile u32 JDR2;   // Injected Data Register 2
    volatile u32 JDR3;   // Injected Data Register 3
    volatile u32 JDR4;   // Injected Data Register 4
    volatile u32 DR;     // Regular Data Register
} ADC_TypeDef;

#define ADC1_BASE       (0x40012000UL)
#define ADC1            ((ADC_TypeDef *)ADC1_BASE)



#endif /* MCAL_MADC_MADC_PRIVATE_H_ */
