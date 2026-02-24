
#include <Arduino.h>
#include "acelerometre.h"
#include "bouton.h"
#include "incremental.h"
#include "potentiometre.h"

int lastValue = 0;
int menu = 0;

void setup()
{
  Serial.begin(9600);
  //Serial.print("Debut de l'initialisation de l'accelerometre");
  setup_encoder(2, 3);  // use interrupt pin 2 for channel A and pin 3 for channel B
  
}

void loop()
{
  setup_accelerometre();
  //setup_bouton();
  //potentiometre();
  Serial.println(module_accelerometre());
 
 
  //bouton du rotary encoder

  /*
  if (digitalRead(4) == true)
  {
    Serial.println("Bouton appuye");
  }
  else if (digitalRead(4) == false)
  {
    Serial.println("Bouton relache");
  }
  */
  /*
  int currentValue = read_encoder();
  

  
  if (currentValue > lastValue)
  {
    menu++;
    if (menu > 2){
      menu = 0;
    }
  
  }
  else if (currentValue < lastValue)
  {
    menu--;
    if (menu < 0){
      menu = 2;
    }
  }
  lastValue = currentValue;
  Serial.println(currentValue);
  Serial.println(lastValue);
  if (menu == 0){
    Serial.println("ACCELEROMETRE");
  }
  else if (menu == 1){
    Serial.println("BOUTON");
  }
  else if (menu == 2){
    Serial.println("LEBRON JAMES");
  }
  
  currentValue = 0;
  lastValue = 0;
  write_encoder(0);
  */

  /*if (currentValue == lastValue){
    Serial.println("Pas de changement");
  }
  else if (currentValue > lastValue)
  {
    Serial.println("Rotation antihoraire");
    Serial.print("Valeur actuelle: ");
    Serial.println(currentValue);
    lastValue = currentValue;
  }
  else if (currentValue < lastValue)
  {
    Serial.println("Rotation horaire");
    Serial.print("Valeur actuelle: ");
    Serial.println(currentValue);
    lastValue = currentValue;
  }*/
  delay (1000);
}


/* endoffile */