/*
 * MPX4115_Prog.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Yasmeen Elkhateb
 */


#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"

#include "../src/MCAL/MADC/MADC_Int.h"
#include "../src/MCAL/MGPIO/MGPIO_Int.h"

#include "MPX4115_Int.h"

// Function to convert voltage to pressure (kPa)
f32 ConvertVoltageToPressure(f32 Vout) {
	const f32 S = 0.045;
	f32 P_kPa;
	Vout = ((f32)Vout/ADC_RESOLUTION)*(ADC_REFERENCE_VOLTAGE);
	P_kPa = ((Vout - 0.204) / S)+14;
    return P_kPa;
}

f32 MPX4115A_GetPressure(){
	f32 Data;
	f32 Output_Pressure;
    MGPIO_vSetPinMode(MPX4115A_PORT, MPX4115A_PIN, MODE_ANALOG); // Configure PA1 as analog
    MADC_Init();
    MADC_StartConv(MPX4115A_PIN); // Start ADC conversion on LM35_PIN
    MADC_ReadData(&Data);
    Output_Pressure=ConvertVoltageToPressure(Data);
    // Convert the raw ADC value to pressure (kPa)
    return Output_Pressure;
}
