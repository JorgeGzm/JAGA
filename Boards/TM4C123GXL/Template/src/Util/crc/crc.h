/**
 * @file   	crc.h
 * @author 	Jorge Guzman (jorge.gzm@gmail.com)
 * @date 	12 de Marco de 2015
 * @version 0.1.0.0 
 * @brief   Bibliteca para o uso de calculo de CRC.
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

#ifndef CRC_H
#define	CRC_H

#include "types/types.h"

/**
 * @brief Calcula CRC de uma variavel "uint8" recebida e retorna o valor calculado. 
 * @param crc 
 * @param dado
 * @return Retorna o valor CRC calculo 
 */
uint16 crc_calculo(uint16 crc, uint8 dado);

/**
 * @brief Calcula CRC de um vetor "uint8" recebido e retorna o valor calculado. 
 * @param count Numero de posicoes do vetor
 * @param buffer Ponteiro bara o vetor que contem os dados.
 * @return Retorna o valor CRC calculo 
 */
uint16 crc_calcula_buff(uint16 count, uint8 *buffer);

#endif	/* LIB_CRC_H */

