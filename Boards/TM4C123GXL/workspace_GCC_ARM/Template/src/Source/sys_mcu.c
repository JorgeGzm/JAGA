/**
  * @file    sys_mcu.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 24, 2015
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

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "sys_mcu.h"
#include "device/hal_device.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

//==============================================================================
// SOURCE CODE
//==============================================================================

 void init_mcu(void)
 {

	 ///init PLL to 80Mhz
	 // 0) Use RCC2
	 SYSCTL_RCC2_R |=  0x80000000;  // USERCC2
	 // 1) bypass PLL while initializing
	 SYSCTL_RCC2_R |=  0x00000800;  // BYPASS2, PLL bypass
	 // 2) select the crystal value and oscillator source
	 SYSCTL_RCC_R = (SYSCTL_RCC_R &~0x000007C0)   // clear XTAL field, bits 10-6
	 	                				 + 0x00000540;   // 10101, configure for 16 MHz crystal
	 SYSCTL_RCC2_R &= ~0x00000070;  // configure for main oscillator source
	 // 3) activate PLL by clearing PWRDN
	 SYSCTL_RCC2_R &= ~0x00002000;
	 // 4) set the desired system divider
	 SYSCTL_RCC2_R |= 0x40000000;   // use 400 MHz PLL
	 SYSCTL_RCC2_R = (SYSCTL_RCC2_R&~ 0x1FC00000)  // clear system clock divider
	 	                				  + (4<<22);      // configure for 80 MHz clock
	 // 5) wait for the PLL to lock by polling PLLLRIS
	 while((SYSCTL_RIS_R&0x00000040)==0){};  // wait for PLLRIS bit
	 // 6) enable use of PLL by clearing BYPASS
	 SYSCTL_RCC2_R &= ~0x00000800;

 }
