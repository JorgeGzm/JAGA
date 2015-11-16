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

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "../Header/app_him.h"
#include "vars/vars.h"
#include "types/types.h"
#include "buttons/buttons.h"
#include "leds/leds.h"
#include "lcd/lcd.h"

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

void run_him(void)
{
	static uint16 counterA = 0;
	static uint16 counterB = 0;
	static uint16 counterC = 0;

	if(buttons_check_press(BTN_UP, BTN_PULSE))
	{
		lcd_gotoxy(1, 1);
		lcd_printf((int8 *)"BUTTON UP       ");

		lcd_gotoxy(1, 2);
		lcd_printf((int8 *)"%u      ", ++counterA);

		leds_set(LD1G, LED_BLINK_SLOW);
		leds_set(LD2G, LED_OFF);

		serial_printf(0, (int8 *)"\r\nButton UP pressed %u times", counterA);
	}

	if(buttons_check_press(BTN_DOWN, BTN_CONTINUOS))
	{
		lcd_gotoxy(1, 1);
		lcd_printf((int8 *)"BUTTON DOWN     ");

		lcd_gotoxy(1, 2);
		lcd_printf((int8 *)"%u      ", ++counterB);

		leds_set(LD1G, LED_OFF);
		leds_set(LD2G, LED_BLINK_FAST);

		serial_printf(0, (int8 *)"\r\nButton DOWN pressed %u times", counterB);
	}

	if(buttons_check_press(BTN_DOWN | BTN_UP, BTN_CONTINUOS))
	{
		lcd_gotoxy(1, 1);
		lcd_printf((int8 *)"\fBUTTON DOWN + UP");

		lcd_gotoxy(1, 2);
		lcd_printf((int8 *)"%u      ", ++counterC);

		leds_set(LD1G | LD2G, LED_BLINK_SLOW);
		serial_printf(0, (int8 *)"\r\nButtons DOWN + UP pressed %u times", counterC);
	}

	Delay_ms(100); //

	buttons_read_isr_10ms(); //TODO passar para interrupcao do timer
	leds_action_isr_100ms();  //TODO passar para interrupcao do timer
}

