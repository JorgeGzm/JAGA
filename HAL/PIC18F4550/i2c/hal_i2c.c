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

/** @brief Informa que o i2c deseja realizar uma escrita */
#define I2C_WR          0x00

/** @brief Informa que o i2c deseja realizar uma leitura */
#define I2C_RD          0x01

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

PUBLIC void set_i2c1_timeout(uint8_t valor)
{
    tmr_i2c1_tout = valor;
}

PUBLIC uint8_t get_i2c1_timeout(void)
{
    return (tmr_i2c1_tout);
}

PUBLIC void i2c_setup_enable(uint8_t enable_i2c, uint8_t sda, uint8_t sck)
{
    SSPEN = enable_i2c;

    if(enable_i2c)
    {
        pinMode(sda, INPUT);
        pinMode(sck, INPUT);
    }
    else
    {
        pinMode(sda, OUTPUT);
        pinMode(sck, OUTPUT);
    }
}

PUBLIC void i2c_setup_master(uint8_t modo, uint8_t speed, uint8_t clock_master)
{
    //bit de controle do slow rate
    SSPSTATbits.SMP = speed;

    //seleciona modo de funcionamento da porta MSSP
    SSPCON1bits.SSPM = modo;

    //Clock configuration: clock = Fosc/[4x(SSPAD+1)]. somente no modo I2C_STP_MASTER_CLOCK
    SSPADD = clock_master;

    //Write data to be transmitted
    SSPBUF = 0x00;

    //bit de deteccao de colisao, limpar via software em modo mestre
    SSPCON1bits.WCOL = 0; //
}

PUBLIC void i2c_setup_slave(uint8_t modo, int8_t speed, uint8_t clock_slave)
{
    //bit de controle do slow rate
    SSPSTATbits.SMP = speed;
    
    //seleciona modo de funcionamento da porta MSSP
    SSPCON1bits.SSPM = modo;
    
    //controle do clock
    SSPCON1bits.CKP = clock_slave;

    //Write data to be transmitted
    SSPBUF = 0x00;

    //bit de deteccao de colisao,
    SSPCON1bits.WCOL = 0; //
}

PUBLIC void i2c_idle(void)//I2C_LIVRE
{
    //Carrega temporizador timeout
//    set_i2c1_timeout(TOUT_I2C1);

    //Aguarda barramento I2C ficar livre
    while((SSPCON2bits.SEN || SSPCON2bits.PEN || SSPCON2bits.RCEN || SSPCON2bits.RSEN || SSPCON2bits.ACKEN || SSPSTATbits.R_W) )//&& get_i2c1_timeout())
        Nop();
}

PUBLIC void i2c_start(void)//I2C_START
{
    //Inicializa Start Condition
    SSPCON2bits.SEN = 1;

    //Carrega temporizador timeout
  //  set_i2c1_timeout(TOUT_I2C1);

    //Aguarda término do Start Condition
    while(SSPCON2bits.SEN )//&& get_i2c1_timeout())
        Nop();
}

PUBLIC void i2c_repeat_start(void)//I2C_RESTART
{
    //Inicializa Repeated Start Condition
    SSPCON2bits.RSEN = 1;

    //Carrega temporizador timeout
//      set_i2c1_timeout(TOUT_I2C1);

    //Aguarda término do Repeated Start Condition
    while(SSPCON2bits.RSEN)// && get_i2c1_timeout())
        Nop();
}

PUBLIC void i2c_stop(void)//I2C_STOP
{
    //Inicializa Stop Condition
    SSPCON2bits.PEN = 1;

    //Carrega temporizador timeout
//    set_i2c1_timeout(TOUT_I2C1);

    //Aguarda término do Stop Condition
    while(SSPCON2bits.PEN )//&& get_i2c1_timeout())
        Nop();
}

PUBLIC void i2c_ack(void)//I2C_ACK
{
    SSPCON2bits.ACKDT = 0;
    SSPCON2bits.ACKEN = 1;
    while (SSPCON2bits.ACKEN);
}

PUBLIC uint8_t i2c_ack_stat(void)//I2C_TESTA_ACK
{
    return (SSPCON2bits.ACKSTAT);
}


PUBLIC void i2c_nack(void)//I2C_NACK
{
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1;
    while (SSPCON2bits.ACKEN);			//aguarda terminar seqüência ACK
}

PUBLIC uint8_t i2c_wait_ack(void)//I2C_TESTA_ACK
{
    //Carrega temporizador timeout
//    set_i2c1_timeout(TOUT_I2C1);

    while(SSPCON2bits.ACKSTAT)// && get_i2c1_timeout())
        Nop();
    return 0;
}

PUBLIC uint8_t i2c_write(uint8_t UI8_dado)
{
    i2c_idle();
    SSPBUF = UI8_dado; //carrega dado a ser transmitido no registrador SSPBUF

    //Verifica write collision
    if(SSPCON1bits.WCOL)
    {
        return -1;
    }
    else
    {
        //Carrega temporizador timeout
//        set_i2c1_timeout(TOUT_I2C1);

        //Aguarda ciclo de escrita terminar
        while(SSPSTATbits.R_W)//&& get_i2c1_timeout()) //aguarda transmissão terminar
            Nop();

        return (0);

    }
}

PUBLIC uint8_t i2c_read(void)
{
    //Carrega temporizador timeout
    // set_i2c1_timeout(TOUT_I2C1);

    //Aguarda barramento ficar livre
    i2c_idle();

    //Ativa Receive Mode
    SSPCON2bits.RCEN = 1;

    //Aguarda ciclo de leitura terminar
    while(!SSPSTATbits.BF)//&& get_i2c1_timeout()) //aguarda chegada do dado
        Nop();

    return(SSPBUF);
}

PUBLIC uint8_t i2c(I2C_COMMAND tipo, uint8_t data)
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

PUBLIC uint8_t i2c0_burst_read(uint8_t slaveAddr, uint8_t memAddr, uint16_t byteCount, uint8_t* data)
{
    i2c_idle();
    i2c_start();
    
    i2c_write(clr_bit(slaveAddr,0));
    i2c_wait_ack();
    
    i2c_write(memAddr);
    i2c_wait_ack();
    
    i2c_start();
        
    i2c_write(set_bit(slaveAddr, 0));   
    i2c_wait_ack();
    
    while (byteCount > 1)
    {
        
        *data++ =  i2c_read();        
        i2c_ack();
        byteCount--;
    }
    
    *data++ =  i2c_read();         
    i2c_stop();
    
    return 0;
}

PUBLIC uint8_t i2c0_burst_write(uint8_t slaveAddr, uint8_t memAddr, uint16_t byteCount, uint8_t* data)
{
    i2c_idle();
    i2c_start();
    
    i2c_write(clr_bit(slaveAddr,0));
    i2c_wait_ack();
    
    i2c_write(memAddr);
    i2c_wait_ack();
    
    while (byteCount)
    { 
       i2c_write(*data++);        
       i2c_wait_ack();
       byteCount--;
    }
    
    i2c_stop();    
    
    return 0;
}

PUBLIC uint8_t i2c0_burst_read16(uint8_t slaveAddr, uint16_t memAddr, uint16_t byteCount, uint8_t* data)
{
    UWord aux_memAddr;
    
    aux_memAddr.value = memAddr;
    
    i2c_idle();
    i2c_start();    
    
    i2c_write(clr_bit(slaveAddr,0));
    i2c_wait_ack();
    
    i2c_write(aux_memAddr.b.b2);
    i2c_wait_ack();
    
     i2c_write(aux_memAddr.b.b1);
    i2c_wait_ack();
    
    i2c_start();  
    
    i2c_write(set_bit(slaveAddr, 0));   
    i2c_wait_ack();
    
    while (byteCount > 1)
    {
        
        *data++ =  i2c_read();        
        i2c_ack();
        byteCount--;
    }
    
    *data++ =  i2c_read();         
    i2c_stop();
    
    return 0;
}

PUBLIC uint8_t i2c0_burst_write16(uint8_t slaveAddr, uint16_t memAddr, uint16_t byteCount, uint8_t* data)
{   
    UWord aux_memAddr;
    
    aux_memAddr.value = memAddr;
    
    i2c_idle();
    i2c_start(); 
    
    i2c_write(clr_bit(slaveAddr,0));
    i2c_wait_ack();
    
    i2c_write(aux_memAddr.b.b2);
    i2c_wait_ack();
    
    i2c_write(aux_memAddr.b.b1);
    i2c_wait_ack();
    
    while (byteCount)
    { 
       i2c_write(*data++);        
       i2c_wait_ack();
       byteCount--;
    }
    
    i2c_stop();  
    
    return 0;
}

DRIVER_I2C Driver_I2C0 =
{
    &i2c0_burst_write,
    &i2c0_burst_read
};

//void i2c_setup(void)//modo Mestre apenas para teste
//{
//    //Pinos usados, pic 18f4550
//    TRISBbits.TRISB0 = 1;       //RTC SDA aki
//    TRISBbits.TRISB1 = 1;       //RTC SCK
//
//     //Disable serial port
//    SSPCON1bits.SSPEN = 0; //descomentar
//
//    //Slew Rate Control is disable for Standard Speed mode (400 KHz a 1 MHz)
//    SSPSTATbits.SMP = 1;//ok
//
//    //I2C Master mode
//    SSPCON1bits.SSPM = 8; //ok
//
//    //Clock configuration (49 = 240 KHz) //bit rate de 100kbps a Fosc = 20MHz. obs: clock = Fosc/[4x(SSPAD+1)].
//    SSPADD = 49; //ok
//
//    //Write data to be transmitted
//    SSPBUF = 0x00; //ok
//
//    //Enable serial port
//    SSPCON1bits.SSPEN = 1; //
//    SSPCON1bits.WCOL = 0; //ok
//}