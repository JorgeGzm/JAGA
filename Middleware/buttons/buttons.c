/**
 * @file    buttons.c
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    27 de Fevereiro de 2015
 * @version 0.1.0.0 
 * @brief   Codigo em C da biblioteca lib_buttons.c
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
 *
 * @section DESCRIPTION
 */

#include "buttons.h"
#include "app_control.h"

#ifndef configButton_pullUP
    #error "configButton_pullUP no defined in app_control.h"
#endif

/** Variavel que recebe a atualizacao do estado das teclas a cada 10ms*/
static volatile Buttons buttons;        

/** Variavel que informa quais teclas foram pressionadas. */
static volatile Buttons buttons_read;   

/** Vetor que informa quais pinos do microcontrolador sao usados para cada tecla.*/
regPin buttons_vector[BUTTON_SIZE];


void buttons_init(void)
{
    uint8 i;
    
    for(i=0; i<sizeof(BUTTON_SIZE); i++)
    {
        buttons_vector[i].out = 0;
        buttons_vector[i].pin = 0;
    }
}

void button_attach(uint8 index, regGPIO *reg)
{
    //indica o pino do microcontrolador que sera usado para o botao
    GPIO_pin_attach(&buttons_vector[index], reg);

    //Configura pino do microcontrolador como entrada
    GPIO_confDir(reg, DIR_INPUT);
}

void buttons_read_isr_10ms(void)
{
    uint8 i;

    buttons_read.b.b1 = 0;
    
    //Leitura instantanea das teclas
    for(i = 0; i < 8; i++)
    {
        if(buttons_vector[i].out && (configButton_pullUP^GPIO_pin_state(&buttons_vector[i])) )
        {
            buttons_read.b.b1 |=  (1 << i);
        }
    }

    //Verfica se alguma tecla esta pressionada
    if(buttons_read.b.b1)
    {
        if(buttons_read.hold && !buttons_read.press)
        {
            //Espera o tempo de debounce acabar para saber se a tecla foi realmente precionada
            if(buttons_read.debounce)
            {
                buttons_read.debounce--;
            }
            
            //Debouce quando a tecla e prescionada
            else
            {
                buttons_read.hold = 0;
                buttons_read.press = 1;

                //Armazena qual tecla foi precionada
                buttons.value = buttons_read.value; //aki

                buttons_read.debounce = BOUNCE;
            }
        }
    }
    else
    {
        if(buttons_read.debounce && !buttons_read.hold)
        {
            //decremtenta tempo de debaunce
            buttons_read.debounce--;
        }        
        else //Debouce quando a tecla e solta
        {
            buttons_read.hold = 1;

            buttons.value = 0; //aki

            //UI8_debounce = BOUNCE;
            buttons_read.debounce = BOUNCE;
        }
    }
}

uint8 buttons_check_press(uint8 button_id, uint8 press)
{
    if(!press)
    {
        if(buttons_read.b.b1 == button_id)
        {
            //limpa flag do botao
            buttons_read.b.b1 ^= (buttons_read.b.b1&button_id);
            
            //limpa flag que sinaliza que o botao foi prescionado.
            buttons_read.press = 0;

            //retorna botao pressionado
            return 1;
        }
        else
        {
            //retorna botao nao pressionado
            return 0;
        }
    }
    else
    {
        if((buttons_read.b.b1 == button_id) && buttons_read.press)
        {
            //limpa flag do botao
            buttons_read.b.b1 ^= (buttons_read.b.b1&button_id);
            
            //limpa flag que sinaliza que o botao foi prescionado.
            buttons_read.press = 0;

            //retorna botao pressionado
            return 1;
        }
        else
        {
            //retorna botao nao pressionado
            return 0;
        }
    }
}

uint8 button_is_press(uint8 button_id)
{
    if(tst_bit(buttons.b.b1, button_id))
    {
        return(buttons.press);
    }

    return(0);
}

uint8 button_is_hold(uint8 button_id)
{
    if(tst_bit(buttons.b.b1, button_id))
    {
        return(buttons.hold);
    }

    return(0);
}
