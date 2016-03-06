/**
  * @file    hal_ad.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 6, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para o do conversor analogico do PIC18f4550
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

#include "hal_ad.h"
#include <pwm.h>
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

void ad_setup_vref(uint8_t p_vref, uint8_t n_vref)
{
    ADCON1bits.VCFG1 = n_vref;

    ADCON1bits.VCFG0 = p_vref;
}

void ad_setup_enable(uint8_t analog_in, uint8_t enable)
{
    uint8_t value;
    
    value = ~analog_in;

    //mascara para configura AD dos pinos analogicos
    ADCON1bits.PCFG = 0x0F &value;    

    ADCON0bits.ADON = enable;
}

void ad_setup_clock(uint8_t tad, uint8_t clock)
{
    //Padrao desta lib, formato da conversao, justificado a direita
    ADCON2bits.ADFM = 1;

    ADCON2bits.ACQT = tad;

    ADCON2bits.ADCS = clock;
}

uint16_t ad_read(uint8_t channel)
{
    UWord resulte_ad; //recebe a leitura do canal AD

    ADCON0bits.CHS = channel;

    ADCON0bits.GO = 1; //requisata leitura AD
 
    while(ADCON0bits.GO); //Espera leitura ser finalizada

    resulte_ad.b.b2 = ADRESH; //Parte alta da leitura
    resulte_ad.b.b1 = ADRESL; //Parte baixa da leitura

    return(resulte_ad.value);  //valor AD lido
}
