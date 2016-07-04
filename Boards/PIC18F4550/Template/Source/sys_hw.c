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

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "sys_hw.h"
#include "app_info.h"
#include "sys_mcu.h"
#include "sys_timer.h"
#include "sys_i2c.h"
#include "sys_spi.h"
#include "sys_ad.h"
#include "sys_pwm.h"
#include "sys_uart.h"
#include "sys_gpio.h"

#include "lcd/lcd.h"
#include "leds/leds.h"
#include "buttons/buttons.h"
#include "interrupt/hal_interrupts.h"
#include "xprintf/xprintf.h"

#include "gpio/hal_gpio.h"

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

PUBLIC void setupHardware(void)
{
    //inicializa as configuraçoes do micrococontrolador
    init_mcu();

    //Inicializa driver das interrupcoes
    interrupt_init();

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

PUBLIC void setupDevices(void)
{   
    //inicializa informaçoes do equipamento.
    info_init();

    //inicializa e configura mecanismo de controle das teclas
    buttons_init();
    button_attach(1, 9);
    button_attach(2, 28);

    //configura e inicializa pinos que serao usados pela biblioteca LCD.
    lcd_attach(14, 15, 22, 23, 24, 25);
    lcd_gotoxy(1, 1);
    uint8_t buff[] = {"Modulo JAGA!    "};
    lcd_print(&buff);
   
    //configura mecanismo de controle dos leds
    pinMode(0, INPUT);
    leds_init();
    leds_attach(0, 4);
    leds_attach(1, 5);
    
    leds_set(LD1G, LED_BLINK_FAST);
    leds_set(LD2G, LED_BLINK_SLOW);
   
}
