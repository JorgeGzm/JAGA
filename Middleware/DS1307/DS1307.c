/**
  * @file    DS1307.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 26, 2015
  * @version 0.1.0.0 (beta)
  * @brief   TODO documentar
  * @details Codigo da biblioca faz o uso da comunicacao I2C para a traca de dados com o CI.
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

//Pinos usados(pic18f4550):
//SDA-B0 input
//SCL-B1 output
//Vcc
//Gnd

//==============================================================================
// INCLUDE FILES
//==============================================================================

#include <stddef.h>
#include "DS1307.h"
#include "types/types.h"
#include "xtime/xtime.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

/** @brief Endereco I2C do CI ds1307 */
#define DS1307_ADDRESS    0xD0// 0x68//0xD0

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

PRIVATE DESCRIPTION_MEMORY DS1307_description = { 8, 63, "DS1307"};

PRIVATE DRIVER_I2C *I2Cdrv;

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================
//
///** @brief Callback para aleitura da funcao i2c usada pela biblioteca.*/
//PRIVATE uint8_t (*DS1307_i2c_read)(uint8_t, uint8_t, uint16_t, uint8_t*);
//
///** @brief Callback para a escrita da funcao i2c usada pela biblioteca.*/
//PRIVATE uint8_t (*DS1307_i2c_write)(uint8_t, uint8_t, uint16_t, uint8_t*);


//==============================================================================
// SOURCE CODE
//==============================================================================

PUBLIC void DS1307_attach_i2c(DRIVER_I2C *driver)
{
    I2Cdrv = driver;
}

PUBLIC void DS1307_write(DataTime data_time)
{
    uint8_t timeDateToSet[7];
    
    if(I2Cdrv->read != NULL)
    {
        timeDateToSet[0] = decToBcd(data_time.second);
        timeDateToSet[1] = decToBcd(data_time.minute);
        timeDateToSet[2] = decToBcd(data_time.hour);
        timeDateToSet[3] = data_time.day;
        timeDateToSet[4] = decToBcd(data_time.date);
        timeDateToSet[5] = decToBcd(data_time.month);
        timeDateToSet[6] = decToBcd(data_time.yearChar);
     
        I2Cdrv->write(DS1307_ADDRESS, 0, 7, &timeDateToSet[0]);
//
//        DS1307_i2c_wr(DS1307_ADDRESS, 0, 1, &timeDateToSet[0]);
//        DS1307_i2c_wr(DS1307_ADDRESS, 1, 1, &timeDateToSet[1]);
//        DS1307_i2c_wr(DS1307_ADDRESS, 2, 1, &timeDateToSet[2]);
//        
//        /* use burst write to write day, date, month, and year */
//        DS1307_i2c_wr(DS1307_ADDRESS, 3, 4, &timeDateToSet[3]);
    }    
}

PUBLIC void DS1307_read(DataTime *data_time)
{    
    uint8_t timeDateReadBack[7];
    
    if(I2Cdrv->read != NULL)
    {
        //DS1307_i2c_read(DS1307_ADDRESS, 0x00, 7, &timeDateReadBack[0]);
        I2Cdrv->read(DS1307_ADDRESS, 0, 7, &timeDateReadBack[0]);

        data_time->second   = bcdToDec(timeDateReadBack[0] & 0x7F);
        data_time->minute   = bcdToDec(timeDateReadBack[1] & 0x7F);
        data_time->hour     = bcdToDec(timeDateReadBack[2] & 0x3F);
        data_time->day      = bcdToDec(timeDateReadBack[3] & 0x3F);
        data_time->date     = bcdToDec(timeDateReadBack[4] & 0x3F);
        data_time->month    = bcdToDec(timeDateReadBack[5] & 0x3F);
        data_time->yearChar = bcdToDec(timeDateReadBack[6] & 0x3F);

        //Verifica se algum dos valores abaixo esta fora dos limites
        if(data_time->yearChar > 99) { data_time->yearChar = 0; }
        if(data_time->month    > 31) { data_time->month    = 0; }
        if(data_time->date     > 31) { data_time->date     = 0; }
        if(data_time->hour     > 23) { data_time->hour     = 0; }
        if(data_time->minute   > 59) { data_time->minute   = 0; }
        if(data_time->second   > 59) { data_time->second   = 0; }

        data_time->yearInt = data_time->yearChar + 2000;

    	get_string_day(data_time);
    }
    else
    {
        data_time->yearChar = 255;
        data_time->yearInt  = 255;
        data_time->month    = 255;
        data_time->date     = 255;
        data_time->day      = 255;
        data_time->hour     = 255;
        data_time->minute   = 255;
        data_time->second   = 255;
    }
}

PUBLIC uint8_t DS1307_sram_write(uint8_t addr, uint16_t count, uint8_t* data)
{
	if(addr >= DS1307_description.init && addr <= DS1307_description.store && I2Cdrv->read != NULL)
    {
        I2Cdrv->write(DS1307_ADDRESS, addr, count, data);
		return 1;
    }
    else
    {
        return 0;
    }
}

PUBLIC uint8_t DS1307_sram_read(uint8_t addr, uint16_t count, uint8_t* data)
{
    if(addr >= DS1307_description.init && addr <= DS1307_description.store && I2Cdrv->read != NULL)
    {
       I2Cdrv->read(DS1307_ADDRESS, addr, count, data);
       return 1;
    }
    else
    {
        return 0;
    }
}

PUBLIC DESCRIPTION_MEMORY DS1307_get_description(void)
{
	return DS1307_description;
}

//i2c_setup_enable(I2C_EN_PIN_I2C, &rB0, &rB1);
//i2c_setup_master(I2C_STP_MASTER_CLOCK, I2C_SPEED_FAST, I2C_CK_240KHz);
//DS1307_attach_i2c(i2c0_burst_rd, i2c0_burst_wr);
//relogio.second = 2;
//relogio.minute = 15;
//relogio.hour = 22;
//relogio.day = 1;
//relogio.date = 14;
//relogio.month = 12;
//relogio.yearChar = 15;
//
//DS1307_write(relogio);
//
//Delay_ms(1000);
//Delay_ms(1000);
//
//DS1307_read(&rtc);
//nokia_fill(0xFF);
//nokia_set_cursor(1, 0);
//xprintf(nokia_white_putc, "%s", rtc.str_day);
//nokia_set_cursor(1, 1);
//xprintf(nokia_white_putc, "Hora: %d:%d:%d", rtc.hour, rtc.minute, rtc.second);
//nokia_set_cursor(1, 2);
//xprintf(nokia_white_putc, "Data: %d/%d/%d", rtc.date, rtc.month, rtc.yearInt);
