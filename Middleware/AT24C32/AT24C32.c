/**
  * @file    AT24C32.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Jun 16, 2014
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
  * @details  Codigo em C da biblioteca lib_AT24C32.c
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

#include "AT24C32.h"
#include <stddef.h>
#include <stdint.h>

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

#define AT24C32_ADDRESS     0xA0

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

PRIVATE DESCRIPTION_MEMORY AT24C32_description = { 0, 4096, "AT24C32"};

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

/** @brief Callback para a funcao de leitura da i2c usada pela biblioteca.*/
PRIVATE uint8_t (*AT24C32_i2c_read)(uint8_t, uint16_t, uint16_t, uint8_t*);

/** @brief Callback para a funcao de escrita da i2c usada pela biblioteca.*/
PRIVATE uint8_t (*AT24C32_i2c_write)(uint8_t, uint16_t, uint16_t, uint8_t*);


//==============================================================================
// SOURCE CODE
//==============================================================================

PUBLIC void AT24C32_attach_i2c(uint8_t (*function_rd)(uint8_t, uint16_t, uint16_t, uint8_t*), uint8_t (*function_wr)(uint8_t, uint16_t, uint16_t, uint8_t*))
{
	AT24C32_i2c_read = function_rd;
    AT24C32_i2c_write = function_wr;	
}

PUBLIC void AT24C32_read(uint16_t addr, uint16_t count, uint8_t* data)
{    
	if(addr >= AT24C32_description.init && addr <= AT24C32_description.store && AT24C32_i2c_read != NULL)
    {        
        AT24C32_i2c_read(AT24C32_ADDRESS, addr, count, data);        
    }    
}

PUBLIC void AT24C32_write(uint16_t addr, uint16_t count, uint8_t* data)
{
	if(addr >= AT24C32_description.init && addr <= AT24C32_description.store && AT24C32_i2c_write != NULL)
    {        
        AT24C32_i2c_write(AT24C32_ADDRESS, addr, count, data);        
    }    
}

PUBLIC DESCRIPTION_MEMORY AT24C32_get_description(void)
{
	return AT24C32_description;
}

