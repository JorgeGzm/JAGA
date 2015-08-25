/**
  * @file    leds.h
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

#ifndef LEDS_H_
#define LEDS_H_

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "types/types.h"
    #include "gpio/hal_gpio.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

#define LD1G 0x01   
#define LD2G 0x02   
#define LD3G 0x04   
#define LD4G 0x08    
#define LD1R 0x10   

/** Numero total de leds*/
#define NUM_LEDS 8
#define LED_OFF 0
#define LED_ON 1
#define LED_BLINK_SLOW 2
#define LED_BLINK_FAST 3

#define LED_BLINK_SLOW_STEP 10
#define LED_BLINK_FAST_STEP 3

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

/** @brief TODO*/
typedef union
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
}Leds;

/** @brief TODO*/
typedef struct 
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


//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

/**
 * @brief TODO
 */
void leds_init(void);

/**
 * @brief Seta os bits das variaveis de controle do acendimento das leds.
 * @details 
 * Exemplo:                                                                         \n
 * V_ledsSet(LD1G|LD2G,LED_ON);  Resultado: joga nivel logico 1 nos pinos RB0 e RB1 \n
 * V_ledsSet(LD1G,LED_OFF);      Resultado: joga nivel logico zero no pino RB0      \n
 * V_ledsSet(LD1G,LED_BLINK_SLOW); Resultado: gera um toogle lento no pino RB1      \n
 * V_ledsSet(LD1G,LED_BLINK_FAST); Resultado: gera um toogle rapido no pino RB0     \n
 * UI8_InLeds: range:0-255->2^n
 * @param UI8_InLeds: informa quas leds devem ser ligados. Range de 0 a 7(1byte->1Porte inteiro)
 * @param UI8_Action: LED_OFF = devemos apagar as leds em questao
 *                    LED_ON = devemos ascender as leds em questao
 *                    LED_BLINK_SLOW = devemos fazer as leds piscarem lentamente
 *                    LED_BLINK_FAST = devemos fazer as leds piscarem rapidamente
 */
void leds_set(uint8 in_leds, uint8 action);

/**
 * @brief Inverte as leds representadas pelos bits 1 da mascara de entrada
 * @param UI8_LedsMask: mascara que contem quais leds serao invertidos
 */
void leds_reverse(uint8 leds_mask);

/**
 * @brief verifica se o timer para a revers�o dos leds estourou tanto no slow como no fast
 * deve ser chamado dentrao da interrucao de timer de 100mS.
 */
void leds_action_isr_100ms(void);

/**
 * @brief Verifica quals leds serao ligados
 * @param UI8_LedsMask: mascara que contem quais leds serao ligados.
 */
void leds_on(uint8 leds_mask);

/**
 * @brief Verifica quals leds serao desligados
 * @param UI8_LedsMask: mascara que contem quais leds serao desligados
 */
void leds_off(uint8 leds_mask);

/**
 * @brief TODO
 * @param out
 */
void leds_write(uint8 out);

/**
 * @brief TODO
 * @param index TODO
 * @param reg   TODO
 */
void leds_attach(uint8 index, regGPIO reg);

/**
 * @brief TODO
 * @return TODO
 */
uint8 leds_status(void);

#endif 
