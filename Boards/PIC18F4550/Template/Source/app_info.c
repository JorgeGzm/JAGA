/**
 * @file    app_him.h
 * @brief   TODO
 * @author  Jorge Guzman
 * @date    10 de Marco 2015
 * @version 0.1.0.0 (beta)
 */

#include "../Header/app_info.h"

/** Codigo do equipamento*/
UWord id_device;

/** Versao do Firmware*/
uint16 version;

/** Inicializa informacoes do equipamento*/
void info_init(void)
{
    version = VERSION_FIRMWARE;
    id_device.value = ID_DEVICE;   
}
