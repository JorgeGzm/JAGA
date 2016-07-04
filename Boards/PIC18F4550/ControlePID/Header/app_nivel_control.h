/**
  * @file    app_control.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com);
  * @date    Jan 31, 2016
  * @version 0.1.0.0 (beta)
  * @brief   App que faz todo o controle de nivel do tanque d'agua usando PID.
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

#ifndef APP_NIVEL_CONTROL_H
    #define APP_NIVEL_CONTROL_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include "const/conts.h"

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

/** @brief Rotinas principais do sistemas */
PUBLIC void init_nivel_controle(void);

PUBLIC void run_nivel_control(void);

PUBLIC float get_nivel_tanque(void);

PUBLIC float get_nivel_dutyPWM(void);

#endif	/* APP_CONTROL_H */
