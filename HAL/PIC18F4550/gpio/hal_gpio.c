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

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

PUBLIC void V_initRefRegisters(void)
{

}

//PUBLIC void GPIO_write_data(volatile uint8_t *registrador, uint8_t UI8_value)
//{
//    *registrador = UI8_value;
//}
//
//PUBLIC void GPIO_regGPIO_attach(regGPIO *reg, regGPIO *_port)
//{
//    reg = _port;    
//}
//
//PUBLIC void GPIO_outputBit(volatile uint8_t *port, uint8_t pino, uint8_t UI8_flag)
//{
//    if(UI8_flag)
//    {
//        set_bit(*port, pino);
//    }
//    else
//    {
//        clr_bit(*port, pino);
//    }
//}
//
//PUBLIC void GPIO_low(volatile uint8_t *port, uint8_t pino)
//{
//    clr_bit(*port, pino);
//}
//
//PUBLIC void GPIO_high( volatile uint8_t *port, uint8_t pino)
//{
//    set_bit(*port, pino);
//}
//
//PUBLIC void GPIO_output_toggle(volatile uint8_t *port, uint8_t pino)
//{
//    toggle_bit(*port, pino);
//}
//
//PUBLIC void GPIO_regPin_attach(regPin *pin, regGPIO *reg)
//{
//    pin->out = reg->port;    
//    pin->pin = reg->numPin;    
//}
//
//PUBLIC void GPIO_regPin_outputHigh(regPin *pin)
//{
//   set_bit(*pin->out, pin->pin);
//}
//
//PUBLIC void GPIO_regPin_outputLow(regPin *pin)
//{
//    clr_bit(*pin->out, pin->pin);
//}
//
//PUBLIC void GPIO_regPin_setDir(regGPIO *pin, PIN_DIR IODirection)
//{
//    if(IODirection)
//    {
//       //input
//       set_bit(*pin->tris, pin->numPin);
//    }
//    else
//    {
//       //output
//       clr_bit(*pin->tris, pin->numPin);
//    }
//}
//
//PUBLIC uint8_t GPIO_regPin_rdBit(regPin *pin)
//{
//    return(tst_bit(*pin->out, pin->pin));
//}
//
//PUBLIC uint8_t GPIO_regPin_inputBit(regPin *pin)
//{
//    if(tst_bit(*pin->out, pin->pin))
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//PUBLIC void GPIO_regPin_outputBit(regPin *pin, uint8_t flag)
//{
//    if(flag)
//    {
//        set_bit(*pin->out, pin->pin);
//    }
//    else
//    {
//        clr_bit(*pin->out, pin->pin);
//    }
//}

PUBLIC void pinMode(int pin, int type)
{
    switch (pin) 
    {            
        case 1:  wr_bit(TRISA, 0, type); break;
        case 2:  wr_bit(TRISA, 1, type); break;
        case 3:  wr_bit(TRISA, 2, type); break;
        case 4:  wr_bit(TRISA, 3, type); break;
        case 5:  wr_bit(TRISA, 4, type); break;
        case 6:  wr_bit(TRISA, 5, type); break;
        case 10:  wr_bit(TRISA, 6, type); break;

        case 26: wr_bit(TRISB, 0, type); break;
        case 27: wr_bit(TRISB, 1, type); break;
        case 28: wr_bit(TRISB, 2, type); break;
        case 29: wr_bit(TRISB, 3, type); break;
        case 30: wr_bit(TRISB, 4, type); break;
        case 31: wr_bit(TRISB, 5, type); break;
        case 32: wr_bit(TRISB, 6, type); break;
        case 33: wr_bit(TRISB, 7, type); break;

        case 11: wr_bit(TRISC, 0, type); break;
        case 12: wr_bit(TRISC, 1, type); break;
        case 13: wr_bit(TRISC, 2, type); break;
        case 18: wr_bit(TRISC, 4, type); break;
        case 19: wr_bit(TRISC, 5, type); break;
        case 20: wr_bit(TRISC, 6, type); break;

        case 14: wr_bit(TRISD, 0, type); break;		
        case 15: wr_bit(TRISD, 1, type); break;
        case 16: wr_bit(TRISD, 2, type); break;
        case 17: wr_bit(TRISD, 3, type); break;
        case 22: wr_bit(TRISD, 4, type); break;
        case 23: wr_bit(TRISD, 5, type); break;
        case 24: wr_bit(TRISD, 6, type); break;
        case 25: wr_bit(TRISD, 7, type); break;

        case 7:  wr_bit(TRISE, 0, type); break;
        case 8:  wr_bit(TRISE, 1, type); break;
        case 9:  wr_bit(TRISE, 2, type); break;
        case 0:  wr_bit(TRISE, 3, type); break;
        
        default: break;
    }
}

PUBLIC void digitalWrite(int pin, int value) 
{
	switch (pin) 
    {            
        case 1:  wr_bit(PORTA, 0, value); break;
        case 2:  wr_bit(PORTA, 1, value); break;
        case 3:  wr_bit(PORTA, 2, value); break;
        case 4:  wr_bit(PORTA, 3, value); break;
        case 5:  wr_bit(PORTA, 4, value); break;
        case 6:  wr_bit(PORTA, 5, value); break;
        case 10: wr_bit(PORTA, 6, value); break;

        case 26: wr_bit(PORTB, 0, value); break;
        case 27: wr_bit(PORTB, 1, value); break;
        case 28: wr_bit(PORTB, 2, value); break;
        case 29: wr_bit(PORTB, 3, value); break;
        case 30: wr_bit(PORTB, 4, value); break;
        case 31: wr_bit(PORTB, 5, value); break;
        case 32: wr_bit(PORTB, 6, value); break;
        case 33: wr_bit(PORTB, 7, value); break;

        case 11: wr_bit(PORTC, 0, value); break;
        case 12: wr_bit(PORTC, 1, value); break;
        case 13: wr_bit(PORTC, 2, value); break;
        case 18: wr_bit(PORTC, 4, value); break;
        case 19: wr_bit(PORTC, 5, value); break;
        case 20: wr_bit(PORTC, 6, value); break;

        case 14: wr_bit(PORTD, 0, value); break;		
        case 15: wr_bit(PORTD, 1, value); break;
        case 16: wr_bit(PORTD, 2, value); break;
        case 17: wr_bit(PORTD, 3, value); break;
        case 22: wr_bit(PORTD, 4, value); break;
        case 23: wr_bit(PORTD, 5, value); break;
        case 24: wr_bit(PORTD, 6, value); break;
        case 25: wr_bit(PORTD, 7, value); break;

        case 7:  wr_bit(PORTE, 0, value); break;
        case 8:  wr_bit(PORTE, 1, value); break;
        case 9:  wr_bit(PORTE, 2, value); break;
        case 0:  wr_bit(PORTE, 3, value); break;
        
        default: break;
    }
}

PUBLIC int digitalRead(int pin) 
{    
    switch (pin) 
    {            
        case 1:  return tst_bit(PORTA, 0);
        case 2:  return tst_bit(PORTA, 1);
        case 3:  return tst_bit(PORTA, 2);
        case 4:  return tst_bit(PORTA, 3);
        case 5:  return tst_bit(PORTA, 4);
        case 6:  return tst_bit(PORTA, 5);
        case 10: return tst_bit(PORTA, 6);

        case 26: return tst_bit(PORTB, 0);
        case 27: return tst_bit(PORTB, 1);
        case 28: return tst_bit(PORTB, 2);
        case 29: return tst_bit(PORTB, 3);
        case 30: return tst_bit(PORTB, 4);
        case 31: return tst_bit(PORTB, 5);
        case 32: return tst_bit(PORTB, 6);
        case 33: return tst_bit(PORTB, 7);

        case 11: return tst_bit(PORTC, 0);
        case 12: return tst_bit(PORTC, 1);
        case 13: return tst_bit(PORTC, 2);
        case 18: return tst_bit(PORTC, 4);
        case 19: return tst_bit(PORTC, 5);
        case 20: return tst_bit(PORTC, 6);

        case 14: return tst_bit(PORTD, 0);		
        case 15: return tst_bit(PORTD, 1);
        case 16: return tst_bit(PORTD, 2);
        case 17: return tst_bit(PORTD, 3);
        case 22: return tst_bit(PORTD, 4);
        case 23: return tst_bit(PORTD, 5);
        case 24: return tst_bit(PORTD, 6);
        case 25: return tst_bit(PORTD, 7);

        case 7:  return tst_bit(PORTE, 0);
        case 8:  return tst_bit(PORTE, 1);
        case 9:  return tst_bit(PORTE, 2);
        case 0:  return tst_bit(PORTE, 3);

        default: return -1;
    }
}