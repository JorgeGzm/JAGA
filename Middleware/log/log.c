/**
  * @file    log.c
  * @author  Jorge Guzman (jorge.gzm@gmail.com)
  * @date    Dez 26, 2015
  * @version 0.2.0.0 (beta)
  * @brief   Bibliteoca para o registro de acontecimentos(log)
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

#include "log/log.h"
#include "crc/crc.h"
#include "AT24C32/AT24C32.h"

//#ifdef configSteps_Num
//	#error "configSteps_Num no defined in app_control.h"
//#else
//	#define configSteps_Num 2 //Defaul Value
//#endif


//==============================================================================
// PRIVATE DEFINITIONS
//==============================================================================

#define TENTATIVAS_BV 3

/** @brief numeros de inteiros que serao gravados por pagina. */
#define SIZE_INTS_PER_PAGE 2

/** @brief numero de paginas que serao gravadas. */
#define TOTAL_INDEX 15

/** @brief numero de gravaçoes por pagina de rodizio. */
#define TOTAL_WRITES_PER_INDEX 10

#define SIZE_USED_FOR_WRITING_OF_INDEX (TOTAL_WRITES_PER_INDEX * TOTAL_INDEX)

/** @brief Endereco inicial na memoria E2P externa. */
#define ADDR_PAGE_ZERO_E2P_EXT (4096 - (TOTAL_INDEX * SIZE_INTS_PER_PAGE))

/** @brief Calcula endereços de salvamento de cada pagina na e2p externa. */
#define NEXT_ADDR_E2P_EXT(pag) ((pag * SIZE_INTS_PER_PAGE) + ADDR_PAGE_ZERO_E2P_EXT)

/** @brief Endereço onde a pagina atual + crc salva. */
#define ADDR_MAIN_INDEX (ADDR_PAGE_ZERO_E2P_EXT - 2)

//==============================================================================
// PRIVATE TYPEDEFS
//==============================================================================

//==============================================================================
// PRIVATE VARIABLES			
//==============================================================================

//==============================================================================
// PRIVATE FUNCTIONS
//==============================================================================

uint16_t main_index;

uint16_t page_index;

//==============================================================================
// SOURCE CODE
//==============================================================================

void log_init()
{
	uint16_t aux1, complemet;

	load_pointer();

	aux1 = rd_ext_e2p(main_index);
	complemet = ~rd_ext_e2p(main_index + 1);

	if(aux1 != complemet)
	{
		page_index = 0;
	}
	else
	{
		page_index = aux1;
	}
}


void save_pointer(uint16_t addr_page) //OK
{
	uint16_t aux_index;
	static uint8_t counter_wr = 0;

	if( !(++counter_wr/TOTAL_WRITES_PER_INDEX) )
	{
		main_index = main_index > TOTAL_WRITES_PER_INDEX ? main_index + 1 : 0;

		 //Salva ponteiro da pagina.
		wr_ext_e2p(ADDR_MAIN_INDEX, main_index);

		//Salva seu Complemento
		wr_ext_e2p(ADDR_MAIN_INDEX + 1, ~main_index);
	}


	//Salva o endereço da nova pagina
	wr_ext_e2p(main_index, addr_page);

	//Salva seu Complemento
	wr_ext_e2p(main_index + 1, ~addr_page);

}

void load_pointer(void) //OK
{
	uint16_t aux_index, complement_index;
	UWord crc;

	aux_index =  rd_ext_e2p(ADDR_MAIN_INDEX);
	complement_index = ~rd_ext_e2p(ADDR_MAIN_INDEX + 1);

	if(aux_index != complement_index)
	{
		main_index = 0;

	}
	else
	{
		main_index = aux_index;
		//retun erro
	}
}

uint16_t load_page(uint16_t page)
{
	UWord crc, aux_crc, aux_data;

	crc.value = 0xFFFF;

	aux_data.value = rd_ext_e2p(NEXT_ADDR_E2P_EXT(page));

	crc_calculo(&crc.value, aux_data.b.b1);
	crc_calculo(&crc.value, aux_data.b.b2);

	//Salva CRC
	aux_crc.value = rd_ext_e2p(NEXT_ADDR_E2P_EXT(page) + 1);

	if(crc.value != aux_crc.value)
	{
		return 0;
	}
	else
	{
		return aux_data.value;
	}

}

void save_page(uint16_t data) //OK
{
	UWord crc, aux_data;
	//uint8_t i;

    aux_data.value = data;

    crc.value = 0xFFFF;

	//Salva balanco de vida.
    crc_calculo(&crc.value, aux_data.b.b1);
    crc_calculo(&crc.value, aux_data.b.b2);

	page_index++;

	//for(i= 0 ; i < SIZE_INTS_PER_PAGE; i++)
	/*{
		wr_ext_e2p(NEXT_ADDR_E2P_EXT(page_index) + i, aux_data.value);
	}*/

	wr_ext_e2p(NEXT_ADDR_E2P_EXT(page_index), aux_data.value);

	//Salva CRC
	wr_ext_e2p(NEXT_ADDR_E2P_EXT(page_index) + 1, crc.value);


	save_pointer(page_index);
}

void wr_ext_e2p(uint16_t addr, uint16_t data)
{
	AT24C32_write(addr, 1, data);
}

uint16_t rd_ext_e2p(uint16_t addr)
{
	uint16_t data;

	AT24C32_read(addr, 1, &data);

	return data;
}

uint16_t get_current_page(void)
{
	return page_index;
}
