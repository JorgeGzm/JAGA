/**
  * @file    buttons.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 27, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo em C da biblioteca buttons.c
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

#include "buttons.h"
#include "config_buttons.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

#ifndef BUTTON_PRESSED_STATE
#error "BUTTON_PRESSED_STATE no defined in config_buttons.h"
#endif

#ifndef BOUNCE
#error "BOUNCE no defined in config_buttons.h"
#endif

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

/** @brief Estrutura usada no controle do estado das teclas. */
typedef union 
{
    /** @brief Varivel de 16bits usada no controle geral das teclas. */
    uint16_t value;

    /** @brief Estrutura que quebra a variavel de "value" de 16 bits em 2 de 8bits. */
    struct
    {
         /** @brief Parte baixa que contem estados das teclas*/
        uint8_t status;

         /** @brief Parte alta que contem temporizador do debouce e se alguma tecla esta ou continua pressioada. */
        uint8_t control;
    }b;

    /** @brief Estrutura que quebra a variavel "value" de 16bits para acesso bit a bit. */
    struct
    {
        /** @brief Bit para controle de estado do botao 1. */
        unsigned button_1   : 1;
        
        /** @brief Bit para controle de estado do botao 2. */
        unsigned button_2   : 1;
        
        /** @brief Bit para controle de estado do botao 3. */
        unsigned button_3   : 1;
        
        /** @brief Bit para controle de estado do botao 4. */
        unsigned button_4   : 1;
        
        /** @brief Bit para controle de estado do botao 5. */
        unsigned button_5   : 1;
        
        /** @brief Bit para controle de estado do botao 6. */
        unsigned button_6   : 1;
        
        /** @brief Bit para controle de estado do botao 7. */
        unsigned button_7   : 1;
        
        /** @brief Bit para controle de estado do botao 8. */
        unsigned button_8   : 1;
        
        /** @brief Bit para indica se alguma tecla foi pressionada. */
        unsigned press      : 1; 
        
        /** @brief Bit para indicar se a tecla continua pressionada. */
        unsigned hold       : 1; 
        
        /** @brief Bit nao usado. */
        unsigned            : 1;
        
        /** @brief Bit nao usado. */
        unsigned            : 1;

        /** @brief Nibble usado como temporizador para elimidar o ruido(debounce) ao pressionar a tecla. */
        unsigned debounce   : 4;
    };
}Buttons;

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** @brief Variavel que recebe a atualizacao do estado das teclas a cada 10ms*/
static volatile Buttons buttons;

/** @brief Variavel que informa quais teclas foram pressionadas. */
static volatile Buttons buttons_instant_read;

/** @brief Vetor que informa quais pinos do microcontrolador sao usados para cada tecla.*/
regPin buttons_pin[BUTTON_SIZE];

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

void buttons_init(void)
{
    uint8_t i;

    for (i = 0; i<sizeof (BUTTON_SIZE); i++)
    {
        buttons_pin[i].out = 0;
        buttons_pin[i].pin = 0;
    }
}

void button_attach(uint8_t index, regGPIO reg)
{
    //Indica o pino do microcontrolador que sera usado para o botao
    GPIO_regPin_attach(&buttons_pin[index], &reg);

    //Configura pino do microcontrolador como entrada
    GPIO_regPin_setDir(&reg, DIR_INPUT);
}

void buttons_read_isr_10ms(void) 
{
    uint8_t i;

    buttons_instant_read.b.status = 0;

    //Leitura instantanea das teclas
    for (i = 0; i < BUTTON_SIZE; i++)
    {
        //Le o botao se tiver algum pino atribuido
        if (buttons_pin[i].out)
        {
            //Verifica se o botao esta pressionado
            if(GPIO_regPin_inputBit(&buttons_pin[i]) == BUTTON_PRESSED_STATE) 
            {
                buttons_instant_read.b.status |= (1 << i);
            }
        }
    }
    
    if(buttons_instant_read.b.status != buttons.b.status)
    {
         //Espera o tempo de debounce acabar para saber se a tecla foi realmente precionada
        if (buttons_instant_read.debounce) 
        {
            buttons_instant_read.debounce--;
        }
        else
        {   
            buttons.b.status = buttons_instant_read.b.status;
            buttons_instant_read.debounce = BOUNCE;      
        }
    }
    else if(!buttons.b.status)
    {
    	buttons.hold = 0;
    }
}

uint8_t buttons_check_press(BUTTON_NAME button_mask, BUTTON_CHECK_TYPE press)
{
    if (press == BTN_PULSE) 
    {
        if (buttons.b.status == button_mask) 
        {
            //limpa flag do botao
            buttons.b.status ^= (buttons.b.status & button_mask);

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
        if ((buttons.b.status == button_mask) && !buttons.hold) 
        {
            buttons.hold = 1;

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
