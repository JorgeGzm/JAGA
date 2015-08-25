 /**
  * @file    hal_systick.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Apr 29, 2015
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
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

#ifndef HAL_SYSTICK_H
	#define	HAL_SYSTICK_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "device/hal_device.h"
#include "gpio/hal_gpio.h"
#include "vars/vars.h"
#include "types/types.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

/**
 * @brief Carregador: usa apenas os primeiros 24 bits
 * @param enable_systick
 * @param enable_interrupt
 * @param reload
*/
void systick_set_reload(uint32 enable_systick, uint32 enable_interrupt, uint32 reload);

/**
 * @brief TODO
 * @param clock TODO
 */
void systick_set_clock(uint32 clock);

#endif	

