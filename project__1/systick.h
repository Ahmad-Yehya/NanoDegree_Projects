#include "common_macros.h"
#include "tiva_c_registers.h"
#include "stdint.h"


/***************************************************************************/
#define ENABLE_BIT				0u
#define INTERRUPT_BIT			1u


/***************************************************************************/
void SysTick_Init(void);

void SysTick_INT_Enable(void);

void SysTick_INT_Disable(void);

void SysTick_ReloadValue(uint32_t TickCount);

void SysTick_Disable(void);

