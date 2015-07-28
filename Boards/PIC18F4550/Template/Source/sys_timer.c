/**
 * @file    sys_timer.c
 * @brief   TODO
 * @author  Rafael Lopes
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 (beta)
 */

#include "../Header/sys_timer.h"
#include "buttons/buttons.h"
#include "leds/leds.h"

/** Internal functions prototype*/
static void timer_counter(void);
inline static void counter_1_ms(void);
inline static void counter_10_ms(void);
inline static void counter_100_ms(void);
inline static void counter_1_s(void);

void init_timer0(void)
{
    //Inicializa TMR0
    timer_init_regs(_TMR0);

    //Configura TMR0 (1 ms)
    timer_setup_bits(_TMR0, TMR_BIT_16);
    timer_setup_scale(_TMR0, TMR_PRESCALE_ON, TMR0_PRESCALE_1_8, 0);
    timer_setup_clock(_TMR0, TMR_CLOCK_INT, TMR_LOW_TO_HIGH);
    timer_set_counter(_TMR0, 0xFA24);

    //Configura interrupcao TMR0
    timer_setup_interrupt(_TMR0, ENABLE);
    timer_priority_interrupt(_TMR0, HIGH_PRIORITY);
    timer_set_callbak(_TMR0, timer_counter);
    timer_start(_TMR0, TMR_ON);
}

/** Funcao callback da interrupcao do TMR0*/
static void timer_counter(void)
{
    // --- Temporizadores das bases de tempo 1ms, 10ms, 100ms, 1s ---
    //static uint8 tmr_1_ms = 1;
    static uint8 tmr_10_ms = 9;
    static uint8 tmr_100_ms = 99;
    static uint16 tmr_1_s = 999;

    //Recarrega contador do timer
    timer_set_counter(_TMR0, 0xFA24);

   //Contadores de 1 milisegundo
    counter_1_ms();

    if((tmr_10_ms--) == 0)
    {
        tmr_10_ms = 9;

        //Contadores de 1 milisegundo
        counter_10_ms();
    }

    if((tmr_100_ms--) == 0)
    {
        tmr_100_ms = 99;

        //Contadores de 1 milisegundo
        counter_100_ms();
    }

    if((tmr_1_s--) == 0)
    {
        tmr_1_s = 999;

        //Contadores de 1 milisegundo
        counter_1_s();
    }
}

/** Contadores de 1 milisegundo */
inline static void counter_1_ms(void)
{

}

/** Contadores de 10 milisegundos */
inline static void counter_10_ms(void)
{
    //Leitura das teclas
    buttons_read_isr_10ms();
}

/** Contadores de 100 milisegundos */
inline static void counter_100_ms(void)
{
    //varredura dos leds
    leds_action_isr_100ms();
}

/** Contadores de 1 segundo */
inline static void counter_1_s(void)
{

}
