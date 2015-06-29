/* 
 * File: app_info.c
 * Author: Jorge Guzman
 *
 * Created on 10 de Marco de 2015, 20:35
 */

#include "../Header/app_info.h"

/** Codigo do equipamento*/
UWord id_device;

/** Numero de serie do equipamento*/
UWord num_serie;

/** Release do Firmware*/
uint16 release;

/** Versao do Firmware*/
uint16 version;

/** Senha usada para configurar ou alterar informacoes de fabrica. */
UWord pwd_device;

/** Data de ativacao do equipamento no formato de Time Stamp*/
Timestamp data_active;

/** Inicializa informacoes do equipamento*/
void info_init(void)
{
//    id_device.value = 0;
//    num_serie.value = 0;
//    release = 0;
//    version = 0;
//    pwd_device.value = 0;
//    data_active.UN_TS0.value = 0;
//    data_active.UN_TS1.value = 0;
//    data_active.UN_TS2.value = 0;

//    set_num_serie(0xFF, 0xFF);
//    set_release(RELEASE_FIRMWARE);
//    set_version(VERSION_FIRMWARE);
    //set_pwd_device(66);
}
