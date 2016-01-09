/**
  * @file    hal_i2c.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com); Rafael lopes (faellf@hotmail.com); 
  * @date    Jun 14, 2014
  * @version 0.1.0.0 (beta)
  * @brief   Codigo do Driver I2C para o microcontrolador PIC18f4550.
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

#include "hal_i2c.h"
#include "bitwise/bitwise.h"

//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

/** @brief timer ?? TODO implementar temporizador*/
uint8_t tmr_i2c1_tout = 0;

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================


//==============================================================================
// SOURCE CODE
//==============================================================================

/** @brief Funcao para gerar o temporizador timeout das comunicacoes */
void isr_1ms_i2c1(void)
{
    //Decrementa temporizador timeout da comunicacao
    if(tmr_i2c1_tout)
        tmr_i2c1_tout--;
}

void set_i2c1_timeout(uint8_t valor)
{
    tmr_i2c1_tout = valor;
}

uint8_t get_i2c1_timeout(void)
{
    return (tmr_i2c1_tout);
}

void i2c_setup_enable(uint8_t enable_i2c, regGPIO *sda, regGPIO *sck)
{
    //SSPEN = enable_i2c;

    if(enable_i2c)
    {
        GPIO_regPin_setDir(sda, DIR_INPUT);
        GPIO_regPin_setDir(sck, DIR_INPUT);
    }
    else
    {
        GPIO_regPin_setDir(sda, DIR_OUTPUT);
        GPIO_regPin_setDir(sck, DIR_OUTPUT);
    }
}

void i2c_setup_master(uint8_t modo, uint8_t speed, uint8_t clock_master)
{

}

void i2c_setup_slave(uint8_t modo, int8_t speed, uint8_t clock_slave)
{

}

void i2c_idle(void)//I2C_LIVRE
{

}

void i2c_start(void)//I2C_START
{

}

void i2c_repeat_start(void)//I2C_RESTART
{

}

void i2c_stop(void)//I2C_STOP
{

}

void i2c_ack(void)//I2C_ACK
{

}

uint8_t i2c_ack_stat(void)//I2C_TESTA_ACK
{
    return 0;
}


void i2c_nack(void)//I2C_NACK
{

}

uint8_t i2c_wait_ack(void)//I2C_TESTA_ACK
{

	return 0;
}

int8_t i2c_write(uint8_t UI8_dado)
{
	return (0);
}

uint8_t i2c_read(void)
{
    return(0);
}

uint8_t i2c(I2C_COMMAND tipo, uint8_t data)
{
    uint8_t feedback = 0;

    switch(tipo)
    {
        case EN_I2C_WRITE:
            feedback = (uint8_t)i2c_write(data);
            break;

        case EN_I2C_READ:
            feedback = i2c_read();
            break;

        case EN_I2C_START:
            i2c_start();
            break;

        case EN_I2C_REPET_START:
            i2c_repeat_start();
            break;
            
        case EN_I2C_STOP:
            i2c_stop();
            break;

        case EN_I2C_ACK:
            i2c_ack();
            break;

        case EN_I2C_NACK:
            i2c_nack();
            break;

        case EN_I2C_WAIT_ACK:
            feedback = i2c_wait_ack();
            break;

        case EN_I2C_ACK_STAT:
            i2c_ack_stat();
            break;

        case EN_I2C_IDLE:
            i2c_idle();
            break;
    }

    return (feedback);
}

void I2C1_setup(void)
{
	SYSCTL->RCGCI2C |= 0x02;    /* enable clock to I2C1 */
	SYSCTL->RCGCGPIO |= 0x01;   /* enable clock to GPIOA */

	/* PORTA 7, 6 for I2C1 */
	GPIOA->AFSEL |= 0xC0;       /* PORTA 7, 6 for I2C1 */
	GPIOA->PCTL &= ~0xFF000000; /* PORTA 7, 6 for I2C1 */
	GPIOA->PCTL |= 0x33000000;
	GPIOA->DEN |= 0xC0;         /* PORTA 7, 6 as digital pins */
	GPIOA->ODR |= 0x80;         /* PORTA 7 as open drain */

	I2C1->MCR = 0x10;           /* master mode */
	I2C1->MTPR = 7;             /* 100 kHz @ 16 MHz */
}

static int I2C1_wait_till_done(void)
{
    while(I2C1->MCS & 1);   /* wait until I2C master is not busy */
    return I2C1->MCS & 0xE; /* return I2C error code */
}

uint8_t i2c1_burst_wr(uint8_t slaveAddr, uint8_t memAddr, uint16_t byteCount, uint8_t* data)
{

    char error;

    if (byteCount <= 0)
        return -1;                  /* no write was performed */

    /* send slave address and starting address */
    I2C1->MSA = clr_bit(slaveAddr, 0);// slaveAddr << 1;
    I2C1->MDR = memAddr;
    I2C1->MCS = 3;                  /* S-(saddr+w)-ACK-maddr-ACK */

    error = I2C1_wait_till_done();   /* wait until write is complete */
    if (error) return error;

    /* send data one byte at a time */
    while (byteCount > 1)
    {
        I2C1->MDR = *data++;             /* write the next byte */
        I2C1->MCS = 1;                   /* -data-ACK- */
        error = I2C1_wait_till_done();
        if (error) return error;
        byteCount--;
    }

    /* send last byte and a STOP */
    I2C1->MDR = *data++;                 /* write the last byte */
    I2C1->MCS = 5;                       /* -data-ACK-P */
    error = I2C1_wait_till_done();
    while(I2C1->MCS & 0x40);             /* wait until bus is not busy */
    if (error) return error;

    return 0;       /* no error */
}

uint8_t i2c1_burst_rd(uint8_t slaveAddr, uint8_t memAddr, uint16_t byteCount, uint8_t* data)
{
	 char error;

	if (byteCount <= 0)
		return -1;         /* no read was performed */

	/* send slave address and starting address */
	I2C1->MSA = clr_bit(slaveAddr, 0); //slaveAddr << 1;
	I2C1->MDR = memAddr;
	I2C1->MCS = 3;       /* S-(saddr+w)-ACK-maddr-ACK */
	error = I2C1_wait_till_done();
	if (error)
		return error;

	/* to change bus from write to read, send restart with slave addr */
	I2C1->MSA = set_bit(slaveAddr, 0); //(slaveAddr << 1) + 1;   /* restart: -R-(saddr+r)-ACK */

	if (byteCount == 1)             /* if last byte, don't ack */
		I2C1->MCS = 7;              /* -data-NACK-P */
	else                            /* else ack */
		I2C1->MCS = 0xB;            /* -data-ACK- */
	error = I2C1_wait_till_done();
	if (error) return error;

	*data++ = I2C1->MDR;            /* store the data received */

	if (--byteCount == 0)           /* if single byte read, done */
	{
		while(I2C1->MCS & 0x40);    /* wait until bus is not busy */
		return 0;       /* no error */
	}

	/* read the rest of the bytes */
	while (byteCount > 1)
	{
		I2C1->MCS = 9;              /* -data-ACK- */
		error = I2C1_wait_till_done();
		if (error) return error;
		byteCount--;
		*data++ = I2C1->MDR;        /* store data received */
	}

	I2C1->MCS = 5;                  /* -data-NACK-P */
	error = I2C1_wait_till_done();
	*data = I2C1->MDR;              /* store data received */
	while(I2C1->MCS & 0x40);        /* wait until bus is not busy */

	return 0;       /* no error */
}


//uint8_t i2c0_burst_wr(int slaveAddr, char memAddr, int byteCount, char* data)
uint8_t i2c1_burst_wr16(uint8_t slaveAddr, uint16_t memAddr, uint16_t byteCount, uint8_t* data)
{

    char error;

    if (byteCount <= 0)
        return -1;                  /* no write was performed */

    /* send slave address and starting address */
    I2C1->MSA = clr_bit(slaveAddr, 0);// slaveAddr << 1;
    I2C1->MDR = memAddr;
    I2C1->MCS = 3;                  /* S-(saddr+w)-ACK-maddr-ACK */

    error = I2C1_wait_till_done();   /* wait until write is complete */
    if (error) return error;

    /* send data one byte at a time */
    while (byteCount > 1)
    {
        I2C1->MDR = *data++;             /* write the next byte */
        I2C1->MCS = 1;                   /* -data-ACK- */
        error = I2C1_wait_till_done();
        if (error) return error;
        byteCount--;
    }

    /* send last byte and a STOP */
    I2C1->MDR = *data++;                 /* write the last byte */
    I2C1->MCS = 5;                       /* -data-ACK-P */
    error = I2C1_wait_till_done();
    while(I2C1->MCS & 0x40);             /* wait until bus is not busy */
    if (error) return error;

    return 0;       /* no error */
}

uint8_t i2c1_burst_rd16(uint8_t slaveAddr, uint16_t memAddr, uint16_t byteCount, uint8_t* data)
{
	 char error;

	if (byteCount <= 0)
		return -1;         /* no read was performed */

	/* send slave address and starting address */
	I2C1->MSA = clr_bit(slaveAddr, 0); //slaveAddr << 1;
	I2C1->MDR = memAddr;
	I2C1->MCS = 3;       /* S-(saddr+w)-ACK-maddr-ACK */
	error = I2C1_wait_till_done();
	if (error)
		return error;

	/* to change bus from write to read, send restart with slave addr */
	I2C1->MSA = set_bit(slaveAddr, 0); //(slaveAddr << 1) + 1;   /* restart: -R-(saddr+r)-ACK */

	if (byteCount == 1)             /* if last byte, don't ack */
		I2C1->MCS = 7;              /* -data-NACK-P */
	else                            /* else ack */
		I2C1->MCS = 0xB;            /* -data-ACK- */
	error = I2C1_wait_till_done();
	if (error) return error;

	*data++ = I2C1->MDR;            /* store the data received */

	if (--byteCount == 0)           /* if single byte read, done */
	{
		while(I2C1->MCS & 0x40);    /* wait until bus is not busy */
		return 0;       /* no error */
	}

	/* read the rest of the bytes */
	while (byteCount > 1)
	{
		I2C1->MCS = 9;              /* -data-ACK- */
		error = I2C1_wait_till_done();
		if (error) return error;
		byteCount--;
		*data++ = I2C1->MDR;        /* store data received */
	}

	I2C1->MCS = 5;                  /* -data-NACK-P */
	error = I2C1_wait_till_done();
	*data = I2C1->MDR;              /* store data received */
	while(I2C1->MCS & 0x40);        /* wait until bus is not busy */

	return 0;       /* no error */
}

//================================================================================
// I2C_2
//================================================================================

void I2C2_setup(void)
{
	SYSCTL->RCGCI2C |= 0x04;    /* enable clock to I2C2 */
	SYSCTL->RCGCGPIO |= 0x10;   /* enable clock to GPIOE */

	/* PORTA 7, 6 for I2C1 */
	GPIOE->AFSEL |= 0x30;       /* PORTE 5, 4 for I2C2 */
	GPIOE->PCTL &= ~0x00FF0000; /* PORTE 5, 4 for I2C2 */
	GPIOE->PCTL |=  0x00330000;
	GPIOE->DEN |= 0x30;         /* PORTE 5, 4 as digital pins */
	GPIOE->ODR |= 0x20;         /* PORTE 5 as open drain */

	I2C2->MCR = 0x10;           /* master mode */
	I2C2->MTPR = 7;             /* 100 kHz @ 16 MHz */
}

static int I2C2_wait_till_done(void)
{
    while(I2C2->MCS & 1);   /* wait until I2C master is not busy */
    return I2C2->MCS & 0xE; /* return I2C error code */
}

uint8_t i2c2_burst_wr(uint8_t slaveAddr, uint8_t memAddr, uint16_t byteCount, uint8_t* data)
{

    char error;

    if (byteCount <= 0)
        return -1;                  /* no write was performed */

    /* send slave address and starting address */
    I2C2->MSA = clr_bit(slaveAddr, 0);// slaveAddr << 1;
    I2C2->MDR = memAddr;
    I2C2->MCS = 3;                  /* S-(saddr+w)-ACK-maddr-ACK */

    error = I2C2_wait_till_done();   /* wait until write is complete */
    if (error) return error;

    /* send data one byte at a time */
    while (byteCount > 1)
    {
        I2C2->MDR = *data++;             /* write the next byte */
        I2C2->MCS = 1;                   /* -data-ACK- */
        error = I2C2_wait_till_done();
        if (error) return error;
        byteCount--;
    }

    /* send last byte and a STOP */
    I2C2->MDR = *data++;                 /* write the last byte */
    I2C2->MCS = 5;                       /* -data-ACK-P */
    error = I2C2_wait_till_done();
    while(I2C2->MCS & 0x40);             /* wait until bus is not busy */
    if (error) return error;

    return 0;       /* no error */
}

uint8_t i2c2_burst_rd(uint8_t slaveAddr, uint8_t memAddr, uint16_t byteCount, uint8_t* data)
{
	 char error;

	if (byteCount <= 0)
		return -1;         /* no read was performed */

	/* send slave address and starting address */
	I2C2->MSA = clr_bit(slaveAddr, 0); //slaveAddr << 1;
	I2C2->MDR = memAddr;
	I2C2->MCS = 3;       /* S-(saddr+w)-ACK-maddr-ACK */
	error = I2C2_wait_till_done();
	if (error)
		return error;

	/* to change bus from write to read, send restart with slave addr */
	I2C2->MSA = set_bit(slaveAddr, 0); //(slaveAddr << 1) + 1;   /* restart: -R-(saddr+r)-ACK */

	if (byteCount == 1)             /* if last byte, don't ack */
		I2C2->MCS = 7;              /* -data-NACK-P */
	else                            /* else ack */
		I2C2->MCS = 0xB;            /* -data-ACK- */
	error = I2C2_wait_till_done();
	if (error) return error;

	*data++ = I2C2->MDR;            /* store the data received */

	if (--byteCount == 0)           /* if single byte read, done */
	{
		while(I2C2->MCS & 0x40);    /* wait until bus is not busy */
		return 0;       /* no error */
	}

	/* read the rest of the bytes */
	while (byteCount > 1)
	{
		I2C2->MCS = 9;              /* -data-ACK- */
		error = I2C2_wait_till_done();
		if (error) return error;
		byteCount--;
		*data++ = I2C2->MDR;        /* store data received */
	}

	I2C2->MCS = 5;                  /* -data-NACK-P */
	error = I2C2_wait_till_done();
	*data = I2C2->MDR;              /* store data received */
	while(I2C2->MCS & 0x40);        /* wait until bus is not busy */

	return 0;       /* no error */
}


uint8_t i2c2_burst_wr16(uint8_t slaveAddr, uint16_t memAddr, uint16_t byteCount, uint8_t* data)
{

    char error;

    if (byteCount <= 0)
        return -1;                  /* no write was performed */

    /* send slave address and starting address */
    I2C2->MSA = clr_bit(slaveAddr, 0);// slaveAddr << 1;
    I2C2->MDR = memAddr;
    I2C2->MCS = 3;                  /* S-(saddr+w)-ACK-maddr-ACK */

    error = I2C2_wait_till_done();   /* wait until write is complete */
    if (error) return error;

    /* send data one byte at a time */
    while (byteCount > 1)
    {
        I2C2->MDR = *data++;             /* write the next byte */
        I2C2->MCS = 1;                   /* -data-ACK- */
        error = I2C2_wait_till_done();
        if (error) return error;
        byteCount--;
    }

    /* send last byte and a STOP */
    I2C2->MDR = *data++;                 /* write the last byte */
    I2C2->MCS = 5;                       /* -data-ACK-P */
    error = I2C2_wait_till_done();
    while(I2C2->MCS & 0x40);             /* wait until bus is not busy */
    if (error) return error;

    return 0;       /* no error */
}

uint8_t i2c2_burst_rd16(uint8_t slaveAddr, uint16_t memAddr, uint16_t byteCount, uint8_t* data)
{
	 char error;

	if (byteCount <= 0)
		return -1;         /* no read was performed */

	/* send slave address and starting address */
	I2C2->MSA = clr_bit(slaveAddr, 0); //slaveAddr << 1;
	I2C2->MDR = memAddr;
	I2C2->MCS = 3;       /* S-(saddr+w)-ACK-maddr-ACK */
	error = I2C2_wait_till_done();
	if (error)
		return error;

	/* to change bus from write to read, send restart with slave addr */
	I2C2->MSA = set_bit(slaveAddr, 0); //(slaveAddr << 1) + 1;   /* restart: -R-(saddr+r)-ACK */

	if (byteCount == 1)             /* if last byte, don't ack */
		I2C2->MCS = 7;              /* -data-NACK-P */
	else                            /* else ack */
		I2C2->MCS = 0xB;            /* -data-ACK- */
	error = I2C2_wait_till_done();
	if (error) return error;

	*data++ = I2C2->MDR;            /* store the data received */

	if (--byteCount == 0)           /* if single byte read, done */
	{
		while(I2C2->MCS & 0x40);    /* wait until bus is not busy */
		return 0;       /* no error */
	}

	/* read the rest of the bytes */
	while (byteCount > 1)
	{
		I2C2->MCS = 9;              /* -data-ACK- */
		error = I2C2_wait_till_done();
		if (error) return error;
		byteCount--;
		*data++ = I2C2->MDR;        /* store data received */
	}

	I2C2->MCS = 5;                  /* -data-NACK-P */
	error = I2C2_wait_till_done();
	*data = I2C2->MDR;              /* store data received */
	while(I2C2->MCS & 0x40);        /* wait until bus is not busy */

	return 0;       /* no error */
}
