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
	Delay_ms(10);
	leds_action_isr_10ms();
}


	//*ref_PORTB = 32;
	////set_bit(*ref_PORTB, 5);
	//Delay_ms(1000);
	//*ref_PORTB = 0;
	////clr_bit(*ref_PORTB, 5);
	//Delay_ms(1000);