#include <stdio.h>
#include <string.h>
#include <Arduino.h>

int pin_bouton1 = 50; 
int pin_bouton2 = 51;
int pin_bouton3 = 52;

void setup_bouton()
{
  // code d'initialisation des boutons
    //Serial.println(analogRead(pin_bouton1)); //600
    //Serial.println(analogRead(pin_bouton2)); //600
    //Serial.println(analogRead(pin_bouton3)); //600
    if ( digitalRead(pin_bouton1) == true ) {
        Serial.println("We are Charly Kirk");
        delay(100);
    }
    if ( digitalRead(pin_bouton2) == true ) {
        Serial.println("We carry the flame");
        delay(100);
    }
    if ( digitalRead(pin_bouton3) == true ) {
        Serial.println("We fight for the gospel");
        delay(100);
    }

    delay(200);

}