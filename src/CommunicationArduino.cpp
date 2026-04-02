/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
 * Modif : Janvier 2025, 115200 BAUDS, JpGouin
*/

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include "ArduinoJson.h"
#include "bouton.h"
#include "LED.h"
#include "encodeur.h"
#include "joystick.h"
#include "Ecran.h"
#include "7seg.h"
#include "acelerometre.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h> 
/*------------------------------ Constantes ---------------------------------*/

#define BAUD 115200        // Frequence de transmission serielle

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message

int ledState = 0;
int potValue = 0;
int pinLED = 32;
int flag_boss = 0;


/*------------------------- Prototypes de fonctions -------------------------*/


/*---------------------------- Fonctions "Main" -----------------------------*/

void CommunicationArduino_setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, ledState);
}
/*
Boucle principale (infinie)
void loop() {

  if(shouldRead_){
    readMsg();
    sendMsg();
  }

  potValue = analogRead(pinPOT);
  //Serial.println(potValue);          // debug
  delay(10);  // delais de 10 ms
}
*/

/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg() {
  StaticJsonDocument<500> doc;
  
  int boutonactif = setup_bouton();
  
  doc["bouton1"] = (boutonactif == 1);
  doc["bouton2"] = (boutonactif == 2);
  doc["bouton3"] = (boutonactif == 3);
  doc["bouton4"] = (boutonactif == 4);
  //doc["zoom"] = calculzoom();
  doc["accel"] = (module_accelerometre() == 1);
  doc["direction"] = cordX();
  doc["vitesse"] = cordY();

  // Envoie systématique (ou conditionnel selon ton besoin)
  serializeJson(doc, Serial);
  Serial.println();
  // delais de 10 ms

  /*
  // Elements du message
  
  doc["time"] = millis();
  doc["analog"] = potValue;

  // Serialisation
  if (shouldSend_) {
    serializeJson(doc, Serial);
  // Envoie
    Serial.println();
    shouldSend_ = false;
  
  }
  */
 
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
int readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  /*
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  */
  // Analyse des éléments du message message
  parse_msg = doc["delB"];
  if (!parse_msg.isNull()) {
 
   // mettre la led a la valeur doc["led"]
    digitalWrite(pinLED,doc["delB"].as<bool>());
  }
  
  parse_msg = doc["ecran"];

  int boss = 0;
  if (!parse_msg.isNull()) {
    // afficher doc["ecran"] sur l'ecran (nom boss + contour rouge)
    boss = doc["ecran"];
  }
  
  /*
    if (flag_boss != boss){
      flag_boss = boss;
    
    
  }
      */

  parse_msg = doc["niveau"];
  if (!parse_msg.isNull()) {
    AfficherUnDigit(2, parse_msg.as<int>());
    //Affichage7Seg(2, parse_msg.as<int>());
    // afficher doc["7seg"] sur le 7seg
  }
    //AfficherUnDigit(2, 2);
  return boss;
}