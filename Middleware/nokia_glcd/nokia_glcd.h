/**
  * @file    nokia_glcd.c
  * @author  Tiago Melo; Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Apr 2, 2014
  * @version 0.2.0.0 (beta)
  * @brief   nokia3310 - Display Monocromático 48x84
  * @details
  * @section LICEnSE
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GnU General Public License as
  * published by the Free Software Foundation; either version 2 of
  * the License, or (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful, but
  * WITHOUT AnY WARRAnTY; without even the implied warranty of
  * MERCHAnTABILITY or FITnESS FOR A PARTICULAR PURPOSE. see the GnU
  * General Public License for more details at
  * http://www.gnu.org/copyleft/gpl.html
*/

#ifndef NOKIA_GLCD_H
#define NOKIA_GLCD_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "types/types.h"
#include "delay/hal_delay.h"
#include "gpio/hal_gpio.h"
#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

//==============================================================================
// Global Variable
//==============================================================================

//==============================================================================
// Public Prototype
//==============================================================================

/**
 * @brief TODO
 * @param clk TODO
 * @param data TODO
 * @param dc TODO
 * @param rst TODO
 * @param sce TODO
 */
PUBLIC void nokia_attach(uint8_t clk, uint8_t data, uint8_t dc, uint8_t rst, uint8_t sce);

/**
 * @brief TODO
 * @param dc Define se o valor enviado e um comando(0) ou um dado(1).
 * @param _data Valor a ser enviado;
 */
PUBLIC void nokia_write(uint8_t dc, uint8_t _data);

/**
 * @brief Define a posicao do cursor no glcd.
 * @param x Coluna - Posicao horizontal (0 - 83).
 * @param y Linha - Pagina situada, posicao vertical ( 0 - 5).
 */
PUBLIC void nokia_set_cursor(uint8_t x, uint8_t y);

/**
 * @brief Escreve um caracter no glcd.
 * @param Caracter Caracter a ser escrito.
 * @param Color Fundo invertido, 1 = fundo nao invertido
 */
PUBLIC void nokia_chr(uint8_t caracter, uint8_t color);

/**
 * @brief Escreve um caracter na cor branca e fundo preto no glcd.
 * @param Caracter Caracter a ser escrito.
 */
PUBLIC void nokia_white_putc(uint8_t caracter);

/**
 * @brief Escreve um caracter na cor preta e fundo branco no glcd.
 * @param Caracter Caracter a ser escrito.
 */
PUBLIC void nokia_black_putc(uint8_t caracter);

/**
 * @brief Escreve um caracter no lcd seguindo a tabela ASCII
 * @param map
 */
PUBLIC void nokia_custom_char(uint8_t *map);

/**
 * @brief Preenche o display com um conteudo do buffer;
 * @param Buffer Valor, quando for 0x00, limpa a tela; 0xFF dexa a tela preta;
 */
PUBLIC void nokia_fill(uint8_t Buffer);

/**
 * @brif Escreve um texto no lcd;
 * @param row
 * @param col
 * @param String
 * @param Color
 */
PUBLIC void nokia_out(uint8_t row, uint8_t col, uint8_t *string, uint8_t color);

/**
 * @brief Escreve um texto
 * @param String Ponteiro para o buffer a ser escrito no LCD.
 * @param Color 0 fundo invertido, 1 fundo nao invertido
 */
PUBLIC void nokia_out_cp(uint8_t *String, uint8_t Color);

/**
 * @brief Desenha uma imagem.
 * @param Bmp
 */
PUBLIC void nokia_image(const uint8_t *Bmp);

/**
 * @brief Escreve um numero de tamanho grande.
 * @param x X deve ser incrementado de 14 em 14.
 * @param y Y deve ser incrementado de 3 em 3.
 * @param n
 * @param Color
 */
PUBLIC void nokia_write_big_number(uint8_t x, uint8_t y, uint8_t n, uint8_t Color);

/**
 * @brief Escreve um numero de tamanho grande.
 * @param x deve ser incrementado de 11 em 11.
 * @param y deve ser incrementado de 2 em 2.(Valores: 0, 2, 4)
 * @param n
 * @param Color
 */
PUBLIC void nokia_write_med_number(uint8_t x, uint8_t y, uint8_t n, uint8_t Color);

#endif
