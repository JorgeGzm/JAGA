/**
 * @file:   vars.h
 * @author: Jorge Guzman
 * @date  24 de Janeiro de 2015
 * @version 1.0
 * @brief definicao de todos os tipos de dados usados pelo Compilador XC8
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

#ifndef VARS_H
#define	VARS_H

/** Descricao:  */

/** Range(-128 a 127) */
typedef char                    int8;   

/** Range(0 a 255)*/
typedef unsigned char           uint8; 

/** Range(-32.768 a 32.767)*/
typedef short                     int16;  

/** Range(0 a 65.535)*/
typedef unsigned short            uint16; 

/** -8.388.608 a 8.388.607*/
//typedef short long              int24;   

/** 0 a 16.777.215*/
//typedef unsigned short long     uint24; 

/** Range(-2.147.438.648 a 2.147.438.647)*/
typedef long                    int32;  

/** Range(0 a 4.294.967.295)*/
typedef unsigned long           uint32;

/** Range() ? incompleto*/
typedef double long             int64;  

/** Range() ? incompleto*/
typedef unsigned long long      uint64; 

//typedef float                 float32 // float32:  32 bits. Range(1.17549435 e-38 to 6.80564693 e+38)  ? incompleto
//typedef double                double32// double32:  32 bits. Range(1.17549435 e-38 to 6.80564693 e+38)  ? incompleto


#endif	/* VARS_H */
