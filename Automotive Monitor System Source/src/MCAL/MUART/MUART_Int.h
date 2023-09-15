/*
 * MUART_Int.h
 *
 *  Created on: Aug 23, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : UART_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef MCAL_MUART_MUART_INT_H_
#define MCAL_MUART_MUART_INT_H_

void MUART_vInit(void);

void MUART_vSendData(u8* copy_u8Data, u8 copy_u8Length);

void MUART_vSendString(u8* copy_u8Data);

u8 MUART_vReceiveData(void);

void MUART_vEnable(void);

void MUART_vDisable(void);

void MUART_vCallBack(void(*ptr)(void));


#endif /* MCAL_MUART_MUART_INT_H_ */
