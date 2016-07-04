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
#include <string.h>
#include <stdio.h>

#include "sys_hw.h"
#include "sys_uart.h"
#include "app_him.h"
#include "app_nivel_control.h"
#include "buttons/buttons.h"
#include "leds/leds.h"
#include "lcd/lcd.h"
#include "DS1307/DS1307.h"
#include "LM35/lm35.h"
#include "AT24C32/AT24C32.h"
#include "xprintf/xprintf.h"
#include "xtime/xtime.h"
#include "types/types.h"

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
    char str[7];
    float aux;
    DataTime rtc;
    static uint8_t press = 0;
    static uint8_t press_old = 0;
    uint8_t buffer_read[5];
    
    press = buttons_event();
    
    if(press_old != press)
    {   
        press_old = press;
        
        switch (press)
        {
            case 0x01:

                lcd_gotoxy(1, 1);
                xprintf(lcd_putc, (uint8_t *)"\fTemperatura:");

                lcd_gotoxy(1, 2);             
                aux = lm35_read(INDEX_0);            
                sprintf(&str, "%.2f", aux);
                xprintf(lcd_putc, (uint8_t *)"%s", str);
                
                break;

            case 0x02:

                lcd_gotoxy(1, 1);
                xprintf(lcd_putc, (uint8_t *)"\fNivel Tanque:");

                lcd_gotoxy(1, 2);             
                aux = get_nivel_tanque();            
                sprintf(&str, "%.2f", aux);
                xprintf(lcd_putc, (uint8_t *)"%s", str);

                leds_set(LD1G, LED_BLINK_SLOW);
                leds_set(LD2G, LED_OFF);       

                break;

            case 0x04:

                lcd_gotoxy(1, 1);
                strcpy(&str, " ");
                sprintf(&str, "%.2f", get_nivel_dutyPWM());
                xprintf(lcd_putc, (uint8_t *)"\fDuty: %s",str);
                lcd_putc('%');

                lcd_gotoxy(1, 2);   
                strcpy(&str, " ");
                sprintf(&str, "%.2f", get_nivel_tanque());
                xprintf(lcd_putc, (uint8_t *)"Nivel: %s", str);
                
                leds_set(LD1G, LED_OFF);
                leds_set(LD2G, LED_BLINK_FAST);   
    
                break;

            case 0x08:

                DS1307_read(&rtc);    
                
                lcd_gotoxy(1, 1);		
                xprintf(lcd_putc, "\fHora: %d:%d:%d", rtc.hour, rtc.minute, rtc.second);
                
                lcd_gotoxy(1, 2);
                xprintf(lcd_putc, "Data: %d/%d/%d", rtc.date, rtc.month, rtc.yearInt);
                break;
                
            case 0x03:
                
                lcd_gotoxy(1, 1);		
                xprintf(lcd_putc, "\fDados Gravados:");
                
                lcd_gotoxy(1, 2);	
                AT24C32_read(0, 5, &buffer_read[0]);
                xprintf(lcd_putc, "%s", &buffer_read[0]);
                break;
        }
    }
            
        
}