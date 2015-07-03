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

void run_him(void)
{
	static uint16 counterA = 0;
	static uint16 counterB = 0;

	if(buttons_check_press(TECLA_UP, 0))
	{
		lcd_gotoxy(1, 1);
		lcd_printf((int8 *)"\fTECLA UP        ");

		lcd_gotoxy(1, 2);
		lcd_printf((int8 *)"%u      ", counterA++);

		leds_set(LD1G, LED_BLINK_SLOW);
		leds_set(LD2G, LED_OFF);
	}

	if(buttons_check_press(TECLA_DOWN, 1))
	{
		lcd_gotoxy(1, 1);
		lcd_printf((int8 *)"\fTECLA DOWN      ");

		lcd_gotoxy(1, 2);
		lcd_printf((int8 *)"%u      ", counterB++);

		leds_set(LD1G, LED_OFF);
		leds_set(LD2G, LED_BLINK_FAST);
	}

	if(buttons_check_press(TECLA_DOWN | TECLA_UP, 1))
	{
		lcd_gotoxy(1, 1);
		lcd_printf((int8 *)"\fTECLA DOWN UP   ");
		leds_set(LD1G | LD2G, LED_BLINK_SLOW);
	}

	Delay_ms(100);

	buttons_read_isr_10ms();
	leds_action_isr_10ms();
}


