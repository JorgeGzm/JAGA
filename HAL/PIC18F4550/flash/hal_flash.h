/**
 * @file    hal_flash.h
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    10 de Fevereiro de 2015
 * @version 0.1.0.0 
 * @brief   Driver para a memoria flash para o microcontrolador PIC18f4550.
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

#ifndef HAL_FLASH_H
    #define HAL_FLASH_H

#include "types/types.h"
#include "device/hal_device.h"
/*
 * @brief Realiza a leitura da memoria flash do PIC18f4550.
 * @details Cada instrucao tem o tamanho de 16 bits, mas cada endereco contem apenas a uma
 * uma parte do dado(parte alta ou parte baixa). A função abaixo retorna o dado ja pronto
 * ficando apenas a cargo da programador controlar os lacos de repeticao corretamente.
 * A passagem de endereco deve ser feito usando numeros pares.Qualquer duvida consultar o datasheet.\n
 * Exemplo: flash_rd(0x0C28) \n
 * proximo flash_rd(0x0C2A)  \n
 * proximo flash_rd(0x0C2C)  \n
 * ou flash_rd(0x0C28+(i*2)); \n
 * OBS: \n
 * TBLPTRU + TBLPTRL + TBLPTRH = Endereco de 32 bits\n
 * PIC18F4550 each have 32 Kbytes of Flash memory \n
 * @param UI16_address A leitura dos endereos deve ser feita Range de enderecos da memoria de programa: 0x19h - 0x8000.
 */
uint16 flash_rd(int16 UI16_address);

/**
 * @brief Apaga regiao da memoria flash
 * @details O minimo de dados que o microcontrolador aceita apagar e um bloco 64 bytes(32 words),
 * iniciando do endereco 0. \n
 * Exemplo: sequencia de enderecos \n
 *  0 -> ([32*1]-1) -> ([32*2]-1) -> ... ate 0x7FFF \n
 * @param UI16_address Indica endereco de inicio para comeca a apagar os proximos 64 bytes.
 *  Range da memoria de programa: 0x0019 ate 0x7FFF,
 */
void flash_erasing(int16 UI16_address);

/**
 * @brief Escreve na memorias flash do PIC18f4550
 * @details Executa a escrita na memoria flash do microcontrolador. O minimo de  \n
 * dados que o microcontrolador aceita escrever sao blocos de 32 bytes(16 words),\n
 * onde cada word e uma instrucao. 
 * TODO: finalizar funcao.
 * @param UI16_buffer
 * @param UI16_address Indica endereco de inicio para comeca a escrever 32 bytes de dados.
 */
void flash_wr(UWord UI16_buffer[], int16 UI16_address);

#endif	/* HAL_FLASH_H */
