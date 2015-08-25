/**
  * @file    hal_pwm.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jul 6, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Codigo do Driver PWM para o microcontrolador PIC18f4550.
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

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "hal_pwm.h"

//------------------------------------------------------------------------------
// Private Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Variable Declaration			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions Source
//------------------------------------------------------------------------------

void pwmMCU_set_frequencia(float frequencia)
{
    float aux_PR2;    
    uint8 retry = 0;
    float aux_prescaler = 1.00;
    
    //Estes bits são os dois bits menos significativos do ciclo PWM 10 bits.
    CCP1CONbits.DC1B = 0;    
    CCPR1L = 0;
  
    T2CONbits.T2CKPS = PWM_TRM2_PRESCALE_1;//Prescaler, Obs: o pwm do pic nao usa o poscaler!!
    
    do
    {
        //calcula valor PR2 usando a frequencia desejada e valor do prescaler.
        aux_PR2 = (_XTAL_FREQ / (frequencia * 4.00 * aux_prescaler)) - 1.00;
        
        //verifia se o calculo nao gerou o estouro da variavel PR2
        if (aux_PR2 <= 255.00 && aux_PR2 >= 0.00) 
        {
             PR2 = (uint8)aux_PR2;
             break;
        }
        //tenta deixar o valor de PR2 calculo dentro do range alterando o Prescaler.
        else if(retry < 2)
        {
            T2CONbits.T2CKPS = 1<<retry; //Prescaler, Obs: o pwm do pic nao usa o poscaler!!
                    
            if(T2CONbits.T2CKPS == PWM_TRM2_PRESCALE_4)
            {
                aux_prescaler = 4.00;
            }
            else if(T2CONbits.T2CKPS >= PWM_TRM2_PRESCALE_16)
            {
                aux_prescaler = 16.00;
            }          
           
            retry++;
        }
        //A funcao nao conseguiu configurar o PWM para a frequencia desejada.
        else
        {
            PR2 = 0;
            break;
        }
        
    }while(retry <= 2);
}

void pwmMCU_setup_tmr(uint8 enable, float frequencia)
{
    //habilitar TIMER2 do pwm
    T2CONbits.TMR2ON = enable;
    pwmMCU_set_frequencia(frequencia);
}

void pwmMCU_setup_conf(uint8 func, uint8 ccp)
{
    //Bits de configuração de saída PWM Aprimorado
    CCP1CONbits.P1M = func;

    CCP1CONbits.CCP1M = ccp;
}

void pwmMCU_set_fduty(float duty)
{
    UWord aux_10bts;
    float aux_duty;
    uint16 np; //numero de passos

    //verifica se a porcentagem passada esta dentro do range
    if (duty <= 100.00 && duty >= 0.00)
    {
        //calcula o maximo de passos usando, limitado pela configuracao do PR2.
        np = (PR2 + 1) * 4;
        
        //Calculo para o valor de saida do duty cicle em porcentagem
        aux_duty = (np * duty) / 100.00;
        aux_10bts.value = (uint16) aux_duty;

        //passagem do duty cycle calculado aos registradores do Microcontrolador.
        //CPPR1L+<DC1B1:DC1B0>(10bits)
        CCP1CONbits.DC1B0 = aux_10bts.bit0;
        CCP1CONbits.DC1B1 = aux_10bts.bit1;
        aux_10bts.value >>= 2;
        CCPR1L = aux_10bts.value;
    }    
}


void pwmMCU_set_duty(uint8 duty)
{
    UWord aux_10bts;
    aux_10bts.b.b1 = duty;

    //passagem do duty cycle calculado aos registradores do Microcontrolador.
    //CPPR1L+<DC1B1:DC1B0>(10bits)
    CCP1CONbits.DC1B0 = aux_10bts.bit0;
    CCP1CONbits.DC1B1 = aux_10bts.bit1;
    aux_10bts.value >>= 2;
    CCPR1L = aux_10bts.value;    
}