/**
 * @file    crc.h
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    12 de Marco de 2015
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

#include "crc.h"

uint16 crc_calculo(uint16 crc, uint8 dado)
{
    UWord aux_crc;
    aux_crc.value = crc;
    
    uint8 UI8_bit_cnt = 8;

    aux_crc.b.b1 ^= dado;

    do
    {
        dado = (aux_crc.b.b1 & 0x01);
        aux_crc.value >>= 1;

        if(dado)
        {
            aux_crc.value ^= 0xA001;
        }
    }
    while(--UI8_bit_cnt);
    
    return (aux_crc.value);
}

uint16 crc_calcula_buff(uint16 count, uint8 *buffer)
{   
    UWord aux_crc;
    
    aux_crc.value = 0xFFFF;
    
    for(; count; count--, buffer++)    
    {
        aux_crc.value = crc_calculo(aux_crc.value, *buffer);
    }
    
    return aux_crc.value;
}

