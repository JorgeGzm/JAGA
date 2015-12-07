/**
  * @file    hal_timer.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 12, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo do Driver Timer para o microcontrolador PIC18f4550.
  * @details
  * @section LICENSE
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License as
  * published by the Free Software Foundation; either version 2 of
  * the License, or (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful, but
  * WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  * General Public License for more details at
  * http://www.gnu.org/copyleft/gpl.html
*/

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "hal_timer.h"
#include "device/hal_device.h"
#include "interrupt/hal_interrupts.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** @brief TODO*/
static volatile uint16_t timer_counter[4] = {0,0,0,0};

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================
 
/** @brief TODO */
void (*tmr0_callback)(void);

/** @brief TODO */
void (*tmr1_callback)(void);

/** @brief TODO */
void (*tmr2_callback)(void);

/** @brief TODO */
void (*tmr3_callback)(void);
    
//==============================================================================
// SOURCE CODE
//==============================================================================

void timer_set_counter(uint8_t module, uint16_t val)
{
    UWord aux_value;
    
    aux_value.value = val;
    
    //timer_counter[module] = value;
    switch(module)
    {
        case _TMR0:
            TMR0H = aux_value.b.b2;
            TMR0L = aux_value.b.b1;
            return;

        case _TMR1:
            TMR1H = aux_value.b.b2;
            TMR1L = aux_value.b.b1;
            return;

        case _TMR2:
            TMR2 = aux_value.b.b1;
            return;

        case _TMR3:
            TMR3H = aux_value.b.b2;
            TMR3L = aux_value.b.b1;
            return;
    }
}

uint16_t timer_get_counter(uint8_t module)
{   
     UWord timer = {0};
    
    switch(module)
    {
        case _TMR0:
            timer.b.b1 = TMR0L; //somete a parte baixa e acessivel a parte alta acaba sendo l
            return(timer.value);

        case _TMR1:
            return(TMR1);

        case _TMR2:
            timer.b.b1 = TMR2;
            return(timer.value);

        case _TMR3:
            return(TMR3);
    }

    return(0);
}

void timer_init_regs(uint8_t module)
{
    switch(module)
    {
        case _TMR0:
            T0CONbits.TMR0ON = 0;   //b7: TMR0 desligado
            T0CONbits.T08BIT = 0;   //b6: TMR0 temporizador/contador 16bits
            T0CONbits.T0CS = 0;     //b5: TMR0 sera incrementado pelo ciclo de instrucao
            T0CONbits.T0SE = 0;     //b4: TMR0 sera incrementado na borda de subido(somente com clock externo T0CS =1)
            T0CONbits.PSA = 0;      //b3: TMR0 prescaler habilitado
            T0CONbits.T0PS2 = 0;    //[b2]: TMR0 prescaler -> 1:2
            T0CONbits.T0PS1 = 0;    //[b1]
            T0CONbits.T0PS0 = 0;    //[b0]
        break;

        case _TMR1:
            T1CONbits.TMR1ON = 0;   //b0: Desliga o contador do TMR1
            T1CONbits.RD16 = 1;     //b7: Habilita registrador de leitura/escrita do timer1 em uma operecao de 16 bits
            T1CONbits.T1RUN = 1;    //b6: Clock do sistema e derivado de outra fonte, não do oscilador do timer1
            T1CONbits.T1CKPS = 0;   //[b5-b4] -> TMR1 prescale 1:1
            T1CONbits.T1OSCEN = 0;  //b3: Oscilador do timer1 desabilitado
            T1CONbits.T1SYNC = 0;   //b2: Nao sincroniza o TMR1 com a entrada de clock externo
            T1CONbits.TMR1CS = 0;   //b1: TMR1 incrementado pelo clock interno (FOSC/4)
        break;

        case _TMR2:
            T2CONbits.TMR2ON = 0;   //b2: desliga o contador TMR2
            T2CONbits.T2CKPS = 0;   //[b0-b1]: TMR2 prescale 1:1
            T2CONbits.TOUTPS = 0;   //[b3-b6]: TMR2 postscale 1:1
        break;

        case _TMR3:
            T3CONbits.TMR3ON = 0;   //b0: desliga o contador TMR3
            T3CONbits.TMR3CS = 0;   //b1: internal clock
            T3CONbits.T3SYNC = 0;   //b2: sincroniza a entrada do clock externo
            T3CONbits.T3CKPS = 0;   //[b4-b5]: prescale 1:1
            T3CONbits.T3CCP1 = 0;   //[b3,b6]: timer1 is the capture/compare clock source
            T3CONbits.T3CCP2 = 0;
            T3CONbits.RD16 = 1;     //b7: Habilita registrador de leitura/escrita do timer3 em uma operecao de 16 bits
        break;
    }
}

void timer_setup_clock(uint8_t module, uint8_t source, uint8_t transition)
{
    switch(module)
    {
        case _TMR0:
            T0CONbits.T0CS = source;        //Clock source
            T0CONbits.T0SE = transition;    //Transition on pin to increment
        break;

        case _TMR1:
            T1CONbits.TMR1CS = source;     //Clock source
        break;

        case _TMR2:
        break;

        case _TMR3:
        break;
    }
}

void timer_setup_scale(uint8_t module, uint8_t on_off, uint8_t prescale, uint8_t postscale)
{
    switch(module)
    {
        case _TMR0:
            T0CONbits.T0PS = prescale;
            T0CONbits.PSA = on_off;
        break;

        case _TMR1:
            if(on_off == TMR_PRESCALE_OFF)
            {
                T1CONbits.T1CKPS = TMR1_PRESCALE_1_1;
            }
            else
            {
                T1CONbits.T1CKPS = prescale;
            }
        break;

        case _TMR2:
            T2CONbits.T2CKPS = prescale;

            T2CONbits.T2OUTPS0 = postscale & 0x01;
            T2CONbits.T2OUTPS1 = postscale & 0x02;
            T2CONbits.T2OUTPS2 = postscale & 0x04;
            T2CONbits.T2OUTPS3 = postscale & 0x08;
        break;

        case _TMR3:
            if(on_off == TMR_PRESCALE_OFF)
            {
                T3CONbits.T3CKPS = TMR3_PRESCALE_1_1;
            }
            else
            {
                T3CONbits.T3CKPS = prescale;
            }
        break;
    }
}

void timer_setup_bits(uint8_t module, uint8_t bits)
{
    //TMR0 = 1 - 8 bits
    //TMR1 = 1 - 16 bits
    //TMR3 = 1 - 16 bits
    switch(module)
    {
        case _TMR0:
            T0CONbits.T08BIT = bits; //(!bits) & 0x01; aki
        break;

        case _TMR1:
            T1CONbits.RD16 = bits;
        break;

        case _TMR2:
            //NA
        break;

        case _TMR3:
            T3CONbits.RD16 = bits;
        break;
    }
}

void timer_start(uint8_t module, uint8_t value)
{
    switch(module)
    {
        case _TMR0:
            T0CONbits.TMR0ON = value;
        break;

        case _TMR1:
            T1CONbits.TMR1ON = value;
        break;

        case _TMR2:
            T2CONbits.TMR2ON = value;
        break;

        case _TMR3:
            T3CONbits.TMR3ON = value;
        break;
    }
}

void timer_setup_interrupt(uint8_t module, uint8_t value)
{
    switch(module)
    {
        case _TMR0:
            INTCONbits.TMR0IF = 0;
            INTCONbits.TMR0IE = value;
        break;

        case _TMR1:
            PIR1bits.TMR1IF = 0;
            PIE1bits.TMR1IE = value;
        break;

        case _TMR2:
            PIR1bits.TMR2IF = 0;
            PIE1bits.TMR2IE = value;
        break;

        case _TMR3:
            PIR2bits.TMR3IF = 0;
            PIE2bits.TMR3IE = value;
        break;
    }

    //interrupt_setup(module, value);
}

void timer_priority_interrupt(uint8_t module, uint8_t value)
{
    switch(module)
    {
        case _TMR0:
            INTCON2bits.TMR0IP = value;
        break;

        case _TMR1:
            IPR1bits.TMR1IP = value;
        break;

        case _TMR2:
            IPR1bits.TMR2IP = value;
        break;

        case _TMR3:
            IPR2bits.TMR3IP = value;
        break;
    }

  //  interrupt_set_priority(module, value);
}

void timer_set_callbak(uint8_t module, void (*func)(void))
{
    switch(module)
    {
        case _TMR0:
            tmr0_callback = func;
        break;

        case _TMR1:
            tmr1_callback = func;
        break;

        case _TMR2:
            tmr2_callback = func;
        break;

        case _TMR3:
            tmr3_callback = func;
        break;
    }
}

inline void timer0_isr(void)
{
    if(INTCONbits.TMR0IF)
    {
        
        tmr0_callback();
        
        //Limpa flag da interrupcao
        INTCONbits.TMR0IF = 0;
    }
}

inline void timer1_isr(void)
{
    if(PIR1bits.TMR1IF)
    {
        tmr1_callback();
        
        //Limpa flag da interrupcao
        PIR1bits.TMR1IF = 0;
    }
}

inline void timer2_isr(void)
{
    if(PIR1bits.TMR2IF)
    {
        tmr2_callback();
        
        //Limpa flag da interrupcao
        PIR1bits.TMR2IF = 0;
    }
}

inline void timer3_isr(void)
{
    if(PIR2bits.TMR3IF)
    {
        tmr3_callback();
        
        //Limpa flag da interrupcao
        PIR2bits.TMR3IF = 0;
    }
}
