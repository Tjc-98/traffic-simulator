/**
******************************************************************************
@brief Header file for the functions that will enable to achieve the
		requirement of intersection traffic control
@file intersection_control.h
@author Berj Bedros
@version 1.0
******************************************************************************
*/

#include "stdint.h"

#ifndef INC_INTERSECTION_CONTROL_H_
#define INC_INTERSECTION_CONTROL_H_

typedef enum {
	Start,
	WE,
	NS
} traffic_state; // Represents the turn that is possible for the traffic street lights.

void Run_Intersection_Control(void);
void West_East_Turn(void);
void West_East_Transition(void);
void North_South_Turn(void);
void North_South_Transition(void);
void No_Lane_Traffic_Allowed(void);
void Set_Lane_Traffic(traffic_state set_state, uint32_t orange_delay);
void Initialize_Traffic(uint32_t orange_delay, uint32_t green_delay);

#endif /* INC_INTERSECTION_CONTROL_H_ */
