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

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

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


PUBLIC int digitalRead(int pin);
PUBLIC void digitalWrite(int pin, int value);
PUBLIC void pinMode(int pin, int type);

#endif	
