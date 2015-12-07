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
#include <stdint.h>

#include "sys_uart.h"
#include "device/hal_device.h"
#include "uart/hal_uart.h"
#include "lcd/lcd.h"
#include "xprintf/xprintf.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

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
void uart0_rx(uint8_t c);

/** @brief Funcao callback da interrupcao do TX da UART1*/
void uart0_tx(void);

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
		xprintf(callback_uart_putc, (uint8_t *)"\r\n%s", &buf);
	}
}

void uart0_tx(void)
{

}

void callback_uart_putc(uint8_t value)
{
	uart0_putc(value);
}

void init_uart(void)
{
	//INIT UART0. TODO ABSTRAIR ROTINA.

	// as part of Lab 11, modify this program to use UART0 instead of UART1
	//                 switching from PC5,PC4 to PA1,PA0
	SYSCTL_RCGC1_R |= 0x00000001; // activate UART0
	SYSCTL_RCGC2_R |= 0x00000001; // activate port A
	UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
	UART0_IBRD_R = 43;                    // IBRD = int(80,000,000 / (16 * 115200)) = int(43.402778)
	UART0_FBRD_R = 26;                    // FBRD = round(0.402778 * 64) = 26
																				// 8 bit word length (no parity bits, one stop bit, FIFOs)
	UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
	UART0_CTL_R |= UART_CTL_UARTEN;       // enable UART
	GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1,PA0
	GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1,PA0
																				// configure PA1,PA0 as UART0
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
	GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA1,PA0

	//Inicializa interrupcao da uart

	//UART0->CTL = 0;         /* disable UART0 */
	//UART0->IBRD = 104;      /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
	//UART0->FBRD = 11;       /* fraction part, see Example 4-4 */
	//UART0->CC = 0;          /* use system clock */
	UART0->LCRH = 0x60;     /* 8-bit, no parity, 1-stop bit, no FIFO */
	UART0->IM |= 0x0010;    /* enable RX interrupt */
	UART0->CTL = 0x301;     /* enable UART0, TXE, RXE */

	/* enable interrupt in NVIC and set priority to 6 */
	NVIC->IP[5] = 3 << 5;   /* set interrupt priority to 3 */
	NVIC->ISER[0] |= 0x00000020;  /* enable IRQ5 for UART0 */

	__enable_irq(); /* global enable IRQs */

	uart_rx_set_callback(_UART0, uart0_rx);
}



