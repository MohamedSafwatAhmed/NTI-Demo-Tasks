/*
 * SSD_Cfg.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_SSD_SSD_CFG_H_
#define HAL_SSD_SSD_CFG_H_
#include "Dio.h"

#define COM1  PA3_Pin //enable for the first segment
#define COM2  PA2_Pin //enable for the second segment
#define COM3  PB5_Pin //enable for the three segment
#define COM4  PB6_Pin //enable for the four segment

#define Data_Pin_0 PB0_Pin  //for the data bit 0
#define Data_Pin_1 PB1_Pin  //for the data bit 1
#define Data_Pin_2 PB2_Pin  //for the data bit 2
#define Data_Pin_3 PB4_Pin  //for the data bit 3

enum num{
	Zero=0,One,Two,Three,Four,Five,Six,Seven,Eight,Nine
};
#endif /* HAL_SSD_SSD_CFG_H_ */
