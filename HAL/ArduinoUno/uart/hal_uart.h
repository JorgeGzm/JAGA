/**
  * @file    hal_uart.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 11, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Driver UART para o microcontrolador ATMEGA328P.
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

/** @brief TODO*/
#define _UART0   0x0000

/** @brief TODO*/
#define _UART1   0x0001

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
/** @brief Habilita recepcao continua*/
#define UART_ENABLE_RX  1

/** @brief Desabilita recepcao continua*/
#define UART_DISABLE_RX 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/** @brief Habilita transmissao*/
#define UART_ENABLE_TX  1

/** Desabilita transmissao*/
#define UART_DISABLE_TX 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Porta serial habilitada*/
#define UART_ENABLE   1 

/** @brief Porta serial desabilitada*/
#define UART_DISABLE  0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief TODO*/
#define BAUD_4800   1

/** @brief TODO*/
#define BAUD_9600   2

/** @brief TODO*/
#define BAUD_19200  3

/** @brief TODO*/
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
 * @param pin TODO
 * @param port TODO
 * @param tris TODO
 */
void uart_attach(regPin reg, regGPIO port);

/**
 * @brief
 * @param module Canal UART que sera usado.
 *  _UART1: UART 1.
 * @param rx Habilita ou Desabilita a interrupcao modulo receptor da porta serial
 * @param tx Habilita ou Desabilita a interrupcao modulo transmissao da porta serial
 */
void uart_setup_interrupt(uint8_t module, uint8_t rx, uint8_t tx);

/**
 * @brief TODO
 * @param module Canal UART que sera usado. \n
 *  _UART1: UART 1.
 * @param rx Modulo receptor, alta ou baixa prioridade  \n
 *  ENABLE: Habilita recepcao de dados como interrupcao de alta prioridade \n
 *  DISABLE: Habilita recepcao de dados como interrupcao de baixa prioridade 
 * @param tx Modulo transmissao , alta ou baixa prioridade \n
 *  ENABLE: Habilita transmissao de dados como interrupcao de alta prioridade \n
 *  DISABLE: Habilita transmissao de dados como interrupcao de baixa prioridade \n
 */
void uart_priority_interrupt(uint8_t module, uint8_t rx, uint8_t tx);

/**
 * @brief TODO
 * @param module Seleciona UART que sera configurada.
 *  _UART1: UART 1.
 * @param enable_uart Habilita/Desabilita porta serial \n
 *  UART_ENABLE: Porta serial habilitada \n
 *  UART_DISABLE: Porta serial Desabilitada 
 * @param enable_rx Configura uart como recepcao continua de dados ou nao. \n
 *  UART_ENABLE_RX: Habilita recepcao continua. \n
 *  UART_DISABE_RX: Desabilita recepcao continua. 
 * @param enable_tx Habilita/Desabilita transmissao. \n
 *  UART_ENABLE_TX: Habilita transmissao. \n
 *  UART_DISABLE_TX: Desabilita transmissao.
 */
void uart_set_enable(uint8_t module, uint8_t enable_uart, uint8_t enable_rx, uint8_t enable_tx);

/**
 * @brief TODO
 * @param module Seleciona UART que sera configurada. \n
 *  _UART1: UART 1.
 * @param sync Configura transmissao como aincrona ou assincrona. \n
 *  UART_ASYNC: Transmissao assincrona \n
 *  UART_SYNC: Transmissao sincrona
 * @param high_com Configura comunicacao como alta ou baixa velocidade. \n
 *  UART_LOW_COM: Baixa velocidade de comunicacao \n
 *  UART_HIGH_COM: Alta velocidade de comunicacao 
 * @param rx9bits Configura recepcao da uart como 8 ou 9 bits. \n
 *  UART_RX_8BITS: Habilita recepcao de 8 bits. \n
 *  UART_RX_9BITS: Habilita recepcao de 9 bits. 
 * @param tx9bits Configura transmissao da uart como 8 ou 9 bits. \n
 *  UART_TX_8BITS: Habilita transmissao de 8 bits. \n
 *  UART_TX_9BITS: Habilita transmissao de 9 bits.
 * @param bd16bits Configura o gerador de baud rate como 8 ou 16 bits. \n
 *  UART_BD_8BITS: Gerador de baud rate de 8 bits. \n
 *  UART_BD_16BITS: Gerador de baud rate de 16 bits.
 */
void uart_set_conf(uint8_t module, uint8_t sync, uint8_t high_com, uint8_t rx9bits, uint8_t tx9bits, uint8_t bd16bits);

/**
 * @brief TODO
 * @param module Seleciona UART que sera configurada.
 * @param value \n
 *  BAUD_4800: configura baud rate com 4800 bits/s \n
 *  BAUD_9600: configura baud rate com 9600 bits/s \n
 *  BAUD_19200: \n
 *  BAUD_115200: \n
 */
void uart_set_baudRate(uint8_t module, uint8_t value);

/**
 * @brief TODO
 * @param module Seleciona UART que sera configurada. \n
 *  _UART1: UART 1.  \n
 * @param func
 */
void uart_rx_set_callbak(uint8_t module, void (*func)(uint8_t));

/**
 * @brief TODO
 * @param module Seleciona UART que sera configurada. \n
 *  _UART1: UART 1. \n
 * @param func
 */
void uart_tx_set_callbak(uint8_t module, void (*func)(void));

/**
 * @brief A funcao envia um  byte  pela porta serial.
 * @param UI8_caracter recebe o byte que sera enviado pela serial.
 */
void uart0_putc(uint8_t UI8_caracter);

/**
 * @brief TODO
 * @return Retorna dado recebido pela serial.
 */
inline uint8_t uart0_getc(void);

#endif	
