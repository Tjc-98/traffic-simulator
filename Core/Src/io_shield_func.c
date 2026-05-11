/**
******************************************************************************
@brief Functions to control the IO shield.
@file io_shield_func.c
@author Berj Bedros
@version 1.0
@brief contains the functions necessary to control the LEDs, buttons and switches.
******************************************************************************
*/

#include "stdbool.h"

#include "gpio.h"
#include "spi.h"

#include "io_shield_func.h"
#include "595_chip_control.h"

static uint8_t trasmit_timeout = 100;

/**
@brief Send_Register_U1_U2_U3, transmit the bits to write them to the chip registers and saved
		into the storage. the chip involved are U1, U2 and U3, basically 24bit to send.
@param uint8_t data[], the array containing the bits desired to be transmitted and saved
		int data_size, the size of the array
@return void
*/
void Send_Register_U1_U2_U3(uint8_t data[], int data_size) {
	Set_595_Reset_Pin();
	Enable_Shift_Register();

	Reset_595_Latch();

	for(int i = (data_size - 1); i > 0; i = i-2) {
		HAL_SPI_Transmit(&hspi3, &data[(i - 1)], sizeof(data[(i - 1)]), trasmit_timeout);
		HAL_SPI_Transmit(&hspi3, &data[i], sizeof(data[i]), trasmit_timeout);
	}

	Set_595_Latch();
}

/**
@brief Turn_Off_All_Lights, resetting the storage register to be zeros. effectively
		turning off all the lights of the IO shield.
@return void
*/
void Turn_Off_All_Lights(void) {
	Disable_Shift_Register();
	Reset_595_Reset_Pin();
	Reset_595_Latch();
	Set_595_Latch();
}

/**
@brief PL2_Switch_Is_Hit, checks if the button SW7 or SW8 are pressed.
@return bool true or false whether the buttons are pressed at the call instance.
*/
bool PL2_Switch_Is_Hit(void) {
	if (HAL_GPIO_ReadPin(PL2_Switch_GPIO_Port, PL2_Switch_Pin) == 0) {
		return true;
	}

	return false;
}

/**
@brief TL1_Car_Switch_Is_On, checks if the car switch SW1 is on or off.
@return bool true or false whether the switch is on or off at the call instance.
*/
bool TL1_Car_Switch_Is_On(void) {
	if (HAL_GPIO_ReadPin(TL1_Car_GPIO_Port, TL1_Car_Pin) == 0) {
		return true;
	}

	return false;
}

/**
@brief TL2_Car_Switch_Is_On, checks if the car switch SW2 is on or off.
@return bool true or false whether the switch is on or off at the call instance.
*/
bool TL2_Car_Switch_Is_On(void) {
	if (HAL_GPIO_ReadPin(TL2_Car_GPIO_Port, TL2_Car_Pin) == 0) {
		return true;
	}

	return false;
}

/**
@brief TL3_Car_Switch_Is_On, checks if the car switch SW3 is on or off.
@return bool true or false whether the switch is on or off at the call instance.
*/
bool TL3_Car_Switch_Is_On(void) {
	if (HAL_GPIO_ReadPin(TL3_Car_GPIO_Port, TL3_Car_Pin) == 0) {
		return true;
	}

	return false;
}

/**
@brief TL4_Car_Switch_Is_On, checks if the car switch SW4 is on or off.
@return bool true or false whether the switch is on or off at the call instance.
*/
bool TL4_Car_Switch_Is_On(void) {
	if (HAL_GPIO_ReadPin(TL4_Car_GPIO_Port, TL4_Car_Pin) == 0) {
		return true;
	}

	return false;
}
