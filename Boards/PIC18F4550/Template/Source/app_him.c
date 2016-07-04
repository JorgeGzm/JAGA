/**
  * @file    app_him.c
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

#include <stdint.h>
#include "app_him.h"
#include "sys_hw.h"
#include "sys_uart.h"
#include "types/types.h"
#include "buttons/buttons.h"
#include "leds/leds.h"
#include "lcd/lcd.h"
#include "xprintf/xprintf.h"

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

PUBLIC void run_him(void)
{
    static uint16_t counterA = 0;
    static uint16_t counterB = 0;
    static uint16_t counterC = 0;
    
    if(buttons_check_press(BTN_UP, BTN_PULSE))
    {
        lcd_gotoxy(1, 1);
        xprintf(lcd_putc, (uint8_t *)"BUTTON UP       ");
        
        lcd_gotoxy(1, 2);
        xprintf(lcd_putc, (uint8_t *)"%u      ", ++counterA);
        
        leds_set(LD1G, LED_BLINK_SLOW);
        leds_set(LD2G, LED_OFF);       
        
        xprintf(callback_uart_putc, (uint8_t *)"\r\nButton UP pressed %u times", counterA);
    }
    
    if(buttons_check_press(BTN_DOWN, BTN_CONTINUOS))
    {   
        lcd_gotoxy(1, 1);
        xprintf(lcd_putc, (uint8_t *)"BUTTON DOWN     ");
        
        lcd_gotoxy(1, 2);
        xprintf(lcd_putc, (uint8_t *)"%u      ", ++counterB);
        
        leds_set(LD1G, LED_OFF);
        leds_set(LD2G, LED_BLINK_FAST);
        
        xprintf(callback_uart_putc, (uint8_t *)"\r\nButton DOWN pressed %u times", counterB);
    }
    
    if(buttons_check_press(BTN_DOWN | BTN_UP, BTN_CONTINUOS))
    {
        lcd_gotoxy(1, 1);
        xprintf(lcd_putc, (uint8_t *)"\fBUTTON DOWN + UP");
        
        lcd_gotoxy(1, 2);
        xprintf(lcd_putc, (uint8_t *)"%u      ", ++counterC);
        
        leds_set(LD1G | LD2G, LED_BLINK_SLOW);    
        
        xprintf(callback_uart_putc, (uint8_t *)"\r\nButtons DOWN + UP pressed %u times", counterC);
    }
}


