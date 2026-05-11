/**
******************************************************************************
@brief Pedestrian Crossing Control, functions to achieve the pedestrian crossing requirements
@file pedestrian_crossing.c
@author Berj Bedros
@version 1.0
@brief contains the functions to turn and transit between the street and pedestrian
		turns, implementing the behavior for the pedestrian crossing control
******************************************************************************
*/

#include "stdint.h"
#include "stdbool.h"

#include "stm32l4xx.h"

#include "pedestrian_crossing.h"
#include "tasks_common_func.h"
#include "io_shield_func.h"

extern const int register_size;

/**
@brief Toggle_Freq, the time it takes to the pedestrian buttons to take affect.
@param uint32_t toggle_freq, the time in seconds to make the switch.
@return void
*/
void Toggle_Freq(uint32_t toggle_freq) {
	HAL_Delay(toggle_freq);
}

/**
@brief Pedestrian_Delay, the time it takes to the pedestrian transition from
		or to green to take affect.
@param uint32_t pedestrian_delay, the time in seconds to make the transition.
@return void
*/
void Pedestrian_Delay(uint32_t pedestrian_delay) {
	HAL_Delay(pedestrian_delay);
}

/**
@brief Walking_Delay, the time the light stays green for the pedestrian to walk.
@param uint32_t walking_delay, the time in seconds the pedestrian light stays green.
@return void
*/
void Walking_Delay(uint32_t walking_delay) {
	HAL_Delay(walking_delay);
}

/**
@brief No_Traffic_Allowed, send the proper bits to turn on the red lights for the North/South
		street and the pedestrian walk path. Specifically LED 4, 10, 19, 20.
@return void
*/
void No_Traffic_Allowed(void) {
	uint8_t data[] = {
		0b0000, 0b0000,
		0b0000, 0b1001,	// LED 19,20 - LED 4
		0b0000, 0b1000	// LED 10
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Allow_Cars_Turn, send the proper bits to turn on the green lights for the North/South
		street and the red light for pedestrian walk path. Specifically LED 6, 12, 19, 20.
@return void
*/
void Allow_Cars_Turn(void) {
	uint8_t data[] = {
		0b0000, 0b0000,
		0b0000, 0b1100,	// LED 19,20 - LED 6
		0b0010, 0b0000	// LED 12
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Cars_Turn_Transition, send the proper bits to turn on the orange lights for the North/South
		street and the red lights for the pedestrian walk path. Specifically LED 5, 11, 19, 20.
@return void
*/
void Cars_Turn_Transition(void) {
	uint8_t data[] = {
		0b0000, 0b0000,
		0b0000, 0b1010,	// LED 19,20 - LED 5
		0b0001, 0b0000	// LED 11
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Allow_Pedestrians_Turn, send the proper bits to turn on the red lights for the North/South
		street and the green light for pedestrian walk path. Specifically LED 4, 10, 21, 22.
@return void
*/
void Allow_Pedestrians_Turn(void) {
	uint8_t data[] = {
		0b0000, 0b0000,
		0b0001, 0b0001,	// LED 21,22 - LED 4
		0b0000, 0b1000	// LED 10
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Pedestrian_Switch_Clicked, the steps needed to transition from the turn of the cars to the
		pedestrians turn when a pedestrian clicks on the pedestrian button.
@param uint32_t toggle_freq, the time in seconds to make the switch to pedestrian turn.
		uint32_t pedestrian_delay, the time in seconds to make the transition for pedestrian turn.
		uint32_t walking_delay, the time in seconds the pedestrian light stays green.
		uint32_t orange_delay, the time in seconds to make the orange transition.
@return void
*/
void Pedestrian_Switch_Clicked(int toggle_freq, int pedestrian_delay, int walking_delay, int orange_delay) {
	Toggle_Freq(toggle_freq);
	Cars_Turn_Transition();
	Orange_Delay(orange_delay);
	No_Traffic_Allowed();
	Pedestrian_Delay(pedestrian_delay);
	Allow_Pedestrians_Turn();
	Walking_Delay(walking_delay);
	No_Traffic_Allowed();
	Pedestrian_Delay(pedestrian_delay);
	Cars_Turn_Transition();
	Orange_Delay(orange_delay);
	Allow_Cars_Turn();
}

/**
@brief Run_Pedestrian_Crossing, runs all the needed pieces to fulfill the requirements of the pedestrian crossing control.
		Starts with the initialized state with car light green and pedestrian lights red.
@return void
*/
void Run_Pedestrian_Crossing(void) {
	Turn_Off_All_Lights();
	Allow_Cars_Turn();

	int toggle_freq = 3000;
	int pedestian_delay = 2000;
	int walking_delay = 5000;
	int orange_delay = 3000;

	while(true) {
		if(PL2_Switch_Is_Hit() == true) {
			Pedestrian_Switch_Clicked(toggle_freq, pedestian_delay, walking_delay, orange_delay);
		}
	}
}
