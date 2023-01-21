#ifndef TIVA_C_REGISTERS
#define TIVA_C_REGISTERS

/*****************************************************************************
RCC Register
*****************************************************************************/
#define SYSCTL_RCGCGPIO_REG        (*((volatile unsigned long *)0x400FE608))

/*****************************************************************************
SysTick timer Registers
*****************************************************************************/
#define SYSTIC_STCTRL_REG           (*((volatile unsigned long *)0xE000E010))
#define SYSTIC_STRELOAD_REG        (*((volatile unsigned long *)0xE000E014))
#define SYSTIC_STCURRENT_REG       (*((volatile unsigned long *)0xE000E018))
	
/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define PORTF_GPIODATA_REG       (*((volatile unsigned long *)0x400253FC))
#define PORTF_GPIODIR_REG        (*((volatile unsigned long *)0x40025400))
#define PORTF_GPIOAFSEL_REG      (*((volatile unsigned long *)0x40025420))
#define PORTF_GPIOPUR_REG        (*((volatile unsigned long *)0x40025510))
#define PORTF_GPIOPDR_REG        (*((volatile unsigned long *)0x40025514))
#define PORTF_GPIODEN_REG        (*((volatile unsigned long *)0x4002551C))
#define PORTF_GPIOLOCK_REG       (*((volatile unsigned long *)0x40025520))
#define PORTF_GPIOCR_REG         (*((volatile unsigned long *)0x40025524))
#define PORTF_GPIOPCTL_REG       (*((volatile unsigned long *)0x4002552C))

/*****************************************************************************
NVIC Registers
*****************************************************************************/

#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile unsigned long *)0xE000E110))
	
#define NVIC_DIS0_REG             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile unsigned long *)0xE000E190))
	
	
#endif
