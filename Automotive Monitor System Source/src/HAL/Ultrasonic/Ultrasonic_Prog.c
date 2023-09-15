/*
 * Ultrasonic_Prog.c
 *
 *  Created on: Sep 12, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : HAL
 *  DRIVER  : Ultrasonic_Driver
 *  File    : Program File
 *  Version :1.0
 */

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/
#include "../src/LIB/STD_Types.h"
#include "../src/LIB/BIT_Math.h"
#include "../src/LIB/Delay/Delay_Interface.h"

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "../src/MCAL/MGPIO/MGPIO_Int.h"
#include "Ultrasonic_Int.h"


void H_VUltrasonicInit(void)
{
	//Configuring PA5 for generating pulse sent to trig pin
	MGPIO_vSetPinMode(TRIGER_PORT ,TRIGER_PIN, MODE_OUTPUT); //Set the PA5 pin to output mode->    P8->16

	//Configuring output from echo pin to be sent to the board (PA6 pin)
	MGPIO_vSetPinMode(ECHO_PORT ,ECHO_PIN ,MODE_INPUT); //Set PA6 to input mode
}

u32  H_u16USRead(void)
{
	u32 data = 0;
	u32 dist = 0;
	f64 time;
	MGPIO_vWriteDataDIR(TRIGER_PORT ,TRIGER_PIN,_LOW); // Make PA5 low again
	Delay_vUsIn16MHzint(10);
    MGPIO_vWriteDataDIR(TRIGER_PORT ,TRIGER_PIN,_HIGH);//PA5 set to High
    Delay_vUsIn16MHzint(10);// wait for 10us
    MGPIO_vWriteDataDIR(TRIGER_PORT ,TRIGER_PIN,_LOW);

    //2. Measure the pulse width of the pulse sent from the echo pin by polling IDR for port A

	while(!MGPIO_u8ReadData(ECHO_PORT,ECHO_PIN));
	while(MGPIO_u8ReadData(ECHO_PORT,ECHO_PIN))
	 {
		data = data+1;
	 }

	//3.Converting the gathered data into distance in cm
	if (data>0)
	{
		time = (data*(0.0625*0.000001));
		dist = (((time*340000.0)/2)* 1.75);
	}
    return dist;
}
