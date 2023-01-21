#include "systick.h"


/* 
 * Initialize and Enable the SystTick Timer to run using the System Clock
 * with Frequency 16Mhz and Count 1 Second 
 * and Enable the Interrupt 
 */
void SysTick_Init(void)
{
    SYSTIC_STRELOAD_REG  = 15999999;        /* Set the Reload value to count 1 Second */
    SYSTIC_STCURRENT_REG = 0;            /* Clear the Current Register value and the COUNT status bit */

    /* 
		 * Configure the SysTick Control Register 
     * 	Enable the SysTick Timer (ENABLE = 1)
     *  Enable SysTick Interrupt (INTEN = 0)
     * 	Choose the clock source to be System Clock (CLK_SRC = 1) 
		 */
    SYSTIC_STCTRL_REG   |= 0x07;
}

void SysTick_Disable(void)
{
		CLEAR_BIT(SYSTIC_STCTRL_REG,ENABLE_BIT);
}

void SysTick_ReloadValue(uint32_t TickCount)
{
		SYSTIC_STRELOAD_REG = TickCount;
}

void SysTick_INT_Enable(void)
{
		SET_BIT(SYSTIC_STCTRL_REG,INTERRUPT_BIT);
}

void SysTick_INT_Disable(void)
{
		CLEAR_BIT(SYSTIC_STCTRL_REG,INTERRUPT_BIT);
}

