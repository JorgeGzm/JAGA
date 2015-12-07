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

#ifdef configSteps_Num
	#error "configSteps_Num no defined in app_control.h"
#else
	#define configSteps_Num 2 //Defaul Value
#endif

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

typedef struct
{
	regPin control1;
	regPin control2;
}Strep_Driver;
//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/**@brief TODO */
Strep_Driver step[configSteps_Num];

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

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
