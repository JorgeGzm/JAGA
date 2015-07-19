/**
 * @file   	print.h
 * @author 	Jorge Guzman (jorge.gzm@gmail.com)
 * @date 	06 de Julho de 2015
 * @version 0.1.0.0 
 * @brief   Bibliteca para o uso de calculo de CRC.
 * @details ...
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
 *
 * @section DESCRIPTION
 */

#ifndef PRINT_H
#define	PRINT_H

#include "vars/vars.h"
#include "types/types.h"
#include <stdarg.h>

typedef struct __Serial
{
    void (*putc)(uint8);
}Serial;

/**
 * @brief TODO
 */
void serial_init(void);

/**
 * @brief TODO
 * @param index TODO
 * @param function TODO
 */
void serial_attach(uint8 index, void (*function)(uint8));

/**
 * Emvia strings pela serial.
 * Ex:
 * uart_printf("string = %s; Caracter = %c, intero: %d; unsigned: %u\n", "Bolivia", 'J', -3156, 65532);
 * uart_printf((uint8 *)"Ola mundo!\n");
 * %d   Numero decimal inteiro (int)
 * %u   Numero decimal natural (unsigned int)
 * %c   Caractere: imprime o caractere que tem o c�digo ASCII correspondente ao valor dado.
 * %s   Sequencia de caracteres (string, em ingles).
 * @param index TODO
 * @param fmt
 * @param ...
 */
void serial_printf(uint8 index, uint8 *fmt, ...);

/**
 * Envia uma string pela UART
 * @param index TODO
 * @param fmt pinteiro para a string que sera enviada.
 */
void serial_printString(uint8 index, uint8 *fmt);

/**
 * Envia uma variavel unsigned int pela UART
 * @param index TODO
 * @param value valor que sera enviado
 */
void serial_printUINT16(uint8 index, uint16 value);

/**
 * Envia uma variavel int pela UART
 * @param index TODO
 * @param value
 */
void serial_printINT16(uint8 index, int16 value);


#endif	/* PRINT_H */

