/**
 * @file    hal_i2c.h
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    14 de Junho de 2014
 * @version 0.1.0.0 
 * @brief   Driver i2c para o microcontrolador PIC18f4550.
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

#ifndef HAL_I2C_H
    #define HAL_I2C_H

#include "types/types.h"
#include "gpio/hal_gpio.h"
#include "device/hal_device.h"

/** Comandos I2C */
enum _I2C_COMMAND
{  
    EN_I2C_START = 0,
    EN_I2C_REPET_START,
    EN_I2C_STOP,
    EN_I2C_ACK,
    EN_I2C_NACK,
    EN_I2C_WAIT_ACK,
    EN_I2C_ACK_STAT,
    EN_I2C_WRITE,
    EN_I2C_READ,
    EN_I2C_IDLE,
};


 /** habilita porta serial sincrona e configura SCL e SDA respectivamente como pinos de clock e dado */
#define I2C_EN_PIN_I2C 1

/** desabilita a porta serial sincronae configura SCL e SDA como pinos digitais*/
#define I2C_EN_PIN_IO 0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Modo escravo, 10 bits de endereco com bit de interrupcao de start e stop habilitado*/
#define I2C_STP_SLAVE_10bt_ISR_START_STOP       0x0F;

/** @brief Modo escravo, 10 bits de endereco.*/
#define I2C_STP_SLAVE_10bt                      0x07

/** @brief Modo escravo, 7 bits de endereco com bit de interrupcao de start e stop habilitado*/
#define I2C_STP_SLAVE_7bt_ISR_START_STOP        0x0E

/** @brief Modo escravo, 7 bits de endereco.*/
#define I2C_STP_SLAVE_7bt                       0x06

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Modo mestre. clock = Fosc/[4x(SSPADD+1)]*/
#define I2C_STP_MASTER_CLOCK                    0x08

/** @brieffirmware controlado pelo mestre(escravo disponivel)*/
#define I2C_STP_MASTER_CONTROL                  0x0B

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/** @brief Controle Slow Rate desabilitado para os modos standard e speed(100KHz e 1kHz)*/
#define I2C_SPEED_FAST                  1

/** @brief Controle Slow Rate habilitado para o modo speed(400kHz)*/
#define I2C_SPEED_SLOW                  0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/**@brief controle do clock, habilita o clock*/
#define I2C_CLOCK_SLAVE_EN                  1

/**@brief controle do clock, mantem o clock em nivel baixo(clock stretch)*/
#define I2C_CLOCK_SLAVE_NL                  0

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/**@brief Clock((49 = 240kHz) da comunicacao i2c, somente com I2C_MASTER_CLOCK habilitado*/
#define I2C_CK_240KHz   49

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/**@brief Informa que o i2c deseja realizar uma escrita */
#define I2C_WR          0x00

/**Informa que o i2c deseja realizar uma leitura */
#define I2C_RD          0x01

/**@brief */
#define TOUT_I2C1       50


/**
 * @briefConfigura temporizador timeout
 * @param valor: valor do timer
 */
void set_i2c1_timeout(uint8);

/** @brief retorna valor do timer*/
uint8 get_i2c1_timeout(void);


/**
 * @brief Porta serial concrona habilitada(quando habilitada, pos pinos SDA e SCL, precisam
 * estar configurados como entrada
 * @param enable_i2c I2C_EN_PIN_I2C: habilita pinos para o uso do i2c.  \n
 *                   I2C_EN_PIN_IO: desabilota i2c e configura pinos como I/O   \n
 * @param sda   pino configurado para dado da i2c
 * @param sck   Pino configurado para o clock da I2C
 */
void i2c_setup_enable(uint8 enable_i2c, regGPIO *sda, regGPIO *sck);

/**
 * @brief Configura i2c para funcionar como mestre
 * @param modo Modo de funcionamento da I2C.    \n
 *  I2C_STP_MASTER_CLOCK:   \n
 *  I2C_STP_MASTER_CONTROL: \n
 * @param speed Bit de controle do slow rate.   \n
 *  I2C_SPEED_FAST: \n
 *  I2C_SPEED_SLOW: \n
 * @param clock_master Clock = Fosc/[4x(SSPAD+1)], apenas para I2C_MASTER_CLOCK \n
 *  I2C_CK_240KHz: configura clock em 240kHz    \n
 */
void i2c_setup_master(uint8 modo, uint8 speed, uint8 clock_master);

/**
 * @brief Configura i2c para funcionar como slave
 * @param modo Modo de funcionamento da I2C.    \n
 *  I2C_STP_SLAVE_7bt:  \n
 *  I2C_STP_SLAVE_10bt: \n
 *  I2C_STP_SLAVE_7bt_ISR_START_STOP:   \n
 *  I2C_STP_SLAVE_10bt_ISR_START_STOP:  \n
 * @param speed Speed Bit de controle do slow rate. \n
 *  I2C_SPEED_FAST: \n
 *  I2C_SPEED_SLOW: \n
 * @param clock_slave   \n
 */
void i2c_setup_slave(uint8 modo, int8 speed, uint8 clock_slave);

//void i2c_setup();
/**
 * @brief Para que o mestre possa inciar uma transimissao é necessario
 * ele se certificar de que o barramento I2C não esteja envolvido em alguma transmissao
 */
void i2c_idle(void);

/**
 * @brief Habilita condicao de START(somente modo Mestre). A condicao
 * START é gerada quando o bit SEN é setado. O bit SEN é automaticamente pagado
 * pelo hardware no final da condiçao START, sendo no mesmo momento setado o
 * bit SSPIF(Uma interrupçao sera gerada se ela estiver habilitada).
 */
void i2c_start(void);

/**
 * @brief A fucao I2C_RESTART e exatamente igual a funcao I2C_START
 * A condicao START repetida ou Restart permite que seja alterada a direçao de fluxo
 * de dados(Estrita ou Leitura) sem que o dispitivo mestre precise antes finalizar
 * a transmissao corrente com uma condicao de STOP.
 */
void i2c_repeat_start(void);

/**
 * @brief A fucao STOP é gerada quando o bit PEN é setado(inicia condicao
 * STOP nos pinos SDA e SCL). O bit PEN é automaticamente pagado pelo hardware no
 * final da condiçao STOP, sendo no mesmo momento setado obit SSPIF(Uma interrupçao
 * sera gerada se ela estiver habilitada).
 */
void i2c_stop(void);

/**
 * @brief Se Apos a chegada de um novo byte no dispostivo mestre deseja
 * receber mais um byte, ele deve gerar um bit ACK = 0.Depois e preciso dar inicio
 * a sequencia setando ACKEN, que sera automaticamento pagado pelo hardware apos
 * o fim da transmissao do bit ACK = 0. O bit SSPIF tambem e setado na borda de
 * descida do nono pulso de clock, sendo gerado uma interrupçao se ela estiver habilitada.
 */
void i2c_ack(void);

/**
 * @brief Se Apos a chegada de um novo byte no dispostivo mestre NAO deseja
 * receber mais um byte, ele deve gerar um bit ACK = 1. Depois e preciso dar inicio
 * a sequencia setando ACKEN, que sera automaticamento pagado pelo hardware apos
 * o fim da transmissao do bit ACK = 1. O bit SSPIF tambem e setado na borda de
 * descida do nono pulso de clock, sendo gerado uma interrupçao se ela estiver habilitada.
 */
void i2c_nack(void);

/**
 * @brief Espera receber um ACK
 */
void i2c_wait_ack(void);

/**
 * @brief Transmite um byte pelo barramento I2C
 * @param UI8_dado
 * @return
 */
int8 i2c_write(uint8 UI8_dado);

/**
 * @brief Le um byte do barramento I2C
 * @return dado lido
 */
uint8 i2c_read(void);

/**
 * @brief Depois de cada byte e transmitido o dispositivo mestre precisa
 * receber do dispositivo escravo um BIT de reconhecimento, o pulso ACK(ou bit ACK)
 * recebido no nono pulso de clock. O bit ACKSTAT indica se o dispositivo escravo
 * recebeu ou nao o byte transmito.
 */
uint8 i2c_ack_stat(void);

/**
 * @brief Funcao que contem todos os camandos da comunicacao i2c habstraidas.
 * @param UI8_tipo Comando que ira ser executado.
 * @param UI8_data Dado que deseja ser enviado.
 * @return Dado recebido.
 */
uint8 i2c(uint8 UI8_tipo, uint8 UI8_data);


extern uint8 tmr_i2c1_tout;




#endif
