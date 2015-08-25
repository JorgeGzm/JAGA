/**
  * @file    serial.h
  * @author  Alexandre Bader; Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 6, 2015
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

#ifndef PRINT_H
	#define	PRINT_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "vars/vars.h"
#include "types/types.h"
#include <stdarg.h>

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

/** @brief TODO */
typedef struct 
{
    /** @brief TODO documentar*/
    void (*putc)(uint8);
}Serial;

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

/**
 * @brief TODO documentar
 */
void serial_init(void);

/**
 * @brief TODO documentar
 * @param index TODO documentar
 * @param function TODO documentar
 */
void serial_attach(uint8 index, void (*function)(uint8));

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
void serial_printf(uint8 index, uint8 *fmt, ...);

/**
 * @brief Envia uma string pela UART
 * @param index TODO documentar
 * @param fmt pinteiro para a string que sera enviada.
 */
void serial_print_string(uint8 index, uint8 *fmt);

/**
 * @brief Envia uma variavel unsigned int pela UART
 * @param index TODO documentar
 * @param value valor que sera enviado
 */
void serial_print_UINT16(uint8 index, uint16 value);

/**
 * @brief Envia uma variavel int pela UART
 * @param index TODO documentar
 * @param value TODO documentar
 */
void serial_print_INT16(uint8 index, int16 value);

#endif	/* PRINT_H */

