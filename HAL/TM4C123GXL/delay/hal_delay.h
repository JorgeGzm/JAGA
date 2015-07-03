/**
 * @file    hal_delay.h
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    29 de Janeiro de 2014
 * @version 0.1.0.0 
 * @brief   Driver de Delay para o microcontrolador TM4C123GXL.
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

#ifndef HAL_DELAY_H
    #define HAL_DELAY_H

#include "device/hal_device.h"
#include "types/types.h"

/**
 * @brief TODO
 */
void Delay(void);

/**
 * @brief TODO
 */
void Delay_10ms(void);

/**
 * @brief Gera um delay de micro-segundo.
 * @param delay TODO
 */
void Delay_us(uint16 delay);

/**
 * @brief Gera um delay de micro-segundo.
 * @param delay TODO
 */
void Delay_ms(uint16 delay);

// /**
// * @brief TODO
// */
//#define Delay_ms(x) __delay_ms(x)











#endif	/* HAL_DELAY_H */
