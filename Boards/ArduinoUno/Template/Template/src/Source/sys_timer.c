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
   
}
