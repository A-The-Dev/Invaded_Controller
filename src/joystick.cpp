
#include <Arduino.h>
#include <stdbool.h>
#include <joystick.h>


float milieuX ;  // valeur de calibration X (apres setup)
float milieuY ;  // valeur de calibration Y (apres setup)


void JoyInit(){
    pinMode(pinX, INPUT); //entré x
    pinMode(pinY, INPUT); //entrée y
    
    milieuX = JoyCalibX();
    milieuY = JoyCalibY(); 
}

//permet de calibrer le Joystick en Y
float JoyCalibY(){
    float valeurJoy;
    float add;
    float joyCalib;
    for(int i ; i <= 5; i++){
        valeurJoy = analogRead(pinY);
        add = add + valeurJoy;
    }
    joyCalib = add/5; 

    return joyCalib;    //retourne la moyenne des reads obtenue
}

//permet de calibrer le joystick en X
float JoyCalibX(){
    float valeurJoy;
    float add;
    float joyCalib;
    for(int i ; i <= 5; i++){
        valeurJoy = analogRead(pinX);
        add = add + valeurJoy;
    }
    joyCalib = add/5; 

    return joyCalib;      //retourne la moyenne des reads obtenue     
}

// permet de lire le potentiometre X et de le tranformer sur une page de valeur entre -1 et 1 dependament de la calibration du setup
float cordX(){
    float joy = analogRead(pinX);
    if(joy < (milieuX - deadZone)){
         return -((milieuX - deadZone - joy) / (milieuX - deadZone)); // retourne entre -1 et 0
    }
    else if(joy > (milieuX + deadZone)){
        return (joy - (milieuX + deadZone)) / (1023.0 - (milieuX + deadZone)); // retourne entre 0 et 1
    }
    else{
        return 0;
    }
}

float cordY(){
    float joy = analogRead(pinY);
    if(joy < (milieuY - deadZone)){
         return -((milieuY - deadZone - joy) / (milieuY - deadZone)); // retourne entre -1 et 0
    }
    else if(joy > (milieuY + deadZone)){
        return (joy - (milieuY + deadZone)) / (1023.0 - (milieuY + deadZone)); // retourne entre 0 et 1
    }
    else{
        return 0;
    }
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