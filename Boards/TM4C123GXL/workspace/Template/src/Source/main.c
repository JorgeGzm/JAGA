/**
 * @file    main.c
 * @brief   TODO
 * @author  Jorge Guzman (jorge.gzm@gmail.com)
 * @date    13 de Junho de 2014
 * @version 0.1.0.0 (beta)
 */

#include "../Header/main.h"
#include <stdint.h>

void main(void)
{
    //Inicializa sistema
    init_drivers();

    //Inicializa dispositivos
    init_devices();
   
    while(1)
    {
        //Executa rotinas da funcionalidade
        run_system();
        
        //Executa rotina que trata a HIM
        run_him();
    }
}
