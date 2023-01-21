#include "tiva_c_it.h"


static void(*Ptr2SysTick_Handler_CB)(void) = NULL;

void SysTick_Handler_Register_CallBack(void(*Ptr2F)(void))
{
	if(Ptr2F != NULL)
		Ptr2SysTick_Handler_CB = Ptr2F;
}

void SysTick_Handler(void)
{
	if(Ptr2SysTick_Handler_CB != NULL)
		Ptr2SysTick_Handler_CB();
}
