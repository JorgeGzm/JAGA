/**
  * @file    xmemory.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Dez 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para descrever memorias eeprom, flash, etc.
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

#ifndef XMEMORY_H
	#define	XMEMORY_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

typedef struct
{
	uint16_t init;
	uint16_t store;
	uint8_t str_devide[10];

}DESCRIPTION_MEMORY;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

#endif	
