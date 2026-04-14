#include <Arduino.h>
#include "incremental.h"

float calculson() {
    // Code pour calculer le zoom en fonction de l'état de l'encodeur
    encode();
    int valeur_encodeur = read_encoder(); // Récupère la valeur actuelle de l'encodeur
    if (valeur_encodeur > 20){
        valeur_encodeur = 20; // Limite la valeur de l'encodeur à 20 pour éviter un zoom excessif // Réinitialise l'encodeur à 20 si la valeur dépasse la limite
    }
    int valeur_son = 0; // Valeur de zoom par défaut
    valeur_son = (valeur_encodeur * 5); // Ajuste le zoom en fonction de la valeur de l'encodeur
    if (valeur_son < 0) {
        valeur_son = 0; // Assure que le zoom ne devient pas négatif
        // Réinitialise l'encodeur à 0 si le zoom est négatif
    }
    return valeur_son;
}

void printson(){
    int son = calculson();
    //Serial.print("Son actuel: ");
    //Serial.print(son);
    //Serial.println("%");
}

void resetson(){
    write_encoder(0); // Réinitialise la valeur de l'encodeur à 0
    Serial.println("Son réinitialisé à 0%");
}