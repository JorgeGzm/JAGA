/**
  * @file    hal_interrupts.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jan 15, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Driver interrupts para o microcontrolador PIC18f4550.
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

#ifndef HAL_INTERRUPTS_H
	#define	HAL_INTERRUPTS_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "device/hal_device.h"
#include "vars/vars.h"
#include "uart/hal_uart.h"
#include "device/hal_device.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

/** @brief TODO */
#define _NULL       (0)

/** @brief TODO */
#define DISABLE     0
/** @brief TODO */
#define ENABLE      1

/** @brief TODO */
#define INTERRUPT_DISABLE   0
/** @brief TODO */
#define INTERRUPT_ENABLE    1

/** @brief TODO */
#define LOW_PRIORITY    0
/** @brief TODO */
#define HIGH_PRIORITY   1

/** @brief TODO */
#define _TMR0       0x0001

/** @brief TODO */
#define _TMR1       0x0002

/** @brief TODO */
#define _TMR2       0x0004

/** @brief TODO */
#define _TMR3       0x0008

/** @brief TODO */
#define _UART_RX    0x0010

/** @brief TODO */
#define _UART_TX    0x0020

/** @brief TODO */
#define _ALL    0xFFFF

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

/** @brief TODO */
typedef union 
{
    uint16 value;

    struct
    {
        unsigned TMR0 : 1;      //Habilita interrupcao do Timer 0
        unsigned TMR1 : 1;      //Habilita interrupcao do Timer 1
        unsigned TMR2 : 1;      //Habilita interrupcao do Timer 2
        unsigned TMR3 : 1;      //Habilita interrupcao do Timer 3

        unsigned UART_RX : 1;   //Habilita interrupcao RX da UART
        unsigned UART_TX : 1;   //Habilita interrupcao TX da UART

        unsigned ADC : 1;       //Habilita interrupcao do AD

        unsigned INT0 : 1;      //Habilita interrupcao externa 0
        unsigned INT1 : 1;      //Habilita interrupcao externa 1
        unsigned INT2 : 1;      //Habilita interrupcao externa 2

        unsigned RB : 1;        //Habilita interrupcao de mudanca do PortB

        unsigned MSSP : 1;      //Habilita interrupcao do modulo MSSP

        unsigned CCP1 : 1;      //Habilita interrupcao do modulo CCP1
        unsigned CCP2 : 1;      //Habilita interrupcao do modulo CCP2

        unsigned USB : 1;       //Habilita interrupcao do modulo USB

        unsigned EEPROM : 1;    //Habilita interrupcao de escrita na EEPROM

        unsigned COMP : 1;      //Habilita interrupcao de mudanca da entrada do comparador
    };
}Interrupts;

/** @brief TODO */
typedef struct 
{
    /** @brief TODO */
    Interrupts call_back_ctrl;

    /** @brief TODO */
    void (*tmr0_callback)();
    
    /** @brief TODO */
    void (*tmr1_callback)();
    
    /** @brief TODO */
    void (*tmr2_callback)();
    
    /** @brief TODO */
    void (*tmr3_callback)();
    
    /** @brief TODO */
    void (*uart_rx_callback)();
    
    /** @brief TODO */
    void (*uart_tx_callback)();
    
}InterruptsCallBack;

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

/** @berif TODO */
void interrupt_init(void);

/**
 * @brief Funcao para habilitar/desabilitar o tratamento das interrupcoes selecionadas
 * Ex.: interrupts_setup(_TMR0 | _TMR1 | _UART_RX, ENABLE);
 * @param _interrupt
 * @param setup
 */
void interrupt_setup(uint16 _interrupt, uint8 setup);

/**
 * @brief Funcao para configurar o nivel de prioridade da interrupcao selecionada
 * Ex.: interrupt_set_priority(_TMR0, LOW_PRIORITY);
 *      interrupt_set_priority(_UART_RX, HIGH_PRIORITY);
 * @param _interrupt
 * @param priority
 */
void interrupt_set_priority(uint16 _interrupt, uint8 priority);

/** @brief TODO */
void interrupt_set_callback(uint16 _interrupt, void (*function)());

/** @brief TODO */
inline static void timer0_isr(void);

/** @brief TODO */
inline static void timer1_isr(void);

/** @brief TODO */
inline static void timer2_isr(void);

/** @brief TODO */
inline static void timer3_isr(void);

/** @brief TODO */
inline static void uart_rx_isr(void);

/** @brief TODO */
inline static void uart_tx_isr(void);

#endif	
