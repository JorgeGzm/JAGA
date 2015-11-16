/**
  * @file    pid.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Set 20, 2015
  * @version 0.2.0.0 (beta)
  * @brief   Bibliteoca para o controle PID
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
// Included Files
//------------------------------------------------------------------------------

#include "pid.h"

//------------------------------------------------------------------------------
// Private Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Variable Declaration
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions Source
//------------------------------------------------------------------------------

float PI_control(float x, float x_ref, PI_Params *params)
{
  float erro_atual, y;

  erro_atual = x_ref - x;

  y = params->y_ant + params->q0*erro_atual + params->q1 * params->erro_ant;

  if(y > params->sat_max) y = params->sat_max;
  else if (y < params->sat_min) y = params->sat_min;

  params->erro_ant = erro_atual;
  params->y_ant = y;

  return y;
}

float PID_control(float x, float x_ref, PID_Params *params)
{
	float erro_atual;
    float y;

    float x2;
    erro_atual = x_ref - x;

    y = params->y_ant + params->q0 * erro_atual + params->q1 * params->erro_ant + params->q2 * params->erro_ant2;

    x2 = params->q1;

    if (y > params->sat_max) y = params->sat_max;
    else if (y < params->sat_min) y = params->sat_min;
    params->erro_ant2 = params->erro_ant;
    params->erro_ant = erro_atual;
    params->y_ant = y;

    return y;
}
