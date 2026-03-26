#include <stdio.h>
#include <string.h>
#include <Arduino.h>
#include <math.h>
#include "acelerometre.h"

int pin_valeur_x = A2;
int pin_valeur_y = A1;
int pin_valeur_z = A0;

int threshold_gauche_y = 350;
int threshold_droite_y = 310;

int setup_accelerometre()
{
  int ValeurY = analogRead(pin_valeur_y);
   
  if (ValeurY < threshold_droite_y) {
    Serial.println("Rotation antihoraire");
    return 0;
  }

  if (ValeurY > threshold_gauche_y) {
    Serial.println("Rotation horaire");
    return 1;
  }

  delay(200);
  return -1;
}

int module_accelerometre()
{
  int ValeurZ = (analogRead(pin_valeur_z) - 423);
  int ValeurY = (analogRead(pin_valeur_y) - 345);
  int ValeurX = (analogRead(pin_valeur_x) - 350);
  //Serial.println(ValeurX);
 // Serial.println(ValeurY);
 // Serial.println(ValeurZ);
  float modu = sqrt(square(ValeurX) + square(ValeurY) + square(ValeurZ));
  //Serial.println(modu);
  if (modu > 200){
    return 1;
  }
  return 0;

}