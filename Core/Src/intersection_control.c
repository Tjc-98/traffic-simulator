/**
******************************************************************************
@brief Intersection Traffic Control, functions to achieve the intersection control requirements
@file intersection_control.c
@author Berj Bedros
@version 1.0
@brief contains the functions to turn and transit between the cross streets
		turns, implementing the behavior for the intersection traffic control
******************************************************************************
*/

#include "stdint.h"
#include "stdbool.h"

#include "stm32l4xx.h"

#include "intersection_control.h"
#include "tasks_common_func.h"
#include "io_shield_func.h"

extern const int register_size;

static traffic_state previous_state, current_state;

/**
@brief Green_Delay, the time that the cars light stays green.
@param uint32_t toggle_freq, the time in seconds for the green period.
@return void
*/
void Green_Delay(uint32_t green_delay) {
	HAL_Delay(green_delay);
}

/**
@brief West_East_Turn, send the proper bits to turn on the green lights for the West/East
		street and the red light for the North/South street. Specifically LED 3, 4, 9, 10.
@return void
*/
void West_East_Turn(void) {
	uint8_t data[] = {
		0b0000, 0b0100,	// LED 3
		0b0000, 0b0001,	// LED 4
		0b0000, 0b1100	// LED 10 - LED 9
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief West_East_Transition, send the proper bits to turn on the orange lights for the West/East
		street and the red light for the North/South street. Specifically LED 2, 4, 8, 10.
@return void
*/
void West_East_Transition(void) {
	uint8_t data[] = {
		0b0000, 0b0010,	// LED 2
		0b0000, 0b0001,	// LED 4
		0b0000, 0b1010	// LED 10 - LED 8
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief North_South_Turn, send the proper bits to turn on the green lights for the North/South
		street and the red light for the West/East street. Specifically LED 1, 6, 7, 12.
@return void
*/
void North_South_Turn(void) {
	uint8_t data[] = {
		0b0000, 0b0001,	// LED 1
		0b0000, 0b0100,	// LED 6
		0b0010, 0b0001	// LED 12 - LED 7
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief North_South_Transition, send the proper bits to turn on the orange lights for the North/South
		street and the red light for the West/East street. Specifically LED 1, 5, 7, 11.
@return void
*/
void North_South_Transition(void) {
	uint8_t data[] = {
		0b0000, 0b0001,	// LED 1
		0b0000, 0b0010,	// LED 5
		0b0001, 0b0001	// LED 11 - LED 7
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief No_Lane_Traffic_Allowed, send the proper bits to turn on the red lights for both
		streets West/East and North/South. Specifically LED 1, 4, 7, 10.
@return void
*/
void No_Lane_Traffic_Allowed(void) {
	uint8_t data[] = {
		0b0000, 0b0001,	// LED 1
		0b0000, 0b0001,	// LED 4
		0b0000, 0b1001	// LED 10 - LED 7
	};

	Send_Register_U1_U2_U3(data, register_size);
}

/**
@brief Set_Lane_Traffic, do the change for the traffic light turns between the streets.
		The change would have the right transition from and to the other turns.
@param traffic_state set_state, the traffic turn to change and transit into.
		uint32_t orange_delay, the time in seconds to make the orange transition.
@return void
*/
void Set_Lane_Traffic(traffic_state set_state, uint32_t orange_delay) {
	switch(set_state) {
		case Start:
			No_Lane_Traffic_Allowed();
			HAL_Delay(1500);
			North_South_Transition();
			Orange_Delay(orange_delay);
			North_South_Turn();
			break;
		case WE:
			North_South_Transition();
			Orange_Delay(orange_delay);
			No_Lane_Traffic_Allowed();
			Orange_Delay(orange_delay);
			West_East_Transition();
			Orange_Delay(orange_delay);
			West_East_Turn();
			break;
		case NS:
			West_East_Transition();
			Orange_Delay(orange_delay);
			No_Lane_Traffic_Allowed();
			Orange_Delay(orange_delay);
			North_South_Transition();
			Orange_Delay(orange_delay);
			North_South_Turn();
			break;
		default:
			break;
	}
}

/**
@brief Initialize_Traffic, sets the start state for the traffic. The North/South street
		lights are set to green and the West/East street lights are set to red.
@param uint32_t toggle_freq, the time in seconds to make the toggle.
@return void
*/
void Initialize_Traffic(uint32_t orange_delay, uint32_t green_delay) {
	current_state = Start;

	Set_Lane_Traffic(current_state, orange_delay);
	Green_Delay(green_delay);

	current_state = NS;
}

/**
@brief Run_Intersection_Control, runs all the needed pieces to fulfill the requirements of the intersection control.
		Starts with a specific the initialized state.
@return void
*/
void Run_Intersection_Control(void) {
	Turn_Off_All_Lights();

	int orange_delay = 2000;
	int green_delay = 4000;

	Initialize_Traffic(orange_delay, green_delay);

	while(true) {
		previous_state = current_state;

		if((TL1_Car_Switch_Is_On() == true || TL3_Car_Switch_Is_On() == true) &&
			(TL2_Car_Switch_Is_On() == true || TL4_Car_Switch_Is_On() == true)) {
			if(current_state == WE) {
				current_state = NS;
			} else {
				current_state = WE;
			}
		} else if(TL1_Car_Switch_Is_On() == true || TL3_Car_Switch_Is_On() == true) {
			current_state = WE;
		} else if(TL2_Car_Switch_Is_On() == true || TL4_Car_Switch_Is_On() == true) {
			current_state = NS;
		} else {
			if(current_state == WE) {
				current_state = NS;
			} else {
				current_state = WE;
			}
		}

		if(current_state == previous_state) {
			Green_Delay(green_delay);
			continue;
		}

		Set_Lane_Traffic(current_state, orange_delay);
		Green_Delay(green_delay);

	}
}
