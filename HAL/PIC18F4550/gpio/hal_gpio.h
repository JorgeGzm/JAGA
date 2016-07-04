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

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/** @brief Rotinha de inicializacao das variaveis abstraidas.*/
PUBLIC void V_initRefRegisters(void);
//
///**
// * @brief TODO documentar
// * @param registrador
// * @param UI8_value
// */
//PUBLIC void GPIO_write_data(volatile uint8_t *registrador, uint8_t UI8_value);
//
///**
// * @brief TODO documentar
// * @param port
// * @param pino
// * @param UI8_flag
// */
//PUBLIC void GPIO_outputBit(volatile uint8_t *port, uint8_t pino, uint8_t UI8_flag);
//
///**
// * @brief TODO documentar
// * @param port TODO
// * @param pino TODO
// */
//PUBLIC void GPIO_output_toggle(volatile uint8_t *port, uint8_t pino);
//
///**
// * @brief TODO documentar
// * @param port TODO
// * @param pino TODO
// */
//PUBLIC void GPIO_low(volatile uint8_t *port, uint8_t pino);
//
///**
// * @brief TODO
// * @param port TODO
// * @param pino TODO
// */
//PUBLIC void GPIO_high(volatile uint8_t *port, uint8_t pino);
//
///**
// * @brief TODO documentar
// * @param reg TODO
// * @param _port TODO
// */
//PUBLIC void GPIO_regGPIO_attach(regGPIO *reg, regGPIO *_port);
//
///**
// * @brief TODO documentar
// * @param pin TODO
// * @return TODO
// */
//PUBLIC uint8_t GPIO_regPin_rdBit(regPin *pin);
//
///**
// * @brief TODO documentar
// * @param pin TODO
// * @param reg TODO
// */
//PUBLIC void GPIO_regPin_attach(regPin *pin, regGPIO *reg);
//
///**
// * @brief TODO documentar
// * @param pin TODO
// */
//PUBLIC void GPIO_regPin_outputHigh(regPin *pin);
//
///**
// * @brief TODO documentar
// * @param pin TODO
// */
//PUBLIC void GPIO_regPin_outputLow(regPin *pin);
//
///**
// * @brief TODO documentar
// * @param pin TODO
// * @param flag TODO
// */
//PUBLIC void GPIO_regPin_outputBit(regPin *pin, uint8_t flag);
//
///**
// * @brief TODO documentar
// * @param pin TODO
// * @return 
// */
//PUBLIC uint8_t GPIO_regPin_inputBit(regPin *pin);
//
///**
// * @brief TODO
// * @param pin TODO
// * @param io IODirection
// */
//PUBLIC void GPIO_regPin_setDir(regGPIO *pin, PIN_DIR IODirection);


PUBLIC void digitalWrite(int pin, int value);
PUBLIC int digitalRead(int pin);
PUBLIC void pinMode(int pin, int type);

#endif	
