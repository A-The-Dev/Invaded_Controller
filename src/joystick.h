#ifndef JOYSTICK_H
#define JOYSTICK_H

// bseoin d'inclure JoyInit dans le setup
// pour les tests appeler JoyTest()
// dans le loop principale appeler JoyCom()


#define pinY A4 //Axe vertical Axe y 
#define pinX A5 //Axe horizontale Axe X
#define deadZone 5 // valeur pour garder le 0 en place a l'entour de la valeur calibre

//fonction pour set up
float JoyCalibX();
float JoyCalibY();
void JoyInit();

//fonction pour les modification
float cordX();
float cordY();

//fonction de test
void JoyPrintCalib();
void JoyPrint();

//fonction de comunication
void JoyCom();

#endif