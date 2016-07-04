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
 
#ifndef LM35_H
#define	LM35_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "gpio/hal_gpio.h"
#include "ad/hal_ad.h"
#include <stdint.h>
#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

/** Temperatura maxima de 150,00 ºC que o sensor LM35 pode ler, apos isso a medicao satura. Referencia do Datasheet.*/
#define LM35_MAX_TEMP_RD 15000.00

/** Temperatura minima de 0,00 ºC que o sensor LM35 pode ler, apos isso a medicao satura. Referencia do Datasheet*/
#define LM35_MIN_TEMP_RD      0.00

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/** @brief Indeces dos sensores LM35*/
typedef enum 
{
    INDEX_0 = 0,
    INDEX_1,
    INDEX_2,
    INDEX_MAX,
}INDEX_LM35;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/** @brief Inicializa variaveis.*/
PUBLIC void lm35_init(void);

/**
 * @brief Configura os pinos que serao usados para a leitura analogicoa do sensor LM35
 * @param index indice do sensor de temperatura que sera usado
 * @param reg registrador que sera usado
 * @param ch Informa o canal AD que sera usado para as leituras analogicas do sensor.
 * @param function_rd ponteiro para a funcao de leitura ADC que sera usada.
 */
PUBLIC void lm35_attach(INDEX_LM35 index, uint8_t pin, uint8_t ch_ad);

/**
 * @brief Transforma a leitura AD em ºC
 * @param sensor
 * @return Retorna temperatura com 2 casas de resolucao apos a virgula
 */
PUBLIC float lm35_read(INDEX_LM35 index);

/**
 * @brief Retorna o tipo de erro que aconteceu durante a leitura de temperatura
 * @param index
 * @return 
 */
PUBLIC uint8_t lm35_get_error(INDEX_LM35 index);

#endif	

