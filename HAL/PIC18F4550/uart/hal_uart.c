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


regPin pinRX1;
regPin pinTX1;

void uart_setup_interrupt(uint8 module, uint8 rx, uint8 tx)
{
    switch(module)
    {
        case _UART1:

            PIE1bits.RCIE = rx;
            PIE1bits.TXIE = tx;

            interrupt_setup(_UART_RX, rx);
            interrupt_setup(_UART_TX, tx);

            break;
    }
}

void uart_priority_interrupt(uint8 module, uint8 rx, uint8 tx)
{
    switch(module)
    {
    case _UART1:

        IPR1bits.RCIP = rx; //modulo receptor
        IPR1bits.TXIP = tx; //modulo transmissao

        interrupt_set_priority(_UART_RX, rx);
        interrupt_set_priority(_UART_TX, tx);

        break;
    }
}

void uart_set_baudRate(uint8 module, uint8 value)
{
    switch(module)
    {
        case _UART1:
            if(value == BAUD_4800)
            {
                //aki igual 9600
                SPBRGH = 0x09;
                SPBRG = 0xC3;
            }
            else if(value == BAUD_9600)
            {
                //valor baseado com um clock de 48MHz
                SPBRGH = 0x04;
                SPBRG = 0xE1;
            }
            else if(value == BAUD_19200)
            {
                //valor baseado com um clock de 48MHz
                SPBRGH = 0x02;
                SPBRG = 0x70;
            }
            else if(value == BAUD_115200)
            {
                //valor baseado com um clock de 48MHz
                SPBRGH = 0x00;
                SPBRG = 0x67;
            }
        break;
    }
}

void uart_attach(regPin *pin, regGPIO *reg)
{
    //Aloca o pino para o botao
    pin->out = reg->port;
    pin->pin = reg->numPin;
    //GPIO_attach(pin, reg);

    //Configura pino do botao como entrada
    GPIO_confDir(reg, DIR_INPUT);//era tris
}

void uart_set_conf(uint8 module, uint8 sync, uint8 high_com, uint8 rx9bits, uint8 tx9bits,  uint8 bd16bits)
{
    switch(module)
    {
        case _UART1:

            TXSTAbits.SYNC = sync;
            TXSTAbits.BRGH = high_com;
            RCSTAbits.RX9 = rx9bits;
            TXSTAbits.TX9 = tx9bits;
            BAUDCONbits.BRG16 = bd16bits;
        break;
    }
}

void uart_set_enable(uint8 module, uint8 enable_uart, uint8 enable_rx, uint8 enable_tx)
{
    switch(module)
    {
        case _UART1:
            
            RCSTAbits.SPEN = enable_uart;
            RCSTAbits.CREN = enable_rx;
            TXSTAbits.TXEN = enable_tx;
        break;
    }
}

void uart_rx_set_callbak(uint8 module, void (*func)(void))
{
    switch(module)
    {
        case _UART1:
            interrupt_set_callback(_UART_RX, func);
        break;
    }
}

void uart_tx_set_callbak(uint8 module, void (*func)(void))
{
    switch(module)
    {
        case _UART1:
            interrupt_set_callback(_UART_TX, func);
        break;
    }
}

void uart_putc(uint8 UI8_caracter)
{
    TXREG = UI8_caracter;
    while(!TXSTAbits.TRMT);

    if(RCSTAbits.FERR)
    {
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
    }
}

inline uint8 uart_get_data(void)
{
    return(RCREG);
}