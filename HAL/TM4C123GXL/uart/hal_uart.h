/**
  * @file    hal_uart.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Apr 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Driver UART para o microcontrolador TM4C123GXL.
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

#ifndef HAL_UART_H
	#define	HAL_UART_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>
#include "device/hal_device.h"
#include "gpio/hal_gpio.h"
#include "types/types.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

#define _UART0   0x0000
#define _UART1   0x0001
#define _UART2   0x0002

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Transmissao assincrona*/
#define UART_ASYNC 0

/** @brief Transmissao sincrona*/
#define UART_SYNC 1

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Baixa velocidade de comunicacao*/
#define UART_LOW_COM    0

/** @brief Alta velocidade de comunicacao*/
#define UART_HIGH_COM   1

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Habilita recepcao de 9 bits*/
#define UART_RX_9BITS 1

/** @brief Habilita recepcao de 8 bits*/
#define UART_RX_8BITS 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Habilita transmissao de 9 bits*/
#define UART_TX_9BITS 1

/** @brief Habilita transmissao de 8 bits*/
#define UART_TX_8BITS 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Gerador de baud rate de 8 bits*/
#define UART_BD_8BITS   0 //?? verificar

/** @brief Gerador de baud rate de 16 bits*/
#define UART_BD_16BITS  1

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/** @brief Habilita recepcao continua*/
#define UART_ENABLE_RX  1

/** @brief Desabilita recepcao continua*/
#define UART_DISABLE_RX 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/** @brief Habilita transmissao*/
#define UART_ENABLE_TX  1

/** @brief Desabilita transmissao*/
#define UART_DISABLE_TX 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Porta serial habilitada*/
#define UART_ENABLE   1 

/** @brief Porta serial desabilitada*/
#define UART_DISABLE  0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief TODO transformar em enum*/
#define BAUD_4800   1
/** @brief TODO */
#define BAUD_9600   2
/** @brief TODO */
#define BAUD_19200  3
/** @brief TODO */
#define BAUD_115200 4

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
 * @brief TODO
 * @param pin
 * @param reg
 */
void uart_attach(uint8_t rx, uint8_t tx);

/**
 * @brief TODO
 * @param module TODO
 * @param rx TODO
 * @param tx TODO
 */
void uart_setup_interrupt(uint8_t module, uint8_t rx, uint8_t tx);

/**
 * @brief TODO
 * @param module TODO
 * @param rx TODO
 * @param tx TODO
 */
void uart_priority_interrupt(uint8_t module, uint8_t rx, uint8_t tx);

/**
 * @brief TODO
 * @param module TODO
 * @param enable_uart TODO
 * @param enable_rx  TODO
 * @param enable_tx TODO
 */
void uart_set_enable(uint8_t module, uint8_t enable_uart, uint8_t enable_rx, uint8_t enable_tx);

/**
 * @brief TODO
 * @param module TODO
 * @param sync TODO
 * @param high_com TODO
 * @param rx9bits TODO
 * @param tx9bits TODO
 * @param bd16bits TODO
 */
void uart_set_conf(uint8_t module, uint8_t sync, uint8_t high_com, uint8_t rx9bits, uint8_t tx9bits, uint8_t bd16bits);

/**
 * @brief TODO
 * @param module TODO
 * @param value TODO
 */
void uart_set_baudRate(uint8_t module, uint8_t value);

/**
 * @brief TODO
 * @param module TODO
 * @param func TODO
 */
void uart_rx_set_callback(uint8_t module, void (*func)(uint8_t));

/**
 * @brief TODO
 * @param module TODO
 * @param func TODO
 */
void uart_tx_set_callback(uint8_t module, void (*func)(void));

/**
 * @brief TODO
 * @param UI8_caracter TODO
 */
void uart0_putc(uint8_t UI8_caracter);
//__inline uint8 uart_get_data(void);

/**
 * @brief TODO
 * @return TODO
 */
uint8_t uart0_get_data(void);

/**
 * @brief TODO
 * @param UI8_caracter TODO
 */
void uart1_putc(uint8_t UI8_caracter);

/**
 * @brief TODO
 * @return TODO
 */
uint8_t uart1_get_data(void);


#endif	
