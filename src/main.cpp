
#include <Arduino.h>
#include "acelerometre.h"
#include "bouton.h"
#include "incremental.h"
#include "potentiometre.h"
#include "joystick.h"
#include "LED.h"
#include "Ecran.h"
#include "CommunicationArduino.h"
#include "7seg.h"
#include "compteurmuons.h"

int lastValue = 0;
int menu = 0;
int derniere_valeur = 4;
int pinledR = 34;
int pinEnvoieArduino1 = 36;
int pinEnvoieArduino2 = 38;
int boss =0;


void setup()
{
  CommunicationArduino_setup();
  //Serial.begin(115200);
  //init_Ecran();
  setup_setup_bouton();
  init_7seg();
  init_Timer5();
  //Serial.print("Debut de l'initialisation de l'accelerometre");
  //setup_encoder(2, 3);  // use interrupt pin 2 for channel A and pin 3 for channel B
  JoyInit();
  //setup_LED();
  //Affichage_boss(2);
  ///TestDanick();
  pinMode(pinledR, OUTPUT);
  digitalWrite(pinledR, true);
  pinMode(pinEnvoieArduino1, OUTPUT);
  pinMode(pinEnvoieArduino2, OUTPUT);
  setupmuons();

}

void loop()
{
  
  sendMsg();
  if (Serial.available() > 0) {
    boss =readMsg();
  }
  
  if (boss == 0){
    digitalWrite(pinEnvoieArduino1, false);
    digitalWrite(pinEnvoieArduino2, false);
  }
  else if (boss == 1){
    digitalWrite(pinEnvoieArduino1, true);
    digitalWrite(pinEnvoieArduino2, false);
  }
  else if (boss == 2){
    digitalWrite(pinEnvoieArduino1, false);
    digitalWrite(pinEnvoieArduino2, true);
  }
  else if (boss == 3){
    digitalWrite(pinEnvoieArduino1, true);
    digitalWrite(pinEnvoieArduino2, true);
  } 
  //Serial.println(1);
}




/* endoffile */