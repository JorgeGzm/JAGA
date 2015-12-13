/**
  * @file    leds.c
  * @author  Alexandre Bader; Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Apr 23, 2014
  * @version 0.2.0.0 (beta)
  * @brief   Bibliteoca para o uso dos Leds
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

#include "leds.h"
#include "bitwise/bitwise.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/**@brief TODO */
regPin leds[NUM_LEDS] = {
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
};

/** @brief Controle imediato do estado das leds */
Leds UN_ledsStatus;

/** @brief Indicao das leds que estao 100% ligadas */
Leds UN_ledsON;

/** @brief Indicao das Leds que estao picando lentamnete */
Leds leds_blink_slow;

/** @brief Indicao das Leds que estao piscando rapido */
Leds leds_blink_fast; 

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

/**
 * @brief Verifica quals leds serao ligados
 * @param UI8_LedsMask: mascara que contem quais leds serao ligados.
 */
static void leds_on(uint8_t leds_mask);

/**
 * @brief Verifica quals leds serao desligados
 * @param UI8_LedsMask: mascara que contem quais leds serao desligados
 */
static void leds_off(uint8_t leds_mask);

/**
 * @brief Inverte as leds representadas pelos bits 1 da mascara de entrada
 * @param UI8_LedsMask: mascara que contem quais leds serao invertidos
 */
static void leds_reverse(uint8_t leds_mask);

/**
 * @brief TODO
 * @param out
 */
static void leds_write(uint8_t out);

//==============================================================================
// SOURCE CODE
//==============================================================================

void leds_init(void)
{
    // Zera os valores das variaveis auxiliares
    UN_ledsStatus.UI8_value = 0;
    UN_ledsON.UI8_value = 0;
    leds_blink_slow.UI8_value = 0;
    leds_blink_fast.UI8_value = 0;
}

void leds_set(uint8_t in_leds, uint8_t action)
{
    // Variaveis locais
    uint8_t leds_temp; /// auxiliar para operacoes logicas

    // verifica qual acao que as leds em questao deve executar
    switch (action)
    {
        case LED_OFF:
        {
            // devemos apagar as leds em questao
            // XOR seguido de um AND para desligar os bits
            // Apaga as leds 100% ligadas
            leds_temp = UN_ledsON.UI8_value ^ in_leds;
            UN_ledsON.UI8_value = UN_ledsON.UI8_value & leds_temp;

            // apaga as leds com blink lento
            leds_temp = leds_blink_slow.UI8_value ^ in_leds;
            leds_blink_slow.UI8_value = leds_blink_slow.UI8_value & leds_temp;

            // apaga as leds com blink rapido
            leds_temp = leds_blink_fast.UI8_value ^ in_leds;
            leds_blink_fast.UI8_value = leds_blink_fast.UI8_value & leds_temp;

            // apaga as leds da mascara
            leds_off(in_leds);

            break;
        }
        case LED_ON:
        {
            // devemos ascender as leds em questao
            UN_ledsON.UI8_value = UN_ledsON.UI8_value | in_leds;

            // desliga as leds com blink lento
            leds_temp = leds_blink_slow.UI8_value ^ in_leds;
            leds_blink_slow.UI8_value = leds_blink_slow.UI8_value & leds_temp;

            // desliga as leds com blink rapido
            leds_temp = leds_blink_fast.UI8_value ^ in_leds;
            leds_blink_fast.UI8_value = leds_blink_fast.UI8_value & leds_temp;

            // acende as leds definidas
            leds_on(UN_ledsON.UI8_value);

            break;
        }
        case LED_BLINK_SLOW:
        {
            // devemos fazer as leds piscarem lentamente

            // Apaga as leds 100% ligadas
            leds_temp = UN_ledsON.UI8_value ^ in_leds;
            UN_ledsON.UI8_value = UN_ledsON.UI8_value & leds_temp;

            // ativa as leds com blink lento
            leds_blink_slow.UI8_value = leds_blink_slow.UI8_value | in_leds;

            // apaga as leds com blink rapido
            leds_temp = leds_blink_fast.UI8_value ^ in_leds;
            leds_blink_fast.UI8_value = leds_blink_fast.UI8_value & leds_temp;

            break;
        }
        case LED_BLINK_FAST:
        {
            // devemos fazer as leds piscarem rapidamente

            // Apaga as leds 100% ligadas
            leds_temp = UN_ledsON.UI8_value ^ in_leds;
            UN_ledsON.UI8_value = UN_ledsON.UI8_value & leds_temp;

            // apaga as leds com blink lento
            leds_temp = leds_blink_slow.UI8_value ^ in_leds;
            leds_blink_slow.UI8_value = leds_blink_slow.UI8_value & leds_temp;

            // ativa as leds com blink rapido
            leds_blink_fast.UI8_value = leds_blink_fast.UI8_value | in_leds;

            break;
        }
    }
}

void leds_attach(uint8_t index, regGPIO reg)
{
    //Aloca o pino para o botao
    GPIO_regPin_attach(&leds[index], &reg);

    //Configura pino do botao como saida
    GPIO_regPin_setDir(&reg, DIR_OUTPUT);
}

void leds_action_isr_100ms(void)
{
    static uint8_t timer_led_slow_reverse_counter = 0; /// variavel de controle do blink lento
    static uint8_t timer_led_fast_reverse_counter = 0; /// controle do blink rapido

    // soma 1 nos contadores
    timer_led_slow_reverse_counter++;
    timer_led_fast_reverse_counter++;

    // verifica se devemos fazer a revers�o para os slow blinks
    if (timer_led_slow_reverse_counter == LED_BLINK_SLOW_STEP)
    {
        // sim, o contador do slow estourou, fazemos a revers�o
        leds_reverse(leds_blink_slow.UI8_value);

        // zera o valor do contador apos a revers�o
        timer_led_slow_reverse_counter = 0;
    }

    // verifica se devemos fazer a revers�o para os fast blinks
    if (timer_led_fast_reverse_counter == LED_BLINK_FAST_STEP)
    {
        // sim, o contador do slow estourou, fazemos a revers�o
        leds_reverse(leds_blink_fast.UI8_value);

        // zera o valor do contador apos a revers�o
        timer_led_fast_reverse_counter = 0;
    }
}

static void leds_reverse(uint8_t leds_mask)
{
    // Variaveis locais
    uint8_t leds_temp; /// auxiliar para opera��es logicas

    // verifica se a mascara tem algum bit ativo
    if (leds_mask)
    {
        // Tem, ent�o executa a opera��o de invers�o
        // copia o status para var temp
        leds_temp = UN_ledsStatus.UI8_value;

        // ativa os bits definidos na mascara
        leds_on(leds_mask);

        // verifica se o valor � igual ao anterior, isso significa que os bits j� estava ligados
        if (leds_temp == UN_ledsStatus.UI8_value)
        {
            // ent�o devemos desligar os bits, pois eles ja estavam ativos
            leds_off(leds_mask);
        }
    }
}

static void leds_on(uint8_t leds_mask)
{
    uint8_t aux;
    // executa um OU para ativar os bits
    UN_ledsStatus.UI8_value = UN_ledsStatus.UI8_value | leds_mask;

    //Atualiza os LEDs no frontal
    aux = leds_status();
    aux |= UN_ledsStatus.UI8_value;

    leds_write(aux);
}

static void leds_off(uint8_t leds_mask)
{
    // Variaveis locais
    uint8_t aux;
    uint8_t leds_temp; /// auxiliar para opera��es logicas

    // devemos desligar os bits
    leds_temp = UN_ledsStatus.UI8_value ^ leds_mask;
    UN_ledsStatus.UI8_value = UN_ledsStatus.UI8_value & leds_temp;

    aux = UN_ledsStatus.UI8_value;
    aux &= ~leds_mask;

    //Atualiza os LEDs no frontal
    leds_write(aux);
}

uint8_t leds_status(void)
{
    uint8_t index;
    UByte status;
    status.value = 0;

    for(index = 0; index < NUM_LEDS; index++)
    {
        if(GPIO_regPin_rdBit(&leds[index]))
        {
            status.value|=  (1 << index);
        }
    }
    return(status.value);
}

static void leds_write(uint8_t out)
{
    uint8_t index;

    for (index = 0; index < NUM_LEDS; index++)
    {

        if (tst_bit(out, index))
        {
            GPIO_regPin_outputHigh(&leds[index]);
        } else
        {
            GPIO_regPin_outputLow(&leds[index]);
        }
    }
}

