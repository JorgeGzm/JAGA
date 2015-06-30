/**
 * @file   	hal_gpio.h
 * @brief   Bibliteoca para o uso e acesso aos pinos de I/O do TM4C123GH6PM.
 * @details Esta biblioca faz o uso da comunicacao I2C para a traca de dados com o CI.
 * @author 	Jorge Guzman (jorge.gzm@gmail.com)
 * @date 	26 de Junho de 2015
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

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

#include "types/types.h"

#define pins1 1

typedef enum _PIN_DIR
{
    DIR_OUTPUT = 0,
    DIR_INPUT
}PIN_DIR;

/** Enum que possui a posicao dos pinos*/
enum PinosMCU
{
    PIN_0 = 0x00,
    PIN_1,
    PIN_2,
    PIN_3,
         
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
};

/** */
typedef struct regGPIO
{
	volatile uint32 *port;
	volatile uint32 *tris;
	volatile uint32 *lat;
    uint32 numPin;
}regGPIO;

typedef struct _regPin
{
	volatile uint32 *out;
    uint32 pin;
}regPin;

/**
 * coloca em 1 o bit x da vari�vel byte. Range(0-7).
 * Exemplo:  set_bit(PORTD, 5);
 * Resultado: PORTD = 0b00010000
 */
#define	set_bit(value,bit_x)	(value |= (1 << bit_x))

/**
 * coloca em 0 no bit_x da variavel vari�vel byte. Range(0-7).
 * Exemplo:  lr_bit(PORTD, 5);
 * Resultado: PORTD = 0b00000000
 */
#define	clr_bit(value,bit_x)	(value &= ~(1 << bit_x))

/**
* troca o estado l�gico do bit x da vari�vel bytex. Range(0-7).
* Exemplo:   toggle_bit(PORTD, 5);
* Resultado: PORTD = 0b00000000 ou PORTD = 0b00010000
*/
#define toggle_bit(value,bit_x)     (value ^= (1 << bit_x))

/**
 * retorna 0 ou !0 conforme leitura do bit. Range(0-7).
 * Exemplo:   tst_bit(PORTD, 5);
 * Resultado: x = 0 ou x = 32
 */
#define tst_bit(value,bit_x)        (value & (1 << bit_x))

/**
 * retorna 0 ou 1 conforme leitura do bit. Range(0-7).
 * Exemplo:   tst_bit_bool(PORTD, 5);
 * Resultado: x = 0 ou x = 1
 */
#define tst_bit_bool(value,bit_x) 	((value & (1 << bit_x)) >> bit_x)



void V_initRefRegisters(void);
void GPIO_write_data(volatile uint32 *registrador, uint32 UI8_value);
void GPIO_outputBit(volatile uint32 *port, uint32 pino, uint32 UI8_flag);
void GPIO_attach(regGPIO *reg, regGPIO *_port);

void GPIO_output_toggle(volatile uint32 *port, uint32 pino);

void GPIO_low(volatile uint32 *port, uint32 pino);
void GPIO_high(volatile uint32 *port, uint32 pino);

uint8 GPIO_input_state(regPin *pin);
void GPIO_pin_high(regPin *pin);
void GPIO_pin_low(regPin *pin);
void GPIO_pin_outputBit(regPin *pin, uint32 flag);
void GPIO_pin_attach(regPin *pin, regGPIO *reg);

/**
 * @brief TODO
 * @param pin
 * @param io
 */
void GPIO_confDir(regGPIO *pin, PIN_DIR IODirection);

//variaveis externas
extern volatile uint32 *ref_PORTA;
extern volatile uint32 *ref_PORTB;
extern volatile uint32 *ref_PORTC;
extern volatile uint32 *ref_PORTD;
extern volatile uint32 *ref_PORTE;
extern volatile uint32 *ref_PORTF;

extern volatile uint32 *ref_TRISA;
extern volatile uint32 *ref_TRISB;
extern volatile uint32 *ref_TRISC;
extern volatile uint32 *ref_TRISD;
extern volatile uint32 *ref_TRISE;
extern volatile uint32 *ref_TRISF;

//extern volatile uint32 *ref_LATA;
//extern volatile uint32 *ref_LATB;
//extern volatile uint32 *ref_LATC;
//extern volatile uint32 *ref_LATD;
//extern volatile uint32 *ref_LATE;

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
extern regGPIO rE3;
extern regGPIO rE4;
extern regGPIO rE5;
extern regGPIO rE6;
extern regGPIO rE7;

extern regGPIO rF0;
extern regGPIO rF1;
extern regGPIO rF2;
extern regGPIO rF3;
extern regGPIO rF4;
extern regGPIO rF5;
extern regGPIO rF6;
extern regGPIO rF7;

#endif	/* HAL_GPIO_H */

