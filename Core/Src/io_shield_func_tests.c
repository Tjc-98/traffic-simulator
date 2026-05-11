/**
******************************************************************************
@brief Test file to test the IO shield functionality.
@file io_shield_func_tests.c
@author Berj Bedros
@version 1.0
******************************************************************************
*/

#include "stdint.h"
#include "stdbool.h"

#include "gpio.h"

#include "io_shield_func_tests.h"
#include "io_shield_func.h"

static const int register_size = 24;

/**
@brief Run the desired test.
@return void
*/
void Run_IO_Shield_Func_Tests(void) {
//	Test_Send_Register_U1();
//	Test_Send_Register_U2();
//	Test_Send_Register_U3();
//	Test_Turn_Off_All_Lights();
//	Test_PL2_Switch_Is_Hit();
//	Test_TL1_Car_Switch_Is_On();
//	Test_TL2_Car_Switch_Is_On();
//	Test_TL3_Car_Switch_Is_On();
//	Test_TL4_Car_Switch_Is_On();
}

/**
@brief Test_Send_Register_U1,
		Test to insure that it is enabled to transmit data to the register and
		save specific bits into the storage. Tests specifically the U1 chip.
		The test accepted criteria are:
			All the output pin of the U1 ship (LEDs) should be high (ON)
			Basically LED 1, 2, 3, 13, 14, 15, 16, 17, 18 should be turned ON
@return void
*/
void Test_Send_Register_U1(void) {
	uint8_t data[] = {
		0b1111, 0b1111,	// U1
		0b0000, 0b0000,
		0b0000, 0b0000
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Test_Send_Register_U2,
		Test to insure that it is enabled to transmit data to the register and
		save specific bits into the storage. Tests specifically the U2 chip.
		The test accepted criteria are:
			All the output pin of the U2 ship (LEDs) should be high (ON)
			Basically LED 4, 5, 6, 19, 20, 21, 22, 23, 24 should be turned ON
@return void
*/
void Test_Send_Register_U2(void) {
	uint8_t data[] = {
		0b0000, 0b0000,
		0b1111, 0b1111,	// U2
		0b0000, 0b0000
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Test_Send_Register_U3,
		Test to insure that it is enabled to transmit data to the register and
		save specific bits into the storage. Tests specifically the U2 chip.
		The test accepted criteria are:
			All the output pin of the U3 ship (LEDs) should be high (ON)
			Basically LED 7, 8, 9, 10, 11, 12 should be turned ON
@return void
*/
void Test_Send_Register_U3(void) {
	uint8_t data[] = {
		0b0000, 0b0000,
		0b0000, 0b0000,
		0b1111, 0b1111	// U3
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Test_Turn_Off_All_Lights,
		Test to insure that it is enabled to transmit data to the register and
		save specific bits into the storage. Tests that we can write on the whole register.
		The test accepted criteria are:
			All the LEDs on the IO shield should be off
@return void
*/
void Test_Turn_Off_All_Lights(void) {
	// Turn On All the Light
	uint8_t data[] = {
		0b1111, 0b1111,
		0b1111, 0b1111,
		0b1111, 0b1111
	};

	Send_Register_U1_U2_U3(data, register_size);
	HAL_Delay(1000);

	Turn_Off_All_Lights();
}

/**
@brief Test_PL2_Switch_Is_Hit,
		Test to insure that we can read the input from the SW7 and SW8 buttons in the IO shield.
		The test accepted criteria are:
			All of the light should be turned On when the SW7 or SW8 is pressed
@return void
*/
void Test_PL2_Switch_Is_Hit(void) {
	while(true) {
		if(PL2_Switch_Is_Hit()) {
			// Turn On All the Light
			uint8_t data[] = {
				0b1111, 0b1111,
				0b1111, 0b1111,
				0b1111, 0b1111
			};

			Send_Register_U1_U2_U3(data, register_size);
			HAL_Delay(10);
		}

		Turn_Off_All_Lights();
	}
}

/**
@brief Test_TL1_Car_Switch_Is_On,
		Test to insure that we can read the input from the SW1 switch in the IO shield.
		The test accepted criteria are:
			All of the light should be turned On when the SW1 is shifted to the ON state
@return void
*/
void Test_TL1_Car_Switch_Is_On(void) {
	while(true) {
		if(TL1_Car_Switch_Is_On()) {
			// Turn On All the Light
			uint8_t data[] = {
				0b1111, 0b1111,
				0b1111, 0b1111,
				0b1111, 0b1111
			};

			Send_Register_U1_U2_U3(data, register_size);
			HAL_Delay(10);
		}

		Turn_Off_All_Lights();
	}
}

/**
@brief Test_TL2_Car_Switch_Is_On,
		Test to insure that we can read the input from the SW2 switch in the IO shield.
		The test accepted criteria are:
			All of the light should be turned On when the SW2 is shifted to the ON state
@return void
*/
void Test_TL2_Car_Switch_Is_On(void) {
	while(true) {
		if(TL2_Car_Switch_Is_On()) {
			// Turn On All the Light
			uint8_t data[] = {
				0b1111, 0b1111,
				0b1111, 0b1111,
				0b1111, 0b1111
			};

			Send_Register_U1_U2_U3(data, register_size);
			HAL_Delay(10);
		}

		Turn_Off_All_Lights();
	}
}

/**
@brief Test_TL3_Car_Switch_Is_On,
		Test to insure that we can read the input from the SW3 switch in the IO shield.
		The test accepted criteria are:
			All of the light should be turned On when the SW3 is shifted to the ON state
@return void
*/
void Test_TL3_Car_Switch_Is_On(void) {
	while(true) {
		if(TL3_Car_Switch_Is_On()) {
			// Turn On All the Light
			uint8_t data[] = {
				0b1111, 0b1111,
				0b1111, 0b1111,
				0b1111, 0b1111
			};

			Send_Register_U1_U2_U3(data, register_size);
			HAL_Delay(10);
		}

		Turn_Off_All_Lights();
	}
}

/**
@brief Test_TL4_Car_Switch_Is_On,
		Test to insure that we can read the input from the SW4 switch in the IO shield.
		The test accepted criteria are:
			All of the light should be turned On when the SW4 is shifted to the ON state
@return void
*/
void Test_TL4_Car_Switch_Is_On(void) {
	while(true) {
		if(TL4_Car_Switch_Is_On()) {
			// Turn On All the Light
			uint8_t data[] = {
				0b1111, 0b1111,
				0b1111, 0b1111,
				0b1111, 0b1111
			};

			Send_Register_U1_U2_U3(data, register_size);
			HAL_Delay(10);
		}

		Turn_Off_All_Lights();
	}
}
