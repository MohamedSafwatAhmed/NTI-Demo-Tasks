/*
 * Lcd.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Safwat
 */

#include "Lcd.h"

void H_Lcd_WriteCommand(uint8_t Local_u8_Command)
{
	M_Dio_SetPinValue(RS,LOW);
	Lcd_Data_Port =(((Local_u8_Command >>4)+0x08) & 0x17) | (Lcd_Data_Port &0xE8);
	M_Dio_SetPinValue(EN,HIGH);
	_delay_ms(1);
	M_Dio_SetPinValue(EN,LOW);
	_delay_ms(1);
	Lcd_Data_Port = (((Local_u8_Command & 0x0F)+0x08) &0x17) | (Lcd_Data_Port &0xE8);
	M_Dio_SetPinValue(EN,HIGH);
	_delay_ms(1);
	M_Dio_SetPinValue(EN,LOW);
	_delay_ms(5);
}
void H_Lcd_Init(void)
{

	M_Dio_SetPinDirection(RS,OUTPUT);
	M_Dio_SetPinDirection(EN,OUTPUT);
	M_Dio_SetPinDirection(D4,OUTPUT);
	M_Dio_SetPinDirection(D5,OUTPUT);
	M_Dio_SetPinDirection(D6,OUTPUT);
	M_Dio_SetPinDirection(D7,OUTPUT);
	_delay_ms(1000);
	H_Lcd_WriteCommand(Lcd_4_Bit_Mode_1);
	H_Lcd_WriteCommand(Lcd_4_Bit_Mode_2);
	H_Lcd_WriteCommand(Lcd_4_Bit_Mode_3);
	H_Lcd_WriteCommand(Lcd_Display_On_Cursor_off);
	H_Lcd_WriteCommand(Lcd_Clear);
	H_Lcd_WriteCommand(Lcd_Return_Home);
}

void H_Lcd_WriteCharacter(uint8_t Local_u8_Character)
{
	M_Dio_SetPinValue(RS,HIGH);
	Lcd_Data_Port =(((Local_u8_Character >>4)+0x08) & 0x17) | (Lcd_Data_Port &0xE8);
	M_Dio_SetPinValue(EN,HIGH);
	_delay_ms(1);
	M_Dio_SetPinValue(EN,LOW);
	_delay_ms(1);
	M_Dio_SetPinValue(RS,HIGH);
	Lcd_Data_Port =(((Local_u8_Character & 0x0F)+0x08) &0x17) | (Lcd_Data_Port &0xE8);
	M_Dio_SetPinValue(EN,HIGH);
	_delay_ms(1);
	M_Dio_SetPinValue(EN,LOW);
	_delay_ms(5);

}

void H_Lcd_WriteString(uint8_t* Local_u8_Ptr)
{
	uint8_t Local_u8_Counter=0;
	while(Local_u8_Ptr[Local_u8_Counter] !=Null_)
	{
		H_Lcd_WriteCharacter(Local_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter ++;
	}
}
void H_Lcd_Clr(void)
{
	H_Lcd_WriteCommand(Lcd_Clear);
}
void H_Lcd_WriteNumber(sint32_t Local_s32_Number)
{
	uint8_t Local_u8_Arr [10] = {0};
	sint8_t Local_s8_Counter  = 0;
	uint8_t Local_u8_Digit    = 0;
	if(Local_s32_Number == 0)
	{
		H_Lcd_WriteCharacter('0');
	}
	else
	{
		if(Local_s32_Number < 0)
		{
			H_Lcd_WriteCharacter('-');
			Local_s32_Number = Local_s32_Number * -1;
		}
		while(Local_s32_Number != 0)
		{
			Local_u8_Digit = Local_s32_Number % 10;
			Local_u8_Arr[Local_s8_Counter] = Local_u8_Digit;
			Local_s8_Counter++;
			Local_s32_Number = Local_s32_Number / 10;
		}
		Local_s8_Counter--;
		while(Local_s8_Counter >= 0)
		{
			H_Lcd_WriteCharacter(Local_u8_Arr[Local_s8_Counter] + 48);
			Local_s8_Counter--;
		}
	}
}
void H_Lcd_GoTO(uint8_t Local_u8_Row,uint8_t Local_u8_Col)
{
	  uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};  // Row offset values for a 4x20 LCD

	    // Calculate the offset for the specified row
	    uint8_t offset = Local_u8_Col + row_offsets[Local_u8_Row];

	    // Set the DDRAM address to move the cursor
	    H_Lcd_WriteCommand(0x80 | offset);
}
