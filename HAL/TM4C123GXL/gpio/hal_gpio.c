/**
  * @file    hal_gpio.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo da lib driver GPIO para o uso e acesso aos pinos de I/O do TM4C123GH6PM
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
#include "device/hal_device.h"
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

/** @brief variavel abstrair para trarar com o PORTA*/
volatile uint32_t *ref_PORTA = &GPIO_PORTA_DATA_R;

/** @brief variavel abstrair para trarar com o TRISA*/
volatile uint32_t *ref_TRISA = &GPIO_PORTA_DIR_R;

regGPIO rA0 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_0};	//Virtual COM Port Signals - U0RX
regGPIO rA1 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_1};	//Virtual COM Port Signals - U0TX
regGPIO rA2 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_2};
regGPIO rA3 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_3};
regGPIO rA4 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_4};
regGPIO rA5 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_5};
regGPIO rA6 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_6};
regGPIO rA7 = { &GPIO_PORTA_DATA_R, &GPIO_PORTA_DIR_R, 0, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstrair para trarar com o PORTB*/
volatile uint32_t *ref_PORTB = &GPIO_PORTB_DATA_R;

/** @brief variavel abstrair para trarar com o TRISB*/
volatile uint32_t *ref_TRISB = &GPIO_PORTB_DIR_R;

regGPIO rB0 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_0};
regGPIO rB1 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_1};
regGPIO rB2 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_2};
regGPIO rB3 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_3};
regGPIO rB4 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_4};
regGPIO rB5 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_5};
regGPIO rB6 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_6};
regGPIO rB7 = { &GPIO_PORTB_DATA_R, &GPIO_PORTB_DIR_R, 0, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstrair para trarar com o PORTC*/
volatile uint32_t *ref_PORTC = &GPIO_PORTC_DATA_R;

/** @brief variavel abstrair para trarar com o TRISC*/
volatile uint32_t *ref_TRISC = &GPIO_PORTC_DIR_R;

//regGPIO rC0 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_0}; //In-Circuit Debug
//regGPIO rC1 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_1}; //In-Circuit Debug
//regGPIO rC2 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_2}; //In-Circuit Debug
//regGPIO rC3 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_3}; //In-Circuit Debug
regGPIO rC4 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_4};
regGPIO rC5 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_5};
regGPIO rC6 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_6};
regGPIO rC7 = { &GPIO_PORTC_DATA_R, &GPIO_PORTC_DIR_R, 0, PIN_7};


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/** variavel abstrair para trarar com PORTD*/
volatile uint32_t *ref_PORTD = &GPIO_PORTD_DATA_R;

/** @brief variavel abstrair para trarar com o TRISD*/
volatile uint32_t *ref_TRISD = &GPIO_PORTD_DIR_R;

regGPIO rD0 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_0};
regGPIO rD1 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_1};
regGPIO rD2 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_2};
regGPIO rD3 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_3};
regGPIO rD4 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_4};	//USB0DM
regGPIO rD5 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_5};	//USB0DP
regGPIO rD6 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_6};
regGPIO rD7 = { &GPIO_PORTD_DATA_R, &GPIO_PORTD_DIR_R, 0, PIN_7};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstrair para trarar com o PORTE*/
volatile uint32_t *ref_PORTE = &GPIO_PORTE_DATA_R;

/** @brief variavel abstrair para trarar com o TRISE*/
volatile uint32_t *ref_TRISE = &GPIO_PORTE_DIR_R;

regGPIO rE0 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_0};
regGPIO rE1 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_1};
regGPIO rE2 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_2};
regGPIO rE3 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_3};
regGPIO rE4 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_4};
regGPIO rE5 = { &GPIO_PORTE_DATA_R, &GPIO_PORTE_DIR_R, 0, PIN_5};

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief variavel abstrair para trarar com o PORTF*/
volatile uint32_t *ref_PORTF = &GPIO_PORTF_DATA_R;

/** @brief variavel abstrair para trarar com o TRISF*/
volatile uint32_t *ref_TRISF = &GPIO_PORTF_DIR_R;

regGPIO rF0 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_0};
regGPIO rF1 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_1};
regGPIO rF2 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_2};
regGPIO rF3 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_3};
regGPIO rF4 = { &GPIO_PORTF_DATA_R, &GPIO_PORTF_DIR_R, 0, PIN_4};

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

void V_initRefRegisters(void)
{

}

void GPIO_write_data(volatile uint32_t *registrador, uint32_t UI8_value)
{
    *registrador = UI8_value;
}

void GPIO_regGPIO_attach(regGPIO *reg, regGPIO *_port)
{
    reg = _port;
}

void GPIO_outputBit(volatile uint32_t *port, uint32_t pino, uint32_t UI8_flag)
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

void GPIO_low(volatile uint32_t *port, uint32_t pino)
{
    clr_bit(*port, pino);
}

void GPIO_high( volatile uint32_t *port, uint32_t pino)
{
    set_bit(*port, pino);
}

void GPIO_output_toggle(volatile uint32_t *port, uint32_t pino)
{
    toggle_bit(*port, pino);
}

void GPIO_regPin_outputHigh(regPin *pin)
{
   set_bit(*pin->out, pin->pin);
}

void GPIO_regPin_outputLow(regPin *pin)
{
    clr_bit(*pin->out, pin->pin);
}

uint8_t GPIO_regPin_rdBit(regPin *pin)
{
    return(tst_bit(*pin->out, pin->pin));
}

void GPIO_regPin_outputBit(regPin *pin, uint32_t flag)
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

void GPIO_regPin_attach(regPin *pin, regGPIO *reg)
{
    pin->out = reg->port;
    pin->pin = reg->numPin;
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

void GPIO_regPin_setDir(regGPIO *pin, PIN_DIR IODirection)
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

PUBLIC void digitalWrite(int pin, int value)
{
	switch (pin)
    {
//        case x:  wr_bit(GPIO_PORTA_DATA_R, 0, value); break;
//        case x:  wr_bit(GPIO_PORTA_DATA_R, 1, value); break;
        case 11: wr_bit(GPIO_PORTA_DATA_R, 2, value); break;
        case 12: wr_bit(GPIO_PORTA_DATA_R, 3, value); break;
        case 13: wr_bit(GPIO_PORTA_DATA_R, 4, value); break;
        case 8:  wr_bit(GPIO_PORTA_DATA_R, 5, value); break;
        case 9:  wr_bit(GPIO_PORTA_DATA_R, 6, value); break;
        case 10: wr_bit(GPIO_PORTA_DATA_R, 7, value); break;

        case 3:  wr_bit(GPIO_PORTB_DATA_R, 0, value); break;
        case 4:  wr_bit(GPIO_PORTB_DATA_R, 1, value); break;
        case 19: wr_bit(GPIO_PORTB_DATA_R, 2, value); break;
        case 38: wr_bit(GPIO_PORTB_DATA_R, 3, value); break;
        case 7:  wr_bit(GPIO_PORTB_DATA_R, 4, value); break;
        case 2:  wr_bit(GPIO_PORTB_DATA_R, 5, value); break;
        case 14: wr_bit(GPIO_PORTB_DATA_R, 6, value); break;
        case 15: wr_bit(GPIO_PORTB_DATA_R, 7, value); break;

//        case x: wr_bit(GPIO_PORTC_DATA_R, 0, value); break;
//        case x: wr_bit(GPIO_PORTC_DATA_R, 1, value); break;
//        case x: wr_bit(GPIO_PORTC_DATA_R, 2, value); break;
//        case x: wr_bit(GPIO_PORTC_DATA_R, 3, value); break;
        case 37: wr_bit(GPIO_PORTC_DATA_R, 4, value); break;
        case 36: wr_bit(GPIO_PORTC_DATA_R, 5, value); break;
        case 35: wr_bit(GPIO_PORTC_DATA_R, 6, value); break;
        case 34: wr_bit(GPIO_PORTC_DATA_R, 7, value); break;

        case 23: wr_bit(GPIO_PORTD_DATA_R, 0, value); break;
        case 24: wr_bit(GPIO_PORTD_DATA_R, 1, value); break;
        case 25: wr_bit(GPIO_PORTD_DATA_R, 2, value); break;
        case 26: wr_bit(GPIO_PORTD_DATA_R, 3, value); break;
//        case x: wr_bit(GPIO_PORTD_DATA_R, 4, value); break;
//        case x: wr_bit(GPIO_PORTD_DATA_R, 5, value); break;
        case 33: wr_bit(GPIO_PORTD_DATA_R, 6, value); break;
        case 32: wr_bit(GPIO_PORTD_DATA_R, 7, value); break;

        case 18: wr_bit(GPIO_PORTE_DATA_R, 0, value); break;
        case 27: wr_bit(GPIO_PORTE_DATA_R, 1, value); break;
        case 28: wr_bit(GPIO_PORTE_DATA_R, 2, value); break;
        case 29: wr_bit(GPIO_PORTE_DATA_R, 3, value); break;
        case 5:  wr_bit(GPIO_PORTE_DATA_R, 4, value); break;
        case 6:  wr_bit(GPIO_PORTE_DATA_R, 5, value); break;

        case 17: wr_bit(GPIO_PORTF_DATA_R, 0, value); break;
		case 30: wr_bit(GPIO_PORTF_DATA_R, 1, value); break;
		case 40: wr_bit(GPIO_PORTF_DATA_R, 2, value); break;
		case 39: wr_bit(GPIO_PORTF_DATA_R, 3, value); break;
		case 31: wr_bit(GPIO_PORTF_DATA_R, 4, value); break;

        default: break;
    }
}

PUBLIC int digitalRead(int pin)
{
	switch (pin)
    {
//        case x:  wr_bit(GPIO_PORTA_DATA_R, 0);
//        case x:  wr_bit(GPIO_PORTA_DATA_R, 1);
        case 11: return tst_bit(GPIO_PORTA_DATA_R, 2);
        case 12: return tst_bit(GPIO_PORTA_DATA_R, 3);
        case 13: return tst_bit(GPIO_PORTA_DATA_R, 4);
        case 8:  return tst_bit(GPIO_PORTA_DATA_R, 5);
        case 9:  return tst_bit(GPIO_PORTA_DATA_R, 6);
        case 10: return tst_bit(GPIO_PORTA_DATA_R, 7);

        case 3:  return tst_bit(GPIO_PORTB_DATA_R, 0);
        case 4:  return tst_bit(GPIO_PORTB_DATA_R, 1);
        case 19: return tst_bit(GPIO_PORTB_DATA_R, 2);
        case 38: return tst_bit(GPIO_PORTB_DATA_R, 3);
        case 7:  return tst_bit(GPIO_PORTB_DATA_R, 4);
        case 2:  return tst_bit(GPIO_PORTB_DATA_R, 5);
        case 14: return tst_bit(GPIO_PORTB_DATA_R, 6);
        case 15: return tst_bit(GPIO_PORTB_DATA_R, 7);

//        case x:  return tst_bit(GPIO_PORTC_DATA_R, 0);
//        case x:  return tst_bit(GPIO_PORTC_DATA_R, 1);
//        case x:  return tst_bit(GPIO_PORTC_DATA_R, 2);
//        case x:  return tst_bit(GPIO_PORTC_DATA_R, 3);
        case 37: return tst_bit(GPIO_PORTC_DATA_R, 4);
        case 36: return tst_bit(GPIO_PORTC_DATA_R, 5);
        case 35: return tst_bit(GPIO_PORTC_DATA_R, 6);
        case 34: return tst_bit(GPIO_PORTC_DATA_R, 7);

        case 23: return tst_bit(GPIO_PORTD_DATA_R, 0);
        case 24: return tst_bit(GPIO_PORTD_DATA_R, 1);
        case 25: return tst_bit(GPIO_PORTD_DATA_R, 2);
        case 26: return tst_bit(GPIO_PORTD_DATA_R, 3);
//        case x:  return tst_bit(GPIO_PORTD_DATA_R, 4);
//        case x:  return tst_bit(GPIO_PORTD_DATA_R, 5);
        case 33: return tst_bit(GPIO_PORTD_DATA_R, 6);
        case 32: return tst_bit(GPIO_PORTD_DATA_R, 7);

        case 18: return tst_bit(GPIO_PORTE_DATA_R, 0);
        case 27: return tst_bit(GPIO_PORTE_DATA_R, 1);
        case 28: return tst_bit(GPIO_PORTE_DATA_R, 2);
        case 29: return tst_bit(GPIO_PORTE_DATA_R, 3);
        case 5:  return tst_bit(GPIO_PORTE_DATA_R, 4);
        case 6:  return tst_bit(GPIO_PORTE_DATA_R, 5);

        case 17: return tst_bit(GPIO_PORTF_DATA_R, 0);
		case 30: return tst_bit(GPIO_PORTF_DATA_R, 1);
		case 40: return tst_bit(GPIO_PORTF_DATA_R, 2);
		case 39: return tst_bit(GPIO_PORTF_DATA_R, 3);
		case 31: return tst_bit(GPIO_PORTF_DATA_R, 4);

        default: break;
    }
}

PUBLIC void pinMode(int pin, int type)
{

}
