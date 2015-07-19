/**
 * @file    printf.h
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    06 de Julho de 2015
 * @version 0.1.0.0 
 * @brief   TODO
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

#include "serial.h"
#include "uart/hal_uart.h"
#include "app_control.h"
#include "lcd/lcd.h"

#ifndef configSerial_numSerial
#error "configButton_numSerial no defined in app_control.h"
#endif

/** Callback para a funcao i2c usada pela biblioteca.*/
Serial serial[configSerial_numSerial];

void serial_init(void)
{
    uint8 i;
    for(i=0;i<configSerial_numSerial;i++)
    {
        serial[i].putc = 0;
    }
}

void serial_attach(uint8 index, void (*function)(uint8))
{
    if (index < configSerial_numSerial) 
    {
        serial[index].putc = function;
    }
}

void serial_printPutc(uint8 index, uint8 c)
{
    serial->putc(c);
    //uart_putc(c);
    
}

void serial_printString(uint8 index, uint8 *fmt)
{
    uint8 c;

    while((c = *fmt) != '\0')
    {
        serial_printPutc(index, c);
        fmt++;
    }
}

void serial_printUINT16(uint8 index, uint16 value)
{
    unsigned cnt = 0;
    uint8 buffer[11];

    do
    {
        buffer[cnt] = value % 10; // Resto da divisao, sempre o primeiro digito
        value = value / 10; //exclui o digito fazendo a divisao
        cnt++; //incrementa contador
    }
    while(value); // repete ate valor n==0

    for(; cnt; cnt--)
    {
        serial_printPutc(index, buffer[cnt - 1] + '0'); //soma o valor do buffer com o valor do caracter zero 0x30.
    }
}

void serial_printINT16(uint8 index, int16 value)
{
        unsigned cnt = 0;
    uint8 flag_negativo;
    volatile uint8 buffer[11];

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
            serial_printPutc(index, 0x2D);
        }
        else
        {
            serial_printPutc(index, buffer[cnt - 1] + '0'); //soma o valor do buffer com o valor do caracter zero 0x30.
        }
    }
}

void serial_printf(uint8 index, uint8 *fmt, ...)
{
    va_list pa;
    uint8 *s, c;
    int16 d;
    uint16 u;

    va_start(pa, fmt);
    
    if(index < configSerial_numSerial)
    {
        while(*fmt != '\0')
        {
            if(*fmt == '%')
            {
                switch(*++fmt)
                {
                    case '%': serial_printPutc(index, '%');
                    break;

                    case 'c': /* uint8*/
                        c = va_arg(pa, int);
                        serial_printPutc(index, (int8)c);
                    break;

                    case 's': /* string */
                        s = va_arg(pa, uint8 *);
                        serial_printString(index, s);
                    break;

                    case 'd': /* int16*/
                        d = va_arg(pa, int);
                        serial_printINT16(index, (int16)d);
                    break;

                    case 'u': /* uint16*/
                        u = va_arg(pa, int);
                        serial_printUINT16(index, (uint16)u);
                    break;

    //                case 'f': /* float*/
    //                    f = va_arg(pa, float);
    //                    print_uint16(f);
    //                break;

                }
            }
            else
            {
                serial_printPutc(index, *fmt);
            }

            /*incrementa o ponteiro*/
            fmt++;
        }
    }
   
    va_end(pa);
}
