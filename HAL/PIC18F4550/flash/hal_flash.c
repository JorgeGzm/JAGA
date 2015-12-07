/**
  * @file    hal_flash.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Feb 10, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo da memoria flash do microcontrolador PIC18f4550.\n
  * @details Referencias:
  * @link http://www.ccsinfo.com/forum/viewtopic.php?t=43278
  * @link https://github.com/krumboeck/pic18f-dfu-bootloader/blob/master/bootloader/flash.c
  * @link http://www.kae-systems.com/CodeExamples/PIC18/Drivers/FLASH_Driver/FLASH_Drv.c
  * @link http://78.20.169.44:8080/posts/Updating%20VSCP%20firmware/
  *
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

#include "hal_flash.h"
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

uint16_t flash_rd(int16_t address)
{
    UWord aux_address;
    UWord aux_data;

    aux_address.value = address;
    
    TBLPTRU = 0; //sempre em zero, porque o endereco maximo da memomoria de programa e 0x8000
    TBLPTRL = aux_address.b.b1;
    TBLPTRH = aux_address.b.b2;

    asm("\tTBLRD*+"); // read into TABLAT and increment

    aux_data.b.b1 = TABLAT; //get data
    
    asm("\tTBLRD*+"); // read into TABLAT and increment

    aux_data.b.b2 = TABLAT; //get data

    return(aux_data.value);
}

void flash_erasing(int16_t address)
{
    UWord aux_address;
    uint8_t UI8_aux;

    UI8_aux = INTCONbits.GIE;
    
    aux_address.value = address;
    TBLPTRU = 0; //sempre em zero, porque o endereco maximo da memomoria de programa e 0x8000
    TBLPTRL = aux_address.b.b1;
    TBLPTRH = aux_address.b.b2;

    EECON1bits.EEPGD = 1;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    EECON1bits.FREE = 1;
    INTCONbits.GIE = 0; //desabilita interrupcoes

    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;

    if(UI8_aux)
    {
        INTCONbits.GIE = 1;
    } //desabilita interrupcoes
}

void flash_wr(UWord UI16_buffer[], int16_t UI16_address)
{
    UWord ST_address;
    uint8_t UI8_aux;
    uint8_t UI8_counter;
    uint8_t UI8_counter1;

    UI8_aux = INTCONbits.GIE;

    UI8_counter = 64;                   // number of bytes in erase block
    FSR0H = UI16_buffer[0].b.b2;        //point to buffer //??
    FSR0L = UI16_buffer[0].b.b1;        //??

    UI8_aux = INTCONbits.GIE;
    ST_address.value = UI16_address;

    TBLPTRU = 0;                    //sempre em zero, porque o endereco maximo da memomoria de programa e 0x8000
    TBLPTRH = ST_address.b.b2;      //address of the memory block
    TBLPTRL = ST_address.b.b1;

    //READ_BLOCK
    do
    {
        asm("\tTBLRD*+");         // read into TABLAT and increment
        POSTINC0 = TABLAT;
        UI8_counter--;
    }
    while(0 < UI8_counter);

    //MODIFY_WORD
//    FSR0H = ;                     //point to buffer
//    FSR0L = ;
//    POSTINC0 = ;                  //update buffer word
//    INDF0 = ;

    //ERASE_BLOCK
    TBLPTRU = 0x00;               // load TBLPTR with the base
    TBLPTRH = ST_address.b.b2;    // address of the memory block
    TBLPTRL = ST_address.b.b1;
    EECON1bits.EEPGD = 1;         // point to Flash program memory
    EECON1bits.CFGS = 0;          // access Flash program memory
    EECON1bits.WREN = 1;          // enable write to memory
    EECON1bits.FREE = 1;          // enable Row Erase operation
    INTCONbits.GIE = 0;           // desabilita interrupcoes
    
    EECON2 = 0x55;                // write 55h
    EECON2 = 0xAA;                // write 0AAh
    EECON1bits.WR = 1;            // start erase (CPU stall)
    if(UI8_aux) { INTCONbits.GIE = 1; }

    asm("\tTBLRD*-"); //dummy read decrement
    FSR0H = UI16_buffer[0].b.b2; // point to buffer //??
    FSR0L = UI16_buffer[0].b.b1; // point to buffer //??
    UI8_counter1 = 2;

    //WRITE_BUFFER_BACK
    do
    {
        UI8_counter = 32;       // number of bytes in holding register

        //WRITE_BYTE_TO_HREGS
        do
        {
            TABLAT = POSTINC0;  // get low byte of buffer data
            asm("\tTBLWT+*");   // write data, perform a short write to internal TBLWT holding register.
            UI8_counter--;      // loop until buffers are full
        }
        while(0 < UI8_counter);
        EECON1bits.EEPGD = 1;   // point to Flash program memory
        EECON1bits.CFGS = 0;    // access Flash program memory
        EECON1bits.WREN = 1;    // enable write to memory
        INTCONbits.GIE = 0;     // disable interrupts

        EECON2 = 0x55;          // write 55h
        EECON2 = 0xAA;          // write 0AAh
        EECON1bits.WR = 1;      // start program (CPU stall)
        UI8_counter1--;
    }
    while(0 < UI8_counter1);

    if(UI8_aux){ INTCONbits.GIE = 1; }  //re-enable interrupts
    EECON1bits.WREN = 1;                //disable write to memory
}
