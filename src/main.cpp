
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

int lastValue = 0;
int menu = 0;
int derniere_valeur = 4;
int pinledR = 34;
void setup()
{
  CommunicationArduino_setup();
  //Serial.begin(115200);
  init_Ecran();
  setup_setup_bouton();
  init_7seg();
  //init_Timer5();
  //Serial.print("Debut de l'initialisation de l'accelerometre");
  //setup_encoder(2, 3);  // use interrupt pin 2 for channel A and pin 3 for channel B
  JoyInit();
  //setup_LED();
  //Affichage_boss(2);
  ///TestDanick();
  pinMode(pinledR, OUTPUT);
  digitalWrite(pinledR, true);
}

void loop()
{
  //Affichage_boss(1);
  sendMsg();
  if (Serial.available()) {
  readMsg();
}
  //if (Serial.available() > 0) {
   // readMsg();
  //}
  
}


/* endoffile */