/**
  * @file    buttons.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 27, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Biblioteca para o uso de teclas.
  * @details Esta biblioca controla e configura os pinos do microcontrolador para o uso de ate 8 teclas.
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

#ifndef BUTTONS_H
    #define BUTTONS_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "device/hal_device.h"
#include "gpio/hal_gpio.h"
#include "config_buttons.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

/** @brief TODO */
typedef enum 
{
    /** @brief TODO */
    BTN_PULSE = 0,
    
    /** @brief TODO */
    BTN_CONTINUOS  
            
} BUTTON_CHECK_TYPE; 

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------
 
/** @brief Inicializa com zero todo o vetor que contem a configuracao das teclas. */
void buttons_init(void);

/** 
 * @brief Verifica se alguma tecla foi pressionada a cada 10ms. 
 * @details A funcao espera um intervalo de tempo antes de confirmar o precionamento da tecla, eliminando assim o debaunce da chave mecanica.
*/
void buttons_read_isr_10ms(void);

/**
 * @brief Verifica e retorna 1 ou 0 se alguma tecla foi pressionado ou nao. 
 * @details
 * Ex:                                                          \n
 * if(buttons_check_press(BTN_MENU; 0))...                      \n
 *  ou                                                          \n
 * if(buttons_check_press(BTN_MENU; 1))...                      \n
 * @param button_id Botoes que deseja ser verificados.
 * @param press 0 = nao precisar soltar o botao para informar que ele foi pressionado. \n
 *              1 = e precisar soltar o botao para informar que ele foi pressionado.
 * @return  
 * 0 = botao nao foi prescionado.                               \n
 * 1 = botao foi prescionado.
 */
uint8 buttons_check_press(BUTTON_NAME button_id, BUTTON_CHECK_TYPE press);

/**
 * @brief Esta funcao configura uma nova tecla.
 * @details A funcao recebe um valor index < BUTTON_SIZE e o pino do microcontrolador que sera usado.
 * TODO: tratar combinacao de teclas.
 * @param index Range: 0 - 7
 * @param reg
 */
void button_attach(uint8 index, regGPIO reg);

#endif 
