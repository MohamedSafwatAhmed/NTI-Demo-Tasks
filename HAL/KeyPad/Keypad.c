/*
 * Keypad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Safwat
 */
#include "KeyPad.h"

void H_KeyPad_Init(void)
{
	//set Rows as Output
	M_Dio_SetPinDirection(Keypad_Row1,OUTPUT);
	M_Dio_SetPinDirection(Keypad_Row2,OUTPUT);
	M_Dio_SetPinDirection(Keypad_Row3,OUTPUT);
	M_Dio_SetPinDirection(Keypad_Row4,OUTPUT);
    //set Columns as input
	M_Dio_SetPinDirection(Keypad_Col1,INPUT);
	M_Dio_SetPinDirection(Keypad_Col2,INPUT);
	M_Dio_SetPinDirection(Keypad_Col3,INPUT);
	M_Dio_SetPinDirection(Keypad_Col4,INPUT);

	//set High level voltage on ROWs
	M_Dio_SetPinValue(Keypad_Row1,HIGH);
	M_Dio_SetPinValue(Keypad_Row2,HIGH);
	M_Dio_SetPinValue(Keypad_Row3,HIGH);
	M_Dio_SetPinValue(Keypad_Row4,HIGH);
}

uint8_t H_KeyPad_Read(void)
{
	#if   KEYPAD_MODE       ==      TYPE_1
	uint8_t Local_u8_Arr[4][4] =
	{{ '1' , '2' , '3' , 'A' },
	{ '4' , '5' , '6' , 'B' },
	{ '7' , '8' , '9' , 'C' },
	{ '*' , '0' , '#' , 'D' }};
	#elif KEYPAD_MODE       ==      TYPE_2
	uint8_t Local_u8_Arr[4][5] =
	{{ '7' , '8' , '9' ,'0', '/' },
	{ '4' , '5' , '6' ,'0', '*' },
	{ '1' , '2' , '3' ,'0', '-' },
	{ 'C' , '0' , '=' , '0','+' }};
	#endif
	uint8_t Local_u8_Reading = KEYPAD_RELEASED;
	uint8_t Local_u8_Value   = 0;
	uint8_t Local_u8_Row = 0;
	uint8_t Local_u8_Col = 0;
	uint8_t Col=0;
	for (Local_u8_Row=Keypad_Row1;Local_u8_Row>=Keypad_Row4;Local_u8_Row--)
	{
		M_Dio_SetPinValue(Local_u8_Row,LOW);
		for (Local_u8_Col=Keypad_Col1;Local_u8_Col >= Keypad_Col4;Local_u8_Col--)
		{
			Col=Keypad_Col1 - Local_u8_Col;

			if(Local_u8_Col == PD4_Pin)
			{
              continue;
			}
			else
			{
			Local_u8_Reading = M_Dio_getPinValue(Local_u8_Col);
			if(Local_u8_Reading == KEYPAD_PRESSED)
			{
				_delay_ms(KEYPAD_DEBOUNCING_TIME);
				if(M_Dio_getPinValue(Local_u8_Col) == KEYPAD_PRESSED)
				{
					while(M_Dio_getPinValue(Local_u8_Col) == KEYPAD_PRESSED);
					Local_u8_Value =  Local_u8_Arr[Keypad_Row1 - Local_u8_Row][Col];
				}
			}
	     	}
		}
		M_Dio_SetPinValue(Local_u8_Row,HIGH);
	}
	return Local_u8_Value ;
}

