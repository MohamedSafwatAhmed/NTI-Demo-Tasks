/*
 * Calculator.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Mohamed Safwat
 */

/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mohamed Safwat
 */
/*
#define F_CPU 16000000UL
#include <util/delay.h>
#include "Dio.h"
#include "StdTypes.h"
#include "BitMath.h"
#include <avr\io.h>
#include "Keypad.h"
#include "Lcd.h"
int main(void)
{
	int number1=0,number2=0;
	char operand=0;
	H_KeyPad_Init();
	H_Lcd_Init();
	int x=0;
	char digit[4];
	int i=0;
	while(1)
	{
		x=H_KeyPad_Read();
		H_Lcd_WriteString("Enter First:");
		while(i !=3){
			if(x==0)  {continue; }//Not pressed
			else if (x == 'C')
			{
				H_Lcd_WriteCommand(Lcd_Shift_Left); //
				H_Lcd_WriteCharacter(' '); //to be modified
				i--;
			}
			else
			{
				H_Lcd_WriteNumber(x-48);
				digit[i] =x-48;
				i++;
			}

			number1=digit[0]+digit[1]*10+digit[2]*100+digit[3]*1000;
		}
		H_Lcd_GoTO(1,0);
		H_Lcd_WriteString("operation:");
		while (x ==0);
		operand=x;
		H_Lcd_WriteCharacter(x);

		H_Lcd_GoTO(2,0);
		H_Lcd_WriteString("Enter Second:");
		i=0;
		while(i !=3){
			if(x==0)  {continue; }//Not pressed
			else if (x == 'C')
			{
				H_Lcd_WriteCommand(Lcd_Shift_Left); //
				H_Lcd_WriteCharacter(' '); //to be modified
				i--;
			}
			else
			{
				H_Lcd_WriteNumber(x-48);
				digit[i] =x-48;
				i++;
			}

			number2=digit[0]+digit[1]*10+digit[2]*100+digit[3]*1000;
		}
		while(x != '=');
		H_Lcd_GoTO(2,0);
		H_Lcd_WriteString("Result:");
		switch(operand)
		{
		case '+': H_Lcd_WriteNumber(number1+number2); break;
		case '-': H_Lcd_WriteNumber(number1-number2); break;
		case '*': H_Lcd_WriteNumber(number1*number2); break;
		case '/':
			if(number2 ==0)
			{
				H_Lcd_WriteString("Error");
			}
			else
			{
				H_Lcd_WriteNumber(number1/number2);
			}
			break;
		default:   break;

		}

	}

}
*/






