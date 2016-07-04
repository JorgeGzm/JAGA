 /**
  * @file    hal_delay.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 21, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Driver de Delay para o microcontrolador Arduino Uno(ATMEGA328P)
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

#ifndef HAL_DELAY_H
    #define HAL_DELAY_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "sys_mcu.h" 
#include "device/hal_device.h"
#include <util/delay.h>

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

/** @brief Gera um delay de mili-segundo.*/
#define Delay_ms(x) _delay_ms(x)

/** @brief Gera um delay de micro-segundo.*/
#define Delay_us(x) _delay_us(x)

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

#endif	
