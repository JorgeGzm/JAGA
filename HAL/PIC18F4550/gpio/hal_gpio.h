/**
  * @file    hal_gpio.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para o uso e acesso aos pinos de I/O do PIC18f4550.
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

#ifndef HAL_GPIO_H
    #define HAL_GPIO_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "types/types.h"
#include "device/hal_device.h"
#include "delay/hal_delay.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/** @brief Enum que possui a posicao dos pinos*/
typedef enum
{
    /**@brief TODO */
    DIR_OUTPUT = 0,
    
    /**@brief TODO */
    DIR_INPUT
            
}PIN_DIR;

/** @brief Enum que possui a posicao dos pinos*/
typedef enum 
{
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,

    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
}PinosMCU;

/** @brief TODO*/
typedef struct
{
    /** @brief TODO*/
    volatile uint8_t *port;
    
    /** @brief TODO*/
    volatile uint8_t *tris;
    
    /** @brief TODO*/
    volatile uint8_t *lat;
    
    /** @brief TODO*/
    PinosMCU numPin;
    
}regGPIO;

/** @brief TODO*/
typedef struct 
{
    /** @brief TODO*/
    volatile uint8_t *out;
    
    /** @brief TODO*/
    uint8_t pin;
    
}regPin;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

extern volatile uint8_t *ref_PORTA;
extern volatile uint8_t *ref_PORTB;
extern volatile uint8_t *ref_PORTC;
extern volatile uint8_t *ref_PORTD;
extern volatile uint8_t *ref_PORTE;

extern volatile uint8_t *ref_TRISA;
extern volatile uint8_t *ref_TRISB;
extern volatile uint8_t *ref_TRISC;
extern volatile uint8_t *ref_TRISD;
extern volatile uint8_t *ref_TRISE;

extern volatile uint8_t *ref_LATA;
extern volatile uint8_t *ref_LATB;
extern volatile uint8_t *ref_LATC;
extern volatile uint8_t *ref_LATD;
extern volatile uint8_t *ref_LATE;

extern regGPIO rA0;
extern regGPIO rA1;
extern regGPIO rA2;
extern regGPIO rA3;
extern regGPIO rA4;
extern regGPIO rA5;
extern regGPIO rA6;
extern regGPIO rA7;

extern regGPIO rB0;
extern regGPIO rB1;
extern regGPIO rB2;
extern regGPIO rB3;
extern regGPIO rB4;
extern regGPIO rB5;
extern regGPIO rB6;
extern regGPIO rB7;

extern regGPIO rC0;
extern regGPIO rC1;
extern regGPIO rC2;
extern regGPIO rC3;
extern regGPIO rC4;
extern regGPIO rC5;
extern regGPIO rC6;
extern regGPIO rC7;

extern regGPIO rD0;
extern regGPIO rD1;
extern regGPIO rD2;
extern regGPIO rD3;
extern regGPIO rD4;
extern regGPIO rD5;
extern regGPIO rD6;
extern regGPIO rD7;

extern regGPIO rE0;
extern regGPIO rE1;
extern regGPIO rE2;

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/** @brief Rotinha de inicializacao das variaveis abstraidas.*/
void V_initRefRegisters(void);

/**
 * @brief TODO documentar
 * @param registrador
 * @param UI8_value
 */
void GPIO_write_data(volatile uint8_t *registrador, uint8_t UI8_value);

/**
 * @brief TODO documentar
 * @param port
 * @param pino
 * @param UI8_flag
 */
void GPIO_outputBit(volatile uint8_t *port, uint8_t pino, uint8_t UI8_flag);

/**
 * @brief TODO documentar
 * @param port TODO
 * @param pino TODO
 */
void GPIO_output_toggle(volatile uint8_t *port, uint8_t pino);

/**
 * @brief TODO documentar
 * @param port TODO
 * @param pino TODO
 */
void GPIO_low(volatile uint8_t *port, uint8_t pino);

/**
 * @brief TODO
 * @param port TODO
 * @param pino TODO
 */
void GPIO_high(volatile uint8_t *port, uint8_t pino);

/**
 * @brief TODO documentar
 * @param reg TODO
 * @param _port TODO
 */
void GPIO_regGPIO_attach(regGPIO *reg, regGPIO *_port);

/**
 * @brief TODO documentar
 * @param pin TODO
 * @return TODO
 */
uint8_t GPIO_regPin_rdBit(regPin *pin);

/**
 * @brief TODO documentar
 * @param pin TODO
 * @param reg TODO
 */
void GPIO_regPin_attach(regPin *pin, regGPIO *reg);

/**
 * @brief TODO documentar
 * @param pin TODO
 */
void GPIO_regPin_outputHigh(regPin *pin);

/**
 * @brief TODO documentar
 * @param pin TODO
 */
void GPIO_regPin_outputLow(regPin *pin);

/**
 * @brief TODO documentar
 * @param pin TODO
 * @param flag TODO
 */
void GPIO_regPin_outputBit(regPin *pin, uint8_t flag);

/**
 * @brief TODO documentar
 * @param pin TODO
 * @return 
 */
uint8_t GPIO_regPin_inputBit(regPin *pin);

/**
 * @brief TODO
 * @param pin TODO
 * @param io IODirection
 */
void GPIO_regPin_setDir(regGPIO *pin, PIN_DIR IODirection);

#endif	
