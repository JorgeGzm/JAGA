/**
  * @file    HCSR04.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Apr 5, 2015
  * @version 0.2.0.0 (beta)
  * @brief   Codigo da biblioteca realiza o calculo de distancia em centimetros usando o sensor HCSR04.
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

//------------------------------------------------------------------------------
// PRIVATE DEFINITIONS
//------------------------------------------------------------------------------

#include "HCSR04.h"

//------------------------------------------------------------------------------
// PRIVATE TYPEDEFS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PRIVATE VARIABLES			
//------------------------------------------------------------------------------

/** */
HCSR04 ultrason[4] =
{
    {0,0},
    {0,0},
    {0,0},
    {0,0},
};

/** */
uint8_t timerM = 0;

/** constante*/
float k = 0.0;

//------------------------------------------------------------------------------
// PRIVATE FUNCTIONS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SOURCE CODE
//------------------------------------------------------------------------------

void HCSR04_set_const(float clock, uint8_t prescaler)
{
    float aux;

    //constante  = 0.017(cm/us)*(prescaler*Fosc(us))
    k = 0.03433*(4.00/clock)*prescaler;
    k = k*1000000.00;
    k = k/2.0;
}

void HCSR04_attach_Timer(uint8_t modulo)
{
    timerM = modulo;
}

void HCSR04_attach(uint8_t index, regGPIO trig, regGPIO eco)
{
    //Aloca o pino para o botao
    GPIO_regPin_attach(&ultrason[index].trig, &trig);
	GPIO_regPin_attach(&ultrason[index].eco, &eco);

    GPIO_regPin_setDir(&trig, DIR_OUTPUT);
    GPIO_regPin_setDir(&eco, DIR_INPUT);
}

uint16_t HCSR04_read(HCSR04 sonar)
{
    float fl_distancia = 0.0;
    UWord count_timer;

    //limpa contador
    timer_set_counter(timerM, 0);

    //Pulso
    GPIO_regPin_outputHigh(&sonar.trig);
    Delay_us(10);
    GPIO_regPin_outputLow(&sonar.trig);

    //ECO
    while(!GPIO_regPin_inputBit(&sonar.eco));
    //while(!GPIO_input_state(sonar.eco.port));//espera chegada do eco
    timer_start(timerM,1);//start
    while(GPIO_regPin_inputBit(&sonar.eco));
    //while(GPIO_input_state(sonar.eco.port));
    timer_start(timerM,0);//stop

    //Calculo de distancia.
    count_timer.value = timer_get_counter(timerM);

    //fl_distancia = (float)distancia.value*0.011328;
    fl_distancia = (float)count_timer.value*k;

    return (uint16_t)(fl_distancia*100);
}

