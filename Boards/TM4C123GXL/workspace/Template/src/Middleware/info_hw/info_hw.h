/*
 * File: info_hw.h
 * Author: Jorge Guzman
 *
 * Created on 10 de Marco de 2015, 20:35
 */

#ifndef INFO_HW_H
    #define INFO_HW_H

#include "vars/vars.h"
#include "types/types.h"

/**
 *  Extern Functions
 */
void set_num_serie(uint16 num_serie_h, uint16 num_serie_l);
void set_release(uint16 _release);
void set_version(uint16 _version);
void set_id_device(uint16 _id);
void set_pwd_device(uint8 celula);
uint16 get_pwd_device(void);
void set_data_active(uint16 high,uint16 middle, uint16 low);
//Timestamp get_data_active(void);

//Variaveis externas
#endif	/* INFO_HW_H */
