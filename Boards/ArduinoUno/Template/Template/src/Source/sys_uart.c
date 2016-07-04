/**
  * @file    sys_uart.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 12, 2015
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

#include <stdarg.h>
#include <avr/interrupt.h>

#include "sys_uart.h"
#include "gpio/hal_gpio.h"
#include "uart/hal_uart.h"
#include "lcd/lcd.h"
#include "xprintf/xprintf.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

#define UART_BAUD 9600
#define MYUBRR (((F_CPU / (UART_BAUD * 16UL))) - 1)

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

/**@brief TODO documentar*/
typedef enum
{
	ST_START,
	ST_MSG,
	ST_END
} RX_STATES;

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

/** @brief TODO documentar */
int decode(uint8_t data, uint8_t buf[]);

/** @brief Funcao callback da interrupcao do RX da UART1*/
void uart_rx(void);

/** @brief Funcao callback da interrupcao do TX da UART1*/
void uart_tx(void);

//==============================================================================
// SOURCE CODE
//==============================================================================

int decode(uint8_t data, uint8_t buf[])
{

	static int ind = 0;
	static RX_STATES status = ST_START;
	int ret = 0;
	
	switch (status)
	{

		case ST_START:
		if (data == 'S')
		{
			status = ST_MSG;
			ind = 0;
		}
		break;

		case ST_MSG:
		buf[ind++] = data;
		if (ind == 4)
		{
			status = ST_END;
		}
		break;

		case ST_END:
		if (data == 'E')
		{
			ret = 1;
		}
		status = ST_START;
		break;
	}

	return ret;
}

void uart0_rx(uint8_t c)
{
	static unsigned char buf[5];

	if (decode(c, buf))
	{
		lcd_gotoxy(1, 1);
		xprintf(lcd_putc, (uint8_t *)"\fUART Message:  ");
		lcd_gotoxy(1, 2);
		xprintf(lcd_putc, (uint8_t *)"%s", &buf);
		xprintf(callback_uart0_putc, (uint8_t *)"\r\n%s", &buf);
	}
}

void uart0_tx(void)
{
	
}

void callback_uart0_putc(uint8_t value)
{
	uart0_putc(value);
}

void init_uart(void)
{
	// Set baud rate
	UBRR0H = (uint8_t)(MYUBRR>>8);
	UBRR0L = (uint8_t)MYUBRR;
	// Set frame format to 8 data bits, no parity, 1 stop bit
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
	//enable reception and RC complete interrupt. Enable transmition.
	UCSR0B |= (1<<RXEN0)| (1 << TXEN0 ) |(1<<RXCIE0);
	sei();
	
	uart_rx_set_callbak(_UART0, uart0_rx);
}
