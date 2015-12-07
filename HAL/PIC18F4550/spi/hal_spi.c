/**
  * @file    hal_spi.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 3, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Codigo do SPI Timer para o microcontrolador PIC18f4550.
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

#include "hal_spi.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

static SpiDevice spi_device;
static SpiSetup spi_setup;

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

/**
 * @brief Configura a polaridade do clock da SPI.
 * Ex.: spi_set_cpol(SPI_IDLE_HIGH);
 * @param polaridade
 */
void spi_set_cpol(uint8_t polaridade);

/**
 * @brief Configura o momento da transmissao do dado pela SPI.
 * Ex.: spi_set_cke(SPI_TRANS_RISING);
 * @param transmissao
 */
void spi_set_cke(uint8_t transmissao);

//==============================================================================
// SOURCE CODE
//==============================================================================

void spi_init(void)
{
    spi_setup.enable = SPI_DISABLE;
    spi_setup.type = SPI_MASTER_FOSC_4;
    spi_setup.polarity = SPI_IDLE_LOW;
    spi_setup.transmit = SPI_TRANS_RISING;
    spi_setup.sampled_time = SPI_SAMPLED_MIDDLE;
    spi_setup.mode = SPI_MODE_0;
}

void spi_attach(regGPIO *_sdi, regGPIO *_sdo, regGPIO *_sck, regGPIO *_ss)
{
    GPIO_regGPIO_attach(&spi_device.sdi_tris, _sdi);
    GPIO_regGPIO_attach(&spi_device.sdo_tris, _sdo);
    GPIO_regGPIO_attach(&spi_device.sck_tris, _sck);
    GPIO_regGPIO_attach(&spi_device.ss_tris, _ss);

    GPIO_regPin_setDir(&spi_device.sdi_tris, DIR_INPUT);
    GPIO_regPin_setDir(&spi_device.sdo_tris, DIR_OUTPUT);
    GPIO_regPin_setDir(&spi_device.ss_tris, DIR_INPUT);

    // Se SPI configurada para operar como SLAVE 
    if(spi_setup.type == SPI_SLAVE_SS_DISABLE || spi_setup.type == SPI_SLAVE_SS_ENABLE)
    {
        GPIO_regPin_setDir(&spi_device.sck_tris, DIR_INPUT);
    }
    else
    {
        GPIO_regPin_setDir(&spi_device.sck_tris, DIR_OUTPUT);
    }
}

void spi_set_chipselect(regGPIO chipselect, uint8_t status)
{
    //GPIO_pin_outputBit(chipselect->port, status);
}

void spi_set_cpol(uint8_t polaridade)
{
    spi_setup.polarity = polaridade;

    SSPCON1bits.CKP = polaridade;
}

void spi_set_cke(uint8_t transmissao)
{
    spi_setup.transmit = transmissao;

    SSPSTATbits.CKE = transmissao;
}

void spi_set_mode(uint8_t mode)
{
    spi_setup.mode = mode;

    //Desabilita modulo SPI para reconfigura-lo
    SSPCON1bits.SSPEN = SPI_DISABLE;
    
    switch(mode)
    {
        //Clock Idle State Low
        //Transmit occurs on transition from active to Idle clock state
        case SPI_MODE_0:
            spi_set_cpol(SPI_IDLE_LOW);
            spi_set_cke(SPI_TRANS_FALLING);
        break;

        //Clock Idle State Low
        //Transmit occurs on transition from Idle to active clock state
        case SPI_MODE_1:
            spi_set_cpol(SPI_IDLE_LOW);
            spi_set_cke(SPI_TRANS_RISING);
        break;

        //Clock Idle State High
        //Transmit occurs on transition from active to Idle clock state
        case SPI_MODE_2:
            spi_set_cpol(SPI_IDLE_HIGH);
            spi_set_cke(SPI_TRANS_FALLING);
        break;

        //Clock Idle State High
        //Transmit occurs on transition from Idle to active clock state
        case SPI_MODE_3:
            spi_set_cpol(SPI_IDLE_HIGH);
            spi_set_cke(SPI_TRANS_RISING);
        break;
    }

    //Reabilita modulo SPI se necessario 
    SSPCON1bits.SSPEN = spi_setup.enable;
}

void spi_set_sampled_time(uint8_t sampled_time)
{
    spi_setup.sampled_time = sampled_time;

    //Desabilita modulo SPI para reconfigura-lo
    SSPCON1bits.SSPEN = SPI_DISABLE;
    
    SSPSTATbits.SMP = sampled_time;

    //Reabilita modulo SPI se necessario 
    SSPCON1bits.SSPEN = spi_setup.enable;
}

void spi_enable(uint8_t value)
{
    spi_setup.enable = value;

    SSPCON1bits.SSPEN = value;
}

void spi_set_type(uint8_t type)
{
    spi_setup.type = type;

    // Desabilita modulo SPI para reconfigura-lo
    SSPCON1bits.SSPEN = SPI_DISABLE;

    SSPCON1bits.SSPM = type;

    //Se configurado como SLAVE
    if(type == SPI_SLAVE_SS_DISABLE || type == SPI_SLAVE_SS_ENABLE)
    {
        spi_set_sampled_time(SPI_SAMPLED_MIDDLE);
    }

    // Reabilita modulo SPI se necessario 
    SSPCON1bits.SSPEN = spi_setup.enable;
}

uint8_t spi_wr_rd(uint8_t UI8_dado)
{
    uint8_t temp;

    // Verifica write collision 
    if(SSPCON1bits.WCOL)
    {
        return(-1);
    }
    else
    {
        // Limpa o buffer 
        temp = SSPBUF;

        // Limpa o flag de interrupcao 
        PIR1bits.SSPIF = 0;

        // Transmite o dado 
        SSPBUF = UI8_dado;

        // Aguarda até o ciclo de escrita terminar 
        while (!PIR1bits.SSPIF)
        {
        }

        // Aguarda até o ciclo de leitura terminar 
        while (!SSPSTATbits.BF)
        {
        }

        // Se SPI configurada para operar como SLAVE 
        if(spi_setup.type == SPI_SLAVE_SS_DISABLE || spi_setup.type == SPI_SLAVE_SS_ENABLE)
        {
            // Verifica SSPBUF overflow 
            if(SSPCON1bits.SSPOV)
            {
                SSPCON1bits.SSPOV = 0;
            }
        }

        // Retorna o dado de leitura da SPI 
        return(SSPBUF);
    }
}

uint8_t spi_write(uint8_t dado)
{   
    if(SSPCON1bits.WCOL)                            //Verifica write collision
    {
        return -1;
    }
    else
    {
        uint8_t temp;
         
        // Limpa o buffer
        temp = SSPBUF;

        // Limpa o flag de interrupção
        PIR1bits.SSPIF = 0;

        //Transmite o dado
        SSPBUF = dado;

        // Aguarda até o ciclo de escrita terminar
        while (!PIR1bits.SSPIF)
        {
            Nop();
        }
    }

    return (0);
}

uint8_t spi_read(void)
{
    SSPBUF = 0xFF; // initiate bus cycle
    
    // Aguarda até o ciclo de leitura terminar
    while (!SSPSTATbits.BF)
    {
    }
    
    SSPCON1bits.SSPOV = 0;

    return(SSPBUF);
}
