/**
  * @file    info_hw.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 10, 2015
  * @version 0.1.0.0 (beta)
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

#ifndef INFO_HW_H
    #define INFO_HW_H

#include <stdint.h>
#include "types/types.h"

/**
 *  Extern Functions
 */
void set_num_serie(uint16_t num_serie_h, uint16_t num_serie_l);
void set_release(uint16_t _release);
void set_version(uint16_t _version);
void set_id_device(uint16_t _id);
void set_pwd_device(uint8_t celula);
uint16_t get_pwd_device(void);
void set_data_active(uint16_t high, uint16_t middle, uint16_t low);
//Timestamp get_data_active(void);

//Variaveis externas
#endif	
