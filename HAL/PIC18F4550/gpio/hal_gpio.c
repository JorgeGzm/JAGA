/**
 * @file    hal_gpio.c
 * @brief   Codigo da lib driver GPIO para o uso e acesso aos pinos de I/O do PIC18f4550.
 * @details Esta biblioca faz o uso da comunicacao I2C para a traca de dados com o CI.
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    26 de Junho de 2015
 * @version 0.1.0.0 (beta) 
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

#include "hal_gpio.h"

/** variavel abstraida para acessar o PORTA*/
volatile uint8 *ref_PORTA = &PORTA;

/** variavel abstraida para acessar o TRISA*/
volatile uint8 *ref_TRISA = &TRISA;

/** variavel abstraida para acessar o LATA*/
volatile uint8 *ref_LATA = &LATA;

/** variavel abstraida para acessar o LATE*/
regGPIO rA0 = { &PORTA, &TRISA, &LATA, PIN_0};
regGPIO rA1 = { &PORTA, &TRISA, &LATA, PIN_1};
regGPIO rA2 = { &PORTA, &TRISA, &LATA, PIN_2};
regGPIO rA3 = { &PORTA, &TRISA, &LATA, PIN_3};
regGPIO rA4 = { &PORTA, &TRISA, &LATA, PIN_4};
regGPIO rA5 = { &PORTA, &TRISA, &LATA, PIN_5};
regGPIO rA6 = { &PORTA, &TRISA, &LATA, PIN_6};
regGPIO rA7 = { &PORTA, &TRISA, &LATA, PIN_7};

//------------------------------------------------------------------------------

/** variavel abstraida para acessar o PORTB*/
volatile uint8 *ref_PORTB = &PORTB;

/** variavel abstraida para acessar o TRISB*/
volatile uint8 *ref_TRISB = &TRISB;

/** variavel abstraida para acessar o LATB*/
volatile uint8 *ref_LATB = &LATB;

regGPIO rB0 = { &PORTB, &TRISB, &LATB, PIN_0};
regGPIO rB1 = { &PORTB, &TRISB, &LATB, PIN_1};
regGPIO rB2 = { &PORTB, &TRISB, &LATB, PIN_2};
regGPIO rB3 = { &PORTB, &TRISB, &LATB, PIN_3};
regGPIO rB4 = { &PORTB, &TRISB, &LATB, PIN_4};
regGPIO rB5 = { &PORTB, &TRISB, &LATB, PIN_5};
regGPIO rB6 = { &PORTB, &TRISB, &LATB, PIN_6};
regGPIO rB7 = { &PORTB, &TRISB, &LATB, PIN_7};

//------------------------------------------------------------------------------

/** variavel abstraida para acessar o PORTC*/
volatile uint8 *ref_PORTC = &PORTC;

/** variavel abstraida para acessar o TRISC*/
volatile uint8 *ref_TRISC = &TRISC;

/** variavel abstraida para acessar o LATC*/
volatile uint8 *ref_LATC = &LATC;

regGPIO rC0 = { &PORTC, &TRISC, &LATC, PIN_0};
regGPIO rC1 = { &PORTC, &TRISC, &LATC, PIN_1};
regGPIO rC2 = { &PORTC, &TRISC, &LATC, PIN_2};
regGPIO rC3 = { &PORTC, &TRISC, &LATC, PIN_3};
regGPIO rC4 = { &PORTC, &TRISC, &LATC, PIN_4};
regGPIO rC5 = { &PORTC, &TRISC, &LATC, PIN_5};
regGPIO rC6 = { &PORTC, &TRISC, &LATC, PIN_6};
regGPIO rC7 = { &PORTC, &TRISC, &LATC, PIN_7};

//------------------------------------------------------------------------------

/** variavel abstraida para acessar o PORTC*/
volatile uint8 *ref_PORTD = &PORTD;

/** variavel abstraida para acessar o TRISD*/
volatile uint8 *ref_TRISD = &TRISD;

/** vvariavel abstraida para acessar o LATD*/
volatile uint8 *ref_LATD = &LATD;

regGPIO rD0 = { &PORTD, &TRISD, &LATD, PIN_0};
regGPIO rD1 = { &PORTD, &TRISD, &LATD, PIN_1};
regGPIO rD2 = { &PORTD, &TRISD, &LATD, PIN_2};
regGPIO rD3 = { &PORTD, &TRISD, &LATD, PIN_3};
regGPIO rD4 = { &PORTD, &TRISD, &LATD, PIN_4};
regGPIO rD5 = { &PORTD, &TRISD, &LATD, PIN_5};
regGPIO rD6 = { &PORTD, &TRISD, &LATD, PIN_6};
regGPIO rD7 = { &PORTD, &TRISD, &LATD, PIN_7};

//------------------------------------------------------------------------------

/** variavel abstraida para acessar o PORTE*/
volatile uint8 *ref_PORTE = &PORTE;

/** variavel abstraida para acessar o TRISE*/
volatile uint8 *ref_TRISE = &TRISE;

/** vvariavel abstraida para acessar o LATE*/
volatile uint8 *ref_LATE = &LATE;

regGPIO rE0 = { &PORTE, &TRISE, &LATE, PIN_0};
regGPIO rE1 = { &PORTE, &TRISE, &LATE, PIN_1};
regGPIO rE2 = { &PORTE, &TRISE, &LATE, PIN_2};


void V_initRefRegisters(void)
{

}

void GPIO_write_data(volatile uint8 *registrador, uint8 UI8_value)
{
    *registrador = UI8_value;
}

void GPIO_regGPIO_attach(regGPIO *reg, regGPIO *_port)
{
    reg = _port;    
}

void GPIO_outputBit(volatile uint8 *port, uint8 pino, uint8 UI8_flag)
{
    if(UI8_flag)
    {
        set_bit(*port, pino);
    }
    else
    {
        clr_bit(*port, pino);
    }
}

void GPIO_low(volatile uint8 *port, uint8 pino)
{
    clr_bit(*port, pino);
}

void GPIO_high( volatile uint8 *port, uint8 pino)
{
    set_bit(*port, pino);
}

void GPIO_output_toggle(volatile uint8 *port, uint8 pino)
{
    toggle_bit(*port, pino);
}

void GPIO_regPin_attach(regPin *pin, regGPIO *reg)
{
    pin->out = reg->port;    
    pin->pin = reg->numPin;    
}

void GPIO_regPin_outputHigh(regPin *pin)
{
   set_bit(*pin->out, pin->pin);
}

void GPIO_regPin_outputLow(regPin *pin)
{
    clr_bit(*pin->out, pin->pin);
}

void GPIO_regPin_setDir(regGPIO *pin, PIN_DIR IODirection)
{
    if(IODirection)
    {
       //input
       set_bit(*pin->tris, pin->numPin);
    }
    else
    {
       //output
       clr_bit(*pin->tris, pin->numPin);
    }
}

uint8 GPIO_regPin_rdBit(regPin *pin)
{
    return(tst_bit(*pin->out, pin->pin));
}

uint8 GPIO_regPin_inputBit(regPin *pin)
{
    if(tst_bit(*pin->out, pin->pin))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void GPIO_regPin_outputBit(regPin *pin, uint8 flag)
{
    if(flag)
    {
        set_bit(*pin->out, pin->pin);
    }
    else
    {
        clr_bit(*pin->out, pin->pin);
    }
}

