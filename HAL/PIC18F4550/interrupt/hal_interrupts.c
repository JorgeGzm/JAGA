/**
  * @file    hal_interrupts.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jan 15, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo do Driver Interrupts para o microcontrolador PIC18f4550.
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

#include "hal_interrupts.h"
#include "device/hal_device.h"
#include "uart/hal_uart.h"
#include "timer/hal_timer.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//static Interrupts interrupts_enable;
//static Interrupts interrupts_priority;
//static InterruptsCallBack interrupt_callback;

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

void interrupt_init(void)
{
   
}

/**
 * @brief Tratamento das interrupcoes de Alta Prioridade.
 */
void interrupt isr_high_interrupt(void)
{
    timer0_isr();  
    
    uart_rx_isr();
 
}

/**
 * @brief Tratamento das interrupcoes de Baixa Prioridade.
 */
void interrupt low_priority isr_low_interrupt(void)
{    
   
}


