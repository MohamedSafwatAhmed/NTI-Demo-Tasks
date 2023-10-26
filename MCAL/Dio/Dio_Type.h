/*
 * Dio_Type.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Safwat
 */

#ifndef MCAL_DIO_TYPE_H_
#define MCAL_DIO_TYPE_H_

#include "StdTypes.h"
#include <avr\io.h>

#define LOW                   0
#define HIGH                  1

enum Port{  A =1, B, C, D};
enum Pins{ PA0_Pin=10 ,PA1_Pin,PA2_Pin,PA3_Pin,PA4_Pin,PA5_Pin,PA6_Pin,PA7_Pin,
           PB0_Pin=20    ,PB1_Pin,PB2_Pin,PB3_Pin,PB4_Pin,PB5_Pin,PB6_Pin,PB7_Pin,
           PC0_Pin=30    ,PC1_Pin,PC2_Pin,PC3_Pin,PC4_Pin,PC5_Pin,PC6_Pin,PC7_Pin,
		   PD0_Pin=40    ,PD1_Pin,PD2_Pin,PD3_Pin,PD4_Pin,PD5_Pin,PD6_Pin, PD7_Pin
};

#define  OUTPUT 1
#define  INPUT  2

#define  ENABLE   1
#define  DISABLE  2


#endif /* MCAL_DIO_DIO_TYPE_H_ */
