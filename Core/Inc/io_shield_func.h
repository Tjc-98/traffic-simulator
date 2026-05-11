/**
******************************************************************************
@brief Header file for the functions to control the IO shield
@file io_shield_func.h
@author Berj Bedros
@version 1.0
******************************************************************************
*/

#include "stdbool.h"

#ifndef INC_IO_SHIELD_FUNC_H_
#define INC_IO_SHIELD_FUNC_H_

void Send_Register_U1_U2_U3(uint8_t data[], int data_size);

void Turn_Off_All_Lights(void);

bool PL2_Switch_Is_Hit(void);
bool TL1_Car_Switch_Is_On(void);
bool TL2_Car_Switch_Is_On(void);
bool TL3_Car_Switch_Is_On(void);
bool TL4_Car_Switch_Is_On(void);

#endif /* INC_IO_SHIELD_FUNC_H_ */
