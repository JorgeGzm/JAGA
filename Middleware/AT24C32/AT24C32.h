/**
  * @file    AT24C32.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Jun 16, 2014
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
  * @details Bibliteca para o uso do CI AT24C32(Memoria eeprom com a capacidade de 32Kx8).
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

#ifndef AT24C32_H
    #define AT24C32_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "types/types.h"
#include "i2c/hal_i2c.h"
#include "xmemory/xmemory.h"

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

/** @brief   Configura I2C do microcontrolador para se comunicar com o CI AT24C32. */
void AT24C32_attach_i2c(uint8_t (*function_rd)(uint8_t, uint16_t, uint16_t, uint8_t*),
					    uint8_t (*function_wr)(uint8_t, uint16_t, uint16_t, uint8_t*));

/**
 * @brief   Escrita de dado na memoria eeprom AT24C32.
 * @details A funcao efetua a escrita da um byte no endereco de memoria passado. 
 * @param addr TODO documentar
 * @param count TODO documentar
 * @param data TODO documentar
 */
void AT24C32_write(uint16_t address, uint16_t count, uint8_t *data);

/**
 * @brief   Leitura de dado armazenado na memoria eeprom AT24C32.
 * @details A funcao retorna o byte lido no endereco de memoria passado.
 * @param addr TODO documentar
 * @param count TODO documentar
 * @param data TODO documentar
 */
void AT24C32_read(uint16_t address, uint16_t count, uint8_t* data);

DESCRIPTION_MEMORY AT24C32_get_description(void);

#endif  /* AT24C32_H */


