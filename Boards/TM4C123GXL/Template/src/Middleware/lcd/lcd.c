/**
 * @file    lcd.c
 * @brief   Bibliteoca para o uso do display LCD 2x16 ou 4x20.
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    9 de Julho de 2014
 * @version 0.1.0.0 (beta) 
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

#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdarg.h>


/** Variavel de configuracao dos pinos do LCD*/
DisplayLcd display;

/** */
uint8 lcd_buffer[LCD_MAX_LINES][LCD_MAX_COLUMNS];

/** Buffer que contem a rotina de inicialização do LCD 2x16 e 4x20 */
int8 const LCD_INIT_STRING[4] =
{
    0x20 | (2 << 2), // Func set: 4-bit, 2 linhas, caracter 5x8
    0xC, // Display ligado
    1, // Limpa display
    6 // Incrementa cursor
};



void lcd_attach(regPin *pin, regGPIO *reg)
{
    //Aloca o pino para o botao
    //pin->out = reg->port;
    //pin->pin = reg->numPin;
    GPIO_pin_attach(pin, reg);

    //Configura pino do botao como entrada
    GPIO_confDir(reg, DIR_OUTPUT);
}

void lcd_init(void)
{   
    int8 i;


    GPIO_pin_low(&display.RS);
    GPIO_pin_low(&display.E);
    
    Delay_ms(15);

    for(i = 0; i < 3; i++)
    {
        lcd_send_nibble(0x03);
        
        Delay_ms(5);
    }

    lcd_send_nibble(0x02);

    for(i = 0; i < sizeof (LCD_INIT_STRING); i++)
    {
        lcd_send_byte(0, LCD_INIT_STRING[i]);
        
        Delay_ms(5);
    }

    memset((void *)lcd_buffer[0], ' ', LCD_MAX_COLUMNS);
    memset((void *)lcd_buffer[1], ' ', LCD_MAX_COLUMNS);
    memset((void *)lcd_buffer[2], ' ', LCD_MAX_COLUMNS);
    memset((void *)lcd_buffer[3], ' ', LCD_MAX_COLUMNS);
}

void lcd_send_nibble(int8 nibble)
{
    Byte aux;

    aux.value = nibble;

    //envia niblbe ao lcd
    GPIO_pin_outputBit(&display.db4, aux.bit0);
    GPIO_pin_outputBit(&display.db5, aux.bit1);
    GPIO_pin_outputBit(&display.db6, aux.bit2);
    GPIO_pin_outputBit(&display.db7, aux.bit3);

    Delay_ms(10);

    GPIO_pin_high(&display.E);

    Delay_us(2);

    GPIO_pin_low(&display.E);
}

void lcd_send_byte(int8 n, int8 address)
{
    GPIO_pin_low(&display.RS);
    
    Delay_us(60);

    if(n)
    {
        GPIO_pin_high(&display.RS);
    }
    else
    {
        GPIO_pin_low(&display.RS);
    }
    
    Delay_ms(1);

    GPIO_pin_low(&display.E);

    lcd_send_nibble(address >> 4);  //envia os primeiros 4 bits mais significativos
    lcd_send_nibble(address & 0xf); //envia os primeiros 4 bits menis significativos
}

void lcd_send_string(int8 *fmt)
{
    uint8 c;
    while((c = *fmt) != '\0')
    {
        lcd_send_byte(1, c);
        fmt++;
    }
}

void lcd_gotoxy(int8 coluna, int8 linha)
{
    int8 address;

    switch(linha)
    {
        case 1:
            address = 0x80; //linha 1
        break;

        case 2:
            address = 0xC0; //linha 2
        break;

        case 3:
            address = 0x94; //linha 3
        break;
        
        case 4:
            address = 0xD4; //linha 4
        break;
    }
    
    address += coluna - 1;
    
    lcd_send_byte(0, address);
}


void lcd_printf(int8 *c, ...)
{
    va_list pa;
    int8 a;    
    int16 d;
    uint16 u;
    int8 *s;

    va_start(pa, c);

    while(*c != '\0')
    {
        if(*c == '%')
        {
            switch(*++c)
            {
                case '%': lcd_send_byte(1, '%');
                break;

                case 'c': /* int8 caracter*/

                	a = va_arg(pa, int);
                    lcd_send_byte(1, (int8)a);

                break;
                
                case 's': /* string */

                    s = va_arg(pa, int8 *);
                    lcd_send_string(s);

                break;

                case 'd': /* int16*/

                    d = va_arg(pa, int);
                    lcd_print_int16((int16)d);

                break;

                case 'u': /* uint16*/

                    u = va_arg(pa, int);
                    lcd_print_uint16((uint16)u);

                break;

            }
        }
        else
        {
            switch(*c)
            {
                case '\f': //Limpa LCD
                    lcd_send_byte(0, 1);
                    Delay_ms(2);
                break;

                case '\n': // Pula Linha
                    lcd_gotoxy(1, 2);
                break;

                case '\b': // Volta um caracter
                    lcd_send_byte(0, 0x10);
                break;

                default: // Escreve o caracter
                    lcd_send_byte(1, *c);
                break;
            }
        }

        c++;
    }
    
    va_end(pa);
}


void lcd_print_uint16(uint16 n)
{
    unsigned cnt = 0;
    int8 buffer[11];

    do
    {
        buffer[cnt] = n % 10; // Resto da divisao, sempre o primeiro digito
        n = n / 10; //exclui o digito fazendo a divisao
        cnt++; //incrementa contador
    }while (n); // repete ate valor n==0

    for (; cnt; cnt--)
    {
        lcd_send_byte(1, buffer[cnt - 1] + '0'); //soma o valor do buffer com o valor do caracter zero 0x30.
    }
}

void lcd_print_int16(int16 n)
{
	unsigned cnt = 0;
    uint8 flag_negativo;
    volatile int8 buffer[11];
    flag_negativo = 0;
    if(n < 0)
    {
        n = -n;
        flag_negativo = 1;
    }
    do
    {
        buffer[cnt] = n % 10; // Resto da divisao, sempre o primeiro digito
        n = n / 10; //exclui o digito fazendo a divisao
        cnt++; //incrementa contador
    }
    while(n); // repete ate valor n==0

    if(flag_negativo)
    {
        //cnt++;
        buffer[++cnt] = 0x2D;
    }

    for(; cnt; cnt--)
    {
        if(buffer[cnt] == 0x2D)
        {
            lcd_send_byte(1, 0x2D);
        }
        else
        {
            lcd_send_byte(1, buffer[cnt - 1] + '0'); //soma o valor do buffer com o valor do caracter zero 0x30.
        }
    }
}


