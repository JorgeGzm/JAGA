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


//Includes
#include "device/hal_device.h"
#include "gpio/hal_gpio.h"
#include "vars/vars.h"

#include "types/types.h"

#define _UART1   0x0001
#define _UART2   0x0002

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** Transmissao assincrona*/
#define UART_ASYNC 0

/** Transmissao sincrona*/
#define UART_SYNC 1

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** Baixa velocidade de comunicacao*/
#define UART_LOW_COM    0

/** Alta velocidade de comunicacao*/
#define UART_HIGH_COM   1

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** Habilita recepcao de 9 bits*/
#define UART_RX_9BITS 1

/** Habilita recepcao de 8 bits*/
#define UART_RX_8BITS 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** Habilita transmissao de 9 bits*/
#define UART_TX_9BITS 1

/** Habilita transmissao de 8 bits*/
#define UART_TX_8BITS 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** Gerador de baud rate de 8 bits*/
#define UART_BD_8BITS   0 //?? verificar

/** Gerador de baud rate de 16 bits*/
#define UART_BD_16BITS  1

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/** Habilita recepcao continua*/
#define UART_ENABLE_RX  1

/** Desabilita recepcao continua*/
#define UART_DISABLE_RX 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/** Habilita transmissao*/
#define UART_ENABLE_TX  1

/** Desabilita transmissao*/
#define UART_DISABLE_TX 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** Porta serial habilitada*/
#define UART_ENABLE   1 

/** Porta serial desabilitada*/
#define UART_DISABLE  0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#define BAUD_4800   1
#define BAUD_9600   2
#define BAUD_19200  3
#define BAUD_115200 4

/**
 *  Extern Functions
 */
void uart_attach(regPin *pin, regGPIO *reg);
void uart_setup_interrupt(uint8 module, uint8 rx, uint8 tx);
void uart_priority_interrupt(uint8 module, uint8 rx, uint8 tx);
void uart_set_enable(uint8 module, uint8 enable_uart, uint8 enable_rx, uint8 enable_tx);
void uart_set_conf(uint8 module, uint8 sync, uint8 high_com, uint8 rx9bits, uint8 tx9bits, uint8 bd16bits);
void uart_set_baudRate(uint8 module, uint8 value);


void uart_rx_set_callbak(uint8 module, void (*func)(void));
void uart_tx_set_callbak(uint8 module, void (*func)(void));

void uart_putc(uint8 UI8_caracter);
//__inline uint8 uart_get_data(void);
uint8 uart_get_data(void);


#endif	/* HAL_UART_H */

