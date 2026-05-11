/**
******************************************************************************
@brief Header file to test the functionality of the IO shield
@file io_shield_func_tests.h
@author Berj Bedros
@version 1.0
******************************************************************************
*/

#ifndef INC_IO_SHIELD_FUNC_TESTS_H_
#define INC_IO_SHIELD_FUNC_TESTS_H_

void Run_IO_Shield_Func_Tests(void);
void Test_Send_Register_U1(void);
void Test_Send_Register_U2(void);
void Test_Send_Register_U3(void);

void Test_Turn_Off_All_Lights(void);

void Test_PL2_Switch_Is_Hit(void);
void Test_TL1_Car_Switch_Is_On(void);
void Test_TL2_Car_Switch_Is_On(void);
void Test_TL3_Car_Switch_Is_On(void);
void Test_TL4_Car_Switch_Is_On(void);

#endif /* INC_IO_SHIELD_FUNC_TESTS_H_ */
