/*
 * Timer0.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Mohamed Safwat
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

#include "Dio.h"
#include <avr/interrupt.h>
#include "Timer0_Cfg.h"
#include "Dio.h"
#include "StdTypes.h"
#include "BitMath.h"
#include <avr\io.h>
/*****************************************_MACROS_*********************************************/

#define Normal_Mode			 1
#define Ctc_Mode			 2
#define      Inverted		 1
#define  Non_Inverted		 2
#define Fast_Pwm0            1
#define Phase_Correct_Pwm0   2


/*****************************************_PROTOTYPES_*********************************************/
void M_Timer0_Init(void);
void M_Timer0_SetTime(uint32_t);
void M_Timer0_Start(void);
void M_Timer0_Stop(void);
void M_Timer0_SetCallBack(void (*)(void));

void M_Timer0_Pwm0Init(void);
void M_Timer0_Pwm0SetDutyCycle(uint8_t);
void M_Timer0_Pwm0Start(void);
void M_Timer0_Pwm0Stop(void);

#endif /* MCAL_TIMER0_TIMER0_H_ */
