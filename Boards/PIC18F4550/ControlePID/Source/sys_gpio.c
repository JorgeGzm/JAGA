/**
  * @file    sys_gpio.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 16, 2015
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
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

#include <stdarg.h>
#include "sys_gpio.h"
#include "gpio/hal_gpio.h"
#include "device/hal_device.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

PUBLIC void init_gpio(void)
{
    //Rotinas de inicializacao especiais

    //Libera o uso do PORTB como I/O
    INTCONbits.RBIE = 0;  //b3:(0) PORTB(RB4-RB7) desabilita interrupcao por mudanca de estado do
    INTCON2bits.RBIP = 0; //b0:(0) PORTB(RB4-RB7) Interrupcao de mudanca de estado, baixa prioridade:

    //Libera o uso do PORTE como I/O
    ADCON1bits.PCFG3 = 1; //[b3-b0]:(1111)(nenhum) //Configura canais
    ADCON1bits.PCFG2 = 1; //[b2]
    ADCON1bits.PCFG1 = 1; //[b1]
    ADCON1bits.PCFG0 = 1; //[b0]
}