/**
  * @file    sys_timer.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 27, 2015
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

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "sys_timer.h"
#include "buttons/buttons.h"
#include "leds/leds.h"
#include "timer/hal_timer.h"
#include "interrupt/hal_interrupts.h"

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

/** @brief Funcao callback da interrupcao do TMR0 */
static void timer_counter(void);

/** @brief Contadores de 1 milisegundo */
inline static void counter_1_ms(void);

/** @brief Contadores de 10 milisegundos */
inline static void counter_10_ms(void);

/** @brief Contadores de 100 milisegundos */
inline static void counter_100_ms(void);

/** @brief Contadores de 1 segundo */
inline static void counter_1_s(void);

//==============================================================================
// SOURCE CODE
//==============================================================================

void init_timer0(void)
{
    //Inicializa TMR0
    timer_init_regs(_TMR0);

    //Configura TMR0 (1 ms)
    timer_setup_bits(_TMR0, TMR_BIT_16);
    timer_setup_scale(_TMR0, TMR_PRESCALE_ON, TMR0_PRESCALE_1_8, 0);
    timer_setup_clock(_TMR0, TMR_CLOCK_INT, TMR_LOW_TO_HIGH);
    timer_set_counter(_TMR0, 0xFA24);

    //Configura interrupcao TMR0
    timer_setup_interrupt(_TMR0, ENABLE);
    timer_priority_interrupt(_TMR0, HIGH_PRIORITY);
    timer_set_callbak(_TMR0, timer_counter);
    
    timer_start(_TMR0, TMR_ON);
}

static void timer_counter(void)
{
    // --- Temporizadores das bases de tempo 1ms, 10ms, 100ms, 1s ---
    //static uint8 tmr_1_ms = 1;
    static uint8_t tmr_10_ms = 9;
    static uint8_t tmr_100_ms = 99;
    static uint16_t tmr_1_s = 999;

    //Recarrega contador do timer
    timer_set_counter(_TMR0, 0xFA24);

   //Contadores de 1 milisegundo
    counter_1_ms();

    if((tmr_10_ms--) == 0)
    {
        tmr_10_ms = 9;

        //Contadores de 1 milisegundo
        counter_10_ms();
    }

    if((tmr_100_ms--) == 0)
    {
        tmr_100_ms = 99;

        //Contadores de 1 milisegundo
        counter_100_ms();
    }

    if((tmr_1_s--) == 0)
    {
        tmr_1_s = 999;

        //Contadores de 1 milisegundo
        counter_1_s();
    }
}

inline static void counter_1_ms(void)
{

}

inline static void counter_10_ms(void)
{
    //Leitura das teclas
    buttons_read_isr_10ms();
}

inline static void counter_100_ms(void)
{
    //varredura dos leds
    leds_action_isr_100ms();
}

inline static void counter_1_s(void)
{

}
