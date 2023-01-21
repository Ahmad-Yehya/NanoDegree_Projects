#include "port.h"



/* Enable PF4 (SW1) */
void SW1_Init(void)
{
		SET_BIT(SYSCTL_RCGCGPIO_REG,5);					 /* Enable Clock for PORTF */
	
    CLEAR_BIT(PORTF_GPIODIR_REG,SW1);        /* Configure PF4 as input pin */
    CLEAR_BIT(PORTF_GPIOAFSEL_REG,SW1);      /* Disable alternative function on PF4 */
    SET_BIT(PORTF_GPIOPUR_REG,SW1);  		     /* Enable pull-up on PF4 */
    SET_BIT(PORTF_GPIODEN_REG,SW1);		       /* Enable Digital I/O on PF4 */
}


/* Enable PF0 (SW2) */
void SW2_Init(void)
{
		SET_BIT(SYSCTL_RCGCGPIO_REG, 5);				 /* Enable Clock for PORTF */
	
    PORTF_GPIOLOCK_REG = 0x4C4F434B;   			 /* Unlock the PORTF_GPIOCR_REG */
    SET_BIT(PORTF_GPIOCR_REG,SW2);      		 /* Enable changes on PF0 */
	
    CLEAR_BIT(PORTF_GPIODIR_REG,SW2);     	 /* Configure PF0 as input pin */
    CLEAR_BIT(PORTF_GPIOAFSEL_REG,SW2);      /* Disable alternative function on PF0 */
    SET_BIT(PORTF_GPIOPUR_REG,SW2);      		 /* Enable pull-up on PF0 */
    SET_BIT(PORTF_GPIODEN_REG,SW2);     	   /* Enable Digital I/O on PF0 */
}

/* Enable PF1 (RED LED) */
void Led_Red_Init(void)
{
  	SET_BIT(SYSCTL_RCGCGPIO_REG, 5);				 /* Enable Clock for PORTF */
	
    SET_BIT(PORTF_GPIODIR_REG,RED_LED);      /* Configure PF1 as output pin */
    CLEAR_BIT(PORTF_GPIOAFSEL_REG,RED_LED);  /* Disable alternative function on PF1 */
    SET_BIT(PORTF_GPIOPUR_REG,RED_LED);      /* Enable Digital I/O on PF1 */
    CLEAR_BIT(PORTF_GPIODATA_REG,RED_LED);   /* Clear bit 1 in Data regsiter to turn off the led */
}

/* Get SW1 Value */
uint8_t GetPushButtonValue(uint8_t SWx)
{
	return (uint8_t)(BIT_IS_SET(PORTF_GPIODATA_REG,SWx));
}

void Turn_LED_ON(void)
{
	SET_BIT(PORTF_GPIODATA_REG,RED_LED);
}

void Turn_LED_OFF(void)
{
	CLEAR_BIT(PORTF_GPIODATA_REG,RED_LED);
}

