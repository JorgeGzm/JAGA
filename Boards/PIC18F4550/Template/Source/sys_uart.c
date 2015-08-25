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

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include <stdarg.h>

#include "../Header/sys_uart.h"
#include "gpio/hal_gpio.h"
#include "uart/hal_uart.h"
#include "serial/serial.h"
#include "lcd/lcd.h"

//------------------------------------------------------------------------------
// Private Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private structs, unions and enums
//------------------------------------------------------------------------------

/**@brief TODO documentar*/
typedef enum 
{
    ST_START,
    ST_MSG,
    ST_END
} RX_STATES;

//------------------------------------------------------------------------------
// Variable Declaration			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Prototypes
//------------------------------------------------------------------------------

/** @brief TODO documentar */
int decode(uint8 data, uint8 buf[]);

/** @brief Funcao callback da interrupcao do RX da UART1*/
void uart_rx(void);

/** @brief Funcao callback da interrupcao do TX da UART1*/
void uart_tx(void);

//------------------------------------------------------------------------------
// Functions Source
//------------------------------------------------------------------------------

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

void uart_rx(void)
{ 
    uint8 c;
    static uint8 buf1[5];
    //retorna o dado recebido, apenas para testes, em caso de erro usar uart_putc(RCREG);
    //c = uart_putc(uart_get_data());   
    c = uart_get_data();
    if (decode(c, buf1)) 
    {
       lcd_gotoxy(1, 1);
        lcd_printf((int8 *)"\fUART Message:  ");
        lcd_gotoxy(1, 2);
        lcd_printf((int8 *)"%s", &buf1);
        serial_printf(0, (int8 *)"\r\n%s", &buf1);     
    }   
    
}
 
void uart_tx(void)
{
   
}

void init_uart(void)
{
    //Inicializa pinos UART
    uart_attach(pinRX1, rC7);
    uart_attach(pinTX1, rC6);

    //Configura funcionamento da UART1   
    uart_set_baudRate(_UART1, BAUD_9600);
    uart_set_enable(_UART1, UART_ENABLE, UART_ENABLE_RX, UART_ENABLE_TX);
    uart_set_conf(_UART1, UART_ASYNC, UART_HIGH_COM, UART_RX_8BITS, UART_TX_8BITS, UART_BD_16BITS);

    //Configura interrupcao UART1   
    uart_setup_interrupt(_UART1, ENABLE, DISABLE);
    uart_priority_interrupt(_UART1, ENABLE, DISABLE);
    uart_rx_set_callbak(_UART1, uart_rx);
    uart_tx_set_callbak(_UART1, uart_tx);
}
