#include "incremental.h"

float calculzoom() {
    // Code pour calculer le zoom en fonction de l'état de l'encodeur
    int valeur_encodeur = read_encoder(); // Récupère la valeur actuelle de l'encodeur
    float valeur_zoom = 100; // Valeur de zoom par défaut
    valeur_zoom = valeur_zoom + (valeur_encodeur * 5); // Ajuste le zoom en fonction de la valeur de l'encodeur
    return valeur_zoom;
}

void printzoom(){
    float zoom = calculzoom();
    Serial.print("Zoom actuel: ");
    Serial.print(zoom);
    Serial.println("%");
}

void resetzoom(){
    write_encoder(0); // Réinitialise la valeur de l'encodeur à 0
    Serial.println("Zoom réinitialisé à 100%");
}