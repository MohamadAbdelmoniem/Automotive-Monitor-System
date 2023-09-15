/*
 * MPX4115_Int.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Yasmeen Elkhateb
 */

#ifndef HAL_MPX4115_MPX4115_INT_H_
#define HAL_MPX4115_MPX4115_INT_H_

#include "MPX4115_Private.h"
#include "MPX4115_Config.h"


f32 MPX4115A_GetPressure();
f32 ConvertVoltageToPressure(f32 Vout);


#endif /* HAL_MPX4115_MPX4115_INT_H_ */
