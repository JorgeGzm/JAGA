/**
  * @file    RFID_Card.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Jun 13, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para o uso do mudulo de leitura do Cartao RFID
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


#ifndef RFIDCARD_H
	#define RFIDCARD_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "types/types.h"
#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/**
 * @brief Informa se o dado foi validado ou nao
 */
typedef enum
{
	/**  @brief Nao ha ID para tratar*/
	VALIDATION_NONE = 0,

	/**  @brief ID de cartao nao e conhecido pelo sistema */
	VALIDATION_ERROR,

	/**  @brief ID de cartao e conhecido pelo sistema */
	VALIDATION_OK, 

}VALIDATION;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/**
 * @brief TODO documentar
 * @param data TODO documentar
 */
PUBLIC void rfid_card_isr_buff(uint8_t data);

/**
 * @brief TODO documentar
 * @param buffID TODO documentar
 */
PUBLIC VALIDATION rfid_card_validation(uint8_t buffID[]);


#endif  /* RFIDCARD_H */
