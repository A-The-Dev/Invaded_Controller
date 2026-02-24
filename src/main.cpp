
#include <Arduino.h>
#include "acelerometre.h"
#include "bouton.h"
#include "incremental.h"
#include "potentiometre.h"
#include "joystick.h"

int lastValue = 0;
int menu = 0;
int derniere_valeur = 4;


void setup()
{
  Serial.begin(9600);
  //Serial.print("Debut de l'initialisation de l'accelerometre");
  setup_encoder(2, 3);  // use interrupt pin 2 for channel A and pin 3 for channel B
  JoyInit();
  
}

void loop()
{
  //setup_accelerometre();
  //setup_bouton();
  //potentiometre();
  //Serial.println(module_accelerometre());
 
 
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
  
  int currentValue = read_encoder();
  

  
  if (currentValue > lastValue)
  {
    menu++;
    if (menu > derniere_valeur){
      menu = 0;
    }
  
  }
  else if (currentValue < lastValue)
  {
    menu--;
    if (menu < 0){
      menu = derniere_valeur;
    }
  }
  lastValue = currentValue;
  //Serial.println(currentValue);
  //Serial.println(lastValue);

  if (menu == 0){
    setup_accelerometre();
    //Serial.println("ACCELEROMETRE");
  }
  if (menu == 1){
    module_accelerometre();
    //Serial.println("ACCELEROMETRE");
  }
  else if (menu == 2){
    setup_bouton();
    //Serial.println("BOUTON");
  }
  else if (menu == 3){
    potentiometre();
    //Serial.println("LEBRON JAMES");
  }
  else if (menu == 4){
    //JoyPrint();
    Serial.println("Ou est le joystick Xavier?");
  }
  
  currentValue = 0;
  lastValue = 0;
  write_encoder(0);
  Serial.println(menu);

  delay (200);
}


/* endoffile */