/**
  * @file    bitwise.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Dez 09, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para manipular bits.
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

#ifndef BITWISE_H
	#define	BITWISE_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

/**
 * @brief coloca em 1 o bit x da variavel byte.
 * @details Exemplo:  set_bit(PORTD, 5); \n
 * Resultado: PORTD = 0b00010000
 */
#define	set_bit(value,bit_x)	(value |= (1 << bit_x))

/**
 * @brief coloca em 0 no bit_x da variavel variavel byte.
 * @details Exemplo:  lr_bit(PORTD, 5);     \n
 * Resultado: PORTD = 0b00000000
 */
#define	clr_bit(value,bit_x)	(value &= ~(1 << bit_x))

/**
* @brief troca o estado logico do bit x da variavel bytex.
* @details Exemplo:   toggle_bit(PORTD, 5); \n
* Resultado: PORTD = 0b00000000 ou PORTD = 0b00010000
*/
#define toggle_bit(value,bit_x)     (value ^= (1 << bit_x))

/**
 * @brief retorna 0 ou !0 conforme leitura do bit.
 * @details Exemplo:   tst_bit(PORTD, 5);   \n
 * Resultado: x = 0 ou x = 32
 */
#define tst_bit(value,bit_x)        (value & (1 << bit_x))

/**
 * @brief retorna 0 ou 1 conforme leitura do bit. Range(0-7).
 * @details Exemplo:   tst_bit_bool(PORTD, 5);  \n
 * Resultado: x = 0 ou x = 1
 */
#define tst_bit_bool(value,bit_x) 	((value & (1 << bit_x)) >> bit_x)

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

#endif	
