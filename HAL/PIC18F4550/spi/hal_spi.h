/**
  * @file    hal_spi.h
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Mar 3, 2015
  * @version 0.1.0.0 (beta)
  * @brief   Driver SPI para o microcontrolador PIC18f4550.
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

#ifndef HAL_SPI_H
    #define HAL_SPI_H

//------------------------------------------------------------------------------
// Included Files
//------------------------------------------------------------------------------

#include "types/types.h"
#include "device/hal_device.h"
#include "gpio/hal_gpio.h"

//------------------------------------------------------------------------------
// Public Definitions
//------------------------------------------------------------------------------

/**
*@link http://dlnware.com/theory/SPI-Transfer-Modes
*
* SPI MODE
*      CKP     CKE
* 0     0       1       - (Idle Low, Falling Edge)  - The first clock signal rising can be used to prepare the data. The clock idle state is zero. The data on MISO and MOSI lines must be stable while the clock is low and can be changed when the clock is high. The data is captured on the clock's high-to-low transition and propagated on low-to-high clock transition.
* 1     0       0       - (Idle Low, Rising Edge)   - The data must be available before the first clock signal rising. The clock idle state is zero. The data on MISO and MOSI lines must be stable while the clock is high and can be changed when the clock is low. The data is captured on the clock's low-to-high transition and propagated on high-to-low clock transition.
* 2     1       1       - (Idle High, Rising Edge)  - The first clock signal falling can be used to prepare the data. The clock idle state is one. The data on MISO and MOSI lines must be stable while the clock is high and can be changed when the clock is low. The data is captured on the clock's low-to-high transition and propagated on high-to-low clock transition.
* 3     1       0       - (Idle High, Falling Edge) - The data must be available before the first clock signal falling. The clock idle state is one. The data on MISO and MOSI lines must be stable while the clock is low and can be changed when the clock is high. The data is captured on the clock's high-to-low transition and propagated on low-to-high clock transition.
**/
#define SPI_ENABLE          1

/** SPI mode */
#define SPI_MODE_0          1
#define SPI_MODE_1          0
#define SPI_MODE_2          3
#define SPI_MODE_3          2

/** SPI idle state */
#define SPI_IDLE_LOW        0
#define SPI_IDLE_HIGH       1

/** SPI transmition time */
#define SPI_TRANS_RISING    0
#define SPI_TRANS_FALLING   1

/** SPI sampled time */
#define SPI_SAMPLED_MIDDLE  0
#define SPI_SAMPLED_END     1

/** SPI setup */
#define SPI_DISABLE         0
#define SPI_ENABLE          1

/** SPI type */
#define SPI_MASTER_FOSC_4       0
#define SPI_MASTER_FOSC_16      1
#define SPI_MASTER_FOSC_64      2
#define SPI_MASTER_TMR2         3
#define SPI_SLAVE_SS_ENABLE     4
#define SPI_SLAVE_SS_DISABLE    5

/** CHIPSELECT CONTROL*/
#define SPI_CHIPSELECT_DISABLE  0
#define SPI_CHIPSELECT_ENABLE   1

//------------------------------------------------------------------------------
// Public structs, unions and enums
//------------------------------------------------------------------------------

typedef struct
{
    regGPIO sdi_tris;
    regGPIO sdo_tris;
    regGPIO sck_tris;
    regGPIO ss_tris;
}SpiDevice;

typedef union
{
    uint16 value;

    struct
    {
        unsigned enable         : 1;
        unsigned type           : 3;    //Master - Slave
        unsigned mode           : 2;
        unsigned polarity       : 1;
        unsigned transmit       : 1;
        unsigned sampled_time   : 1;
    };
}SpiSetup;

//------------------------------------------------------------------------------
// Global Variable 			
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Prototype  
//------------------------------------------------------------------------------

/**
 * @brief Funcao para inicializar a SPI. \n
 * Ex.: spi_init();
 * @param spi_setup
 */
void spi_init(void);

/**
 * @brief Configura quais pinos do microcontrolador sao utilizados pela SPI.
 * Obs.: Deve ser chamada somente depois de configurar o tipo de comunicacao (mestre/escravo).
 * @param sdi
 * @param sdo
 * @param sck
 * @param ss
 */
void spi_attach(regGPIO *_sdi, regGPIO *_sdo, regGPIO *_sck, regGPIO *_ss);

/**
 * @brief Funcao para habilitar ou desabilitar o chipselect
 * @param cs
 * @param status
 */
void spi_set_chipselect(regGPIO chipselect, uint8 status);

/**
 * @brief Funcao para configurar o modo de operacao da SPI.
 * Ex.: spi_set_mode(SPI_MODE_1);
 * @param mode  - Seleciona o modo de operacao da SPI
 */
void spi_set_mode(uint8 mode);
/**
 * @brief Configura o momento da amostragem do dado de entrada.
 * Ex.: spi_set_sampled_time(SPI_SAMPLED_MIDDLE);
 * @param sampled_time
 */
void spi_set_sampled_time(uint8 sampled_time);

/**
 * @brief Configura os pinos do microcontrolador como porta serial.
 * Ex.: spi_enalbe(SPI_ENABLE);
 * @param value
 */
void spi_enable(uint8 value);

/**
 * @brief Confiura o tipo da comunicao serial (Mestre/Escravo).
 * Ex.: spi_type(SPI_MASTER_FOSC_4);
 * @param type
 */
void spi_set_type(uint8 type);

/**
 * @brief Transmite um dado pela SPI e retorna o dado recebido pela mesma.
 * @param dado: dado a enviar
 * @return dado a recebido
 */
uint8 spi_wr_rd(uint8 UI8_dado);

/**
 * @brief Transmite um dado pela SPI 1
 * @param dado: dado a ser transmitido
 * @return
 */
uint8 spi_write(uint8 dado);

/**
 * @brief Recebe um dado pela SPI 1
 * @return dado recebido
 */
uint8 spi_read(void);

#endif

/*
 Clock polarity and phase
A timing diagram showing clock polarity and phase. The red vertical line represents CPHA=0 and the blue vertical line represents CPHA=1

In addition to setting the clock frequency, the master must also configure the clock polarity and phase with respect to the data. Freescale's SPI Block Guide[2] names these two options as CPOL and CPHA respectively, and most vendors have adopted that convention.

The timing diagram is shown to the right. The timing is further described below and applies to both the master and the slave device.

    At CPOL=0 the base value of the clock is zero
        For CPHA=0, data are captured on the clock's rising edge (low?high transition) and data is propagated on a falling edge (high?low clock transition).
        For CPHA=1, data are captured on the clock's falling edge and data is propagated on a rising edge.
    At CPOL=1 the base value of the clock is one (inversion of CPOL=0)
        For CPHA=0, data are captured on clock's falling edge and data is propagated on a rising edge.
        For CPHA=1, data are captured on clock's rising edge and data is propagated on a falling edge.

That is, CPHA=0 means sample on the leading (first) clock edge, while CPHA=1 means sample on the trailing (second) clock edge, regardless of whether that clock edge is rising or falling. Note that with CPHA=0, the data must be stable for a half cycle before the first clock cycle.

The MOSI and MISO signals are usually stable (at their reception points) for the half cycle until the next clock transition. SPI master and slave devices may well sample data at different points in that half cycle.

This adds more flexibility to the communication channel between the master and slave.

 */