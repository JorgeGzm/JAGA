/**
 * @file    sys_hw.c
 * @brief   TODO
 * @author  Rafael Lopes
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 (beta)
 */

#include "../Header/sys_hw.h"
#include "uart/hal_uart.h"

void init_drivers(void)
{
	//Inicializa as portas do microcontrolador
    init_gpio();

    //inicializa as configuraçoes do micrococontrolador
    init_mcu();

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

    //Inicializa driver das interrupcoes
	//interrupt_init();
}

void init_devices(void)
{
	serial_init();
	serial_attach(0, uart0_putc);

	//inicializa informaçoes do equipamento.
	info_init();

	//Inicializa e configura mecanismo de controle das teclas
	buttons_init();
	button_attach(1, rF0);
	button_attach(2, rF4);

	//Configura e inicializa pinos que serao usados pela biblioteca LCD.
	lcd_attach(rB5, rB4, rB3, rB2, rB1, rB0);
	lcd_gotoxy(1, 1);
	lcd_printf((int8 *)"Modulo JAGA     ");

	//configura mecanismo de controle dos leds
	leds_attach(0, rF1);
	leds_attach(1, rF2);
	leds_set(LD1G, LED_OFF);
	leds_set(LD2G, LED_OFF);

}


