/**
  * @file    vars.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jan 24, 2015
  * @version 0.1.0.0 (beta)
  * @brief   definicao de todos os tipos de variaveis usadas nas libs.
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

#ifndef VARS_H
	#define	VARS_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

/** @brief Range(-128 a 127) */
typedef char                    int8;   

/** @brief Range(0 a 255) */
typedef unsigned char           uint8; 

/** Range(-32.768 a 32. )*/
typedef short                   int16;  

/** @brief Range(0 a 65.535) */
typedef unsigned short          uint16; 

/** @brief Range(-2.147.438.648 a 2.147.438.647) */
typedef long                    int32;  

/** @brief Range(0 a 4.294.967.295) */
typedef unsigned long           uint32;

/** @brief Range() ? incompleto */
typedef double long             int64;  

/** @brief Range() ? incompleto */
typedef unsigned long long      uint64; 

//typedef float                 float32 // float32:  32 bits. Range(1.17549435 e-38 to 6.80564693 e+38)  ? incompleto
//typedef double                double32// double32:  32 bits. Range(1.17549435 e-38 to 6.80564693 e+38)  ? incompleto

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

#endif	
