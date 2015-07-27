/**
* @file    hal_uart.c
* @author  Jorge Guzman (jorge.gzm@gmail.com)
* @date    11 de Marco de 2014
* @version 0.1.0.0
* @brief   Codigo do Driver UART para o microcontrolador PIC18f4550.
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

#include "hal_uart.h"
#include <avr/interrupt.h>

/**@brief */
void (*uart0_rx_callback)(uint8);

/**@brief */
void (*uart0_tx_callback)();

void uart_rx_set_callbak(uint8 module, void (*func)(uint8))
{
	switch(module)
	{
		case _UART0:

		//interrupt_set_callback(_UART_RX, func); //not used in ARM
		uart0_rx_callback = func;

		break;
	}
}

void uart_tx_set_callbak(uint8 module, void (*func)(void))
{
	switch(module)
	{
		case _UART0:

		//interrupt_set_callback(_UART_TX, func); //not used in ARM
		uart0_tx_callback = func;

		break;
	}
}

void uart0_putc(uint8 UI8_caracter)
{
	while(!(UCSR0A & (1<<UDRE0)) ); //espera o dado ser enviado
	UDR0 = UI8_caracter; // envia o dado
}

inline uint8 uart0_get_data(void)
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