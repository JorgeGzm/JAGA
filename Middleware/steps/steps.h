/**
  * @file    steps.h
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

#ifndef STEPS_H_
#define STEPS_H_

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "types/types.h"
#include "gpio/hal_gpio.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================


//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/** @brief */
typedef enum
{
	STOP = 0,
	GO,
	BACK,
	LEFT,
	RIGHT
}STEP_DIRECTION;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/** @brief Limpa e inicializa o controle das rodas. */
void step_init(void);

/**
 * @brief TODO
 * @param step1
 * @param step2
 * @param step3
 * @param step4
 */
void step_driver_attach(uint8_t index, regGPIO step_1A, regGPIO step_1B);

/**
 * @brief TODO
 * @param index
 * @param action
 */
void step_action(uint8_t index, STEP_DIRECTION action);

#endif
