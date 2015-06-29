/**
 * @file    hal_i2c.c
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    14 de Junho de 2014
 * @version 0.1.0.0 
 * @brief   Codigo do Driver I2C para o microcontrolador PIC18f4550.
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
 *
 * @section DESCRIPTION
 */
#include "hal_i2c.h"


/** timer ?? TODO implementar temporizador*/
uint8 tmr_i2c1_tout = 0;

/**
 * Funcao para gerar o temporizador timeout das comunicacoes
 */
void isr_1ms_i2c1(void)
{
    //Decrementa temporizador timeout da comunicacao
    if(tmr_i2c1_tout)
        tmr_i2c1_tout--;
}

void set_i2c1_timeout(uint8 valor)
{
    tmr_i2c1_tout = valor;
}

uint8 get_i2c1_timeout(void)
{
    return (tmr_i2c1_tout);
}

void i2c_setup_enable(uint8 enable_i2c, regGPIO *sda, regGPIO *sck)
{
    SSPEN = enable_i2c;

    if(enable_i2c)
    {
        GPIO_pin_high(sda); //TODO erro
        GPIO_pin_high(sck); //TODO erro
    }
    else
    {
        GPIO_pin_low(sda);//TODO erro
        GPIO_pin_low(sck);
    }
}

void i2c_setup_master(uint8 modo, uint8 speed, uint8 clock_master)
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

void i2c_setup_slave(uint8 modo, int8 speed, uint8 clock_slave)
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

//void i2c_setup(void)//modo Mestre
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

void i2c_idle(void)//I2C_LIVRE
{
    //Carrega temporizador timeout
//    set_i2c1_timeout(TOUT_I2C1);

    //Aguarda barramento I2C ficar livre
    while((SSPCON2bits.SEN || SSPCON2bits.PEN || SSPCON2bits.RCEN || SSPCON2bits.RSEN || SSPCON2bits.ACKEN || SSPSTATbits.R_W) )//&& get_i2c1_timeout())
        Nop();
}

void i2c_start(void)//I2C_START
{
    //Inicializa Start Condition
    SSPCON2bits.SEN = 1;

    //Carrega temporizador timeout
  //  set_i2c1_timeout(TOUT_I2C1);

    //Aguarda término do Start Condition
    while(SSPCON2bits.SEN )//&& get_i2c1_timeout())
        Nop();
}

void i2c_repeat_start(void)//I2C_RESTART
{
    //Inicializa Repeated Start Condition
    SSPCON2bits.RSEN = 1;

    //Carrega temporizador timeout
//      set_i2c1_timeout(TOUT_I2C1);

    //Aguarda término do Repeated Start Condition
    while(SSPCON2bits.RSEN)// && get_i2c1_timeout())
        Nop();
}

void i2c_stop(void)//I2C_STOP
{
    //Inicializa Stop Condition
    SSPCON2bits.PEN = 1;

    //Carrega temporizador timeout
//    set_i2c1_timeout(TOUT_I2C1);

    //Aguarda término do Stop Condition
    while(SSPCON2bits.PEN )//&& get_i2c1_timeout())
        Nop();
}

void i2c_ack(void)//I2C_ACK
{
    SSPCON2bits.ACKDT = 0;
    SSPCON2bits.ACKEN = 1;
    while (SSPCON2bits.ACKEN);
}

uint8 i2c_ack_stat(void)//I2C_TESTA_ACK
{
    return (SSPCON2bits.ACKSTAT);
}


void i2c_nack(void)//I2C_NACK
{
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1;
    while (SSPCON2bits.ACKEN);			//aguarda terminar seqüência ACK
}

void i2c_wait_ack(void)//I2C_TESTA_ACK
{
    //Carrega temporizador timeout
//    set_i2c1_timeout(TOUT_I2C1);

    while(SSPCON2bits.ACKSTAT)// && get_i2c1_timeout())
        Nop();
}

int8 i2c_write(uint8 UI8_dado)
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



uint8 i2c_read(void)
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

uint8 i2c(uint8 tipo, uint8 data)
{
    uint8 feedback = 0;

    switch(tipo)
    {
        case EN_I2C_WRITE:
            feedback = (uint8)i2c_write(data);
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
            i2c_wait_ack();
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
