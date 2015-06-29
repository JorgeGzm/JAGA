/*
 * File: app_info.h
 * Author: Jorge Guzman
 *
 * Created on 10 de Marco de 2015, 20:35
 */

#ifndef APP_INFO_H
    #define APP_INFO_H

#include "vars/vars.h"
#include "types/types.h"

/** Release do Firmware. Ex: release 1*/
#define RELEASE_FIRMWARE 1   //

/** Versao do Firmware. Ex: versao 1.0.0*/
#define VERSION_FIRMWARE 100

/** Codigo de identificacao da linha do equipamento*/
#define ID_DEVICE 1

void info_init(void);

#endif	/* INFO_HW_H */
