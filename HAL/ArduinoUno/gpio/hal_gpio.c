/**
  * @file    hal_gpio.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 21, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo da lib driver GPIO para o uso e acesso aos pinos de I/O do Arduino Uno(ATMEGA328P).
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

#include "hal_gpio.h"

//------------------------------------------------------------------------------
// Private Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Variable Declaration			
//------------------------------------------------------------------------------

/** @brief variavel abstraida para acessar o PORTB*/
volatile uint8 *ref_PORTB = &PORTB;
//volatile uint8_t * ref_PORTB =  &(*(volatile uint8_t *)((0x05) + 0x20));
volatile uint8 *ref_TRISB = &DDRB;

/** @brief variavel abstraida para acessar o LATB*/
volatile uint8 *ref_LATB = 0;

regGPIO rB0 = { &PORTB, &DDRB, 0, PIN_0};
regGPIO rB1 = { &PORTB, &DDRB, 0, PIN_1};
regGPIO rB2 = { &PORTB, &DDRB, 0, PIN_2};
regGPIO rB3 = { &PORTB, &DDRB, 0, PIN_3};
regGPIO rB4 = { &PORTB, &DDRB, 0, PIN_4};
regGPIO rB5 = { &PORTB, &DDRB, 0, PIN_5};
regGPIO rB6 = { &PORTB, &DDRB, 0, PIN_6};
regGPIO rB7 = { &PORTB, &DDRB, 0, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstraida para acessar o PORTC*/
volatile uint8 *ref_PORTC = &PORTC;

/** @brief variavel abstraida para acessar o DDRC*/
volatile uint8 *ref_TRISC = &DDRC;

/** @brief variavel abstraida para acessar o LATC*/
volatile uint8 *ref_LATC = 0;

regGPIO rC0 = { &PORTC, &DDRC, 0, PIN_0};
regGPIO rC1 = { &PORTC, &DDRC, 0, PIN_1};
regGPIO rC2 = { &PORTC, &DDRC, 0, PIN_2};
regGPIO rC3 = { &PORTC, &DDRC, 0, PIN_3};
regGPIO rC4 = { &PORTC, &DDRC, 0, PIN_4};
regGPIO rC5 = { &PORTC, &DDRC, 0, PIN_5};
regGPIO rC6 = { &PORTC, &DDRC, 0, PIN_6};
regGPIO rC7 = { &PORTC, &DDRC, 0, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstraida para acessar o PORTC*/
volatile uint8 *ref_PORTD = &PORTD;

/** @brief variavel abstraida para acessar o DDRD*/
volatile uint8 *ref_TRISD = &DDRD;

/** @brief variavel abstraida para acessar o LATD*/
volatile uint8 *ref_LATD = 0;

//PORTD:usado para escrever nos pinos do PORTD; 
//PIND:usado para ler o conteudo dos pinos do PORTD; 
//DDRD: usado para definir se os pinos do PORTD sao entrada ou saida.
regGPIO rD0 = { &PORTD, &DDRD, 0, PIN_0};
regGPIO rD1 = { &PORTD, &DDRD, 0, PIN_1};
regGPIO rD2 = { &PIND, &DDRD, 0, PIN_2};  //TODO revisar possivel conflito, em outras microcontroladores(PIC e ARM) existe apenas um PORTX para ler e escrever.
regGPIO rD3 = { &PIND, &DDRD, 0, PIN_3};  //TODO revisar possivel conflito, em outras microcontroladores(PIC e ARM) existe apenas um PORTX para ler e escrever.
regGPIO rD4 = { &PORTD, &DDRD, 0, PIN_4};
regGPIO rD5 = { &PORTD, &DDRD, 0, PIN_5};
regGPIO rD6 = { &PORTD, &DDRD, 0, PIN_6};
regGPIO rD7 = { &PORTD, &DDRD, 0, PIN_7};

//------------------------------------------------------------------------------
// Private Prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions Source
//------------------------------------------------------------------------------

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
       clr_bit(*pin->tris, pin->numPin);
    }
    else
    {
       //output
       set_bit(*pin->tris, pin->numPin);
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

