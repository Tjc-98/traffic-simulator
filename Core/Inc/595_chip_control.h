/**
******************************************************************************
@brief Header file for the functions to control the 74HC595D inputs
@file 595_chip_control.h
@author Berj Bedros
@version 1.0
******************************************************************************
*/
#ifndef INC_595_CHIP_CONTROL_H_
#define INC_595_CHIP_CONTROL_H_

void Set_595_Reset_Pin(void);
void Reset_595_Reset_Pin(void);

void Set_595_Latch(void);
void Reset_595_Latch(void);

void Enable_Shift_Register(void);
void Disable_Shift_Register(void);

#endif /* INC_595_CHIP_CONTROL_H_ */
