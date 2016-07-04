/**
  * @file    hal_pwm.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 6, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Driver de PWM para o microcontrolador PIC18f4550.
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

#ifndef HAL_PWM_H
    #define	HAL_PWM_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "types/types.h"
#include "device/hal_device.h"
#include "sys_mcu.h"
#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

#define PWM_COUNTER_OFF 0
#define PWM_COUNTER_ON 1

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/**Single output: P1A modulated; P1B, P1C, P1D assigned as port pins.*/
#define PWM_P1A_MODU_P1B_P1C_P1D_IO  0

/**Full-bridge output forward: P1D modulated; P1A active; P1B, P1C inactive*/
#define PWM_P1D_MODU_P1A_ACTI_P1C_P1D_INACT  1

/**Half-bridge output: P1A, P1B modulated with dead-band control; P1C, P1D assigned as port pins*/
#define PWM_P1A_P1D_MODU_P1C_P1D_IO  2

/**Full-bridge output reverse: P1B modulated; P1C active; P1A, P1D inactive*/
#define PWM_P1B_MODU_P1C_ACTI_P1A_P1D_INACT  3

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** PWM mode: P1A, P1C active-high; P1B, P1D active-high.*/
#define PWM_MODE_P1A_P1C_HIGH_P1B_P1D_HIGH 12

/**PWM mode: P1A, P1C active-high; P1B, P1D active-low.*/
#define PWM_MODE_P1A_P1C_HIGH_P1B_P1D_LOW 13

/**PWM mode: P1A, P1C active-low; P1B, P1D active-high.*/
#define PWM_MODE_P1A_P1C_LOW_P1B_P1D_HIGH 14

/**PWM mode: P1A, P1C active-low; P1B, P1D active-low.*/
#define PWM_MODE_P1A_P1C_LOW_P1B_P1D_LOW 15

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/**Timer2 Clock Prescale Select bits*/
#define PWM_TRM2_PRESCALE_1     0
#define PWM_TRM2_PRESCALE_4     1
#define PWM_TRM2_PRESCALE_16    2

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/**
 * @brief
 * @param func Bits de configuração de saída PWM Aprimorado: \n
 * PWM_P1A_MODU_P1B_P1C_P1D_IO:         \n
 * PWM_P1D_MODU_P1A_ACTI_P1C_P1D_INACT: \n
 * PWM_P1A_P1D_MODU_P1C_P1D_IO:         \n
 * PWM_P1B_MODU_P1C_ACTI_P1A_P1D_INACT: \n
 * @param ccp Configura modo de funciomaneoto do CCP. \n
 * PWM_MODE_P1A_P1C_HIGH_P1B_P1D_HIGH:  \n
 * PWM_MODE_P1A_P1C_HIGH_P1B_P1D_LOW:   \n
 * PWM_MODE_P1A_P1C_LOW_P1B_P1D_HIGH:   \n
 * PWM_MODE_P1A_P1C_LOW_P1B_P1D_LOW:    \n
 */
PUBLIC void pwmMCU_setup_conf(uint8_t func, uint8_t ccp);

/**
 * @brief
 * Configura de forma automatica o duty cicle.  \n
 * OBS: verificara os existem limites de configuracao!!
 * @param frequencia Frequencia desejada pelo usuario.
 */
void pwmMCU_set_frequencia(float periodo);

/**
 * @brief
 * @param enable Habilita/Desliga timer usado pelo modulo PWM \n
 * PWM_COUNTER_ON \n
 * PWM_COUNTER_OFF \n
 * @param prescale configura prescaler do timer usado PWM\ n
 * PWM_TRM2_PRESCALE_1: \n
 * PWM_TRM2_PRESCALE_4 \n
 * PWM_TRM2_PRESCALE_16 \n
 * @param postscale configura postscaler do timer usado PWM
 */
void pwmMCU_setup_tmr(uint8_t enable, float frequencia);

/**
 * @brief Configura Duty cycle
 * @param duty Porgentagem do duty cycle. Range: 0.00 - 100.00%
 */
PUBLIC void pwmMCU_set_fduty(float duty);

/**
 * @brief
 * @param duty
 */
PUBLIC void pwmMCU_set_duty(uint8_t duty);

#endif

