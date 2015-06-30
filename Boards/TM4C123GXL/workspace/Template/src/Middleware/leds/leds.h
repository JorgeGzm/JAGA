/**
 * @file    leds.h
 * @brief   Bibliteoca para o uso dos Leds
 * @details Esta biblioca usa ...         
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

#ifndef LEDS_H_
#define LEDS_H_

//Includes
#include "types/types.h"
#include "gpio/hal_gpio.h"

//Defini��es
#define LD1G 0x01   
#define LD2G 0x02   
#define LD3G 0x04   


/** Numero total de leds*/
#define NUM_LEDS 8
#define LED_OFF 0
#define LED_ON 1
#define LED_BLINK_SLOW 2
#define LED_BLINK_FAST 3

#define LED_BLINK_SLOW_STEP 10
#define LED_BLINK_FAST_STEP 3

/** @brief TODO*/
union _Leds
{
    uint8 UI8_value;

    struct
    {
        unsigned  L1 : 1;
        unsigned  L2 : 1;
        unsigned  L3 : 1;
        unsigned  L4 : 1;
        unsigned  L5 : 1;
        unsigned  L6 : 1;
        unsigned  L7 : 1;
        unsigned  L8 : 1;
    };
};
typedef union _Leds Leds;

/** @brief TODO*/
typedef struct _LD
{
   regGPIO ld1;
   regGPIO ld2;
   regGPIO ld3;
   regGPIO ld4;
   regGPIO ld5;
   regGPIO ld6;
   regGPIO ld7;
   regGPIO ld8;
}LD;

/**
 * @brief TODO
 */
void leds_init(void);

/**
 * Seta os bits das variaveis de controle do acendimento das leds.
 * Exemplo:
 * V_ledsSet(LD1G|LD2G,LED_ON);  Resultado: joga nivel logico 1 nos pinos RB0 e RB1
 * V_ledsSet(LD1G,LED_OFF);      Resultado: joga nivel logico zero no pino RB0
 * V_ledsSet(LD1G,LED_BLINK_SLOW); Resultado: gera um toogle lento no pino RB1
 * V_ledsSet(LD1G,LED_BLINK_FAST); Resultado: gera um toogle rapido no pino RB0
 * UI8_InLeds: range:0-255->2^n
 * @param UI8_InLeds: informa quas leds devem ser ligados. Range de 0 a 7(1byte->1Porte inteiro)
 * @param UI8_Action: LED_OFF = devemos apagar as leds em questao
 *                    LED_ON = devemos ascender as leds em questao
 *                    LED_BLINK_SLOW = devemos fazer as leds piscarem lentamente
 *                    LED_BLINK_FAST = devemos fazer as leds piscarem rapidamente
 */
void leds_set(uint8 UI16_InLeds, uint8 UI8_Action);

/**
 * @brief Inverte as leds representadas pelos bits 1 da mascara de entrada
 * @param UI8_LedsMask: mascara que contem quais leds serao invertidos
 */
void leds_reverse(uint8 UI16_LedsMask);

/**
 * @brief verifica se o timer para a revers�o dos leds estourou tanto no slow como no fast
 * deve ser chamado dentrao da interrucao de timer de 100mS.
 */
void leds_action_isr_10ms(void);

/**
 * @brief Verifica quals leds serao ligados
 * @param UI8_LedsMask: mascara que contem quais leds serao ligados.
 */
void leds_on(uint8 UI16_LedsMask);

/**
 * @brief Verifica quals leds serao desligados
 * @param UI8_LedsMask: mascara que contem quais leds serao desligados
 */
void leds_off(uint8 UI16_LedsMask);

/**
 * @brief TODO
 * @param out
 */
void leds_write(uint8 out);

/**
 * @brief TODO
 * @param pin
 * @param port
 * @param tris
 */
void leds_attach(regPin *pin, regGPIO *reg);

/**
 * @brief TODO
 * @return 
 */
uint8 leds_status(void);
//void V_presentation(void);


//Variaveis globais
extern regPin leds[NUM_LEDS];
extern Leds UN_ledsStatus, UN_ledsON, UN_ledsBlinkSlow, UN_ledsBlinkFast;

#endif /* LEDS_H_ */
