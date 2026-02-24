#include <stdio.h>
#include <string.h>
#include <Arduino.h>

int pin_valeur = A10;
int Max_valeur= 10000;

void potentiometre()
{
    
   
    float Valeur_pot = analogRead(pin_valeur)/930.0*Max_valeur/1000.0;
    Serial.println(Valeur_pot, 3); //on affiche valeur pot en k genre 1.2k

}
