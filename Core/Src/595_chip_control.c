/**
******************************************************************************
@brief Functions to control the 74HC595D inputs
@file 595_chip_control.c
@author Berj Bedros
@version 1.0
@brief contains the functions necessary to set the input pins to high or low
******************************************************************************
*/

#include "595_chip_control.h"
#include "gpio.h"

/**
@brief Set_595_Reset_Pin, Set the reset pin for the chip to High
@return void
*/
void Set_595_Reset_Pin(void) {
	HAL_GPIO_WritePin(_595_Reset_GPIO_Port, _595_Reset_Pin, GPIO_PIN_SET);
}

/**
@brief Reset_595_Reset_Pin, Set the reset pin for the chip to Low
@return void
*/
void Reset_595_Reset_Pin(void) {
	HAL_GPIO_WritePin(_595_Reset_GPIO_Port, _595_Reset_Pin, GPIO_PIN_RESET);
}

/**
@brief Set_595_Latch, Set the latch (storage) pin for the chip to High
@return void
*/
void Set_595_Latch(void) {
	HAL_GPIO_WritePin(_595_STCP_GPIO_Port, _595_STCP_Pin, GPIO_PIN_SET);
}

/**
@brief Reset_595_Latch, Set the latch (storage) pin for the chip to Low
@return void
*/
void Reset_595_Latch(void) {
	HAL_GPIO_WritePin(_595_STCP_GPIO_Port, _595_STCP_Pin, GPIO_PIN_RESET);
}

/**
@brief Enable_Shift_Register, Enable the chip to be able to use the register
@return void
*/
void Enable_Shift_Register(void) {
	HAL_GPIO_WritePin(_595_Enable_GPIO_Port, _595_Enable_Pin, GPIO_PIN_RESET);
}

/**
@brief Disable_Shift_Register, Disable the chip so it is not possible to write to register
@return void
*/
void Disable_Shift_Register(void) {
	HAL_GPIO_WritePin(_595_Enable_GPIO_Port, _595_Enable_Pin, GPIO_PIN_SET);
}
