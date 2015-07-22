/**
 * @file    sys_uart.c
 * @brief   TODO
 * @author  Rafael Lopes
 * @date    12 de Marco de 2015
 * @version 0.1.0.0 (beta)
 */

#include <stdarg.h>

#include "../Header/sys_uart.h"
#include "gpio/hal_gpio.h"
//#include "uart/hal_uart.h"
#include "serial/serial.h"
#include "lcd/lcd.h"

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
void uart_rx(void)
{ 
	
}
 
/** Funcao callback da interrupcao do TX da UART1*/
void uart_tx(void)
{
   
}

void init_uart(void)
{
   
}
