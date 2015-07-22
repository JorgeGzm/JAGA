/**
 * @file    main.c
 * @brief   TODO
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    13 de Junho de 2014
 * @version 0.1.0.0 (beta)
 */
//noovo
#include "../Header/main.h"
#include "device/hal_device.h"

void main(void)
{
    //Inicializa sistema
    setupHardware();

    //Inicializa dispositivos
    setupDevices();
   
    while(1)
    {
        //Executa rotinas da funcionalidade
        run_system();
        
        //Executa rotina que trata a HIM
        run_him();
    }
	
}
