/**
  * @file    types.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 13, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Bibliteoca para de variaveis especiais.
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

#ifndef TYPES_H
	#define	TYPES_H

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stdint.h>

//==============================================================================
// PUBLIC DEFINITIONS
//==============================================================================

//==============================================================================
// PUBLIC TYPEDEFS
//==============================================================================

/** @brief Estrutura para acessar bits individuais de um byte */
#ifdef UINT8_MAX
typedef union 
{
    uint8_t value;

    struct
    {
        unsigned bit0   :1;
        unsigned bit1   :1;
        unsigned bit2   :1;
        unsigned bit3   :1;
        unsigned bit4   :1;
        unsigned bit5   :1;
        unsigned bit6   :1;
        unsigned bit7   :1;
    };
}UByte;
#endif

/** @brief TODO*/
#ifdef INT8_MAX
typedef union 
{
    int8_t value;

    struct
    {
        unsigned bit0   :1;
        unsigned bit1   :1;
        unsigned bit2   :1;
        unsigned bit3   :1;
        unsigned bit4   :1;
        unsigned bit5   :1;
        unsigned bit6   :1;
        unsigned bit7   :1;
    };
}Byte;
#endif

/** @brief Estrutura de 16 bits que pode ser quebrada em bytes ou bits */
#ifdef UINT16_MAX
typedef union 
{
    uint16_t value;

    struct
    {
        uint8_t b1;
        uint8_t b2;
    }b;

    struct
    {
        unsigned bit0   : 1;
        unsigned bit1   : 1;
        unsigned bit2   : 1;
        unsigned bit3   : 1;
        unsigned bit4   : 1;
        unsigned bit5   : 1;
        unsigned bit6   : 1;
        unsigned bit7   : 1;

        unsigned bit8   : 1;
        unsigned bit9   : 1;
        unsigned bit10  : 1;
        unsigned bit11  : 1;
        unsigned bit12  : 1;
        unsigned bit13  : 1;
        unsigned bit14  : 1;
        unsigned bit15  : 1;
    };
}UWord;
#endif

/** @brief TODO*/
#ifdef UINT32_MAX
typedef union 
{
    uint32_t value;

    struct
    {
        uint8_t b1;
        uint8_t b2;
        uint8_t b3;
        uint8_t b4;
    }b;
    
    struct
    {
        uint16_t w1;
        uint16_t w2;
    }w;

    struct
    {
        unsigned bit0   : 1;
        unsigned bit1   : 1;
        unsigned bit2   : 1;
        unsigned bit3   : 1;
        unsigned bit4   : 1;
        unsigned bit5   : 1;
        unsigned bit6   : 1;
        unsigned bit7   : 1;

        unsigned bit8   : 1;
        unsigned bit9   : 1;
        unsigned bit10  : 1;
        unsigned bit11  : 1;
        unsigned bit12  : 1;
        unsigned bit13  : 1;
        unsigned bit14  : 1;
        unsigned bit15  : 1;
        
        unsigned bit16  : 1;
        unsigned bit17  : 1;
        unsigned bit18  : 1;
        unsigned bit19  : 1;
        unsigned bit20  : 1;
        unsigned bit21  : 1;
        unsigned bit22  : 1;
        unsigned bit23  : 1;

        unsigned bit24  : 1;
        unsigned bit25  : 1;
        unsigned bit26  : 1;
        unsigned bit27  : 1;
        unsigned bit28  : 1;
        unsigned bit29  : 1;
        unsigned bit30  : 1;
        unsigned bit31  : 1;
    };
}UDWord;
#endif

/** @brief Estrutura para manipular variaveis grandes */
#ifdef UINT64_MAX
typedef union 
{
    uint64_t value;
    
    struct
    {
        uint8_t b1;
        uint8_t b2;
        uint8_t b3;
        uint8_t b4;
        uint8_t b5;
        uint8_t b6;
        uint8_t b7;
        uint8_t b8;
    }b;
    
    struct
    {
        uint16_t w1;
        uint16_t w2;
        uint16_t w3;
        uint16_t w4;
    } w;
    
    struct
    {
        uint32_t dw1;
        uint32_t dw2;
    } dw;
    
    struct
    {
        unsigned bit0   : 1;
        unsigned bit1   : 1;
        unsigned bit2   : 1;
        unsigned bit3   : 1;
        unsigned bit4   : 1;
        unsigned bit5   : 1;
        unsigned bit6   : 1;
        unsigned bit7   : 1;

        unsigned bit8   : 1;
        unsigned bit9   : 1;
        unsigned bit10  : 1;
        unsigned bit11  : 1;
        unsigned bit12  : 1;
        unsigned bit13  : 1;
        unsigned bit14  : 1;
        unsigned bit15  : 1;
        
        unsigned bit16  : 1;
        unsigned bit17  : 1;
        unsigned bit18  : 1;
        unsigned bit19  : 1;
        unsigned bit20  : 1;
        unsigned bit21  : 1;
        unsigned bit22  : 1;
        unsigned bit23  : 1;

        unsigned bit24  : 1;
        unsigned bit25  : 1;
        unsigned bit26  : 1;
        unsigned bit27  : 1;
        unsigned bit28  : 1;
        unsigned bit29  : 1;
        unsigned bit30  : 1;
        unsigned bit31  : 1;
        
        unsigned bit32  : 1;
        unsigned bit33  : 1;
        unsigned bit34  : 1;
        unsigned bit35  : 1;
        unsigned bit36  : 1;
        unsigned bit37  : 1;
        unsigned bit38  : 1;
        unsigned bit39  : 1;

        unsigned bit40  : 1;
        unsigned bit41  : 1;
        unsigned bit42  : 1;
        unsigned bit43 : 1;
        unsigned bit44 : 1;
        unsigned bit45 : 1;
        unsigned bit46 : 1;
        unsigned bit47 : 1;
        
        unsigned bit48 : 1;
        unsigned bit49 : 1;
        unsigned bit50 : 1;
        unsigned bit51 : 1;
        unsigned bit52 : 1;
        unsigned bit53 : 1;
        unsigned bit54 : 1;
        unsigned bit55 : 1;

        unsigned bit56 : 1;
        unsigned bit57 : 1;
        unsigned bit58 : 1;
        unsigned bit59 : 1;
        unsigned bit60 : 1;
        unsigned bit61 : 1;
        unsigned bit62 : 1;
        unsigned bit63 : 1;        
    };

    
}UQWord;
#endif

//==============================================================================
// PUBLIC VARIABLES			
//==============================================================================

//==============================================================================
// PUBLIC FUNCTIONS
//==============================================================================

#endif	
