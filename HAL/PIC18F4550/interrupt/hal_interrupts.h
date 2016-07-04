/**
  * @file    hal_interrupts.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jan 15, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Driver interrupts para o microcontrolador PIC18f4550.
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

#ifndef HAL_INTERRUPTS_H
	#define	HAL_INTERRUPTS_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

/** @brief TODO */
#define DISABLE     0
/** @brief TODO */
#define ENABLE      1

/** @brief TODO */
#define INTERRUPT_DISABLE   0
/** @brief TODO */
#define INTERRUPT_ENABLE    1

/** @brief TODO */
#define LOW_PRIORITY    0
/** @brief TODO */
#define HIGH_PRIORITY   1

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/** @berif TODO */
PUBLIC void interrupt_init(void);

#endif	
