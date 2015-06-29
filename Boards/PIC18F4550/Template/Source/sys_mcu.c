/**
 * @file    sys_mcu.h
 * @brief   configura fuses dos microcontrolador, TODO: nao esta generico para o arm, este arquivo so foi criado para usar o _XTAL_FREQ na funcao Delay_ms e Delay_us
 * @author  Rafael Lopes
 * @date    24 de Junho de 2015
 * @version 0.1.0.0 (beta)
 */

#include "../Header/sys_mcu.h"
#include "device/hal_device.h"

 void init_mcu(void)
 {
    //Inicializacao de todas as interrupcoes utilizadas no sistema. TODO abstrair
    RCONbits.IPEN = 1; //b7:(1) habilita niveis de interrupcao
    INTCONbits.GIEH = 1; //b7:(1) hablita interrupcoes de alta prioridade
    INTCONbits.GIEL = 1;    //b6:(1) habilita interrupcoes de baixa prioridade
 }
