/**
  * @file    sys_ad.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 3, 2014
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

#include "sys_ad.h"
#include "ad/hal_ad.h"
#include "LM35/lm35.h"

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

void init_AD(void)
{
//  float valor;
//  float valor2;
//  float valor3;
  ad_setup_vref(AD_VREF_POS_VDD, AD_VREF_NEG_GND);
  ad_setup_clock(AD_TAD_12, AD_CK_FOSC_DIV_8);
  ad_setup_enable(EN_AN0_TO_1, AD_ENABLE);
  
//  while(1)
//  {
//    //valor = (float)ad_read(AD_CH0)*0.48828125; //{ADC*5)/(2^10)
//    valor = lm35_read(INDEX_0); 
//    Delay_ms(10);
//    Delay_ms(10);
//    Delay_ms(10);
//    
//    //valor2 = lm35_read(AD_CH1);//float)ad_read(AD_CH1)*0.0048828125; //{ADC*5)/(2^10)
////    valor2 =(float)ad_read(AD_CH1)*0.0048828125; //{ADC*5)/(2^10)
////    Delay_ms(10);
////    Delay_ms(10);
////    Delay_ms(10);
//    
////    valor3 = lm35_read(AD_CH0); 
////    Delay_ms(10);
//
//  }
}



