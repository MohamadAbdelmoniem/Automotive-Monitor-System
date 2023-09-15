/*
 * MEXTI_Int.h
 *
 *  Created on: Aug 14, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : EXTI_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef MCAL_MEXTI_MEXTI_INT_H_
#define MCAL_MEXTI_MEXTI_INT_H_


#define EXTI0     0
#define EXTI1     1


/************************************   Triggering Source Mode   *************************************/
typedef enum{
	MEXTI_FALLING_EDGE,
	MEXTI_RISING_EDGE,
	MEXTI_ANY_CHANGE
}MEXTI_TrigType;


/************************************   Selected Port Number   *************************************/
typedef enum{

	MEXTI_PORTA,
	MEXTI_PORTB,
	MEXTI_PORTC,

}MEXTI_PORT;



/************************************   Selected Line Number   *************************************/
typedef enum{

	MEXTI_LINE0,
	MEXTI_LINE1,
	MEXTI_LINE2,
	MEXTI_LINE3,
	MEXTI_LINE4,
	MEXTI_LINE5,
	MEXTI_LINE6,
	MEXTI_LINE7,
	MEXTI_LINE8,
	MEXTI_LINE9,
	MEXTI_LINE10,
	MEXTI_LINE11,
	MEXTI_LINE12,
	MEXTI_LINE13,
	MEXTI_LINE14,
	MEXTI_LINE15

}MEXTI_LineNo;

void MEXTI_vEnableExternalInterrupt(MEXTI_LineNo copy_uddLineNo);
void MEXTI_vDisableExternalInterrupt(MEXTI_LineNo copy_uddLineNo);
void MEXTI_vSetTrigger( MEXTI_TrigType copy_uddTrigType, MEXTI_LineNo copy_uddLineNo );
void MEXTI_vEnableSoftwareInterruptEvent(MEXTI_LineNo copy_uddLineNo);
void MEXTI_vSetExtiConfig(MEXTI_LineNo copy_uddLineNo, MEXTI_PORT copy_uddGpioPortNo);
void MEXTI0_vCallBack(void (*ptr)(void));
void MEXTI1_vCallBack(void (*ptr)(void));


#endif /* MCAL_MEXTI_MEXTI_INT_H_ */
