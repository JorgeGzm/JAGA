/**
 * @file    sys_hw.c
 * @brief   TODO
 * @author  Rafael Lopes
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 (beta)
 */

#include "../Header/sys_hw.h"
#include "gpio/hal_gpio.h"

void setupHardware(void)
{
    //inicializa as configuraçoes do micrococontrolador
    init_mcu();

    //Inicializa driver das interrupcoes
    //interrupt_init();

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

void setupDevices(void)
{
    //inicializa informaçoes do equipamento.
    info_init();

    //Inicializa e configura mecanismo de controle das teclas
    //buttons_init();
    //button_attach(1, rC0);
    //button_attach(2, rB2);

    //Configura e inicializa pinos que serao usados pela biblioteca LCD.
    lcd_attach(rB0, rB1, rD4, rD5, rD6, rD7);
    lcd_gotoxy(1, 1);
    int8 buff[] = {"Modulo JAGA     "};
    lcd_printf(&buff);
    
    //configura mecanismo de controle dos leds
	leds_init();
    leds_attach(0, rB5);
    leds_set(LD1G, LED_BLINK_FAST);  
}


