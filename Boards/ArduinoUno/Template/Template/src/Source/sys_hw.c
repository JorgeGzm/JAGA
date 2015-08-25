/**
  * @file    sys_hw.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 27, 2015
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
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

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "../Header/sys_hw.h"
#include "gpio/hal_gpio.h"
#include "buttons/buttons.h"
#include "leds/leds.h"
#include "lcd/lcd.h"
#include "uart/hal_uart.h"

//------------------------------------------------------------------------------
// Private Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Variable Declaration			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions Source
//------------------------------------------------------------------------------

void setupHardware(void)
{
	//inicializa as configuraçoes do micrococontrolador
	init_mcu();

	//Inicializa driver das interrupcoes
	//interrupt_init();

	//Inicializa as portas do microcontrolador
	init_gpio();

	//Inicializa UART
	init_uart();

	//Inicializa TMR0
	init_timer0();

	//Inicializa I2C
	init_i2c();

	//Inicializa ADs
	init_AD();

	//Inicializa PWM
	init_pwm();
}

void setupDevices(void)
{
	//inicializa informaçoes do equipamento.
	info_init();

	serial_init();
	serial_attach(0, uart0_putc);
	
	//Inicializa e configura mecanismo de controle das teclas
	buttons_init();
	button_attach(2, rD2);
	button_attach(1, rD3);

	//Configura e inicializa pinos que serao usados pela biblioteca LCD.
	lcd_attach(rB0, rB1, rD4, rD5, rD6, rD7);
	lcd_gotoxy(1, 1);
	int8 buff[] = {"Modulo JAGA     "};
	lcd_printf(&buff);
	
	//configura mecanismo de controle dos leds
	leds_init();
	leds_attach(0, rB2);
	leds_attach(1, rB3);
	leds_set(LD1G, LED_OFF);
	leds_set(LD2G, LED_OFF);
}


