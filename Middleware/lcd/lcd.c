/**
 * @file    lcd.c
 * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
 * @date    Jul 9, 2014
 * @version 0.2.0.0 (beta)
 * @brief   Bibliteoca para o uso do display LCD 2x16 ou 4x20.
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

#include "lcd.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** @brief Variavel de configuracao dos pinos do LCD*/
PRIVATE DisplayLcd display = 
{
    0xFF, //rs
    0xFF, //e
    0xFF, //db4
    0xFF, //db5
    0xFF, //db6
    0xFF  //db7
};

/** @brief Buffer que contem a rotina de inicialização do LCD 2x16 e 4x20 */
const uint8_t LCD_INIT_STRING[4] =
{
    0x20 | (2 << 2), // Func set: 4-bit, 2 linhas, caracter 5x8
    0xC, // Display ligado
    1, // Limpa display
    6 // Incrementa cursor
};

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

/** @brief Rotina de inicializacao do Display*/
PRIVATE void lcd_init(void);

/**
 * @brief funcaoo que se encarreca de enviar um dado ou uma instrucao ao lcd.
 * @param 0(instrucao), 1(Dado).
 * @param endereco do lcd onde o dado sera escrito.
 */
PRIVATE void lcd_send_byte(uint8_t address, uint8_t n);

/**
 * @brief funcao que enviara os primeiros 4 bits menos significativos nas saidas db4 a db7 do lcd.
 * @param dado de 8bits onde somente os 4 primeiros serao usados no envio de comandos do lcd.
 */
PRIVATE void lcd_send_nibble(uint8_t nibble);

//==============================================================================
// SOURCE CODE
//==============================================================================

PRIVATE void lcd_init(void) 
{
    uint8_t i;

    digitalWrite(display.rs, LOW);
    digitalWrite(display.e, LOW);

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
}

PUBLIC void lcd_attach(uint8_t RS, uint8_t E, uint8_t DB4, uint8_t DB5, uint8_t DB6, uint8_t DB7)
{
    display.rs = RS;
    pinMode(display.rs, OUTPUT);

    display.e = E;
    pinMode(display.e, OUTPUT);

    display.rs = RS;
    pinMode(display.rs, OUTPUT);

    display.db4 = DB4;
    pinMode(display.db4, OUTPUT);

    display.db5 = DB5;
    pinMode(display.db5, OUTPUT);

    display.db6 = DB6;
    pinMode(display.db6, OUTPUT);

    display.db7 = DB7;
    pinMode(display.db7, OUTPUT);

    lcd_init();
}

PUBLIC void lcd_gotoxy(uint8_t coluna, uint8_t linha) 
{
    int8_t address;

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

PRIVATE void lcd_send_nibble(uint8_t nibble) 
{
    Byte aux;

    aux.value = nibble;

    //envia niblbe ao lcd
    digitalWrite(display.db4, aux.bit0);
    digitalWrite(display.db5, aux.bit1);
    digitalWrite(display.db6, aux.bit2);
    digitalWrite(display.db7, aux.bit3);

    Delay_ms(3);
    digitalWrite(display.e, HIGH);

    Delay_us(2);
    digitalWrite(display.e, LOW);
}

PRIVATE void lcd_send_byte(uint8_t n, uint8_t address) 
{
    digitalWrite(display.rs, LOW);

    Delay_us(60);

    if(n) 
    {
        digitalWrite(display.rs, HIGH);
    } 
    else
    {
        digitalWrite(display.rs, LOW);
    }

    Delay_ms(1);

    digitalWrite(display.e, LOW);

    lcd_send_nibble(address >> 4); //envia os primeiros 4 bits mais significativos
    lcd_send_nibble(address & 0xf); //envia os primeiros 4 bits menis significativos
}

PUBLIC void lcd_print(const uint8_t *fmt) 
{
    uint8_t c;
    while((c = *fmt) != '\0') 
    {
        lcd_send_byte(1, c);
        fmt++;
    }
}

PUBLIC void lcd_putc(uint8_t c) 
{
    switch(c) 
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

        case '%': // Volta um caracter
            lcd_send_byte(1, 0x25);
            break;

        default: // Escreve o caracter
            lcd_send_byte(1, c);
            break;
    }
}
