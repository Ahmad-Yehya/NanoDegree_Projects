#include "tiva_c_registers.h"
#include "common_macros.h"
#include <stdint.h>

/***************************************************************************/
#define SW2						0                   	/* PF0 bit number */
#define RED_LED				1                   	/* PF1 bit number */ 
#define SW1						4                   	/* PF4 bit number */


/***************************************************************************/
void SW1_Init(void);

void SW2_Init(void);

void Led_Red_Init(void);

uint8_t GetPushButtonValue(uint8_t SWx);

void Turn_LED_ON(void);

void Turn_LED_OFF(void);

