#include "port.h"
#include "NVIC.h"
#include "systick.h"
#include "tiva_c_it.h"
#include <stdint.h>

/* 0x40000000,0x400FFFFF >>> to use simulator */
/***************************************************************************/

#define MAX_ON_TIME							10u		/* 10 Seconds Max LED ON Time */
#define MAX_OFF_TIME						10u		/* 10 Seconds Max LED OFF Time */


static uint8_t ON_Time = 1;					/* Minimum 1-Second */
static uint8_t OFF_Time = 1;				/* Minimum 1-Second */
static uint8_t TickCount = 0;				/* Tick Counter     */


void SysTick_Handler_CallBack(void);


int main(void)
{
	Enable_Interrupts();
	NVIC_Enable(SYSTICK_INTERRUPT_NUM);
	NVIC_SetPriority(SYSTICK_INTERRUPT_NUM, 1);
	
	SW1_Init();
	SW2_Init();
	Led_Red_Init();
		
	SysTick_Handler_Register_CallBack(SysTick_Handler_CallBack);
	
	SysTick_Init();

	while(1)
	{
		if(GetPushButtonValue(SW1) == 1)
		{
			if(ON_Time >= MAX_ON_TIME)
				ON_Time = 1;
			else ON_Time++;
		}
		

		
		if(GetPushButtonValue(SW2) == 1)
		{
			if(OFF_Time >= MAX_OFF_TIME)
				OFF_Time = 1;
			else OFF_Time++;
		}

	}
}

void SysTick_Handler_CallBack(void)
{
	TickCount++;
	
	if(TickCount <= ON_Time)
		Turn_LED_ON();
	else if(TickCount > ON_Time && TickCount <= (ON_Time+OFF_Time))
		Turn_LED_OFF();
	else if(TickCount > (ON_Time+OFF_Time))
	{
		Turn_LED_ON();
		TickCount = 1;
	}
}
