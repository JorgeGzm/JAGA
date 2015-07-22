/**
 * @file    sys_mcu.h
 * @brief   configura fuses dos microcontrolador, TODO: nao esta generico para o arm, este arquivo so foi criado para usar o _XTAL_FREQ na funcao Delay_ms e Delay_us
 * @author  Rafael Lopes
 * @date    24 de Junho de 2015
 * @version 0.1.0.0 (beta)
 */

#ifndef SYS_MCU_H
    #define SYS_MCU_H

#define F_CPU 16000000UL

/** @brief TODO*/
void init_mcu(void);
 
#endif	/* SYS_MCU_H */
