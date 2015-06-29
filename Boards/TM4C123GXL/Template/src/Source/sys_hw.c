/**
 * @file    sys_hw.c
 * @brief   TODO
 * @author  Rafael Lopes
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 (beta)
 */

#include "../Header/sys_hw.h"

void init_drivers(void)
{

    //Inicializa driver das interrupcoes
    //interrupt_init();

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
}

void init_devices(void)
{
	//inicializa informaçoes do equipamento.
	info_init();

	//Inicializa e configura mecanismo de controle das teclas
	buttons_init();
	button_attach(TECLA_UP, &rF0);
	button_attach(TECLA_DOWN, &rF4);

	//Configura e inicializa pinos que serao usados pela biblioteca LCD.
	lcd_attach(&display.RS, &rB5);
	lcd_attach(&display.E, &rB4);
	lcd_attach(&display.db4, &rB3);
	lcd_attach(&display.db5, &rB2);
	lcd_attach(&display.db6, &rB1);
	lcd_attach(&display.db7, &rB0);
	lcd_init();

	lcd_gotoxy(1, 1);
	lcd_printf((int8 *)"Modulo JAGA     ");

	//configura mecanismo de controle dos leds
	leds_attach(&leds[0], &rF1);
	leds_attach(&leds[1], &rF2);
	leds_set(LD1G, LED_OFF);
	leds_set(LD2G, LED_OFF);

}


