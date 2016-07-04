/**
  * @file    log.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Dez 26, 2015
  * @version 0.2.0.0 (beta)
  * @brief   Bibliteoca para o registro de acontecimentos(log)
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

#ifndef XLOG_H_
#define XLOG_H_

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "types/types.h"

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================


//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

void save_pointer(uint16_t addr_page);
void load_pointer(void);
void wr_ext_e2p(uint16_t addr, uint16_t data);
uint16_t rd_ext_e2p(uint16_t addr);

#endif
