/**
  * @file    config_buttons.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Aug 18, 2015
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
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

#ifndef BUTTONS_CONF_H
    #define BUTTONS_CONF_H

/** @brief Define quantidade maxima de teclas que a biblioteca suporta. */
#define BUTTON_SIZE 8	

/** @brief Define o intervalo de tempo de espera para eliminar o debouce da tecla. */
#define BOUNCE      6

/** @brief Define em qual estado o botao esta acionado(0: PULL_UP	1:PULL_DOWN). */
#define BUTTON_PRESSED_STATE 1

/** @brief Define nomes para os botoes. */
typedef enum
{
    /* Nomes da aplicacao devem ser definido aqui*/
    
    /** @brief TODO */
    BTN_MENU = 1,

    /** @brief TODO */
    BTN_UP = 2,

    /** @brief TODO */
    BTN_DOWN = 4,

    /** @brief TODO */
    BTN_BACK = 8

} BUTTON_NAME;

#endif /** BUTTOHS_CONF_H*/
