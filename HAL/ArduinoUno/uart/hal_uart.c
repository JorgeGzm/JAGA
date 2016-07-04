/**
  * @file    hal_uart.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 11, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo do Driver UART para o microcontrolador ATMEGA328P.
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

#include "hal_uart.h"
#include <avr/interrupt.h>

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

/**@brief TODO documentar */
void (*uart0_rx_callback)(uint8_t);

/**@brief TODO documentar */
void (*uart0_tx_callback)(void);

//==============================================================================
// SOURCE CODE
//==============================================================================

void uart_rx_set_callbak(uint8_t module, void (*func)(uint8_t))
{
	switch(module)
	{
		case _UART0:

		//interrupt_set_callback(_UART_RX, func); //not used in ARM
		uart0_rx_callback = func;

		break;
	}
}

void uart_tx_set_callbak(uint8_t module, void (*func)(void))
{
	switch(module)
	{
		case _UART0:

		//interrupt_set_callback(_UART_TX, func); //not used in ARM
		uart0_tx_callback = func;

		break;
	}
}

void uart0_putc(uint8_t UI8_caracter)
{
	while(!(UCSR0A & (1<<UDRE0)) ); //espera o dado ser enviado
	UDR0 = UI8_caracter; // envia o dado
}

inline uint8_t uart0_getc(void)
{
	while (!(UCSR0A & (1<<RXCIE0)) ); //espera o dado ser recebido
	return UDR0;
}

ISR(USART_RX_vect)
{
	char data = UDR0;	
	uart0_rx_callback(data);
}

//ISR(USART_TX_vect)
//{
//
//}