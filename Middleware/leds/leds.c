/**
 * @file    lib_leds.c
 * @brief   Bibliteoca para o uso dos Leds
 * @author  Alexandre Bader; Jorge Guzman
 * @date    23 de Abril de 2014
 * @version 0.2.0.0 (beta)
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
 *
 * @section DESCRIPTION
 */

#include "leds.h"

 /**@brief */
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

/** @brief Controle imediato do estado das leds*/
Leds UN_ledsStatus;

/** @brief Indicação das leds que estão 100% ligadas*/
Leds UN_ledsON;

/** @brief Indicação das Leds que estão picando lentamnete*/
Leds UN_ledsBlinkSlow;

/** @brief Indicação das Leds que estão piscando rápido*/
Leds UN_ledsBlinkFast; 

void leds_init(void)
{
    // Zera os valores das variaveis auxiliares
    UN_ledsStatus.UI8_value = 0;
    UN_ledsON.UI8_value = 0;
    UN_ledsBlinkSlow.UI8_value = 0;
    UN_ledsBlinkFast.UI8_value = 0;
}

void leds_set(uint8 UI8_InLeds, uint8 UI8_Action)
{
    // Variaveis locais
    uint8 UI8_LedsTemp; /// auxiliar para operações logicas

    // verifica qual acão que as leds em questão deve executar
    switch (UI8_Action)
    {
        case LED_OFF:
        {
            // devemos apagar as leds em questao
            // XOR seguido de um AND para desligar os bits
            // Apaga as leds 100% ligadas
            UI8_LedsTemp = UN_ledsON.UI8_value ^ UI8_InLeds;
            UN_ledsON.UI8_value = UN_ledsON.UI8_value & UI8_LedsTemp;

            // apaga as leds com blink lento
            UI8_LedsTemp = UN_ledsBlinkSlow.UI8_value ^ UI8_InLeds;
            UN_ledsBlinkSlow.UI8_value = UN_ledsBlinkSlow.UI8_value & UI8_LedsTemp;

            // apaga as leds com blink rapido
            UI8_LedsTemp = UN_ledsBlinkFast.UI8_value ^ UI8_InLeds;
            UN_ledsBlinkFast.UI8_value = UN_ledsBlinkFast.UI8_value & UI8_LedsTemp;

            // apaga as leds da mascara
            leds_off(UI8_InLeds);

            break;
        }
        case LED_ON:
        {
            // devemos ascender as leds em questao
            UN_ledsON.UI8_value = UN_ledsON.UI8_value | UI8_InLeds;

            // desliga as leds com blink lento
            UI8_LedsTemp = UN_ledsBlinkSlow.UI8_value ^ UI8_InLeds;
            UN_ledsBlinkSlow.UI8_value = UN_ledsBlinkSlow.UI8_value & UI8_LedsTemp;

            // desliga as leds com blink rapido
            UI8_LedsTemp = UN_ledsBlinkFast.UI8_value ^ UI8_InLeds;
            UN_ledsBlinkFast.UI8_value = UN_ledsBlinkFast.UI8_value & UI8_LedsTemp;

            // acende as leds definidas
            leds_on(UN_ledsON.UI8_value);

            break;
        }
        case LED_BLINK_SLOW:
        {
            // devemos fazer as leds piscarem lentamente

            // Apaga as leds 100% ligadas
            UI8_LedsTemp = UN_ledsON.UI8_value ^ UI8_InLeds;
            UN_ledsON.UI8_value = UN_ledsON.UI8_value & UI8_LedsTemp;

            // ativa as leds com blink lento
            UN_ledsBlinkSlow.UI8_value = UN_ledsBlinkSlow.UI8_value | UI8_InLeds;

            // apaga as leds com blink rapido
            UI8_LedsTemp = UN_ledsBlinkFast.UI8_value ^ UI8_InLeds;
            UN_ledsBlinkFast.UI8_value = UN_ledsBlinkFast.UI8_value & UI8_LedsTemp;

            break;
        }
        case LED_BLINK_FAST:
        {
            // devemos fazer as leds piscarem rapidamente

            // Apaga as leds 100% ligadas
            UI8_LedsTemp = UN_ledsON.UI8_value ^ UI8_InLeds;
            UN_ledsON.UI8_value = UN_ledsON.UI8_value & UI8_LedsTemp;

            // apaga as leds com blink lento
            UI8_LedsTemp = UN_ledsBlinkSlow.UI8_value ^ UI8_InLeds;
            UN_ledsBlinkSlow.UI8_value = UN_ledsBlinkSlow.UI8_value & UI8_LedsTemp;

            // ativa as leds com blink rapido
            UN_ledsBlinkFast.UI8_value = UN_ledsBlinkFast.UI8_value | UI8_InLeds;

            break;
        }
    }
}

void leds_attach(uint8 index, regGPIO reg)
{
    //Aloca o pino para o botao
    GPIO_regPin_attach(&leds[index], &reg);

    //Configura pino do botao como saida
    GPIO_regPin_setDir(&reg, 0);
}

void leds_action_isr_10ms(void)
{
    static uint8 UI8_timerLedSlowReverseCounter = 0; /// variavel de controle do blink lento
    static uint8 UI8_timerLedFastReverseCounter = 0; /// controle do blink rapido

    // soma 1 nos contadores
    UI8_timerLedSlowReverseCounter++;
    UI8_timerLedFastReverseCounter++;

    // verifica se devemos fazer a reversão para os slow blinks
    if (UI8_timerLedSlowReverseCounter == LED_BLINK_SLOW_STEP)
    {
        // sim, o contador do slow estourou, fazemos a reversão
        leds_reverse(UN_ledsBlinkSlow.UI8_value);

        // zera o valor do contador apos a reversão
        UI8_timerLedSlowReverseCounter = 0;
    }

    // verifica se devemos fazer a reversão para os fast blinks
    if (UI8_timerLedFastReverseCounter == LED_BLINK_FAST_STEP)
    {
        // sim, o contador do slow estourou, fazemos a reversão
        leds_reverse(UN_ledsBlinkFast.UI8_value);

        // zera o valor do contador apos a reversão
        UI8_timerLedFastReverseCounter = 0;
    }
}

void leds_reverse(uint8 UI8_LedsMask)
{
    // Variaveis locais
    uint8 UI8_LedsTemp; /// auxiliar para operações logicas

    // verifica se a mascara tem algum bit ativo
    if (UI8_LedsMask)
    {
        // Tem, então executa a operação de inversão
        // copia o status para var temp
        UI8_LedsTemp = UN_ledsStatus.UI8_value;

        // ativa os bits definidos na mascara
        leds_on(UI8_LedsMask);

        // verifica se o valor é igual ao anterior, isso significa que os bits já estava ligados
        if (UI8_LedsTemp == UN_ledsStatus.UI8_value)
        {
            // então devemos desligar os bits, pois eles ja estavam ativos
            leds_off(UI8_LedsMask);
        }
    }
}

void leds_on(uint8 UI8_LedsMask)
{
    uint8 UI8_aux;
    // executa um OU para ativar os bits
    UN_ledsStatus.UI8_value = UN_ledsStatus.UI8_value | UI8_LedsMask;

    //Atualiza os LEDs no frontal
    UI8_aux = leds_status();
    UI8_aux |= UN_ledsStatus.UI8_value;

    leds_write(UI8_aux);
}

void leds_off(uint8 UI8_LedsMask)
{
    // Variaveis locais
    uint8 UI8_aux;
    uint8 UI8_LedsTemp; /// auxiliar para operações logicas

    // devemos desligar os bits
    UI8_LedsTemp = UN_ledsStatus.UI8_value ^ UI8_LedsMask;
    UN_ledsStatus.UI8_value = UN_ledsStatus.UI8_value & UI8_LedsTemp;

    UI8_aux = UN_ledsStatus.UI8_value;
    UI8_aux &= ~UI8_LedsMask;

    //Atualiza os LEDs no frontal
    leds_write(UI8_aux);
}

uint8 leds_status(void)
{
    uint8 i;
    UByte status;
    status.value = 0;

    for(i = 0; i < NUM_LEDS; i++)
    {
        if(GPIO_regPin_rdBit(&leds[i]))
        {
            status.value|=  (1 << i);
        }
    }
    return(status.value);
}

void leds_write(uint8 out)
{
    uint8 i;

    for (i = 0; i < NUM_LEDS; i++)
    {

        if (tst_bit(out, i))
        {
            GPIO_regPin_outputHigh(&leds[i]);
        } else
        {
            GPIO_regPin_outputLow(&leds[i]);
        }
    }
}

