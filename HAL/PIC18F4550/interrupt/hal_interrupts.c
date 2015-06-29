/**
 * @file    hal_interrupts.c
 * @author  Rafael Lopes
 * @date    15 de Janeiro de 2015
 * @version 0.1.0.0 
 * @brief   Codigo do Driver Interrupts para o microcontrolador PIC18f4550.
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

#include "hal_interrupts.h"


static Interrupts interrupts_enable;
static Interrupts interrupts_priority;
static InterruptsCallBack interrupt_callback;

void interrupt_init(void)
{
    interrupts_enable.value = 0;

    interrupts_priority.value = 0;

    interrupt_callback.call_back_ctrl.value = 0;
}


void interrupt_setup(uint16 _interrupt, uint8 setup)
{
    switch(setup)
    {
        case ENABLE:
            interrupts_enable.value |= _interrupt;
        break;

        case DISABLE:
            interrupts_enable.value &= ~_interrupt;
        break;
    }
}


void interrupt_set_priority(uint16 _interrupt, uint8 priority)
{
    switch(priority)
    {
        case LOW_PRIORITY:
            interrupts_priority.value &= ~(_interrupt);
        break;

        case HIGH_PRIORITY:
            interrupts_priority.value |= _interrupt;
        break;
    }
}

/**
 * Funcao para verificar se a interrupcao esta habilitada e configurada com a prioridade desejada
 * Ex.: status = interrupt_is_enable(_TMR0, HIGH_PRIORITY);
 * @param _interrupt
 * @param priority
 * @return
 */
uint8 interrupt_is_enable(uint16 _interrupt, uint8 priority)
{
    uint8 enable_status;
    uint8 priority_status;

    enable_status = (interrupts_enable.value & _interrupt) ? INTERRUPT_ENABLE : INTERRUPT_DISABLE;

    priority_status = (interrupts_priority.value & _interrupt) ? HIGH_PRIORITY : LOW_PRIORITY;

    return((enable_status == INTERRUPT_ENABLE) && (priority_status == priority));
}

/**
 * @brief Tratamento das interrupcoes de Alta Prioridade.
 */
void interrupt isr_high_interrupt(void)
{
    

    if(interrupt_is_enable(_TMR0, HIGH_PRIORITY))
    {
        timer0_isr();
    }

    if(interrupt_is_enable(_TMR1, HIGH_PRIORITY))
    {
        timer1_isr();
    }

    if(interrupt_is_enable(_TMR2, HIGH_PRIORITY))
    {
        timer2_isr();
    }

    if(interrupt_is_enable(_TMR3, HIGH_PRIORITY))
    {
        timer3_isr();
    }

    if(interrupt_is_enable(_UART_RX, HIGH_PRIORITY))
    {
        uart_rx_isr();
    }

    if(interrupt_is_enable(_UART_TX, HIGH_PRIORITY))
    {
        uart_tx_isr();
    }
}

/**
 * @brief Tratamento das interrupcoes de Baixa Prioridade.
 */
void interrupt low_priority isr_low_interrupt(void)
{
    if(interrupt_is_enable(_TMR0, LOW_PRIORITY))
    {
        timer0_isr();
    }

    if(interrupt_is_enable(_TMR1, LOW_PRIORITY))
    {
        timer1_isr();
    }

    if(interrupt_is_enable(_TMR2, LOW_PRIORITY))
    {
        timer2_isr();
    }

    if(interrupt_is_enable(_TMR3, LOW_PRIORITY))
    {
        timer3_isr();
    }

    if(interrupt_is_enable(_UART_RX, LOW_PRIORITY))
    {
        uart_rx_isr();
    }

    if(interrupt_is_enable(_UART_TX, LOW_PRIORITY))
    {
        uart_tx_isr();
    }
}

/**
 *
 * @param _interrupt
 * @param function
 */
void interrupt_set_callback(uint16 _interrupt, void (*function)())
{
    switch(_interrupt)
    {
        case _TMR0:
            interrupt_callback.tmr0_callback = function;

            interrupt_callback.call_back_ctrl.TMR0 = 1;
        break;

        case _TMR1:
            interrupt_callback.tmr1_callback = function;

            interrupt_callback.call_back_ctrl.TMR1 = 1;
        break;

        case _TMR2:
            interrupt_callback.tmr2_callback = function;

            interrupt_callback.call_back_ctrl.TMR2 = 1;
        break;

        case _TMR3:
            interrupt_callback.tmr3_callback = function;

            interrupt_callback.call_back_ctrl.TMR3 = 1;
        break;

        case _UART_RX:
            interrupt_callback.uart_rx_callback = function;

            interrupt_callback.call_back_ctrl.UART_RX = 1;
        break;

        case _UART_TX:
            interrupt_callback.uart_tx_callback = function;

            interrupt_callback.call_back_ctrl.UART_TX = 1;
        break;

    }
}

inline static void timer0_isr(void)
{
    if(INTCONbits.TMR0IF)
    {
        if(interrupt_callback.call_back_ctrl.TMR0 != _NULL)
        {
            interrupt_callback.tmr0_callback();
        }

        //Limpa flag da interrupcao
        INTCONbits.TMR0IF = 0;
    }
}

inline static void timer1_isr(void)
{
    if(PIR1bits.TMR1IF)
    {
        if(interrupt_callback.call_back_ctrl.TMR1 != _NULL)
        {
            interrupt_callback.tmr1_callback();
        }

        //Limpa flag da interrupcao
        PIR1bits.TMR1IF = 0;
    }
}

inline static void timer2_isr(void)
{
    if(PIR1bits.TMR2IF)
    {
        if(interrupt_callback.call_back_ctrl.TMR2 != _NULL)
        {
            interrupt_callback.tmr2_callback();
        }

        //Limpa flag da interrupcao
        PIR1bits.TMR2IF = 0;
    }
}

inline static void timer3_isr(void)
{
    if(PIR2bits.TMR3IF)
    {
        if(interrupt_callback.call_back_ctrl.TMR3 != _NULL)
        {
            interrupt_callback.tmr3_callback();
        }

        //Limpa flag da interrupcao
        PIR2bits.TMR3IF = 0;
    }
}

inline static void uart_rx_isr(void)
{
    if(PIR1bits.RCIF)
    {
        if(interrupt_callback.call_back_ctrl.UART_RX != _NULL)
        {
          interrupt_callback.uart_rx_callback();
        }

        //Limpa flag da interrupcao
        PIR1bits.RCIF = 0;
    }
}

inline static void uart_tx_isr(void)
{
    if(PIR1bits.TXIF)
    {
        if(interrupt_callback.call_back_ctrl.UART_TX != _NULL)
        {
            interrupt_callback.uart_tx_callback();
        }

        //Limpa flag da interrupcao
        PIR1bits.TXIF = 0;
    }
}
