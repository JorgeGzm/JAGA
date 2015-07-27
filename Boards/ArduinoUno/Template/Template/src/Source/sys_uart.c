/**
* @file    sys_uart.c
* @brief   TODO
* @author  Rafael Lopes
* @date    12 de Marco de 2015
* @version 0.1.0.0 (beta)
*/

#include <stdarg.h>
#include <avr/interrupt.h>

#include "../Header/sys_uart.h"
#include "gpio/hal_gpio.h"
#include "uart/hal_uart.h"
#include "serial/serial.h"
#include "lcd/lcd.h"

#define UART_BAUD 9600
#define MYUBRR (((F_CPU / (UART_BAUD * 16UL))) - 1)

typedef enum
{
	ST_START,
	ST_MSG,
	ST_END
} RX_STATES;

int decode(uint8 data, uint8 buf[])
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

/**  */
void uart0_rx(uint8 c)
{
	static unsigned char buf[5];

	if (decode(c, buf))
	{
		lcd_gotoxy(1, 1);
		lcd_printf((int8 *)"\fUART Message:  ");
		lcd_gotoxy(1, 2);
		lcd_printf((int8 *)"%s", &buf);
		serial_printf(0, (int8 *)"\r\n%s", &buf);
	}
}

/** Funcao callback da interrupcao do TX da UART1*/
void uart0_tx(void)
{
	
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
