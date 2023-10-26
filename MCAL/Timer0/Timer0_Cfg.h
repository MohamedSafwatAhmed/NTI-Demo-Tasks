/*
 * Timer0_Cfg.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Mohamed Safwat
 */

#ifndef MCAL_TIMER0_TIMER0_CFG_H_
#define MCAL_TIMER0_TIMER0_CFG_H_

/*********************_SELECT_TIMER0_MODE********************/
//Option 1-> [Normal_Mode]
//Option 2-> [Ctc_Mode]
#define  Timer0_Mode         Normal_Mode

/*********************_SELECT_FAST_PWM0_MODE********************/
//Option 1-> [Inverted]
//Option 2-> [Non_Inverted]
#define  Fast_Pwm0_Mode         Non_Inverted

/*********************_SELECT_FAST_PWM0_MODE********************/
//Option 1-> [Inverted]
//Option 2-> [Non_Inverted]
#define  Phase_Correct_Pwm0_Mode        Non_Inverted

/*********************_SELECT_PWM0_MODE********************/
//Option 1-> [Fast_Pwm0]
//Option 2-> [Phase_Correct_Pwm0]
#define Pwm0_Mode   Phase_Correct_Pwm0_Mode

/*********************_SELECT_FREQUANCY_********************/
#define  F_OSC                 16
/*********************_SELECT_TIMER0_PRESCALER********************/
//Option 1-> [1024]
//Option 2-> [256]
#define  TIMER0_PRESCALER       1024


#endif /* MCAL_TIMER0_TIMER0_CFG_H_ */
