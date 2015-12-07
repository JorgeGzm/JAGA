/**
  * @file    lcd.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 9, 2014
  * @version 0.1.0.0 (beta)
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdarg.h>

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
DisplayLcd display;

/** @brief Buffer que contem a rotina de inicialização do LCD 2x16 e 4x20 */
const uint8_t LCD_INIT_STRING[4] =
{
    0x20 | (2 << 2), // Func set: 4-bit, 2 linhas, caracter 5x8
    0xC, 			// Display ligado
    1, 				// Limpa display
    6 				// Incrementa cursor
};

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================


/** @brief Rotina de inicializacao do Display*/
static void lcd_init(void);

/**
 * @brief funcaoo que se encarreca de enviar um dado ou uma instrucao ao lcd.
 * @param 0(instrucao), 1(Dado).
 * @param endereco do lcd onde o dado sera escrito.
 */
static void lcd_send_byte(uint8_t address, uint8_t n);

/**
 * @brief funcao que enviara os primeiros 4 bits menos significativos nas saidas db4 a db7 do lcd.
 * @param dado de 8bits onde somente os 4 primeiros serao usados no envio de comandos do lcd.
 */
static void lcd_send_nibble(uint8_t nibble);

//==============================================================================
// SOURCE CODE
//==============================================================================

static void lcd_init(void)
{
    uint8_t i;


    GPIO_regPin_outputLow(&display.rs);
    GPIO_regPin_outputLow(&display.e);

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

void lcd_attach(regGPIO RS, regGPIO E, regGPIO DB4, regGPIO DB5, regGPIO DB6, regGPIO DB7)
{
    GPIO_regPin_attach(&display.rs, &RS);  //configura pino RS do lcd
    GPIO_regPin_setDir(&RS, DIR_OUTPUT);      //Configura pino como saida

    GPIO_regPin_attach(&display.e, &E);
    GPIO_regPin_setDir(&E, DIR_OUTPUT);

    GPIO_regPin_attach(&display.db4, &DB4);
    GPIO_regPin_setDir(&DB4, DIR_OUTPUT);

    GPIO_regPin_attach(&display.db5, &DB5);
    GPIO_regPin_setDir(&DB5, DIR_OUTPUT);

    GPIO_regPin_attach(&display.db6, &DB6);
    GPIO_regPin_setDir(&DB6, DIR_OUTPUT);

    GPIO_regPin_attach(&display.db7, &DB7);
    GPIO_regPin_setDir(&DB7, DIR_OUTPUT);

    lcd_init();
}

void lcd_gotoxy(uint8_t coluna, uint8_t linha)
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

static void lcd_send_nibble(uint8_t nibble)
{
    Byte aux;

    aux.value = nibble;

    //envia niblbe ao lcd
    GPIO_regPin_outputBit(&display.db4, aux.bit0);
    GPIO_regPin_outputBit(&display.db5, aux.bit1);
    GPIO_regPin_outputBit(&display.db6, aux.bit2);
    GPIO_regPin_outputBit(&display.db7, aux.bit3);

    Delay_ms(3);//Delay_ms(10);

    GPIO_regPin_outputHigh(&display.e);

    Delay_us(2);

    GPIO_regPin_outputLow(&display.e);
}

static void lcd_send_byte(uint8_t n, uint8_t address)
{
    GPIO_regPin_outputLow(&display.rs);
    
    Delay_us(60);

    if(n)
    {
        GPIO_regPin_outputHigh(&display.rs);
    }
    else
    {
        GPIO_regPin_outputLow(&display.rs);
    }
    
    Delay_ms(1);

    GPIO_regPin_outputLow(&display.e);

    lcd_send_nibble(address >> 4);  //envia os primeiros 4 bits mais significativos
    lcd_send_nibble(address & 0xf); //envia os primeiros 4 bits menis significativos
}

void lcd_print(const uint8_t *fmt)
{
    uint8_t c;
    while((c = *fmt) != '\0')
    {
        lcd_send_byte(1, c);
        fmt++;
    }
}

void lcd_putc(uint8_t c)
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

		default: // Escreve o caracter
			lcd_send_byte(1, c);
		break;
	}
}
