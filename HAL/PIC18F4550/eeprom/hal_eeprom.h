/**
  * @file    hal_eeprom.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 6, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Driver para a memoria eeprom para o microcontrolador PIC18f4550.
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

#ifndef HAL_EEPROM_H
    #define HAL_EEPROM_H

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

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/**
 * @brief Realiza a leitura na memoria EEPROM do pic18f4550.
 * @param address Endereco onde o dado sera gravado.
 * @return Retorna o dado lido no endereço passado
 */
uint8_t eeprom_rd(uint8_t address);

/**
 * @brief  Escrita na memoria EEPROM do pic18f4550
 * @param address Endereco onde o dado se encontra. Range: 0 - 255.
 * @param data Dado a ser gravado.
 */
void eeprom_wr(uint8_t address, uint8_t data);

#endif	
