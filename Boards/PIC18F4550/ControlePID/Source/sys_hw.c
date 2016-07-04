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
#include "sys_mcu.h"
#include "sys_timer.h"
#include "sys_i2c.h"
#include "sys_spi.h"
#include "sys_ad.h"
#include "sys_pwm.h"
#include "sys_uart.h"
#include "sys_gpio.h"
#include "app_nivel_control.h"
#include "app_info.h"

#include "lcd/lcd.h"
#include "leds/leds.h"
#include "buttons/buttons.h"
#include "HCSR04/HCSR04.h"
#include "DS1307/DS1307.h"
#include "AT24C32/AT24C32.h"
#include "LM35/lm35.h"
#include "xprintf/xprintf.h"

#include "ad/hal_ad.h"
#include "i2c/hal_i2c.h"
#include "interrupt/hal_interrupts.h"
#include "timer/hal_timer.h"
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
    init_gpio();
    init_uart();
    init_timer0();    
    init_timer1();
    init_i2c();    
    init_AD();    
    init_pwm();
}

PUBLIC void setupDevices(void)
{   
   // DataTime relogio;    
      
    //inicializa informaçoes do equipamento.
    info_init();
    
    //Inicializa e configura mecanismo de controle das teclas
    buttons_init();
   // button_attach(0, 29);
    button_attach(1, 28);
    button_attach(2, 9);
    //button_attach(3, 8);

    //Configura e inicializa pinos que serao usados pela biblioteca LCD.
    lcd_attach(14, 15, 22, 23, 24, 25);
    lcd_gotoxy(1, 1);
    uint8_t buff[] = {"Modulo JAGA!    "};
    lcd_print(&buff);
   
    //configura mecanismo de controle dos leds
    leds_attach(0, 4);
    leds_attach(1, 5);
    leds_set(LD1G, LED_OFF);
         
    //Sensor Ultrasonico
    HCSR04_attach(0, 17, 16); 
    HCSR04_set_const(48000000, 8);                                                    
    HCSR04_attach_Timer(_TMR1);     
    
    //RTC
    DS1307_attach_i2c(&Driver_I2C0);
    
    //Memoria EEPROM externa
    AT24C32_attach_i2c(i2c0_burst_read16, i2c0_burst_write16);
        
    lm35_init();
    lm35_attach(0, 1, AD_CH0);
    
    init_nivel_controle();
     
   // Init datatime in RTC
//    relogio.second = 10;
//    relogio.minute = 56;
//    relogio.hour = 33;
//    relogio.day = 6;
//    relogio.date = 11;
//    relogio.month = 3;
//    relogio.yearChar = 16;
//    DS1307_write(relogio);
     
    xprintf(callback_uart_putc, (uint8_t *)"\r\nInit JAGA system");    
}