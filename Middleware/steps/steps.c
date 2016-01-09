/**
  * @file    steps.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Set 20, 2015
  * @version 0.2.0.0 (beta)
  * @brief   Bibliteoca para o uso das rodas do carrinho
  * @details
  * @section LICENSE
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License as
  * published by the Free Software Foundation; either version 2 of
  * the License, or (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful, but
  * WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  * General Public License for more details at
  * http://www.gnu.org/copyleft/gpl.html
*/

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "steps.h"
#include "gpio/hal_gpio.h"
#include "sys_uart.h"
#include "xprintf/xprintf.h"
#include "leds/leds.h"

#ifdef configSteps_Num
	#error "configSteps_Num no defined in app_control.h"
#else
	#define configSteps_Num 2 //Defaul Value
#endif




//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

#define MAX_BUFFER     7

/** @brief TODO documentar */
#define START_CARACTER '#'

/** @brief TODO documentar */
#define END_CARACTER   '\n'

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

typedef struct
{
	regPin control1;
	regPin control2;
}Strep_Driver;

typedef enum
{
    ST_START,
    ST_MSG,
    ST_END
}COMAND_STATES;

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/**@brief TODO */
Strep_Driver step[configSteps_Num];

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

uint8_t buffer_protocol[MAX_BUFFER];

uint8_t protocol_ready = 0;

//==============================================================================
// SOURCE CODE
//==============================================================================

void step_protocol_commads_RAFA(uint8_t data)
{
	static int ind = 0;
	static COMAND_STATES status = ST_START;

	switch (status)
	{

		case ST_START:
			if (data == START_CARACTER)
			{
				ind = 0;
				buffer_protocol[ind++] = data;
				status = ST_MSG;

			}
			break;

		case ST_MSG:
			buffer_protocol[ind++] = data;
			if (ind == MAX_BUFFER - 1)
			{
				status = ST_END;
			}
			break;

		case ST_END:
			if (data == END_CARACTER)
			{
				buffer_protocol[ind++] = data;

				//xprintf(callback_uart_putc, (uint8_t *)"%s", &buffer_protocol[0]);
				protocol_ready = 1;
			}
			status = ST_START;
			break;
	}
}

void step_trata()
{
	if(protocol_ready)
	{
		protocol_ready = 0;
		xprintf(callback_uart_putc, (uint8_t *)"%s",buffer_protocol);
	}
}

void step_init(void)
{
	uint8_t i;
	for(i=0;i<configSteps_Num;i++)
	{
		step[i].control1.out = 0;
		step[i].control1.pin = 0;
		step[i].control2.out = 0;
		step[i].control2.pin = 0;
	}
}

void step_driver_attach(uint8_t index, regGPIO step_1A, regGPIO step_1B)
{
    GPIO_regPin_attach(&step[index].control1, &step_1A);
	GPIO_regPin_attach(&step[index].control2, &step_1B);
}

void step_action(uint8_t index, STEP_DIRECTION action) //), anglo, aceleracao)
{
	switch(action)
	{
	case STOP:

		GPIO_regPin_outputLow(&step[index].control1);
		GPIO_regPin_outputLow(&step[index].control2);

		break;

	case BACK:

		GPIO_regPin_outputHigh(&step[index].control1);
		GPIO_regPin_outputLow(&step[index].control2);

		break;

	case GO:

		GPIO_regPin_outputLow(&step[index].control1);
		GPIO_regPin_outputHigh(&step[index].control2);

		break;
	}
}

void step_protocol_commads(uint8_t action) //), anglo, aceleracao)
{

	switch(action)
	{
	case C_STOP:

		leds_set(LD1G, LED_OFF);
		leds_set(LD2G, LED_BLINK_FAST);

		GPIO_regPin_outputLow(&step[0].control1);
		GPIO_regPin_outputLow(&step[0].control2);

		GPIO_regPin_outputLow(&step[1].control1);
		GPIO_regPin_outputLow(&step[1].control2);

		break;

	case C_BACK:

		leds_set(LD1G, LED_BLINK_SLOW);
		leds_set(LD2G, LED_OFF);

		GPIO_regPin_outputHigh(&step[0].control1);
		GPIO_regPin_outputLow(&step[0].control2);

		GPIO_regPin_outputHigh(&step[1].control1);
		GPIO_regPin_outputLow(&step[1].control2);

		break;

	case C_GO:

		leds_set(LD1G, LED_OFF);
		leds_set(LD2G, LED_OFF);

		GPIO_regPin_outputLow(&step[0].control1);
		GPIO_regPin_outputHigh(&step[0].control2);

		GPIO_regPin_outputLow(&step[1].control1);
		GPIO_regPin_outputHigh(&step[1].control2);

		break;

	case C_LEFT:

			leds_set(LD1G, LED_OFF);
			leds_set(LD2G, LED_BLINK_FAST);

			GPIO_regPin_outputLow(&step[0].control1);
			GPIO_regPin_outputLow(&step[0].control2);

			GPIO_regPin_outputLow(&step[1].control1);
			GPIO_regPin_outputHigh(&step[1].control2);

			break;


	case C_RIGHT:

			leds_set(LD1G, LED_OFF);
			leds_set(LD2G, LED_BLINK_FAST);

			GPIO_regPin_outputLow(&step[0].control1);
			GPIO_regPin_outputHigh(&step[0].control2);

			GPIO_regPin_outputLow(&step[1].control1);
			GPIO_regPin_outputLow(&step[1].control2);

			break;
	}

}
