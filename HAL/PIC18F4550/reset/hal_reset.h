 /**
  * @file    hal_reset.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Apr 4, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Driver de Reset para o microcontrolador PIC18f4550.
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

#ifndef HAL_RESET_H
	#define	HAL_RESET_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "device/hal_device.h"
#include "types/types.h"
#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/** @brief Reinicia o microcontrolador */
PUBLIC void resetMCU(void);

/**
 * @brief TODO
 * @param senha_p1
 * @param senha_p2
 */
PUBLIC void resetMCU_device(uint16_t senha_p1, uint16_t senha_p2);

#endif	

