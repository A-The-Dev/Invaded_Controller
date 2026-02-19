#include <stdio.h>
#include <string.h>
#include <Arduino.h>

int pin_valeur_x = 0;
int pin_valeur_y = 0;
int pin_valeur_z = A1;



int threshold_haut = 455; 
int threshold_bas = 370;

int compteur = 0;

void setup_accelerometre()
{
    // code d'initialisation de l'accelerometre
    //analogRead(pin_valeur_x);
    //analogRead(pin_valeur_y);
    int ValeurZ = analogRead(pin_valeur_z);
    
    //Serial.println(ValeurZ);

  if (ValeurZ > threshold_haut || ValeurZ < threshold_bas) {
    if (compteur == 1){
      Serial.println("Mouvement detecte");
    }
    if (compteur == 2) {
                Serial.println("Mouvement detecte");
                Serial.print("Valeur Z: ");
                Serial.println(ValeurZ);
                compteur = 0;
            }
      compteur++;
    }
    delay(300);
}
