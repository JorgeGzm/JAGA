/**
  * @file    nokia_glcd.c
  * @author  Tiago Melo; Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Apr 2, 2014
  * @version 0.1.0.0 (beta)
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

#ifndef nOKIAGLCD_H
#define nOKIAGLCD_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------
#include "types/types.h"

#include "delay/hal_delay.h"
#include "gpio/hal_gpio.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global Variable
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype
//------------------------------------------------------------------------------

/**
 * @brief TODO
 * @param clk TODO
 * @param data TODO
 * @param dc TODO
 * @param rst TODO
 * @param sce TODO
 */
void nokia_attach(regGPIO clk, regGPIO data, regGPIO dc, regGPIO rst, regGPIO sce);

/**
 * @brief Envia um dado de forma serial, nao usa a SPI no microcontrolador
 * @param data Valor a ser enviado;
 */
static void nokia_spi_wr(uint8 data);

/**
 * @brief TODO
 * @param dc Define se o valor enviado é um comando(0) ou um dado(1).
 * @param _data Valor a ser enviado;
 */
void nokia_write(uint8 dc, uint8 _data);

/**
 * @brief Define a posicao do cursor no glcd.
 * @param x Posicao horizontal (0 - 83).
 * @param y Pagina situada, posicao vertical ( 0 - 5).
 */
void nokia_set_cursor(uint8 x, uint8 y);

/**
 * @brief Escreve um caracter no glcd.
 * @param Caracter Caracter a ser escrito.
 * @param Color Fundo invertido, 1 = fundo nao invertido
 */
void nokia_chr(uint8 caracter, uint8 color);

/**
 * @brief Escreve um caracter no glcd.
 * @param Caracter Caracter a ser escrito.
 */
void nokia_putc(uint8 caracter);

/**
 * @brief Escreve um caracter no lcd seguindo a tabela ASCII
 * @param map
 */
void nokia_custom_char(uint8 *map);

/**
 * @brief Preenche o display com um conteudo do buffer;
 * @param Buffer Valor, quando for 0x00, limpa a tela;
 */
void nokia_fill(uint8 Buffer);

/**
 * @brif Escreve um texto no lcd;
 * @param row
 * @param col
 * @param String
 * @param Color
 */
void nokia_out(uint8 row, uint8 col, uint8 *string, uint8 color);

/**
 * @brief Escreve um texto
 * @param String Ponteiro para o buffer a ser escrito no LCD.
 * @param Color 0 fundo invertido, 1 fundo nao invertido
 */
void nokia_out_cp(uint8 *String, uint8 Color);

/**
 * @brief Desenha uma imagem.
 * @param Bmp
 */
void nokia_image(const uint8 *Bmp);

/**
 * @brief Escreve um numero de tamanho grande.
 * @param x X deve ser incrementado de 14 em 14.
 * @param y Y deve ser incrementado de 3 em 3.
 * @param n
 * @param Color
 */
void nokia_write_big_number(uint8 x, uint8 y, uint8 n, uint8 Color);

/**
 * @brief Escreve um numero de tamanho grande.
 * @param x X deve ser incrementado de 11 em 11.
 * @param y Y deve ser incrementado de 2 em 2.
 * @param n
 * @param Color
 */
void nokia_write_med_number(uint8 x, uint8 y, uint8 n, uint8 Color);

#endif
