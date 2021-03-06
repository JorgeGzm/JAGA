 /**
  * @file    hal_uart.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Apr 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo do Driver UART para o microcontrolador TM4C123GXL.
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

/**@brief TODO documentar*/
void (*uart0_rx_callback)(uint8_t);

/**@brief TODO documentar*/
void (*uart0_tx_callback)(void);

/**@brief TODO documentar*/
void (*uart1_rx_callback)(uint8_t);

/**@brief TODO documentar*/
void (*uart1_tx_callback)(void);

//==============================================================================
// SOURCE CODE
//==============================================================================

void uart_rx_set_callback(uint8_t module, void (*func)(uint8_t))
{
	switch(module)
	{
	case _UART0:

		//interrupt_set_callback(_UART_RX, func); //not used in ARM
		uart0_rx_callback = func;
		break;

	case _UART1:

		//interrupt_set_callback(_UART_RX, func); //not used in ARM
		uart1_rx_callback = func;
		break;
	}
}

void uart_tx_set_callback(uint8_t module, void (*func)(void))
{
	switch(module)
	{
	case _UART0:

		//interrupt_set_callback(_UART_TX, func); //not used in ARM
		uart0_tx_callback = func;
		break;

	case _UART1:

		//interrupt_set_callback(_UART_TX, func); //not used in ARM
		uart1_tx_callback = func;

		break;
	}
}

void uart0_putc(uint8_t UI8_caracter)
{
	// as part of Lab 11, modify this program to use UART0 instead of UART1
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = UI8_caracter;
}


//__inline uint8 uart_get_data(void)
uint8_t uart0_get_data(void)
{	
	while((UART0_FR_R&0x0010) != 0);      // wait until RXFE is 0
	return((unsigned char)(UART0_DR_R&0xFF));
}

void UART0_Handler(void)
{
	volatile int readback;

	unsigned char c;
	static unsigned char buf[5];

	if (UART0->MIS & 0x0010)
	{
		c = UART0->DR;              /* read the received data */
		//-------------------

		uart0_rx_callback(c);

		//-------------------------

		UART0->ICR = 0x0010;        /* clear Rx interrupt flag */
		readback = UART0->ICR;      /* a read to force clearing of interrupt flag */
	}
	else
	{
		/* should not get here. But if it does, */
		UART0->ICR = UART0->MIS;    /* clear all interrupt flags */
		readback = UART0->ICR;      /* a read to force clearing of interrupt flag */
	}
}

void uart1_putc(uint8_t UI8_caracter)
{
	// as part of Lab 11, modify this program to use UART0 instead of UART1
	while((UART1_FR_R&UART_FR_TXFF) != 0);
	UART1_DR_R = UI8_caracter;

}

uint8_t uart1_get_data(void)
{
	while((UART1_FR_R&0x0010) != 0);      // wait until RXFE is 0
	return((unsigned char)(UART1_DR_R&0xFF));
}


void UART1_Handler(void)
{
	volatile int readback;

	unsigned char c;

	if (UART1->MIS & 0x0010)
	{
		c = UART1->DR;              /* read the received data */
		//-------------------

		uart1_rx_callback(c);

		UART1->ICR = 0x0010;        /* clear Rx interrupt flag */
		readback = UART1->ICR;      /* a read to force clearing of interrupt flag */
	}
	else
	{
		/* should not get here. But if it does, */
		UART1->ICR = UART1->MIS;    /* clear all interrupt flags */
		readback = UART1->ICR;      /* a read to force clearing of interrupt flag */
	}
}
