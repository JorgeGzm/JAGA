/**
* @file    app_him.c
* @brief   TODO
* @author  Rafael Lopes
* @date    27 de Fevereiro 2015
* @version 0.1.0.0 (beta)
*/

#include "../Header/app_him.h"
#include "vars/vars.h"
#include "types/types.h"
#include "buttons/buttons.h"
#include "leds/leds.h"
#include "lcd/lcd.h"
#include "serial/serial.h"
#include "sys_hw.h"

#include "delay/hal_delay.h"

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
	
	Delay_ms(10); 
	leds_action_isr_10ms(); //TODO passar para interrupcao do timer
	buttons_read_isr_10ms(); //TODO passar para interrupcao do timer
}