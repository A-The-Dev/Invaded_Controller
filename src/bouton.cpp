#include <stdio.h>
#include <string.h>
#include <Arduino.h>
#include "bouton.h"

int pin_bouton1 = 22; 
int pin_bouton2 = 24;
int pin_bouton3 = 26;
int pin_bouton4 = 28;
void setup_setup_bouton()
{
  pinMode(pin_bouton1, INPUT_PULLUP);
  pinMode(pin_bouton2, INPUT_PULLUP);
  pinMode(pin_bouton3, INPUT_PULLUP);
  pinMode(pin_bouton4, INPUT_PULLUP);
}

int setup_bouton()
{
  
    if ( digitalRead(pin_bouton1) == false ) {
        //Serial.println("We are Charly Kirk");
        return 1;
    }
    if ( digitalRead(pin_bouton2) == false ) {
        //Serial.println("We carry the flame");
        return 2;
    }
    if ( digitalRead(pin_bouton3) == false ) {
        //Serial.println("We fight for the gospel");
        return 3;
    }
    if ( digitalRead(pin_bouton4) == false ) {
        //Serial.println("We honor his name");
        return 4;
    }

    return 0;

}