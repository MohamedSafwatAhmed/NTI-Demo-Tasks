/*
 * KeyPad.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
#include "KeyPad_Cfg.h"
#include "StdTypes.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include "Keypad_Cfg.h"
#include "Dio.h"

/************************************************_PROTOTYPES_********************************************/
void H_KeyPad_Init(void);
uint8_t   H_KeyPad_Read(void);


#endif /* HAL_KEYPAD_KEYPAD_H_ */
