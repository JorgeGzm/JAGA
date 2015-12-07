/**
  * @file    hal_eeprom.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 6, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Codigo da memoria eeprom do microcontrolador PIC18f4550.
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

#include "hal_eeprom.h"
#include "types/types.h"
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

uint8_t eeprom_rd(uint8_t address)
{
    EEADR = address; ;//endereço da eeprom onde o dado esta gravado
    EECON1bits.EEPGD = 0; //ponteiro da memoria de dados
    EECON1bits.CFGS = 0;
    EECON1bits.RD = 1;//inicia leitura
    
    return (EEDATA);
}

void eeprom_wr(uint8_t address, uint8_t data)
{
    EEADR = address; ;//endereço da eeprom onde o dado sera gravado
    EEDATA = data;    //repassa o dado que sera escrito ao microcontrolador

    //rotina de gravacao
    EECON1bits.EEPGD = 0; 
    EECON1bits.CFGS = 0; 
    EECON1bits.WREN = 1; //habilita escrita na eeprom

    INTCONbits.GIE = 0; //desliga interrupcoes ate fim da escrita
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;    //dispara o evento de escrita

    while(EECON1bits.WR); //espera ate o dado ser escrito
    
    INTCONbits.GIE = 1; //habilita interrupcoes

    EECON1bits.WREN = 0; //desabilita escrita  
}
