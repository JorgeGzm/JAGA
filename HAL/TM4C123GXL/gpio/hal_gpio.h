/**
  * @file    hal_gpio.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para o uso e acesso aos pinos de I/O do TM4C123GH6PM.
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
	#define	HAL_GPIO_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "types/types.h"
#include <stdint.h>
#include "const/conts.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

#define OUTPUT 0
#define INPUT  1
#define LOW 0
#define HIGH 1

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/** @brief TODO*/
typedef enum
{
	/** @brief TODO Documentar*/
    DIR_OUTPUT = 0,
    
	/** @brief TODO Documentar*/
	DIR_INPUT
	
}PIN_DIR;

/** @brief Enum que possui a posicao dos pinos*/
typedef enum 
{
    PIN_0 = 0x00,
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
	/** @brief TODO Documentar*/
	volatile uint32_t *port;
	
	/** @brief TODO Documentar*/
	volatile uint32_t *tris;
	
	/** @brief TODO Documentar*/
	volatile uint32_t *lat;
	
	/** @brief TODO Documentar*/
    uint32_t numPin;
	
}regGPIO;

/** @brief TODO Documentar*/
typedef struct
{
	/** @brief TODO Documentar*/
	volatile uint32_t *out;
	
	/** @brief TODO Documentar*/
    uint32_t pin;
	
}regPin;

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

extern volatile uint32_t *ref_PORTA;
extern volatile uint32_t *ref_PORTB;
extern volatile uint32_t *ref_PORTC;
extern volatile uint32_t *ref_PORTD;
extern volatile uint32_t *ref_PORTE;
extern volatile uint32_t *ref_PORTF;

extern volatile uint32_t *ref_TRISA;
extern volatile uint32_t *ref_TRISB;
extern volatile uint32_t *ref_TRISC;
extern volatile uint32_t *ref_TRISD;
extern volatile uint32_t *ref_TRISE;
extern volatile uint32_t *ref_TRISF;

//extern volatile uint32_t *ref_LATA;
//extern volatile uint32_t *ref_LATB;
//extern volatile uint32_t *ref_LATC;
//extern volatile uint32_t *ref_LATD;
//extern volatile uint32_t *ref_LATE;

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

//extern regGPIO rC0;
//extern regGPIO rC1;
//extern regGPIO rC2;
//extern regGPIO rC3;
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
extern regGPIO rE3;
extern regGPIO rE4;
extern regGPIO rE5;

extern regGPIO rF0;
extern regGPIO rF1;
extern regGPIO rF2;
extern regGPIO rF3;
extern regGPIO rF4;

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/** @brief Rotinha de inicializacao das variaveis abstraidas. */
void V_initRefRegisters(void);

/**
 * @brief TODO
 * @param registrador TODO
 * @param UI8_value TODO
 */
void GPIO_write_data(volatile uint32_t *registrador, uint32_t UI8_value);

/**
 * @brief TODO
 * @param reg TODO
 * @param _port TODO
 */
void GPIO_outputBit(volatile uint32_t *port, uint32_t pino, uint32_t UI8_flag);

/**
 * @brief TODO
 * @param port TODO
 * @param pino TODO
 */
void GPIO_regGPIO_attach(regGPIO *reg, regGPIO *_port);

/**
 * @brief TODO
 * @param pin TODO
 */
void GPIO_output_toggle(volatile uint32_t *port, uint32_t pino);

/**
 * @brief TODO
 * @param pin TODO
 * @param reg TODO
 */
void GPIO_low(volatile uint32_t *port, uint32_t pino);

/**
 * @brief TODO
 * @param pin TODO
 * @param IODirection TODO
 */
void GPIO_high(volatile uint32_t *port, uint32_t pino);

/**
 * @brief TODO
 * @param pin TODO
 * @return TODO
 */
uint8_t GPIO_regPin_rdBit(regPin *pin);

/**
 * @brief TODO
 * @param pin TODO
 */
void GPIO_regPin_outputHigh(regPin *pin);

/**
 * @brief TODO
 * @param pin
 */
void GPIO_regPin_outputLow(regPin *pin);

/**
 * @brief TODO
 * @param flag
 */
void GPIO_regPin_outputBit(regPin *pin, uint32_t flag);

/**
 * @brief TODO
 * @param pin TODO
 * @param reg TODO
 */
void GPIO_regPin_attach(regPin *pin, regGPIO *reg);

/**
 * @brief TODO
 * @param pin TODO
 * @param IODirection
 */
void GPIO_regPin_setDir(regGPIO *pin, PIN_DIR IODirection);

/**
 * @brief TODO
 * @param pin TODO
 * @return TODO
 */
uint8_t GPIO_regPin_inputBit(regPin *pin);

PUBLIC int digitalRead(int pin);
PUBLIC void digitalWrite(int pin, int value);
PUBLIC void pinMode(int pin, int type);

#endif	
