/*
 * Dio.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Safwat
 */
#include "Dio.h"
//#include "Reg.h"
#include "BitMath.h"
#include <avr\io.h>

void M_Dio_SetPinDirection(uint8_t Local_u8_Num,uint8_t local_u8_Mode)
{
	uint8_t Local_u8_Port =Local_u8_Num /10;
	uint8_t Local_u8_Pin  =Local_u8_Num %10;
	switch(local_u8_Mode)
	{
	case OUTPUT:
		switch (Local_u8_Port)
		{
		case A:SetBit(DDRA,Local_u8_Pin);  break;
		case B:SetBit(DDRB,Local_u8_Pin);  break;
		case C:SetBit(DDRC,Local_u8_Pin);  break;
		case D:SetBit(DDRD,Local_u8_Pin);  break;
		default:                           break;
		}
		break;

	case INPUT:
		switch (Local_u8_Port)
		{
		case A:ClrBit(DDRA,Local_u8_Pin); break;
		case B:ClrBit(DDRB,Local_u8_Pin); break;
		case C:ClrBit(DDRC,Local_u8_Pin); break;
		case D:ClrBit(DDRD,Local_u8_Pin); break;
		default:                          break;
		}

			break;

			default:                              break;

	}
}

void M_Dio_SetPortDirection(uint8_t Local_u8_Num,uint8_t Local_u8_Mode)

{
	uint8_t Value=0;
	if(Local_u8_Mode == OUTPUT)
	{
		Value = 0xFF;
	}
	else
	{
		Value =0x0;
	}
	switch(Local_u8_Num)
	{
	case A: DDRA=Value; break;
	case B: DDRB=Value; break;
	case C: DDRC=Value; break;
	case D: DDRD=Value; break;
	default:            break;
	}
}

void M_Dio_SetPinValue(uint8_t Local_u8_Num,uint8_t Local_u8_Level)
{
	uint8_t Local_u8_Pin =Local_u8_Num %10;
	uint8_t Local_u8_Port =Local_u8_Num/10;
	switch(Local_u8_Level)
	{
	case HIGH:
		switch (Local_u8_Port)
		{
		case A:SetBit(PORTA,Local_u8_Pin);  break;
		case B:SetBit(PORTB,Local_u8_Pin);  break;
		case C:SetBit(PORTC,Local_u8_Pin);  break;
		case D:SetBit(PORTD,Local_u8_Pin);  break;
		default:                            break;
		}
		break;
		case LOW:
			switch (Local_u8_Port)
			{
			case A:ClrBit(PORTA,Local_u8_Pin);  break;
			case B:ClrBit(PORTB,Local_u8_Pin);  break;
			case C:ClrBit(PORTC,Local_u8_Pin);  break;
			case D:ClrBit(PORTD,Local_u8_Pin);  break;
			default:                            break;
			}

			break;
			default:                              break;

	}

}

void M_Dio_SetPortValue(uint8_t Local_u8_Port,uint8_t Local_u8_Value)
{
	switch(Local_u8_Port)
	{
	case A: PORTA=Local_u8_Value; break;
	case B: PORTB=Local_u8_Value; break;
	case C: PORTC=Local_u8_Value; break;
	case D: PORTD=Local_u8_Value; break;
	default:                          break;
	}
}

uint8_t   M_Dio_getPortValue(uint8_t Local_u8_Port)
{
	uint8_t Value=0;
	switch(Local_u8_Port)
	{
	case A:Value=PORTA; break;
	case B:Value=PORTB; break;
	case C:Value=PORTC; break;
	case D:Value=PORTD; break;
	default:            break;
	}
	return Value;
}

uint8_t M_Dio_getPinValue(uint8_t Local_u8_Num)
{
	uint8_t Local_u8_Pin =Local_u8_Num %10;
	uint8_t Local_u8_Port =Local_u8_Num /10;
	uint8_t Local_u8_PinReading =0;
	switch(Local_u8_Port)
	{
	case 1:Local_u8_PinReading=GetBit(PINA,Local_u8_Pin);  break;
	case 2:Local_u8_PinReading=GetBit(PINB,Local_u8_Pin);  break;
	case 3:Local_u8_PinReading=GetBit(PINC,Local_u8_Pin);  break;
	case 4:Local_u8_PinReading=GetBit(PIND,Local_u8_Pin);  break;
	default:                                               break;

	}
	return Local_u8_PinReading;
}

void M_Dio_SetPullUPRes(uint8_t Local_u8_Num)
{
	uint8_t Local_u8_Pin = Local_u8_Num %10;
	uint8_t Local_u8_Port = Local_u8_Num /10;
	M_Dio_SetPinDirection(Local_u8_Num,INPUT);
	switch(Local_u8_Port)
	{
	case A: SetBit(PORTA,Local_u8_Pin); break;
	case B: SetBit(PORTB,Local_u8_Pin); break;
	case C: SetBit(PORTC,Local_u8_Pin); break;
	case D: SetBit(PORTD,Local_u8_Pin); break;
	default:                                break;
	}
}
