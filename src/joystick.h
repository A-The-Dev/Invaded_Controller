#ifndef JOYSTICK_H
#define JOYSTICK_H

// bseoin d'inclure JoyInit dans le setup
// dans le loop appeler JoyPrint

#define pinX 8//nb 
#define pinY 10// 



void JoyInit();
float cordX();
float cordY();
float JoyCalibX();
float JoyCalibY();
void JoyPrintCalib();
void JoyPrint();
void JoyCom();


#endif