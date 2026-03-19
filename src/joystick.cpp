
#include <Arduino.h>
#include <stdbool.h>
#include <joystick.h>
#include <math.h>


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

//permet de voir l'orientation
float angle(){

    float x = cordX();
    float y = cordY();

    return atan2(y, x) * 180 / PI;
}

//permet de voir la vitesse
float hypotenuse(){

    float x = cordX();
    float y = cordY();

    return sqrt(x*x + y*y)/sqrt(2);
}

void JoyPrintTestCalib(){
    Serial.print("X Calib: ");
    Serial.print(JoyCalibX());    //print la valeur de calibration X
    Serial.print("\n X read: ");
    Serial.print(analogRead(pinX)); //print ce qu'on voit
    Serial.print("\n X milieu: ");
    Serial.print(milieuX);      // print le milieu lors de la calibration
    Serial.print("\n \n");


    Serial.print("Y Calib:");
    Serial.print(JoyCalibX());    //print les valeur de calibration Y
    Serial.print("\n Y read:");
    Serial.print(analogRead(pinY)); //print ce qu'on voit
    Serial.print("\n Y milieu");
    Serial.print(milieuY);      // print le milieu lors de la calibration
    Serial.print("\n \n");
}

void JoyPrintTestModif(){
    Serial.print("\n X read: ");
    Serial.print(analogRead(pinX)); // print le read X
    Serial.print("\n X Cord: "); 
    Serial.print(cordX()); // print la valeur entre -1 et 1 de X

    Serial.print("\n Y read: ");
    Serial.print(analogRead(pinY)); // print le read Y
    Serial.print("\n Y Cord: ");
    Serial.print(cordY()); // print la valeur entre -1 et 1 de Y

    Serial.print("\n angle: ");
    Serial.print(angle()); // print le read Y
    Serial.print("\n hypotenuse: ");
    Serial.print(hypotenuse()); // print la valeur entre -1 et 1 de Y

}

void JoyPrintTestCom(){

}

void JoyCom(){
// je ne sais pas encore comment faire la comunication
}