/**
  * @file    app_info.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 27, 2015
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
 
#ifndef APP_INFO_H
    #define APP_INFO_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "vars/vars.h"
#include "types/types.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

/** Versao do Firmware. Ex: versao 1.0.0*/
#define VERSION_FIRMWARE 100

/** Codigo de identificacao da linha do equipamento*/
#define ID_DEVICE 1

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

void info_init(void);

#endif	
