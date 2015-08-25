/**
  * @file    lcd.h
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

#ifndef LCD_H
	#define	LCD_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "vars/vars.h"
#include "types/types.h"
#include "gpio/hal_gpio.h"
#include "delay/hal_delay.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

/** @brief Estrutura que contem os pinos do microcontrolador que irao controlar o display-lcd 2x16 ou 4x20*/
typedef struct 
{
    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB4 do CLD */
    regPin db4;
    
    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB5 do CLD */
    regPin db5;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB6 do CLD */
    regPin db6;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB7 do CLD */
    regPin db7;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o E do CLD */
    regPin e;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o RS do CLD */
    regPin rs;
}DisplayLcd;

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

/**
 * @brief Inicializa display LCD. Deve ser chamado antes de qualquer funcao do lcd
 * @param pin
 * @param port
 * @param tris
 */
void lcd_attach(regGPIO RS, regGPIO E, regGPIO DB4, regGPIO DB5, regGPIO DB6, regGPIO DB7);

/**
 * @brief funcaoo que se encarreca de enviar um dado ou uma instrucao ao lcd.
 * @param 0(instrucao), 1(Dado).
 * @param endereco do lcd onde o dado sera escrito.
 */
void lcd_send_byte(int8 address, int8 n);

/**
 * @brief Escreve o vetor de caracters na proxima posicao do LCD.
 * @details 
 * Ex:                                              \n
 * int8 buff[] = {"12345"};                         \n
 * lcd_printf(&buff);                               \n
 * lcd_printf((int8 *)"Temperatura = %d", TAMB);    \n
 * lcd_printf((int8 *)"%u/%u/%u-%u:%u:%u", relogio.UI8_Dia, relogio.UI8_Mes, relogio.UI8_Ano, relogio.UI8_Horas, relogio.UI8_Minutos, relogio.UI8_Segundos);
 * @param ponteiro que aponta o vetor de caracteres que vai ser enviado ao lcd.
 */
void lcd_printf(int8 *c, ...);
void lcd_send_string(int8 *fmt);

/**
 * funcao que enviara os primeiros 4 bits menos significativos nas saidas db4 a db7 do lcd.
 * @param dado de 8bits onde somente os 4 primeiros serao usados no envio de comandos do lcd.
 */
void lcd_send_nibble(int8 nibble);

/** Rotina de inicializacao do Display*/
void lcd_init(void);

/**
* @brief Posiciona o cursor na posicao x , y.  O limite superior 1, 1 e o limete inferior e 1, 4
* @details Explicacao:                          \n
* Endereco para a escrita em LCD 2x16 e 4x20    \n
*          Col1  Col2 ... Col20                 \n
* Linha 1: 0x80  0x81 ... 0x93                  \n
* Linha 2: 0xC0  0xC1 ... 0xD3                  \n
* Linha 3: 0x94  0x95 ... 0xA7                  \n
* Linha 4: 0xD4  0xD5 ... 0xE7                  
* @param x: coluna
* @param y: linha
*/
void lcd_gotoxy(int8 x, int8 y);

/**
 * @brief Imprime variaveis in16 no display LCD
 * @param n Valor que sera impresso no LCD
 */
void lcd_print_int16(int16 n);

/**
 * @brief Imprime Variaveis uin16 no display LCD
 * @param n Valor que sera impresso no LCD
 */
void lcd_print_uint16(uint16 n);

#endif	

