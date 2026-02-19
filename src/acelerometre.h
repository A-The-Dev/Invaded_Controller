#include <stdio.h>
#include <string.h>
#include <Arduino.h>

int pin_valeur_x = A0;
int pin_valeur_y = A1;
int pin_valeur_z = A2;



int threshold_haut_z = 420; 
int threshold_bas_z = 370;

int threshold_gauche_y = 350;
int threshold_droite_y = 325;

int threshold_avant_x = 360;
int threshold_arriere_x = 315;

void setup_accelerometre()
{
    // code d'initialisation de l'accelerometre
    int ValeurZ = analogRead(pin_valeur_z);
    int ValeurY = analogRead(pin_valeur_y);
    //Serial.println(ValeurY);
    int ValeurX = analogRead(pin_valeur_x);
    //Serial.println(ValeurX);
    
    //Serial.println(ValeurZ);

    //Valeur en Z

  if (ValeurZ > threshold_haut_z) {
    Serial.println("Mouvement monte detecte");
    Serial.print("Valeur Z: ");
    Serial.println(ValeurZ);
    delay(200);
    }
  if (ValeurZ < threshold_bas_z) {
    Serial.println("Mouvement descendre detecte");
    Serial.print("Valeur Z: ");
    Serial.println(ValeurZ);
    delay(200);
    }

      //valeur en y

  if (ValeurY < threshold_droite_y) {
    Serial.println("Mouvement droite detecte");
    Serial.print("Valeur Y: ");
    Serial.println(ValeurY);
    delay(200);
    }
  if (ValeurY > threshold_gauche_y) {
    Serial.println("Mouvement gauche detecte");
    Serial.print("Valeur Y: ");
    Serial.println(ValeurY);
    delay(200);
    }

      //valeur en x

  if (ValeurX > threshold_avant_x) {
    Serial.println("Mouvement avant detecte");
    Serial.print("Valeur X: ");
    Serial.println(ValeurX);
    delay(200);
    }
  if (ValeurX < threshold_arriere_x) {
    Serial.println("Mouvement arriere detecte");
    Serial.print("Valeur X: ");
    Serial.println(ValeurX);
    delay(200);
    }
  
    delay(200);
}
