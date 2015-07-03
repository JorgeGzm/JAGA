/**
 * @file    hal_uart.h
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    26 de Abril de 2015
 * @version 0.1.0.0 

 * @brief   Driver UART para o microcontrolador TM4C123GXL.
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
 
#ifndef HAL_UART_H
#define	HAL_UART_H

#include "device/hal_device.h"
#include "gpio/hal_gpio.h"
#include "vars/vars.h"

#include "types/types.h"

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

/**
 * @brief TODO
 * @param pin
 * @param reg
 */
void uart_attach(regPin *pin, regGPIO *reg);

/**
 * @brief TODO
 * @param module TODO
 * @param rx TODO
 * @param tx TODO
 */
void uart_setup_interrupt(uint8 module, uint8 rx, uint8 tx);

/**
 * @brief TODO
 * @param module TODO
 * @param rx TODO
 * @param tx TODO
 */
void uart_priority_interrupt(uint8 module, uint8 rx, uint8 tx);

/**
 * @brief TODO
 * @param module TODO
 * @param enable_uart TODO
 * @param enable_rx  TODO
 * @param enable_tx TODO
 */
void uart_set_enable(uint8 module, uint8 enable_uart, uint8 enable_rx, uint8 enable_tx);

/**
 * @brief TODO
 * @param module TODO
 * @param sync TODO
 * @param high_com TODO
 * @param rx9bits TODO
 * @param tx9bits TODO
 * @param bd16bits TODO
 */
void uart_set_conf(uint8 module, uint8 sync, uint8 high_com, uint8 rx9bits, uint8 tx9bits, uint8 bd16bits);

/**
 * @brief TODO
 * @param module TODO
 * @param value TODO
 */
void uart_set_baudRate(uint8 module, uint8 value);

/**
 * @brief TODO
 * @param module TODO
 * @param func TODO
 */
void uart_rx_set_callbak(uint8 module, void (*func)(void));

/**
 * @brief TODO
 * @param module TODO
 * @param func TODO
 */
void uart_tx_set_callbak(uint8 module, void (*func)(void));

/**
 * @brief TODO
 * @param UI8_caracter TODO
 */
void uart_putc(uint8 UI8_caracter);
//__inline uint8 uart_get_data(void);

/**
 * @brief TODO
 * @return TODO
 */
uint8 uart_get_data(void);


#endif	/* HAL_UART_H */

