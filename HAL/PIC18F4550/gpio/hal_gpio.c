/**
  * @file    hal_gpio.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo da lib driver GPIO para o uso e acesso aos pinos de I/O do PIC18f4550.
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

#include "hal_gpio.h"
#include "bitwise/bitwise.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** @brief variavel abstraida para acessar o PORTA*/
volatile uint8_t *ref_PORTA = &PORTA;

/** @brief variavel abstraida para acessar o TRISA*/
volatile uint8_t *ref_TRISA = &TRISA;

/** @brief variavel abstraida para acessar o LATA*/
volatile uint8_t *ref_LATA = &LATA;

/** variavel abstraida para acessar o LATE*/
regGPIO rA0 = { &PORTA, &TRISA, &LATA, PIN_0}; //{ .port = &PORTA, .tris = &TRISA, .lat = &LATA, .numPin = PIN_0 };
regGPIO rA1 = { &PORTA, &TRISA, &LATA, PIN_1};
regGPIO rA2 = { &PORTA, &TRISA, &LATA, PIN_2};
regGPIO rA3 = { &PORTA, &TRISA, &LATA, PIN_3};
regGPIO rA4 = { &PORTA, &TRISA, &LATA, PIN_4};
regGPIO rA5 = { &PORTA, &TRISA, &LATA, PIN_5};
regGPIO rA6 = { &PORTA, &TRISA, &LATA, PIN_6};
regGPIO rA7 = { &PORTA, &TRISA, &LATA, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstraida para acessar o PORTB*/
volatile uint8_t *ref_PORTB = &PORTB;

/** @brief variavel abstraida para acessar o TRISB*/
volatile uint8_t *ref_TRISB = &TRISB;

/** @brief variavel abstraida para acessar o LATB*/
volatile uint8_t *ref_LATB = &LATB;

regGPIO rB0 = { &PORTB, &TRISB, &LATB, PIN_0};
regGPIO rB1 = { &PORTB, &TRISB, &LATB, PIN_1};
regGPIO rB2 = { &PORTB, &TRISB, &LATB, PIN_2};
regGPIO rB3 = { &PORTB, &TRISB, &LATB, PIN_3};
regGPIO rB4 = { &PORTB, &TRISB, &LATB, PIN_4};
regGPIO rB5 = { &PORTB, &TRISB, &LATB, PIN_5};
regGPIO rB6 = { &PORTB, &TRISB, &LATB, PIN_6};
regGPIO rB7 = { &PORTB, &TRISB, &LATB, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstraida para acessar o PORTC*/
volatile uint8_t *ref_PORTC = &PORTC;

/** @brief variavel abstraida para acessar o TRISC*/
volatile uint8_t *ref_TRISC = &TRISC;

/** @brief variavel abstraida para acessar o LATC*/
volatile uint8_t *ref_LATC = &LATC;

regGPIO rC0 = { &PORTC, &TRISC, &LATC, PIN_0};
regGPIO rC1 = { &PORTC, &TRISC, &LATC, PIN_1};
regGPIO rC2 = { &PORTC, &TRISC, &LATC, PIN_2};
regGPIO rC3 = { &PORTC, &TRISC, &LATC, PIN_3};
regGPIO rC4 = { &PORTC, &TRISC, &LATC, PIN_4};
regGPIO rC5 = { &PORTC, &TRISC, &LATC, PIN_5};
regGPIO rC6 = { &PORTC, &TRISC, &LATC, PIN_6};
regGPIO rC7 = { &PORTC, &TRISC, &LATC, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstraida para acessar o PORTC*/
volatile uint8_t *ref_PORTD = &PORTD;

/** @brief variavel abstraida para acessar o TRISD*/
volatile uint8_t *ref_TRISD = &TRISD;

/** @brief variavel abstraida para acessar o LATD*/
volatile uint8_t *ref_LATD = &LATD;

regGPIO rD0 = { &PORTD, &TRISD, &LATD, PIN_0};
regGPIO rD1 = { &PORTD, &TRISD, &LATD, PIN_1};
regGPIO rD2 = { &PORTD, &TRISD, &LATD, PIN_2};
regGPIO rD3 = { &PORTD, &TRISD, &LATD, PIN_3};
regGPIO rD4 = { &PORTD, &TRISD, &LATD, PIN_4};
regGPIO rD5 = { &PORTD, &TRISD, &LATD, PIN_5};
regGPIO rD6 = { &PORTD, &TRISD, &LATD, PIN_6};
regGPIO rD7 = { &PORTD, &TRISD, &LATD, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstraida para acessar o PORTE*/
volatile uint8_t *ref_PORTE = &PORTE;

/** @brief variavel abstraida para acessar o TRISE*/
volatile uint8_t *ref_TRISE = &TRISE;

/** @brief variavel abstraida para acessar o LATE*/
volatile uint8_t *ref_LATE = &LATE;

regGPIO rE0 = { &PORTE, &TRISE, &LATE, PIN_0};
regGPIO rE1 = { &PORTE, &TRISE, &LATE, PIN_1};
regGPIO rE2 = { &PORTE, &TRISE, &LATE, PIN_2};

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

void V_initRefRegisters(void)
{

}

void GPIO_write_data(volatile uint8_t *registrador, uint8_t UI8_value)
{
    *registrador = UI8_value;
}

void GPIO_regGPIO_attach(regGPIO *reg, regGPIO *_port)
{
    reg = _port;    
}

void GPIO_outputBit(volatile uint8_t *port, uint8_t pino, uint8_t UI8_flag)
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

void GPIO_low(volatile uint8_t *port, uint8_t pino)
{
    clr_bit(*port, pino);
}

void GPIO_high( volatile uint8_t *port, uint8_t pino)
{
    set_bit(*port, pino);
}

void GPIO_output_toggle(volatile uint8_t *port, uint8_t pino)
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

uint8_t GPIO_regPin_rdBit(regPin *pin)
{
    return(tst_bit(*pin->out, pin->pin));
}

uint8_t GPIO_regPin_inputBit(regPin *pin)
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

void GPIO_regPin_outputBit(regPin *pin, uint8_t flag)
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

