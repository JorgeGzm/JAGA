/**
  * @file    xprintf.c
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

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "xprintf.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

/**
 * @brief Envia uma string pela UART
 * @param index TODO documentar
 * @param fmt pinteiro para a string que sera enviada.
 */
void xprint_string(void (*func)(uint8_t), const uint8_t *fmt);

/**
 * @brief Envia uma variavel unsigned int pela UART
 * @param index TODO documentar
 * @param value valor que sera enviado
 */
void xprint_UINT16(void (*func)(uint8_t), uint16_t value);

/**
 * @brief Envia uma variavel int pela UART
 * @param index TODO documentar
 * @param value TODO documentar
 */
void xprint_INT16(void (*func)(uint8_t), int16_t value);

//==============================================================================
// SOURCE CODE
//==============================================================================

void xprint_putc(void (*func)(uint8_t), uint8_t c)
{
  	func(c);
}

void xprint_string(void (*func)(uint8_t), const uint8_t *fmt)
{
    uint8_t c;

    while((c = *fmt) != '\0')
    {
        xprint_putc(func, c);
        fmt++;
    }
}

void xprint_UINT16(void (*func)(uint8_t), uint16_t value)
{
    unsigned cnt = 0;
    uint8_t buffer[11];

    do
    {
        buffer[cnt] = value % 10; // Resto da divisao, sempre o primeiro digito
        value = value / 10; //exclui o digito fazendo a divisao
        cnt++; //incrementa contador
    }
    while(value); // repete ate valor n==0

    for(; cnt; cnt--)
    {
        xprint_putc(func, buffer[cnt - 1] + '0'); //soma o valor do buffer com o valor do caracter zero 0x30.
    }
}

void xprint_INT16(void (*func)(uint8_t), int16_t value)
{
	unsigned cnt = 0;
    uint8_t flag_negativo;
    volatile uint8_t buffer[11];

    flag_negativo = 0;

    if(value < 0)
    {
        value = -value;
        flag_negativo = 1;
    }
    
    do
    {
        buffer[cnt] = value % 10; // Resto da divisao, sempre o primeiro digito
        value = value / 10; //exclui o digito fazendo a divisao
        cnt++; //incrementa contador
    }
    while(value); // repete ate valor n==0

    if(flag_negativo)
    {
        //cnt++;
        buffer[++cnt] = 0x2D;
    }

    for(; cnt; cnt--)
    {
        if(buffer[cnt] == 0x2D)
        {
            xprint_putc(func, 0x2D);
        }
        else
        {
            xprint_putc(func, buffer[cnt - 1] + '0'); //soma o valor do buffer com o valor do caracter zero 0x30.
        }
    }
}

void xprintf(void (*func)(uint8_t), const uint8_t *fmt, ...)
{
    va_list pa;
    uint8_t *s, c;
    int16_t d;
    uint16_t u;

    va_start(pa, fmt);
    
	//while(*fmt != '\0')
	while(*fmt)
	{
		if(*fmt == '%')
		{
			switch(*++fmt)
			{
				case '%': //XXX Bug aqui
                    xprint_putc(func, '%');
				break;

				case 'c': /* uint8*/
					c = va_arg(pa, int);
					xprint_putc(func, (int8_t)c);
				break;

				case 's': /* string */
					s = va_arg(pa, uint8_t *);
					xprint_string(func, s);
				break;

				case 'd': /* int16*/
					d = va_arg(pa, int);
					xprint_INT16(func, (int16_t)d);
				break;

				case 'u': /* uint16*/
					u = va_arg(pa, int);
					xprint_UINT16(func, (uint16_t)u);
				break;

//                case 'f': /* float*/
//                    f = va_arg(pa, float);
//                    xprint_float(f);
//                break;

			}
		}
		else
		{
			xprint_putc(func, *fmt);
		}

		/*incrementa o ponteiro*/
		fmt++;
	}

   
    va_end(pa);
}
