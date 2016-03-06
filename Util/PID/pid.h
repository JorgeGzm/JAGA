/**
  * @file    pid.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Set 20, 2015
  * @version 0.2.0.0 (beta)
  * @brief   Bibliteoca para o uso das rodas do carrinho
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

#ifndef _PID_H
#define _PID_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================


/** @brief Struct de Parametros do Controlador PI */
typedef struct
{
    /** @brief Ganhos q0. q0 = Kp, Kp->Ganho Proporcional, Ti->Tempo de Integracao. */
    float q0;

    /**@brief Ganhos q1. q1 = -Kp*(1-Tamost/Ti), Tamost->Tempo de Amostragem. */
    float q1;

    /** @brief Saturacao da Saida. */
    float sat_min, sat_max;

    /** @brief Variáveis Auxiliares.*/
    float erro_ant, y_ant;

}PI_Params;


/** @brief Struct de Parametros do Controlador PID*/
typedef struct
{
    /** @brief Ganhos q0. q0 = Kp * (1+Td/Tamost) */
    float q0;

    /** @brief Ganhos q1. q1 = -Kp * (1+2Td/Tamost - Tamost/Ti)*/
    float q1;

    /** @brief Ganhos q2. q2 = Kp*Td/Tamost */
    float q2;

    /** @brief Saturacao da Saida. */
    float sat_min, sat_max;

    /** @brief Variaveis Auxiliares. */
    float erro_ant, erro_ant2, y_ant;

}PID_Params;

//==============================================================================
// Global Variable
//==============================================================================

//==============================================================================
// Public Prototype
//==============================================================================

/**
 * 
 * @param x
 * @param x_ref
 * @param params
 * @return 
 */
float PI_control(float x, float x_ref, PI_Params *params);

/**
 * 
 * @param x
 * @param x_ref
 * @param params
 * @return 
 */
float PID_control(float x, float x_ref, PID_Params *params);

#endif

