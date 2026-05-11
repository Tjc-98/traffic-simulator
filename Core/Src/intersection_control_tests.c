/**
******************************************************************************
@brief Test file to test the intersection control implementation that fulfills the requirements
@file intersection_control_tests.c
@author Berj Bedros
@version 1.0
******************************************************************************
*/

#include "intersection_control_tests.h"
#include "intersection_control.h"

/**
@brief Run_Intersection_Control_Tests, controls which tests are desired to be run.
@return void
*/
void Run_Intersection_Control_Tests(void) {
//	Test_West_East_Turn();
//	Test_West_East_Transition();
//	Test_North_South_Turn();
//	Test_North_South_Transition();
//	Test_No_Lane_Traffic_Allowed();
}

/**
@brief Test_West_East_Turn,
		Test to insure that the West/East street car lights are green. And the
		North/South lights are red.
		The test accepted criteria are:
			LED 3, 4, 9, 10 Should be turned ON
@return void
*/
void Test_West_East_Turn(void) {
	West_East_Turn();
}

/**
@brief Test_West_East_Transition,
		Test to insure that the West/East street car lights are orange. And the
		North/South lights are red.
		The test accepted criteria are:
			LED 2, 4, 8, 10 Should be turned ON
@return void
*/
void Test_West_East_Transition(void) {
	West_East_Transition();
}

/**
@brief Test_North_South_Turn,
		Test to insure that the North/South street car lights are green. And the
		West/East lights are red.
		The test accepted criteria are:
			LED 1, 6, 7, 12 Should be turned ON
@return void
*/
void Test_North_South_Turn(void) {
	North_South_Turn();
}

/**
@brief Test_North_South_Transition,
		Test to insure that the North/South street car lights are orange. And the
		West/East lights are red.
		The test accepted criteria are:
			LED 1, 5, 7, 11 Should be turned ON
@return void
*/
void Test_North_South_Transition(void) {
	North_South_Transition();
}

/**
@brief Test_No_Lane_Traffic_Allowed,
		Test to insure that the North/South and West/East streets car lights are red.
		The test accepted criteria are:
			LED 1, 4, 7, 10 Should be turned ON
@return void
*/
void Test_No_Lane_Traffic_Allowed(void) {
	No_Lane_Traffic_Allowed();
}
