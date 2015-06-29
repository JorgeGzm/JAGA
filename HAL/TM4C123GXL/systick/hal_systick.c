/**
 * @file   	hal_systick.c
 * @brief   TODO LM4C123GXL.
 * @details TODO
 * @author 	Jorge Guzman (jorge.gzm@gmail.com)
 * @date 	29 de Abril de 2015
 * @version 0.1.0.0 (beta) 
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
 
#include "hal_systick.h"


void systick_set_reload(uint32 enable_systick, uint32 enable_interrupt, uint32 reload)
{
	GPIO_outputBit(&NVIC_ST_CTRL_R, 0, enable_systick);
	GPIO_outputBit(&NVIC_ST_CTRL_R, 1, enable_interrupt);
	NVIC_ST_RELOAD_R = reload;
}


void systick_set_clock(uint32 clock)
{
	NVIC_ST_CTRL_R = clock;
}
