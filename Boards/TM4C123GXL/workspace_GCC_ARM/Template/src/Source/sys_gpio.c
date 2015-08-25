/**
  * @file    sys_gpio.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 16, 2015
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

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include <stdarg.h>
#include "../Header/sys_gpio.h"
#include "gpio/hal_gpio.h"
#include "device/hal_device.h"
#include "delay/hal_delay.h"

//------------------------------------------------------------------------------
// Private Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private structs, unions and enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Variable Declaration			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions Source
//------------------------------------------------------------------------------

void init_gpio(void)
{
	//Rotinas de inicializacao especiais

	/** Antiga funcao PortF_Init*/

	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
	Delay();
	Delay();
	delay = SYSCTL_RCGC2_R;           // allow time for clock to start
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
	GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
	// only PF0 needs to be unlocked, other bits can't be locked
	GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
	GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
	GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
	GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
	GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
	GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital I/O on PF4-0

	/** Antiga funcao PortC_Init*/
	SYSCTL_RCGC2_R |= 0x00000002;     // 1) activate clock for Port C
	Delay();
	Delay();
	GPIO_PORTB_CR_R = 0xFF;			  //pinos que serao usados
	GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog on PC
	GPIO_PORTB_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PC4-PC7
	GPIO_PORTB_DIR_R = 0xFF;          // 5) PC4-PC7 como saidas GPIO
	GPIO_PORTB_AFSEL_R = 0x00;        // 6) disable alt funct on PC4-PC7
	GPIO_PORTB_PUR_R = 0x00;          // Disable pull-up
	GPIO_PORTB_DEN_R = 0xFF;          // 7) enable digital I/O on PC4-PC7
}
