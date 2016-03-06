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

#ifndef XTIME_H
	#define	XTIME_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

typedef struct 
{
    uint8_t day;
    uint8_t date;
    uint8_t month;
    uint8_t yearChar;
    uint16_t yearInt;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t str_day[16];
}DataTime; 

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

/**
 * @brief Converte um valor decimal para o formato BCD
 * @param val Valor decimal a ser convertido para BCD
 * @return Valor no formato BCD
 */
uint8_t decToBcd(uint8_t val);

/**
 * @brief Configura o módulo MSSP 1 para I2c
 * @param val Valor BCD a ser convertido para decimal
 * @return Valor no formato decimal
 */
uint8_t bcdToDec(uint8_t val);

/**
 * @brief Recupera string do dia da semana.
 * @param day
 * @return erro
 */
uint8_t get_string_day(DataTime *day);

/**
 *
 * @param Relogio
 * @return Retorna o Time Stamp calculado usando o Data Time passado.
 */
//Timestamp timestamp_calc(DataTime data_time);

#endif	/* PRINT_H */

