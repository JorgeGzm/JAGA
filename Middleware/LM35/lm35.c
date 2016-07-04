/**
  * @file    lm35.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); 
  * @date    Fev 12, 2015
  * @version 0.1.0.0 (beta)
  * @brief   odigo da biblioca faz o uso sensor de temperatura LM35.
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

#include "lm35.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

/** Base de conversao para Graus Celsiu: Constante (5/1024))*100 */
#define LM35_CONVERT_GRAUS 0.0048828125F * 100

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** Variavel que contem as configuracoes do sensor de temperatura LM35*/
PRIVATE Analog LM35[INDEX_MAX];

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

PUBLIC void lm35_init(void)
{
    uint8_t i;

    for(i = 0; i < INDEX_MAX; i++)
    {
        LM35[i].pin = 0;
        LM35[i].channel = 0;
        LM35[i].error = 0;        
    }   
}

PUBLIC void lm35_attach(INDEX_LM35 index, uint8_t pin, uint8_t ch_ad)
{
    LM35[index].pin = pin;
    LM35[index].channel = ch_ad;    
    
    pinMode(pin, INPUT);
}

PUBLIC float lm35_read(INDEX_LM35 index)
{
    float value;
    
    //funcao de transferencia que converte a leitura AD em ºC
    value = (float)ad_read(LM35[index].channel) * LM35_CONVERT_GRAUS;
    
//    if(LM35_MAX_TEMP_RD < value)
//    {
//        LM35[index].error = OVER_FLOW;
//    }
//    else if(LM35_MIN_TEMP_RD > value)
//    {
//        LM35[index].error = UNDER_FLOW;
//    }
//    else
//    {
//        LM35[index].error = NO_ERROR;        
//    }
    
    return(value);    
}

PUBLIC uint8_t lm35_get_error(INDEX_LM35 index)
{
    return (LM35[index].error);
}

