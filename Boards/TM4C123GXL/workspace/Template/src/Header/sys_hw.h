/**
 * @file    sys_hw.h
 * @brief   TODO
 * @author  Rafael Lopes
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 (beta)
 */

#ifndef SYS_HW_H
    #define SYS_HW_H

#include "app_mcu.h"
#include "app_info.h"

#include "sys_mcu.h"
#include "sys_timer.h"
#include "sys_i2c.h"
#include "sys_spi.h"
#include "sys_ad.h"
#include "sys_pwm.h"
#include "sys_uart.h"
#include "sys_gpio.h"

#include "lcd/lcd.h"
#include "leds/leds.h"
#include "buttons/buttons.h"


/** @brief Configura o Hardware segundo as especifica��es do projeto */
void init_drivers(void);

/** @brief Configuracao e inicializacao dos dispositivos externo que serao usados */
void init_devices(void);

#endif	/* SYS_HW_H */
