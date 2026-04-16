#include <Arduino.h>

 
int tresholdmuon = 0;
int valdetecte = 0;
int pinmuons = A7;
int compteur = 0;
 

 
float muonCalib(){
    float valeurmuon;
    float add = 0;
    float muonCalib;
    for(int i = 0 ; i < 10; i++){
        valeurmuon = analogRead(pinmuons);
        add = add + valeurmuon;
    }
    muonCalib = add/10.0;
 
    return muonCalib+6;    //retourne la moyenne des reads obtenue
}


 void setupmuons() {
  pinMode(pinmuons, INPUT);
 
  tresholdmuon = muonCalib();
 
}
 
bool detection_muons(){
    valdetecte = analogRead(pinmuons);
    if (valdetecte > tresholdmuon) {
        compteur++;
        if (compteur >= 20){
            compteur = 0;
            return true;
        }
    }
    return false;
   
    //Serial.println(valdetecte);
}
 
float detection_muons_test(){
    valdetecte = analogRead(pinmuons);
    //if (valdetecte > tresholdmuon) {
        Serial.println("val et tresold");
        Serial.println(valdetecte);
        Serial.println(tresholdmuon);
        compteur++;
   // }
 
    return compteur;
   
    //Serial.println(valdetecte);
}
 