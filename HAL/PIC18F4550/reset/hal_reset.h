/**
 * @file    hal_reset.h
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    4 de Abril de 2015
 * @version 0.1.0.0 
 * @brief   Driver de Reset para o microcontrolador PIC18f4550.
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
#ifndef HAL_RESET_H
#define	HAL_RESET_H


//Includes
#include "device/hal_device.h"
#include "types/types.h"

void resetMCU(void);
void resetMCU_device(uint16 senha_p1, uint16 senha_p2);

#endif	/* HAL_RESET_H */

