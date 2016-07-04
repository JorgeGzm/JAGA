/**
  * @file    RFID_Card.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Jun 13, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para o uso do mudulo de leitura do Cartao RFID
  * @details Configurar o baund RX em 9600, usar o pino D0 do shield para receber os dados.
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
//===============================================================================

#include "RFID_Card.h"
#include <string.h>

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

/** @brief Tamanho maximo do buffer que contem o ID do cartao */
#define MAX_BUFFER     10

/** @brief TODO documentar */
#define START_CARACTER 0x02

/** @brief TODO documentar */
#define END_CARACTER   0x03

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

typedef enum
{
    ST_START,
    ST_MSG,
    ST_END
}CARD_STATES;

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** @brief Buffer que sera preenchido com o valor recebido pela UART*/
uint8_t buffer_id[MAX_BUFFER]; //Vetor que contem o Dado Recebido pela Serial

/** @brief flag que indica quando um ID valido foi recebido pela UART*/
uint8_t ready = 0;

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

PUBLIC void rfid_card_isr_buff(uint8_t data)
{
	static int ind = 0;
	static CARD_STATES status = ST_START;

	switch (status)
	{

		case ST_START:
			if (data == START_CARACTER)
			{
				ind = 0;
				buffer_id[ind++] = data;
				status = ST_MSG;

			}
			break;

		case ST_MSG:
			buffer_id[ind++] = data;
			if (ind == MAX_BUFFER - 1)
			{
				status = ST_END;
			}
			break;

		case ST_END:
			if (data == END_CARACTER)
			{
				 buffer_id[ind++] = data;
				 ready = 1;
			}
			status = ST_START;
			break;
	}
}

PUBLIC VALIDATION rfid_card_validation(uint8_t buffID[])
{
	if(ready)
    {
  		ready = 0;

        //verifica se as string sao iguais
        if(!strcmp(buffer_id, buffID))
        {
            return VALIDATION_OK;
        }
        else
        {   //strings diferentes
            return VALIDATION_ERROR;
        }
    }
	
    return VALIDATION_NONE;
}

//Exemplo
//Pinos: D0-RX
//
//static uint8_t IDPadrao2[10] = {0x02, 0x31, 0x35, 0x39, 0x35, 0x31, 0x35, 0x30, 0x39, 0x03};
//
//switch(rfid_card_validation(IDPadrao2))
//{
//	case VALIDATION_OK:
//		leds_set(LD1G, LED_ON);
//		break;
//
//	case VALIDATION_ERROR:
//			leds_set(LD1G, LED_OFF);
//			break;
//
//}
