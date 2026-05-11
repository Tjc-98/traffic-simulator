/**
******************************************************************************
@brief Test file to test the pedestrian crossing control implementation that fulfills the requirements
@file pedestrian_crossing_tests.c
@author Berj Bedros
@version 1.0
******************************************************************************
*/

#include "pedestrian_crossing_tests.h"
#include "pedestrian_crossing.h"

/**
@brief Run_Pedestrian_Crossing_Tests, controls which tests are desired to be run.
@return void
*/
void Run_Pedestrian_Crossing_Tests(void) {
//	Test_No_Traffic_Allowed();
//	Test_Allow_Cars_Turn();
//	Test_Cars_Turn_Transition();
//	Test_Allow_Pedestrians_Turn();
}

/**
@brief Test_Allow_Cars_Turn,
		Test to insure that the North/South street car lights are green. And the
		pedestrian lights are red.
		The test accepted criteria are:
			LED 6, 12, 19, 20 Should be turned ON
@return void
*/
void Test_Allow_Cars_Turn(void) {
	Allow_Cars_Turn();
}

/**
@brief Test_Cars_Turn_Transition,
		Test to insure that the North/South street car lights are orange. And the
		pedestrian lights are red.
		The test accepted criteria are:
			LED 5, 11, 19, 20 Should be turned ON
@return void
*/
void Test_Cars_Turn_Transition(void) {
	Cars_Turn_Transition();
}

/**
@brief Test_No_Traffic_Allowed,
		Test to insure that the North/South street car lights and the
		pedestrian lights are red.
		The test accepted criteria are:
			LED 4, 10, 19, 20 Should be turned ON
@return void
*/
void Test_No_Traffic_Allowed(void) {
	No_Traffic_Allowed();
}

/**
@brief Test_Allow_Pedestrians_Turn,
		Test to insure that the North/South street car lights are red. And the
		pedestrian lights are green.
		The test accepted criteria are:
			LED 4, 10, 21, 22 Should be turned ON
@return void
*/
void Test_Allow_Pedestrians_Turn(void) {
	Allow_Pedestrians_Turn();
}
