/**
 * @file    hal_gpio.c
 * @brief   Codigo da lib driver GPIO para o uso e acesso aos pinos de I/O do TM4C123GH6PM
 * @details Esta biblioca faz o uso da comunicacao I2C para a traca de dados com o CI.
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    29 de Junho de 2015
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
#include "device/hal_device.h"

//------------------------------------------------------------------------------

/** variavel abstrair para trarar com o PORTA*/
volatile uint32 *ref_PORTA = &GPIO_PORTA_DATA_R;

/** variavel abstrair para trarar com o TRISA*/
volatile uint32 *ref_TRISA = &GPIO_PORTA_DIR_R;




/** */
regGPIO rA0 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_0};
regGPIO rA1 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_1};
regGPIO rA2 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_2};
regGPIO rA3 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_3};
regGPIO rA4 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_4};
regGPIO rA5 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_5};
regGPIO rA6 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_6};
regGPIO rA7 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_7};

//------------------------------------------------------------------------------






















/** variavel abstrair para trarar com o PORTB*/
volatile uint32 *ref_PORTB = &GPIO_PORTB_DATA_R;

/** variavel abstrair para trarar com o TRISB*/
volatile uint32 *ref_TRISB = &GPIO_PORTB_DIR_R;

regGPIO rB0 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_0};
regGPIO rB1 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_1};
regGPIO rB2 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_2};
regGPIO rB3 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_3};
regGPIO rB4 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_4};
regGPIO rB5 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_5};
regGPIO rB6 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_6};
regGPIO rB7 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_7};



//------------------------------------------------------------------------------































/** variavel abstrair para trarar com o PORTC*/
volatile uint32 *ref_PORTC = &GPIO_PORTC_DATA_R;

/** variavel abstrair para trarar com o TRISC*/
volatile uint32 *ref_TRISC = &GPIO_PORTC_DIR_R;

regGPIO rC0 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_0};
regGPIO rC1 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_1};
regGPIO rC2 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_2};
regGPIO rC3 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_3};
regGPIO rC4 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_4};
regGPIO rC5 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_5};
regGPIO rC6 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_6};
regGPIO rC7 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_7};













//------------------------------------------------------------------------------























/** variavel abstrair para trarar com PORTD*/
volatile uint32 *ref_PORTD = &GPIO_PORTD_DATA_R;

/** variavel abstrair para trarar com o TRISD*/
volatile uint32 *ref_TRISD = &GPIO_PORTD_DIR_R;

regGPIO rD0 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_0};
regGPIO rD1 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_1};
regGPIO rD2 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_2};
regGPIO rD3 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_3};
regGPIO rD4 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_4};
regGPIO rD5 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_5};
regGPIO rD6 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_6};
regGPIO rD7 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_7};



//------------------------------------------------------------------------------
































/** variavel abstrair para trarar com o PORTE*/
volatile uint32 *ref_PORTE = &GPIO_PORTE_DATA_R;

/** variavel abstrair para trarar com o TRISE*/
volatile uint32 *ref_TRISE = &GPIO_PORTE_DIR_R;

regGPIO rE0 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_0};
regGPIO rE1 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_1};
regGPIO rE2 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_2};
regGPIO rE3 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_3};
regGPIO rE4 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_4};
regGPIO rE5 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_5};
regGPIO rE6 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_6};
regGPIO rE7 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_7};



//------------------------------------------------------------------------------
































/** variavel abstrair para trarar com o PORTF*/
volatile uint32 *ref_PORTF = &GPIO_PORTF_DATA_R;

/** variavel abstrair para trarar com o TRISF*/
volatile uint32 *ref_TRISF = &GPIO_PORTF_DIR_R;

regGPIO rF0 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_0};
regGPIO rF1 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_1};
regGPIO rF2 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_2};
regGPIO rF3 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_3};
regGPIO rF4 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_4};
regGPIO rF5 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_5};
regGPIO rF6 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_6};
regGPIO rF7 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_7};



/**
 * Rotinha de inicializacao das variaveis abstraidas.









 */










void V_initRefRegisters(void)
{

}

/**
 *
 * @param registrador
 * @param UI8_value
 */
void GPIO_write_data(volatile uint32 *registrador, uint32 UI8_value)
{
    *registrador = UI8_value;
}


/**
 *
 * @param reg
 * @param port
 * @param pino
 */
void GPIO_attach(regGPIO *reg, regGPIO *_port)
{
    reg = _port;

}

/**
 *
 * @param port
 * @param pino Range(0-31).
 * @param UI8_flag escrever 0 ou 1 na saida
 */
void GPIO_outputBit(volatile uint32 *port, uint32 pino, uint32 UI8_flag)
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


/**
 *
 * @param reg
 */
void GPIO_low(volatile uint32 *port, uint32 pino)
{
    clr_bit(*port, pino);
}


/**
 *
 * @param reg
 */
void GPIO_high( volatile uint32 *port, uint32 pino)
{
    set_bit(*port, pino);
}

/**
 *
 * @param reg
 */
void GPIO_output_toggle(volatile uint32 *port, uint32 pino)
{
    toggle_bit(*port, pino);
}

/**
 *
 * @param pin
 */
void GPIO_pin_high(regPin *pin)
{
   set_bit(*pin->out, pin->pin);
}

/**
 *
 * @param pin
 */
void GPIO_pin_low(regPin *pin)
{
    clr_bit(*pin->out, pin->pin);
}

/**
 *
 * @param reg
 */
uint8 GPIO_input_state(regPin *pin)
{
    return(tst_bit(*pin->out, pin->pin));
}

void GPIO_pin_outputBit(regPin *pin, uint32 flag)
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

void GPIO_pin_attach(regPin *pin, regGPIO *reg)
{
    pin->out = reg->port;
    pin->pin = reg->numPin;
}

void GPIO_confDir(regGPIO *pin, PIN_DIR IODirection)
{
	/*
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
    */
}
