#ifndef JOYSTICK_H
#define JOYSTICK_H

// bseoin d'inclure JoyInit dans le setup
// dans le loop appeler JoyPrint

#include <Arduino.h>
#include <stdbool.h>

#define pinX 8//nb 
#define pinY 10//nb

float maxX = 100;  // À modifier et rentrer la valeur maximal de X  
float maxY = 200;  // À modifier et rentrer la valeur maximal de Y


void JoyInit(){
    pinMode(pinX, INPUT); //entré x
    pinMode(pinY, INPUT); //entrée y 
}

float cordX(){
    float joyX = analogRead(pinX);
    return (joyX/maxX);     //change les valeur pour etre entre -1 et 1
}

float cordY(){
    float joyY = analogRead(pinY);
    return (joyY/maxY);     //change les valeur pour etre entre -1 et 1
}

float JoyCalibX(){
    float joyX = analogRead(pinX);
    Serial.print(joyX);             // a utiliser pour le max X
}

float JoyCalibY(){
    float joyY = analogRead(pinY);
    Serial.print(joyY);             // a utiliser pour le max Y
}


void JoyPrintCalib(){
    Serial.print("X Calib");
    Serial.print(JoyCalibX());    //print les valeur entre -1 et 1 de X
    Serial.print("Y Calib");
    Serial.print(JoyCalibY());    //print les valeur entre -1 et 1 de Y

}

void JoyPrint(){
    Serial.print("X");
    Serial.print(JoyCalibX());
    Serial.print("y");
    Serial.print(JoyCalibX());
}

void JoyCom(){
// je ne sais pas encore comment faire la comunication encore
}


#endif