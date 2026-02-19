
#include <Arduino.h>
#include "acelerometre.h"
#include "bouton.h"

void setup()
{
  Serial.begin(9600);
  //Serial.print("Debut de l'initialisation de l'accelerometre");
}

void loop()
{
  setup_accelerometre();
  //setup_bouton();
}


/* endoffile */