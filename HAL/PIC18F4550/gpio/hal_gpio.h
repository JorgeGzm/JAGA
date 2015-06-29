/**
 * @file   	hal_gpio.h
 * @brief   Bibliteoca para o uso e acesso aos pinos de I/O do PIC18f4550.
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
    #define HAL_GPIO_H

#include "types/types.h"
#include "device/hal_device.h"
#include "delay/hal_delay.h"

#define pins1 1

typedef enum _PIN_DIR
{
    DIR_OUTPUT = 0,
    DIR_INPUT
}PIN_DIR;

#ifndef NULL
    #define NULL ((*void)0)
#endif

/** Enum que possui a posicao dos pinos*/
enum PinosMCU
{
    PIN_0 = 0,
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
    volatile uint8 *port;
    volatile uint8 *tris;
    volatile uint8 *lat;
    uint8 numPin;
}regGPIO;

typedef struct _regPin
{
    volatile uint8 *out;
    uint8 pin;
}regPin;

/**
 * coloca em 1 o bit x da variável byte. Range(0-7).
 * Exemplo:  set_bit(PORTD, 5);
 * Resultado: PORTD = 0b00010000
 */
#define	set_bit(value,bit_x)	(value |= (1 << bit_x))

/**
 * coloca em 0 no bit_x da variavel variável byte. Range(0-7).
 * Exemplo:  lr_bit(PORTD, 5);
 * Resultado: PORTD = 0b00000000
 */
#define	clr_bit(value,bit_x)	(value &= ~(1 << bit_x))

/**
* troca o estado lógico do bit x da variável bytex. Range(0-7).
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

/** Rotinha de inicializacao das variaveis abstraidas.*/
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
 * @param reg
 * @param _port
 * @param _tris
 */
void GPIO_attach(regGPIO *reg, regGPIO *_port);

/**
 * @brief TODO documentar
 * @param pin
 * @return 
 */
uint8 GPIO_input_state(regPin *pin);

/**
 * @brief TODO documentar
 * @param port
 * @param pino
 */
void GPIO_output_toggle(volatile uint8 *port, uint8 pino);

/**
 * @brief TODO documentar
 * @param port
 * @param pino
 */
void GPIO_low(volatile uint8 *port, uint8 pino);

/**
 * @brief TODO
 * @param port
 * @param pino
 */
void GPIO_high(volatile uint8 *port, uint8 pino);

/**
 * @brief TODO documentar
 * @param pin
 * @param reg
 */
void GPIO_pin_attach(regPin *pin, regGPIO *reg);

/**
 * @brief TODO documentar
 * @param pin
 */
void GPIO_pin_high(regPin *pin);

/**
 * @brief TODO documentar
 * @param pin
 */
void GPIO_pin_low(regPin *pin);

/**
 * @brief TODO documentar
 * @param pin
 * @param flag
 */
void GPIO_pin_outputBit(regPin *pin, uint8 flag);

/**
 * @brief TODO documentar
 * @param pin
 * @param delay_us
 */
void GPIO_pin_pulse(regGPIO *pin, uint16 delay_us);

/**
 * @brief TODO
 * @param pin
 * @param io
 */
void GPIO_confDir(regGPIO *pin, PIN_DIR IODirection);

//variaveis externas
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

/** */
extern regGPIO rA0;
extern regGPIO rA1;
extern regGPIO rA2;
extern regGPIO rA3;
extern regGPIO rA4;
extern regGPIO rA5;
extern regGPIO rA6;
extern regGPIO rA7;

/** */
extern regGPIO rB0;
extern regGPIO rB1;
extern regGPIO rB2;
extern regGPIO rB3;
extern regGPIO rB4;
extern regGPIO rB5;
extern regGPIO rB6;
extern regGPIO rB7;

/** */
extern regGPIO rC0;
extern regGPIO rC1;
extern regGPIO rC2;
extern regGPIO rC3;
extern regGPIO rC4;
extern regGPIO rC5;
extern regGPIO rC6;
extern regGPIO rC7;

/** */
extern regGPIO rD0;
extern regGPIO rD1;
extern regGPIO rD2;
extern regGPIO rD3;
extern regGPIO rD4;
extern regGPIO rD5;
extern regGPIO rD6;
extern regGPIO rD7;

/** */
extern regGPIO rE0;
extern regGPIO rE1;
extern regGPIO rE2;


#endif	/* HAL_GPIO_H */
