/*
 * Dio.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Safwat
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_
#include "Dio_Type.h"

/*****************************_PROTOTYPES_****************************/
void M_Dio_SetPinDirection(uint8_t,uint8_t);
void M_Dio_SetPortDirection(uint8_t,uint8_t);

void M_Dio_SetPinValue(uint8_t,uint8_t);
void M_Dio_SetPortValue(uint8_t,uint8_t);

uint8_t   M_Dio_getPortValue(uint8_t);
uint8_t   M_Dio_getPinValue(uint8_t);
void M_Dio_SetPullUPRes(uint8_t);

#endif /* MCAL_DIO_DIO_H_ */
