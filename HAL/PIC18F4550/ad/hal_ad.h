/**
  * @file    hal_ad.h
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

#ifndef HAL_AD_H
    #define HAL_AD_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "types/types.h"
#include "gpio/hal_gpio.h"
#include "device/hal_device.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

/** @brief Conversor A/D desligado*/
#define AD_DISABLE      0

/** @brief Conversor A/D esta em operacao*/
#define AD_ENABLE       1

/** @brief Seleciona VCC como tensao de refencia de VREF+. */
#define AD_VREF_POS_VDD     0

/** @brief Seleciona GND como tensao de refencia de VREF-. */
#define AD_VREF_NEG_GND     0

/** @brief Seleciona o pino AN3 como tensao de refencia de VREF+. */
#define AD_VREF_POS_AN3     1

/** @brief Seleciona o pino AN2 como tensao de refencia de VREF-. */
#define AD_VREF_NEG_AN2    1

/** Bits de selecao de tempo*/
#define AD_TAD_0    0
#define AD_TAD_2    1
#define AD_TAD_4    2
#define AD_TAD_6    3
#define AD_TAD_8    4
#define AD_TAD_12   5
#define AD_TAD_16   6
#define AD_TAD_20   7

/** FRC(clock derivado de um oscilador RC)*/
#define AD_CK_FRC           7
#define AD_CK_FOSC_DIV_64   6       /** Fosc/64 */
#define AD_CK_FOSC_DIV_16   5       /** Fosc/16 */
#define AD_CK_FOSC_DIV_4    4       /** Fosc/4  */

/** FRC(clock derivado de um oscilador RC), ler datasheet*/
#define AD_CK_FRC2          3
#define AD_CK_FOSC_DIV_32   2   /** Fosc/32 */
#define AD_CK_FOSC_DIV_8    1   /** Fosc/8 */
#define AD_CK_FOSC_DIV_2    0   /** Fosc/2 */

#define NO_ERROR 0
#define OVER_FLOW 1
#define UNDER_FLOW 2

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/** Seleciona os canais AD que serao usados iniciando de AD_CH0 ate AD_CHX. */
enum AD_CH
{
    AD_CH0 = 0,
    AD_CH1,
    AD_CH2,
    AD_CH3,
    AD_CH4,
    AD_CH5,
    AD_CH6,
    AD_CH7,
    AD_CH8,
    AD_CH9,
    AD_CH10,
    AD_CH11,
    AD_CH12,
    AD_CH_SIZE,
};

/**
 * Referencia os Conversores AD que serao usados. OBS: configura alguma sensor
 * para leitura do canal AN4 implicitamente configura AN0 a AN3 como entradas analogicas tambem.
 */
enum AD_AN
{
    AD_AN0 = 1,
    AD_AN1,
    AD_AN2,
    AD_AN3,
    AD_AN4,
    AD_AN5,
    AD_AN6,
    AD_AN7,
    AD_AN8,
    AD_AN9,
    AD_AN10,
    AD_AN11,
    AD_AN12,
    AD_AN_SIZE,
};

/** @brif Estrutura que configura o uso do convesor AD para qualquer sensor*/
typedef struct 
{
    regGPIO reg;
    uint8_t channel;
    //void (*set1)(uint8);//configura canal que vai ser usado.  Responsabilidade do AD agora
    uint16_t(*read1)(uint8_t);    
    uint8_t error;    
}Analog;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/**
 * @brief Configura tensoes de referencia Vref+ e Vref-.
 * @param p_vref                                                            \n    
 *  AD_VREF_POS_VDD: Seleciona VCC como tensao de refencia de VREF+         \n
 *  AD_VREF_POS_AN3: Seleciona o pino AN3 como tensao de refencia de VREF+. \n
 * @param n_vref                                                            \n
 *  AD_VREF_NEG_GND: Seleciona GND como tensao de refencia de VREF-.        \n
 *  AD_VREF_NEG_AN2: Seleciona o pino AN2 como tensao de refencia de VREF-. \n
 */
void ad_setup_vref(uint8_t pVref, uint8_t nVref);

/**
 * @brief TODO documentar
 * @param bit de selecao do canal analogico, iniciando de AD_CH0 ate AD_CHX. \n
 *  AD_CH0: seleciona canal 0               \n
 *  AD_CH1: seleciona canais 0 e 1          \n
 *  AD_CH2: seleciona canais 0, 1 e 2       \n
 *  AD_CH3: seleciona canal 0, 1, 2 e 3     \n
 *  AD_CH4: seleciona canais 0 ate 4        \n
 *  AD_CH5: seleciona canais 0 ate 5        \n
 *  AD_CH6: seleciona canais 0 ate 6        \n
 *  AD_CH7: seleciona canais 0 ate 7        \n
 *  AD_CH8: seleciona canais 0 ate 8        \n
 *  AD_CH9: seleciona canais 0 ate 9        \n
 *  AD_CH10: seleciona canais 0 ate 10      \n
 *  AD_CH11: seleciona canais 0 ate 11      \n
 *  AD_CH12: seleciona canais 0 ate 12      
 * @param analog_in Configura os pinos conversores A/D como entrada analogica ou digital. \n
 * AD_AN0: Habilita AD do CH0               \n
 * AD_AN1: Habilita AD de CH0 e CH1         \n
 * AD_AN2: Habilita AD de CH0 ate CH2       \n
 * AD_AN3: Habilita AD de CH0 ate CH3       \n
 * AD_AN4: Habilita AD de CH0 ate CH4       \n
 * AD_AN5: Habilita AD de CH0 ate CH5       \n
 * AD_AN6: Habilita AD de CH0 ate CH6       \n
 * AD_AN7: Habilita AD de CH0 ate CH7       \n  
 * AD_AN8: Habilita AD de CH0 ate CH8       \n
 * AD_AN9: Habilita AD de CH0 ate CH9       \n
 * AD_AN10: Habilita AD de CH0 ate CH10     \n
 * AD_AN11: Habilita AD de CH0 ate CH11     \n
 * AD_AN12: Habilita AD de CH0 ate CH12     \n
 * @param enable Liga/Desliga conversor AD  \n
 *  AD_ENABLE:                              \n
 *  AD_DISABLE                              
 */
void ad_setup_enable(uint8_t chanel, uint8_t analog_in, uint8_t enable);

/**
 * @brief TODO documentar
 * @param tad Bits de selecao de tempo de aquisicao. \n
 *  AD_TAD_0:                               \n
 *  AD_TAD_2:                               \n
 *  AD_TAD_4:                               \n
 *  AD_TAD_6:                               \n
 *  AD_TAD_8:                               \n
 *  AD_TAD_12:                              \n
 *  AD_TAD_16:                              \n
 *  AD_TAD_20:                              \n
 * @param clock Bits de selecao do clock do conversor A/D. \n
 *  AD_CK_FRC:                              \n
 *  AD_CK_FOSC_DIV_64:                      \n
 *  AD_CK_FOSC_DIV_16:                      \n
 *  AD_CK_FOSC_DIV_4:                       \n
 *  AD_CK_FRC2:                             \n
 *  AD_CK_FOSC_DIV_32:                      \n
 *  AD_CK_FOSC_DIV_8:                       \n
 *  AD_CK_FOSC_DIV_2:                       \n
 */
void ad_setup_clock(uint8_t tad, uint8_t clock);

/**
 * @brief TODO documentar
 * @param channel TODO documentar
 * @return TODO documentar
 */
uint16_t ad_read(uint8_t channel);

#endif	
