/**
******************************************************************************
@brief Common functionality shared between tasks.
@file tasks_common_func.c
@author Berj Bedros
@version 1.0
@brief contains the functions that can be used in both pedestrian crossing and intersection control implementations.
******************************************************************************
*/

#include "stdint.h"

#include "stm32l4xx.h"

#include "tasks_common_func.h"

const int register_size = 24 / 4; // 24 bit register shift, 4 bit batch each transmit

/**
@brief Orange_Delay, the time to toggle from and to orange lights for the cars.
@param uint32_t orange_delay, the time in seconds to make the orange transition.
@return void
*/
void Orange_Delay(uint32_t orange_delay) {
	HAL_Delay(orange_delay);
}

void Improvment(void) {
	/*
	 * Improvement tips, separate the street transition into different function that manipulate
	 * on some specific bit. On method that combines the transition all together to the proper one
	 */
}
