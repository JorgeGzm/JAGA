/**
  * @file    xtime.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Dez 11, 2015
  * @version 0.2.0.0 (beta)
  * @brief   TODO documentar
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

#include "xtime.h"
#include <string.h>

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

PUBLIC uint8_t decToBcd(uint8_t val)
{
    return ( (val/10*16) + (val%10) );
}

PUBLIC uint8_t bcdToDec(uint8_t val)
{
    return ( (val/16*10) + (val%16) );
}


PUBLIC uint8_t get_string_day(DataTime *day)
{
	switch(day->day)
	{
		case 1:
			strcpy(day->str_day, "Domingo");
			break;
		case 2:
			strcpy(day->str_day, "Segunda-Feira");
				break;
		case 3:
			strcpy(day->str_day, "Terca-Feira");
				break;
		case 4:
			strcpy(day->str_day, "Quarta-Feira");
				break;
		case 5:
			strcpy(day->str_day, "Quinta-Feira");
				break;
		case 6:
			strcpy(day->str_day, "Sexta-Feira");
				break;
		case 7:
			strcpy(day->str_day, "Sabado");
				break;
		default:
			strcpy(day->str_day, "    ");
			return -1;			
	}
	return 0;
}

//Timestamp timestamp_calc(DataTime data_time)
//{
//    Timestamp ST_TS;
//    uint16 UI16_ajuste = 0, i;
//
//    UQWord UN_big;
//    UQWord UN_big2;
//
//    DataHora aux_relogio;
//
//    aux_relogio.UI8_Dia = 0;
//    aux_relogio.UI8_Mes = 0;
//    aux_relogio.UI8_Ano = 0;
//    aux_relogio.UI8_Horas = 0;
//    aux_relogio.UI8_Minutos = 0;
//    aux_relogio.UI8_Segundos = 0;
//
//    int32 aux_dia;
//    int32 aux_mes = 0;
//    int32 aux_ano;
//    int32 aux_hora;
//    int32 aux_min;
//    int32 aux_seg;
//
//    UN_big.value = 0;
//
//    //Atualiza Relogio RTC
//
//    aux_relogio = data_time; //OK
//
//    //--Calcula Segundos da DATA--
//    aux_ano = ((aux_relogio.UI8_Ano + 2000) - 1970);
//
//    //verificar anos bissexto
//    for(i = 1970; i < (aux_relogio.UI8_Ano + 2000); i++)
//    {
//        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) //Adicionado mais formas de verifica��o
//        {
//            UI16_ajuste++;
//        }
//    }
//
//    //transforma quantidade de anos em dias
//    aux_dia = (aux_ano * 365) + UI16_ajuste;
//
//    for(i = 1; i < aux_relogio.UI8_Mes; i++)
//    {
//        switch(i)
//        {
//        case 1:
//        case 3:
//        case 5:
//        case 7:
//        case 8:
//        case 10:
//        case 12:
//            aux_mes += 31;
//            break;
//
//        case 4:
//        case 6:
//        case 9:
//        case 11:
//            aux_mes += 30;
//            break;
//
//        case 2:
//            if(((aux_relogio.UI8_Ano + 2000) % 4 == 0 && (aux_relogio.UI8_Ano + 2000) % 100 != 0) || (aux_relogio.UI8_Ano + 2000) % 400 == 0)
//            {
//                aux_mes += 29;
//            }
//            else
//            {
//                aux_mes += 28;
//            }
//            break;
//        }
//    }
//
//    aux_mes = aux_mes + (aux_relogio.UI8_Dia - 1);
//
//    aux_dia += aux_mes;
//
//    UN_big.dw.dw1 = (aux_dia * 86400); //Transforma data em segundos
//
//    //--Calcula Segundos do TEMPO--
//    aux_hora = ((long int)aux_relogio.UI8_Horas * 3600);
//
//    aux_min = ((long int)aux_relogio.UI8_Minutos * 60);
//
//    aux_seg = (aux_hora + aux_min + aux_relogio.UI8_Segundos);
//
//    UN_big.dw.dw1 += aux_seg;
//    UN_big.dw.dw2 = 0;
//
//    UN_big2.value = UN_big.value;
//
//    UN_big.value = UN_big2.value * 1000; //Transforma em milisegundos
//
//    ST_TS.UN_TS0.value = UN_big.w.w1;
//    ST_TS.UN_TS1.value = UN_big.w.w2;
//    ST_TS.UN_TS2.value = UN_big.w.w3;
//
//    return ST_TS;
//}

