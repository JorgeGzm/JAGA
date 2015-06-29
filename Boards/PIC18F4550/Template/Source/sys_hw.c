/**
 * @file    sys_hw.c
 * @brief   TODO
 * @author  Rafael Lopes
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 (beta)
 */

#include "../Header/sys_hw.h"

void setupHardware(void)
{
    //inicializa as configuraçoes do micrococontrolador
    init_mcu();

    //Inicializa driver das interrupcoes
    interrupt_init();

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
    buttons_init();
    button_attach(TECLA_UP, &rE1);
    button_attach(TECLA_DOWN, &rB2);

    //Configura e inicializa pinos que serao usados pela biblioteca LCD.
    lcd_attach(&display.RS, &rD0);
    lcd_attach(&display.E, &rD1);
    lcd_attach(&display.db4, &rD4);
    lcd_attach(&display.db5, &rD5);
    lcd_attach(&display.db6, &rD6);
    lcd_attach(&display.db7, &rD7);
    lcd_init();

    lcd_gotoxy(1, 1);
    lcd_printf((int8 *)"Modulo JAGA     ");

    //configura mecanismo de controle dos leds
    leds_attach(&leds[0], &rA1);
    leds_attach(&leds[1], &rA2);
    leds_set(LD1G, LED_OFF);
    leds_set(LD2G, LED_OFF);
}


