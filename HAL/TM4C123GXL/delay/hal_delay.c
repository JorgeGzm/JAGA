
/**
 * @file    hal_delay.c
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    29 de Janeiro de 2014
 * @version 0.1.0.0 
 * @brief   Codigo do Driver Delay para o microcontrolador TM4C123GXL.
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

#include "hal_delay.h"


void Delay(void)
{
	unsigned long volatile time;
  time = 1598;
	//145448;  // 0.1sec
  while(time)
	{
		time--;
  }
}

void Delay_10ms(void)
{
	unsigned long volatile time;
  time = 15982;
  while(time)
	{
		time--;
  }
}






void Delay_us(uint16 delay)
{
	uint16 i;
	uint16 volatile time;
  time = 1;  // 1us
	for(i = 0; i< delay; i++)
	{
		time = 1;  // 0.1sec
		while(time)
		{
			time--;
		}
	}
}





void Delay_ms(uint16 delay)
{
	uint16 i;
	uint16 volatile time;
  time = 1598;  // 1ms
	for(i = 0; i< delay; i++)
	{
		time = 1598;  // 0.1sec
		while(time)
		{
			time--;
		}
	}
}










