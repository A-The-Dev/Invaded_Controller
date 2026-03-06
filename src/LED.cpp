#include <stdio.h>
#include <string.h>
#include <Arduino.h>
#include "LED.h"

int rouge = 22;
int vert = 28;
int bleu = 24;
int blanc = 25;


void setup_LED()
{
  pinMode(rouge, OUTPUT);
  pinMode(vert, OUTPUT);
  pinMode(bleu, OUTPUT);
  pinMode(blanc, OUTPUT);
}

int LED_allumer(int couleur)
{
  if (couleur == 1){
    digitalWrite(rouge, true);
    return 1;
  }
  if (couleur == 2){
    digitalWrite(bleu, true);
    return 2;
  }
  if (couleur == 3){
    digitalWrite(vert, true);
    return 3;
  }
  if (couleur == 4){
    digitalWrite(blanc, true);
    return 4;
  }
  
}

int LED_eteindre(int couleur)
{
  if (couleur == 1){
    digitalWrite(rouge, false);
    return 1;
  }
  if (couleur == 2){
    digitalWrite(bleu, false);
    return 2;
  }
  if (couleur == 3){
    digitalWrite(vert, false);
    return 3;
  }
  if (couleur == 4){
    digitalWrite(blanc, false);
    return 4;
  }
  
}