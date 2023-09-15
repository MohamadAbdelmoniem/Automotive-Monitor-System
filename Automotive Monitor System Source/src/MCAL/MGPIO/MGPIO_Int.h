/*
 * MGPIO_Int.h
 *
 *  Created on: Aug 10, 2023
 *  Author  : Yasmeen Elkhateb
 *  MICRO   : STM32F401CCU6
 *  LAYER   : MCAL
 *  DRIVER  : GPIO_Driver
 *  File    : Interface File
 *  Version :1.0
 */

#ifndef MCAL_MGPIO_MGPIO_INT_H_
#define MCAL_MGPIO_MGPIO_INT_H_

/********************* Port Naming ****************/
#define _GPIOA_PORT 0U
#define _GPIOB_PORT 1U
#define _GPIOC_PORT 2U

/*======== Macros ALTF  ========*/
#define ALTF_0      0U
#define ALTF_1      1U
#define ALTF_2      2U
#define ALTF_3      3U
#define ALTF_4      4U
#define ALTF_5      5U
#define ALTF_6      6U
#define ALTF_7      7U
#define ALTF_8      8U
#define ALTF_9      9U
#define ALTF_10     10U
#define ALTF_11     11U
#define ALTF_12     12U
#define ALTF_13     13U
#define ALTF_14     14U
#define ALTF_15     15U

/****************************PIN MODE***************/
 #define MODE_INPUT			0U
 #define MODE_OUTPUT		1U
 #define MODE_ALTF			2U
 #define MODE_ANALOG		3U

/*****************output type *************/
#define _OUTPUT_TYPE_PUSH_PUL			0U
#define _OUTPUT_TYPE_OPEN_DRAIN			1U

/*************SPeed Mode*********************/
#define _OUTPUT_SPEED_LOW   			0U
#define _OUTPUT_SPEED_MEDUIM            1U
#define _OUTPUT_SPEED_HIGH              2U
#define _OUTPUT_SPEED_VERY_HIGH         3U

/*************** PullUp/Down resister***********/
#define _PULL_OFF                0U
#define _PULL_UP                 1U
#define _PULL_DOWN               2U

/********************* write data ***********/
#define _LOW                      (0U)
#define _HIGH	                  (1U)

/*======== Macros Of Pins ========*/
#define GPIO_PIN_0              ((u16)0U )       /*!< Pin 0 selected    */
#define GPIO_PIN_1              ((u16)1U )       /*!< Pin 1 selected    */
#define GPIO_PIN_2              ((u16)2U )       /*!< Pin 2 selected    */
#define GPIO_PIN_3              ((u16)3U )       /*!< Pin 3 selected    */
#define GPIO_PIN_4              ((u16)4U )       /*!< Pin 4 selected    */
#define GPIO_PIN_5              ((u16)5U )       /*!< Pin 5 selected    */
#define GPIO_PIN_6              ((u16)6U )       /*!< Pin 6 selected    */
#define GPIO_PIN_7              ((u16)7U )       /*!< Pin 7 selected    */
#define GPIO_PIN_8              ((u16)8U )       /*!< Pin 8 selected    */
#define GPIO_PIN_9              ((u16)9U )       /*!< Pin 9 selected    */
#define GPIO_PIN_10             ((u16)10U)       /*!< Pin 10 selected   */
#define GPIO_PIN_11             ((u16)11U)       /*!< Pin 11 selected   */
#define GPIO_PIN_12             ((u16)12U)       /*!< Pin 12 selected   */
#define GPIO_PIN_13             ((u16)13U)       /*!< Pin 13 selected   */
#define GPIO_PIN_14             ((u16)14U)       /*!< Pin 14 selected   */
#define GPIO_PIN_15             ((u16)15U)       /*!< Pin 15 selected   */
#define GPIO_PIN_All            ((u16)0xFFFF)    /*!< All pins selected */


/*===============   1-Function Set The Mode Of Pin	 ===============*/
void MGPIO_vSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNum, u32 Copy_u32Mode);
/*===============   2-Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)  ===============*/
void MGPIO_vSetPinOutPutType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u16 Copy_u16OutPutType);
/*===============	3-Function Set The Speed Of output pin  (LOW , Medium , High ,VeryHaigh	===============*/
void MGPIO_vSetPinOutSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNum, u32 Copy_u32OutSpeed);
/*===============   4-Function Set The PULL ( Almost Input ) ( OFF , UP , DOWN )  ===============*/
void MGPIO_vSetPullType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u32 Copy_u32PullType);
/*===============   5-Function To Read Data From IDR  ===============*/
u8 MGPIO_u8ReadData(u8 copy_u8PORT, u8 copy_u8PIN);
/*===============   6-Function To Write Data At ODR	Value = HIGH , LOW  ===============*/
void MGPIO_vWriteData(u8 Copy_u32PortName, u8 Copy_u8PinNum, u8 Copy_u8State);
/*===============   7-Function To Locked   ===============*/
void MGPIO_vPinLock(u8 Copy_u8PortNum, u8 Copy_u8PinNum );
/*===============   7-Function To Set ALTF   ===============*/
void MGPIO_vSetPinAltFn(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8ALF );
/*===============   7-Function To Send One Byte  ===============*/
void MGPIO_vPortOutputOneByte(u8 Copy_u8Port, u8 Copy_u8Data, u8 Copy_u8StartBit);

void MGPIO_vWriteDataDIR(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8State);

u8 MGPIO_vPortReadOneByte(u8 Copy_u8Port, u8 Copy_u8StartBit);

#endif /* MCAL_MGPIO_MGPIO_INT_H_ */
