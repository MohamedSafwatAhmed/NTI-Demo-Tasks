/*
 * Lcd.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "Lcd_Cfg.h"
# define F_CPU 16000000UL
#include <util/delay.h>


/*****************************************_PROTOTYPES_*******************************************/
void H_Lcd_Init(void);
void H_Lcd_WriteCharacter(uint8_t);
void H_Lcd_WriteCommand(uint8_t);
void H_Lcd_WriteString(uint8_t*);
void H_Lcd_WriteNumber(sint32_t);
void H_Lcd_Clr(void);
void H_Lcd_GoTO(uint8_t,uint8_t);
void H_Lcd_ShiftRight(void);
void H_Lcd_ShiftLeft(void);
void H_Lcd_GoTO(uint8_t Local_u8_Row,uint8_t Local_u8_Col);


#endif /* HAL_LCD_LCD_H_ */
