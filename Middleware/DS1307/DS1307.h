/**
  * @file    DS1307.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
  * @details Esta biblioca faz o uso da comunicacao I2C para a traca de dados com o CI.
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

#ifndef DS1307_H
    #define DS1307_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "i2c/hal_i2c.h"
#include "xtime/xtime.h"
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

/**
 * @brief TODO Documentar.
 * @param function_rd
 * @param function_wr
 */
//void DS1307_attach_i2c(uint8_t (*function_rd)(), uint8_t (*function_wr)());
void DS1307_attach_i2c(uint8_t (*function_rd)(uint8_t, uint8_t, uint16_t, uint8_t*),
					   uint8_t (*function_wr)(uint8_t, uint8_t, uint16_t, uint8_t*));

/**
 * @brief TODO Documentar. 
 * @param data_time
 */
void DS1307_write(DataTime data_time);

/**
 * @brief Funcao para ler os dados do CI RTC e carregar na estrutura RTC
 * @param data_time
 */
void DS1307_read(DataTime *data_time);

/**
 * @brief Os dados sao perdidos apos a interrup��o da fonte de energia.
 * @param addr Range 0x08 to 0x3F
 * @param count
 * @param data
 * @return 
 */
uint8_t DS1307_sram_write(uint8_t addr, uint16_t count, uint8_t* data);

/**
 * @brief Os dados sao perdidos apos a interrup��o da fonte de energia.
 * @param addr Range 0x08 to 0x3F
 * @param count
 * @param data
 * @return 
 */
uint8_t DS1307_sram_read(uint8_t addr, uint16_t count, uint8_t* data);

DESCRIPTION_MEMORY DS1307_get_description(void);

#endif
