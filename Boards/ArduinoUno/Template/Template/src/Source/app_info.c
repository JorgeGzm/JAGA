/**
  * @file    app_info.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 10, 2015
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

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "app_info.h"
#include <stdint.h>
#include "types/types.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** @brief Codigo do equipamento*/
UWord id_device;

/** @brief Versao do Firmware*/
uint16_t version;

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

void info_init(void)
{
    version = VERSION_FIRMWARE;
    id_device.value = ID_DEVICE;   
}
