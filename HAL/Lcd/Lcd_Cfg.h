/*
 * Lcd_Cfg.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_
/***********************************_INCLUDES_*********************************/
#include "Dio.h"
#include <avr\io.h>
#include "StdTypes.h"
/*****************************************_Configuration_***********************************************/

#define _8_Bit_Mode                      1
#define _4_Bit_Mode                      2
#define Lcd_8_Bit_Mode                   0x38
#define Lcd_4_Bit_Mode_1                 0x33
#define Lcd_4_Bit_Mode_2                 0x32
#define Lcd_4_Bit_Mode_3                 0x28
#define  Lcd_Display_On_Cursor_off       0x0c
#define  Lcd_Clear                       0x01
#define  Lcd_Return_Home                 0x02
#define  Null_                           '\0'
#define  Lcd_Shift_Right                 0x05
#define  Lcd_Shift_Left                  0x07

#define RS         PA3_Pin
#define EN         PA2_Pin

#define D4         PB0_Pin
#define D5         PB1_Pin
#define D6         PB2_Pin
#define D7         PB4_Pin

#define Lcd_Data_Port PORTB



#endif /* HAL_LCD_LCD_CFG_H_ */
