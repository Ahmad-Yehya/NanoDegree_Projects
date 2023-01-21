#include "NVIC.h"

/***************************************************************************/
volatile static unsigned long* NVIC_PRIn_REG_array[35] =
{  
 NVIC_PRI1_REG,
 NVIC_PRI2_REG,
 NVIC_PRI3_REG,
 NVIC_PRI4_REG,
 NVIC_PRI5_REG,
 NVIC_PRI6_REG,
 NVIC_PRI7_REG,
 NVIC_PRI8_REG,
 NVIC_PRI9_REG,
 NVIC_PRI10_REG,
 NVIC_PRI11_REG,
 NVIC_PRI12_REG,
 NVIC_PRI13_REG,
 NVIC_PRI14_REG,
 NVIC_PRI15_REG,
 NVIC_PRI16_REG,
 NVIC_PRI17_REG,
 NVIC_PRI18_REG,
 NVIC_PRI19_REG,
 NVIC_PRI20_REG,
 NVIC_PRI21_REG,
 NVIC_PRI22_REG,
 NVIC_PRI23_REG,
 NVIC_PRI24_REG,
 NVIC_PRI25_REG,
 NVIC_PRI26_REG,
 NVIC_PRI27_REG,
 NVIC_PRI28_REG,
 NVIC_PRI29_REG,
 NVIC_PRI30_REG,
 NVIC_PRI31_REG,
 NVIC_PRI32_REG,
 NVIC_PRI33_REG,
 NVIC_PRI34_REG
};
	
 /***************************************************************************/
void NVIC_Enable(uint8_t INT_Num)
{
	if(INT_Num <= 31)
	{
		SET_BIT(NVIC_EN0_REG,INT_Num);
	}
}

void NVIC_Disable(uint8_t INT_Num)
{
	if(INT_Num <= 31)
	{
		SET_BIT(NVIC_DIS0_REG,INT_Num);
	}
}

void NVIC_SetPriority(uint8_t INT_Num, uint8_t PriorityNum)
{	
	uint8_t PRIn = INT_Num / 4;
	
	if(INT_Num == (4*PRIn))
	{
		*NVIC_PRIn_REG_array[PRIn] |= ((unsigned long)PriorityNum << 5ul);
	}
	else if(INT_Num == ((4*PRIn)+1))
	{
		*NVIC_PRIn_REG_array[PRIn] |= ((unsigned long)PriorityNum << 13ul);
	}
	else if(INT_Num == ((4*PRIn)+2))
	{
		*NVIC_PRIn_REG_array[PRIn] |= ((unsigned long)PriorityNum << 21ul);
	}
	else if(INT_Num == ((4*PRIn)+3))
	{
		*NVIC_PRIn_REG_array[PRIn] |= ((unsigned long)PriorityNum << 29ul);
	}
}
