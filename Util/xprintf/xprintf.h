/**
  * @file    xprintf.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Set 26, 2015
  * @version 0.2.0.0 (beta)
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

#ifndef XPRINT_H
	#define	XPRINT_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include <stdarg.h>

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
 * @brief Emvia strings pela serial.
 * Ex:
 * uart_printf("string = %s; Caracter = %c, intero: %d; unsigned: %u\n", "Bolivia", 'J', -3156, 65532);
 * uart_printf((uint8 *)"Ola mundo!\n");
 * %d   Numero decimal inteiro (int)
 * %u   Numero decimal natural (unsigned int)
 * %c   Caractere: imprime o caractere que tem o c�digo ASCII correspondente ao valor dado.
 * %s   Sequencia de caracteres (string, em ingles).
 * @param index TODO documentar
 * @param fmt TODO documentar
 * @param ... TODO documentar
 */
void xprintf(void (*func)(uint8_t), const uint8_t *fmt, ...);


#endif	/* PRINT_H */

