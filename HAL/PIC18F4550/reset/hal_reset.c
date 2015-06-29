/**
 * @file    hal_reset.c
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    4 de Abril de 2015
 * @version 0.1.0.0 
 * @brief   Codigo do Driver Reset para o microcontrolador PIC18f4550.
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

#include "hal_reset.h"

/**
 * @brief
 * reinicia o equipamento
 */
void resetMCU(void)
{
     asm(" reset");
}

/**
 * @brief
 * @param senha_p1
 * @param senha_p2
 */
void resetMCU_device(uint16 senha_p1, uint16 senha_p2)
{
    //Verifica se chegou comando de reset do aparelho
    if(senha_p1 == 1234 && senha_p2 == 4321)
    {
        resetMCU();
    }
}