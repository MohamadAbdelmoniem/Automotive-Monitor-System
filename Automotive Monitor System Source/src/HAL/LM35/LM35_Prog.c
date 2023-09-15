/*
 * LM35_Prog.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Yasmeen Elkhateb
 */


#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"

#include "../src/MCAL/MADC/MADC_Int.h"
#include "../src/MCAL/MGPIO/MGPIO_Int.h"

#include"LM35_Int.h"


f32 LM35_GetTempreture(){
	f32 Data;
	f32 output_temp;
    MGPIO_vSetPinMode(LM35_PORT, LM35_PIN, MODE_ANALOG); // Configure PA0 as analog
    MADC_Init();
    MADC_StartConv(LM35_PIN); // Start ADC conversion on LM35_PIN
    MADC_ReadData(&Data);
    // Convert the raw ADC value to temperature in Celsius
    output_temp = ((float)Data/ADC_RESOLUTION)*(ADC_REFERENCE_VOLTAGE);
    output_temp = output_temp/LM35_VOLTAGE_PER_DEGREE;
    return output_temp;
}
