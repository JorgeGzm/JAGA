/**
 * @file    app_info.h
 * @brief   TODO
 * @author  Jorge Guzman
 * @date    10 de Marco 2015
 * @version 0.1.0.0 (beta)
 */

#ifndef APP_INFO_H
    #define APP_INFO_H

#include "vars/vars.h"
#include "types/types.h"

/** @brief Release do Firmware. Ex: release 1*/
#define RELEASE_FIRMWARE 1   //

/** @brief Versao do Firmware. Ex: versao 1.0.0*/
#define VERSION_FIRMWARE 100

/** @brief Codigo de identificacao da linha do equipamento*/
#define ID_DEVICE 1

/** @brief Inicializa informacoes do equipamento*/
void info_init(void);

#endif	/* INFO_HW_H */
