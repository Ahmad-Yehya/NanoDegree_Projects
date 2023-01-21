#include "common_macros.h"
#include "tiva_c_registers.h"
#include "stdint.h"
/***************************************************************************/

#define SYSTICK_INTERRUPT_NUM				15u


#define NVIC_PRI0_REG             (((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_REG             (((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_REG             (((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_REG             (((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_REG             (((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_REG             (((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_REG             (((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_REG             (((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_REG             (((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_REG             (((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_REG            (((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_REG            (((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_REG            (((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_REG            (((volatile unsigned long *)0xE000E434))
#define NVIC_PRI14_REG            (((volatile unsigned long *)0xE000E438))
#define NVIC_PRI15_REG            (((volatile unsigned long *)0xE000E43C))
#define NVIC_PRI16_REG            (((volatile unsigned long *)0xE000E440))
#define NVIC_PRI17_REG            (((volatile unsigned long *)0xE000E444))
#define NVIC_PRI18_REG            (((volatile unsigned long *)0xE000E448))
#define NVIC_PRI19_REG            (((volatile unsigned long *)0xE000E44C))
#define NVIC_PRI20_REG            (((volatile unsigned long *)0xE000E450))
#define NVIC_PRI21_REG            (((volatile unsigned long *)0xE000E454))
#define NVIC_PRI22_REG            (((volatile unsigned long *)0xE000E458))
#define NVIC_PRI23_REG            (((volatile unsigned long *)0xE000E45C))
#define NVIC_PRI24_REG            (((volatile unsigned long *)0xE000E460))
#define NVIC_PRI25_REG            (((volatile unsigned long *)0xE000E464))
#define NVIC_PRI26_REG            (((volatile unsigned long *)0xE000E468))
#define NVIC_PRI27_REG            (((volatile unsigned long *)0xE000E46C))
#define NVIC_PRI28_REG            (((volatile unsigned long *)0xE000E470))
#define NVIC_PRI29_REG            (((volatile unsigned long *)0xE000E474))
#define NVIC_PRI30_REG            (((volatile unsigned long *)0xE000E478))
#define NVIC_PRI31_REG            (((volatile unsigned long *)0xE000E47C))
#define NVIC_PRI32_REG            (((volatile unsigned long *)0xE000E480))
#define NVIC_PRI33_REG            (((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_REG            (((volatile unsigned long *)0xE000E488))
/***************************************************************************/

/* 
 * This Macro clears the I-bit in the PRIMASK 
 * using CPS Change processor state, enable - interrupts
 */
#define Enable_Interrupts()    __asm("CPSIE I")	

/* 
 * This Macro sets the I-bit in the PRIMASK 
 * using CPS Change processor state, disenable - interrupts
 */
#define Disable_Interrupts()   __asm("CPSID I")	

/***************************************************************************/

void NVIC_Enable(uint8_t INT_Num);

void NVIC_Disable(uint8_t INT_Num);

void NVIC_SetPriority(uint8_t INT_Num, uint8_t PriorityNum);
