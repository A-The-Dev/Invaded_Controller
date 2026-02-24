#include <stdio.h>
#include <string.h>
#include <Arduino.h>

int pin_bouton1 = 41; 
int pin_bouton2 = 42;
int pin_bouton3 = 43;
int pin_bouton4 = 44;

int setup_bouton()
{
  // code d'initialisation des boutons
    //Serial.println(analogRead(pin_bouton1)); //600
    //Serial.println(analogRead(pin_bouton2)); //600
    //Serial.println(analogRead(pin_bouton3)); //600
    if ( digitalRead(pin_bouton1) == true ) {
        Serial.println("We are Charly Kirk");
        delay(100);
        return 1;
    }
    if ( digitalRead(pin_bouton2) == true ) {
        Serial.println("We carry the flame");
        delay(100);
        return 2;
    }
    if ( digitalRead(pin_bouton3) == true ) {
        Serial.println("We fight for the gospel");
        delay(100);
        return 3;
    }
    if ( digitalRead(pin_bouton4) == true ) {
        Serial.println("We honor his name");
        delay(100);
        return 4;
    }

    delay(200);
    return 0;

}