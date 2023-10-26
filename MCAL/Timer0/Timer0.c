
#include "Timer0.h"
uint32_t Timer0_u32_NumOfOverFlows = 0;
uint8_t  Timer0_u8_RemTicks        = 0;
uint32_t Timer0_NumOfCompareMatch  = 0;
void (*CallBack)(void);
void M_Timer0_Init(void)
{
	#if   Timer0_Mode   ==   Normal_Mode
	ClrBit(TCCR0,3);
	ClrBit(TCCR0,6);
	SetBit(TIMSK,0);    // to enable timer0 overflow int
	#elif Timer0_Mode   ==   Ctc_Mode
	SetBit(TCCR0,3);
	ClrBit(TCCR0,6);
	SetBit(TIMSK,1);    // to enable timer0 compare match int
	#endif
	SetBit(SREG,7);     // to enable global int
}
void M_Timer0_SetTime(uint32_t Local_u8_DesiredTime)
{
	#if   Timer0_Mode   ==   Normal_Mode
	uint32_t Local_u32_TickTime        = TIMER0_PRESCALER / F_OSC;                            // result will be in micro second
	uint32_t Local_u32_Total_Ticks     = (Local_u8_DesiredTime * 1000) / Local_u32_TickTime;
	    Timer0_u32_NumOfOverFlows = Local_u32_Total_Ticks / 256;
	    Timer0_u8_RemTicks        = Local_u32_Total_Ticks % 256;
	if(Timer0_u8_RemTicks != 0)
	{
		TCNT0= 256 - Timer0_u8_RemTicks;
		Timer0_u32_NumOfOverFlows++;
	}
	#elif Timer0_Mode   ==   Ctc_Mode
	uint32_t Local_u32_TickTime        = TIMER0_PRESCALER / F_OSC;
	uint32_t Local_u32_Total_Ticks     = (Local_u8_DesiredTime * 1000) / Local_u32_TickTime;
	uint8_t  Local_u8_DevisionFactor   = 255;
	while(Local_u32_Total_Ticks % Local_u8_DevisionFactor)
	{
		Local_u8_DevisionFactor--;
	}
	    Timer0_NumOfCompareMatch  = Local_u32_Total_Ticks / Local_u8_DevisionFactor;
	OCR0                          = Local_u8_DevisionFactor - 1 ;
	#endif
}
void M_Timer0_Start(void)
{
	#if   TIMER0_PRESCALER   ==   1024
	SetBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif TIMER0_PRESCALER   ==   256
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#endif
}

void M_Timer0_Stop(void)
{
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	ClrBit(TCCR0,2);
}

void M_Timer0_SetCallBack(void (*Ptr)(void))
{
	CallBack = Ptr;
}

#if   Timer0_Mode   ==   Normal_Mode
ISR(TIMER0_OVF_vect)
{
	static uint32_t Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer0_u32_NumOfOverFlows)
	{
		CallBack();
		Local_u32_Counter = 0;
		TCNT0  =   256 - Timer0_u8_RemTicks;
	}
}
#elif Timer0_Mode   ==   Ctc_Mode
ISR(TIMER0_COMP_vect)
{
	static uint32_t Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer0_NumOfCompareMatch)
	{
		CallBack();
		Local_u32_Counter = 0;
	}
}
#endif
