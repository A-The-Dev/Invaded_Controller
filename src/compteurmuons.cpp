#include <Arduino.h>

int valdetecte = 0;
int pinmuons = A7;
int compteur = 0;
void setupmuons() {
  pinMode(pinmuons, INPUT);
}

bool detection_muons(){
    valdetecte = analogRead(pinmuons);
    if (valdetecte > 610) {
        Serial.println(valdetecte);
        compteur++;
        if (compteur >= 20){
            compteur = 0;
            return true;
        }
    }
    return false;
    
    //Serial.println(valdetecte);
}