/**
 * @file    HCSR04.c
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    Apr 5, 2015
 * @version 0.2.0.0 (beta)
 * @brief   Esta biblioteca realiza o calculo de distancia em centimetros usando o sensor HCSR04.
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
 * @link http://larios.tecnologia.ws/iBlog/archives/3715
 * @link http://waihung.net/hc-sr04-ultrasonic-sensor-on-pic/
 * @details Explicacao:                     \n
 * Velocidade do som no ar seco t(ºC):      \n
 * c = 331,3 + 0,6*t em m/seg               \n
 * c = 331,3 + 0,6*20 = 343,3m/seg          \n
 * 34330/1000000(cm/us) = 0.03433 cm/us     \n
 * Ida e volta do som ate o sensor          \n
 * 0,03433/2 = 0.017165                     \n
 *
 * Constante k:                             \n
 * FOSC=48Mhz                               \n
 * Cycle= 4/48MHz = 0.083333µS              \n
 * timer count = 0.083333µS*8 = 0.666666µS (prescaler=8) \n

 * within 1.6µS distance = 1.6(us)*0.03433(cm/seg) = 0.054928 cm per count          \n
 * but sound distance is twice ( to come an go back)                                \n
 * so relationchip becomes 0.054928/2 = 0.027464 cm per count                       \n
 *
 * Exemplo:                                                                         \n
 *  HCSR04_attach(&ultrason[0].trig, &pRD3, &tRD3, &ultrason[0].eco, &pRD2, &tRD2); \n
 *  HCSR04_set_const(48000000F, 8);                                                 \n
 *  HCSR04_attach_Timer(_TMR1);                                                     \n
 *  timer_setup_scale(_TMR1, TMR_PRESCALE_ON, TMR1_PRESCALE_1_8,0); //configura prescaler do timer1 \n
 *  distancia = HCSR04_read(ultrason[0]); //Chamada dentro de uma interrupcao de 1seg. \n
 */


#ifndef HCSR04_H
#define	HCSR04_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "types/types.h"
#include "gpio/hal_gpio.h"
#include "delay/hal_delay.h"
#include "timer/hal_timer.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

/** */
typedef struct
{
    /** */
    regPin trig;
    /** */
    regPin eco;
}HCSR04;

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/**
 * @brief Calcula o valor da constante usando o Fosc e prescaler passados pelo programador
 * para o calculos de distancia em centrimetros.
 * @param clock Clock usado para gerar os ciclos de maquina do microcontrolador. \n
 *  20000000F: refencia a um clock de 20MHz \n
 *  48000000F: refencia a um clock de 48MHz
 * @param prescaler Valor do prescaler que sera usado para medicao de tempo do sensor. \n
 *  1: prescaler igual a 1 \n
 *  2: prescaler igual a 2 \n
 *  ...etc
 */
void HCSR04_set_const(float clock, uint8_t prescaler);

/**
 * @brief Funcao que indica qual timer sera usado para medicao de tempo de duracao do eco.
 * @param modulo Referencia ao timer que sera usado.    \n
 *  _TMR0: referencia ao timer 0                        \n
 *  _TMR1: referencia ao timer 1                        \n
 *  _TMR2: referencia ao timer 2                        \n
 *  _TMR3: referencia ao timer 3                        \n
 *  ...etc.                                             \n
 */
void HCSR04_attach_Timer(uint8_t modulo);

/**
 * @brief TODO
 * @param index
 * @param trig
 * @param eco
 */
void HCSR04_attach(uint8_t index, regGPIO trig, regGPIO eco);

/**
 * @brief A funcao abaixo realiza a leitura da distancia em centimetros
 * @param sonar Variavel que contem as configuracoes do sensor.
 * @return Retorna a distancia em centimetros com resolucao de 2 casas decimais.
 */
uint16_t HCSR04_read(HCSR04 sonar);

extern HCSR04 ultrason[4];

#endif	/* HCSR04_H */
