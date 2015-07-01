/**
 * @file    buttons.h
 * @brief   Biblioteca para o uso de teclas.
 * @details Esta biblioca controla e configura os pinos do microcontrolador para o uso de ate 8 teclas.
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 (beta) 
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

#ifndef BUTTONS_H
    #define BUTTONS_H


#include "device/hal_device.h"
#include "gpio/hal_gpio.h"

enum SYS_TECLAS
{
    TECLA_MENU = 1,
    TECLA_UP = 2,
    TECLA_DOWN = 4,
    TECLA_BACK = 8
};


/** @brief Define o intervalo de tempo de espera para eliminar o debouce da tecla.*/
#define BOUNCE      2

/** Define quantidade maxima de teclas que a biblioteca suporta. */
#define BUTTON_SIZE 8

/** @brief Estrutura usada no controle do estado das teclas. */
union Buttons_
{
    /** @brief Varivel de 16bits usada no controle geral das teclas. */
    uint16 value;

    /** @brief Estrutura que quebra a variavel de "value" de 16 bits em 2 de 8bits. */
    struct
    {
         /** @brief Parte baixa que contem estados das teclas*/
        uint8 b1;
         /** @brief Parte alta que contem temporizador do debouce e se alguma tecla esta ou continua pressioada. */
        uint8 b2;
    }b;

    /** @brief Estrutura que quebra a variavel "value" de 16bits para acesso bit a bit. */
    struct
    {
        /** @brief Bit para controle de estado do botao 1. */
        unsigned button_1   : 1;
        
        /** @brief Bit para controle de estado do botao 2. */
        unsigned button_2   : 1;
        
        /** @brief Bit para controle de estado do botao 3. */
        unsigned button_3   : 1;
        
        /** @brief Bit para controle de estado do botao 4. */
        unsigned button_4   : 1;
        
        /** @brief Bit para controle de estado do botao 5. */
        unsigned button_5   : 1;
        
        /** @brief Bit para controle de estado do botao 6. */
        unsigned button_6   : 1;
        
        /** @brief Bit para controle de estado do botao 7. */
        unsigned button_7   : 1;
        
        /** @brief Bit para controle de estado do botao 8. */
        unsigned button_8   : 1;
        
        /** @brief Bit para indica se alguma tecla foi pressionada. */
        unsigned press      : 1; 
        
        /** @brief Bit para indicar se a tecla continua pressionada. */
        unsigned hold       : 1; 
        
        /** @brief Bit nao usado. */
        unsigned            : 1;
        
        /** @brief Bit nao usado. */
        unsigned            : 1;

        /** @brief Nibble usado como temporizador para elimidar o ruido(debounce) ao pressionar a tecla. */
        unsigned debounce : 4;
    };
};

/** @brief Define um novo nome a union Buttons_*/
typedef union Buttons_ Buttons;
 
/** @brief Inicializa com zero todo o vetor que contem a configuracao das teclas. */
void buttons_init(void);

/** 
 * @brief Verifica se alguma tecla foi pressionada a cada 10ms. 
 * @details A funcao espera um intervalo de tempo antes de confirmar o precionamento da tecla, eliminando assim o debaunce da chave mecanica.
*/
void buttons_read_isr_10ms(void);

/**
 * @brief Verifica e retorna 1 ou 0 se alguma tecla foi pressionado ou nao. \n
 * Ex:                                                          \n
 * if(buttons_check_press(BTN_MENU; 0))...                      \n
 *  ou                                                          \n
 * if(buttons_check_press(BTN_MENU; 1))...                      \n
 * @param UI8_botao Botao que deseja ser verificado.
 * @param press 0 = nao precisar soltar o botao para informar que ele foi pressionado. \n
 *              1 = e precisar soltar o botao para informar que ele foi pressionado.
 * @return  
 * 0 = botao nao foi prescionado.                               \n
 * 1 = botao foi prescionado.
 */
uint8 buttons_check_press(uint8 button_id, uint8 press);

/**
 * @brief Esta funcao configura uma nova tecla.
 * @details A funcao recebe um valor index < BUTTON_SIZE e o pino do microcontrolador que sera usado.
 * TODO: tratar combinacao de teclas.
 * @param index Range: 0 - 7
 * @param port
 * @param tris
 */
void button_attach(uint8 index, regGPIO *reg);

/**
 * 
 * @param button_id
 * @return 
 */
uint8 button_is_press(uint8 button_id);

/**
 * 
 * @param button_id
 * @return 
 */
uint8 button_is_hold(uint8 button_id);
/**  */
extern regPin buttons_vector[BUTTON_SIZE];

#endif /** BUTTOHS_H*/
