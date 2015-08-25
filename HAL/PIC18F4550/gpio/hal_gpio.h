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

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "types/types.h"
#include "device/hal_device.h"
#include "delay/hal_delay.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

#ifndef NULL
    /** @brief TODO documentar */
    #define NULL ((*void)0)
#endif

/**
 * @brief Coloca em 1 o bit x da variável byte. Range(0-7).
 * Exemplo:  set_bit(PORTD, 5);
 * Resultado: PORTD = 0b00010000
 */
#define	set_bit(value,bit_x)	(value |= (1 << bit_x))

/**
 * @brief coloca em 0 no bit_x da variavel variável byte. Range(0-7).
 * Exemplo:  lr_bit(PORTD, 5);
 * Resultado: PORTD = 0b00000000
 */
#define	clr_bit(value,bit_x)	(value &= ~(1 << bit_x))

/**
* @brief Troca o estado lógico do bit x da variável bytex. Range(0-7).
* Exemplo:   toggle_bit(PORTD, 5);
* Resultado: PORTD = 0b00000000 ou PORTD = 0b00010000
*/
#define toggle_bit(value,bit_x)     (value ^= (1 << bit_x))

/**
 * @brief Retorna 0 ou !0 conforme leitura do bit. Range(0-7).
 * Exemplo:   tst_bit(PORTD, 5);
 * Resultado: x = 0 ou x = 32
 */
#define tst_bit(value,bit_x)        (value & (1 << bit_x))

/**
 * @brief Retorna 0 ou 1 conforme leitura do bit. Range(0-7).
 * Exemplo:   tst_bit_bool(PORTD, 5);
 * Resultado: x = 0 ou x = 1
 */
#define tst_bit_bool(value,bit_x) 	((value & (1 << bit_x)) >> bit_x)

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

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
    volatile uint8 *port;
    
    /** @brief TODO*/
    volatile uint8 *tris;
    
    /** @brief TODO*/
    volatile uint8 *lat;
    
    /** @brief TODO*/
    PinosMCU numPin;
    
}regGPIO;

/** @brief TODO*/
typedef struct 
{
    /** @brief TODO*/
    volatile uint8 *out;
    
    /** @brief TODO*/
    uint8 pin;
    
}regPin;

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

extern volatile uint8 *ref_PORTA;
extern volatile uint8 *ref_PORTB;
extern volatile uint8 *ref_PORTC;
extern volatile uint8 *ref_PORTD;
extern volatile uint8 *ref_PORTE;

extern volatile uint8 *ref_TRISA;
extern volatile uint8 *ref_TRISB;
extern volatile uint8 *ref_TRISC;
extern volatile uint8 *ref_TRISD;
extern volatile uint8 *ref_TRISE;

extern volatile uint8 *ref_LATA;
extern volatile uint8 *ref_LATB;
extern volatile uint8 *ref_LATC;
extern volatile uint8 *ref_LATD;
extern volatile uint8 *ref_LATE;

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

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

/** @brief Rotinha de inicializacao das variaveis abstraidas.*/
void V_initRefRegisters(void);

/**
 * @brief TODO documentar
 * @param registrador
 * @param UI8_value
 */
void GPIO_write_data(volatile uint8 *registrador, uint8 UI8_value);

/**
 * @brief TODO documentar
 * @param port
 * @param pino
 * @param UI8_flag
 */
void GPIO_outputBit(volatile uint8 *port, uint8 pino, uint8 UI8_flag);

/**
 * @brief TODO documentar
 * @param port TODO
 * @param pino TODO
 */
void GPIO_output_toggle(volatile uint8 *port, uint8 pino);

/**
 * @brief TODO documentar
 * @param port TODO
 * @param pino TODO
 */
void GPIO_low(volatile uint8 *port, uint8 pino);

/**
 * @brief TODO
 * @param port TODO
 * @param pino TODO
 */
void GPIO_high(volatile uint8 *port, uint8 pino);

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
uint8 GPIO_regPin_rdBit(regPin *pin);

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
void GPIO_regPin_outputBit(regPin *pin, uint8 flag);

/**
 * @brief TODO documentar
 * @param pin TODO
 * @return 
 */
uint8 GPIO_regPin_inputBit(regPin *pin);

/**
 * @brief TODO
 * @param pin TODO
 * @param io IODirection
 */
void GPIO_regPin_setDir(regGPIO *pin, PIN_DIR IODirection);

#endif	
