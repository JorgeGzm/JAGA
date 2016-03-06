/**
  * @file    app_nivel_control.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); 
  * @date    Jan 31, 2016
  * @version 0.1.0.0 (beta)
  * @brief   App que faz todo o controle de nivel do tanque d'agua usando PID.
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

#include "app_nivel_control.h"
#include "HCSR04/HCSR04.h"
#include "pwm/hal_pwm.h"
#include "PID/pid.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================
#define ALTURA_TANQUE 28.150879F

PID_Params pid;
float fl_set_point;
    
float Td = 1;
float Ti = 0.1;
float Kp = 4;
float Tamost = 0.1;

float nivel_real = 0.0; //em cemtimetros
float pwm_out;

void init_nivel_controle(void)
{    
    fl_set_point = 15.0;

    pid.q0 = Kp * (1+Td/Tamost);
    pid.q1 = -Kp * (1+2*Td/Tamost - Tamost/Ti);    
    pid.q2 = Kp*Td/Tamost;

    pid.sat_min = 38.0;
    pid.sat_max = 90.0;   //Saturação da Saída

    pid.erro_ant = 0;
    pid.erro_ant2 = 0;
    pid.y_ant = 0;
}

void run_nivel_control(void)
{    
    nivel_real = ALTURA_TANQUE - HCSR04_read(0);  
  
//    if (nivel_real < 0.0)
//    {
//       nivel_real = 0.00; 
//    }
   
    pwm_out = PID_control(nivel_real, fl_set_point, &pid);
      
    if(pwm_out < 0.0)
    {
        pwm_out = 0.0;
    }
    else if(pwm_out > 80.00)
    {
        pwm_out = 80;
    }
    
    pwmMCU_set_fduty(pwm_out);        
}

float get_nivel_tanque(void)
{
    return nivel_real;
}

float get_nivel_dutyPWM(void)
{
    return pwm_out;
}

