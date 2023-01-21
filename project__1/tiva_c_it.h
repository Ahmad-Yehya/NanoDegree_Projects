#include "common_macros.h"
#include <stdint.h>
#include <stddef.h>


void SysTick_Handler(void);

void SysTick_Handler_Register_CallBack(void(*Ptr2F)(void));
