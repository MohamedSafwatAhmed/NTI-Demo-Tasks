/*
 * Keypad_Cfg.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_
#include "Dio.h"
#define KEYPAD_PRESSED     LOW
#define KEYPAD_RELEASED    HIGH
#define TYPE_1             1
#define TYPE_2             2

#define KEYPAD_DEBOUNCING_TIME    40
/**************************************_SELECT_KEYPAD_MODE_******************************************/
// option1 -> [ TYPE_1 ]
// option2 -> [ TYPE_2 ]
#define KEYPAD_MODE        TYPE_2
/*********************************************_SELECT_KEYPAD_PIN_********************************************/
#define Keypad_Row1       PC5_Pin
#define Keypad_Row2       PC4_Pin
#define Keypad_Row3       PC3_Pin
#define Keypad_Row4       PC2_Pin

#define Keypad_Col1       PD7_Pin
#define Keypad_Col2       PD6_Pin
#define Keypad_Col3       PD5_Pin
#define Keypad_Col4       PD3_Pin



#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
