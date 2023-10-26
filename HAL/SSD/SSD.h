/*
 * SSD.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_SSD_SSD_H_
#define HAL_SSD_SSD_H_
/*****************************************_INCLUDES_*********************************************/
#include "SSD_Cfg.h"
#include "StdTypes.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*****************************************_MACROS_***********************************************/
#define  Ssd_One    1
#define  Ssd_Two     2
#define  Ssd_Three   3
#define  Ssd_Four    4

/*****************************************_PROTOTYPES_*******************************************/
void H_Ssd_Init(void);
void H_Ssd_Write(uint16_t);
void H_Ssd_CounterUp(uint16_t);
void H_Ssd_CounterDown(uint16_t);
void H_SSD_DigitDisplay(uint8_t Local_u8_Number,uint8_t Local_u8_Sd);

#endif /* HAL_SSD_SSD_H_ */
