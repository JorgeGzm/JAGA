/**
  * @file    lcd.h
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

#ifndef LCD_H
	#define	LCD_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "types/types.h"
#include "gpio/hal_gpio.h"
#include "delay/hal_delay.h"
#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/** @brief Estrutura que contem os pinos do microcontrolador que irao controlar o display-lcd 2x16 ou 4x20*/
typedef struct 
{
    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB4 do CLD */
    uint8_t db4;
    
    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB5 do CLD */
    uint8_t db5;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB6 do CLD */
    uint8_t db6;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o DB7 do CLD */
    uint8_t db7;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o E do CLD */
    uint8_t e;

    /** @brief Recebe a configuracao de qual pino do pic que controlara o RS do CLD */
    uint8_t rs;
}DisplayLcd;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/**
 * @brief Inicializa display LCD. Deve ser chamado antes de qualquer funcao do lcd
 * @param pin
 * @param port
 * @param tris
 */
PUBLIC void lcd_attach(uint8_t RS, uint8_t E, uint8_t DB4, uint8_t DB5, uint8_t DB6, uint8_t DB7);

/**
 * @brief Todo Documentar
 */
PUBLIC void lcd_putc(uint8_t c);

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
PUBLIC void lcd_gotoxy(uint8_t x, uint8_t y);

/**
 * @brief Todo Documentar
 */
PUBLIC void lcd_print(const uint8_t *fmt);

#endif	

