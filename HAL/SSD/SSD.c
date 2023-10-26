/*

 * SSD.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Safwat
 */

#include "SSD.h"
void H_Ssd_Init(void)
{
	//setting the Driver pins as output
	M_Dio_SetPinDirection(COM1,OUTPUT);
	M_Dio_SetPinDirection(COM2,OUTPUT);
	M_Dio_SetPinDirection(COM3,OUTPUT);
	M_Dio_SetPinDirection(COM4,OUTPUT);

	M_Dio_SetPinDirection(Data_Pin_0,OUTPUT);
	M_Dio_SetPinDirection(Data_Pin_1,OUTPUT);
	M_Dio_SetPinDirection(Data_Pin_2,OUTPUT);
	M_Dio_SetPinDirection(Data_Pin_3,OUTPUT);

}

void H_Ssd_Write(uint16_t local_u16_Number)
{
	uint8_t Local_u8_Counter=0;
	uint8_t local_u8_Thuns=local_u16_Number /1000;
	local_u16_Number %=1000;
	uint8_t local_u8_Hund=local_u16_Number /100;
	local_u16_Number %=100;
	uint8_t local_u8_Unit=local_u16_Number %10;
	uint8_t local_u8_Tens=local_u16_Number /10;
	for (Local_u8_Counter=0;Local_u8_Counter<50;Local_u8_Counter++)
	{
		H_SSD_DigitDisplay(local_u8_Unit,Ssd_One);
		H_SSD_DigitDisplay(local_u8_Tens,Ssd_Two);
		H_SSD_DigitDisplay(local_u8_Hund,Ssd_Three);
		H_SSD_DigitDisplay(local_u8_Thuns,Ssd_Four);
	}

}

 void H_SSD_DigitDisplay(uint8_t Local_u8_Number,uint8_t Local_u8_Sd)
{
	switch(Local_u8_Sd)
	{
	case Ssd_One:
		M_Dio_SetPinValue(COM1,LOW);
		M_Dio_SetPinValue(COM2,HIGH);
		M_Dio_SetPinValue(COM3,HIGH);
		M_Dio_SetPinValue(COM4,HIGH);
		break;
	case Ssd_Two:
		M_Dio_SetPinValue(COM1,HIGH);
		M_Dio_SetPinValue(COM2,LOW);
		M_Dio_SetPinValue(COM3,HIGH);
		M_Dio_SetPinValue(COM4,HIGH);
		break;
	case Ssd_Three:
		M_Dio_SetPinValue(COM1,HIGH);
		M_Dio_SetPinValue(COM2,HIGH);
		M_Dio_SetPinValue(COM3,LOW);
		M_Dio_SetPinValue(COM4,HIGH);
		break;
	case Ssd_Four:
		M_Dio_SetPinValue(COM1,HIGH);
		M_Dio_SetPinValue(COM2,HIGH);
		M_Dio_SetPinValue(COM3,HIGH);
		M_Dio_SetPinValue(COM4,LOW);
		break;
	default:                  break;
	}
	switch(Local_u8_Number)
	{
	case Zero:
		M_Dio_SetPinValue(Data_Pin_0,LOW);
		M_Dio_SetPinValue(Data_Pin_1,LOW);
		M_Dio_SetPinValue(Data_Pin_2,LOW);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case One:
		M_Dio_SetPinValue(Data_Pin_0,HIGH);
		M_Dio_SetPinValue(Data_Pin_1,LOW);
		M_Dio_SetPinValue(Data_Pin_2,LOW);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case Two:
		M_Dio_SetPinValue(Data_Pin_0,LOW);
		M_Dio_SetPinValue(Data_Pin_1,HIGH);
		M_Dio_SetPinValue(Data_Pin_2,LOW);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case Three:
		M_Dio_SetPinValue(Data_Pin_0,HIGH);
		M_Dio_SetPinValue(Data_Pin_1,HIGH);
		M_Dio_SetPinValue(Data_Pin_2,LOW);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case Four:
		M_Dio_SetPinValue(Data_Pin_0,LOW);
		M_Dio_SetPinValue(Data_Pin_1,LOW);
		M_Dio_SetPinValue(Data_Pin_2,HIGH);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case Five:
		M_Dio_SetPinValue(Data_Pin_0,HIGH);
		M_Dio_SetPinValue(Data_Pin_1,LOW);
		M_Dio_SetPinValue(Data_Pin_2,HIGH);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case Six:
		M_Dio_SetPinValue(Data_Pin_0,LOW);
		M_Dio_SetPinValue(Data_Pin_1,HIGH);
		M_Dio_SetPinValue(Data_Pin_2,HIGH);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case Seven:
		M_Dio_SetPinValue(Data_Pin_0,HIGH);
		M_Dio_SetPinValue(Data_Pin_1,HIGH);
		M_Dio_SetPinValue(Data_Pin_2,HIGH);
		M_Dio_SetPinValue(Data_Pin_3,LOW);
		break;
	case Eight:
		M_Dio_SetPinValue(Data_Pin_0,LOW);
		M_Dio_SetPinValue(Data_Pin_1,LOW);
		M_Dio_SetPinValue(Data_Pin_2,LOW);
		M_Dio_SetPinValue(Data_Pin_3,HIGH);
		break;
	case Nine:
		M_Dio_SetPinValue(Data_Pin_0,HIGH);
		M_Dio_SetPinValue(Data_Pin_1,LOW);
		M_Dio_SetPinValue(Data_Pin_2,LOW);
		M_Dio_SetPinValue(Data_Pin_3,HIGH);
		break;
	default:                break;
	}
	_delay_ms(2);

}
void H_Ssd_CounterUp(uint16_t Local_u16_Target)
{
	uint16_t Local_u16_Number =0;
	for(Local_u16_Number=0;Local_u16_Number<=Local_u16_Target;Local_u16_Number++)
	{
		H_Ssd_Write(Local_u16_Number);
	}
}

void H_Ssd_CounterDown(uint16_t Local_u16_Target)
{
	uint8_t Local_u16_Number =0;
	for(;Local_u16_Target>Local_u16_Number;Local_u16_Target--)
	{
		H_Ssd_Write(Local_u16_Target);
	}

}

