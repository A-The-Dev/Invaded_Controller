
#include <Arduino.h>
#include "acelerometre.h"
#include "bouton.h"
#include "incremental.h"
#include "potentiometre.h"
#include "joystick.h"
#include "LED.h"
#include "Ecran.h"

int lastValue = 0;
int menu = 0;
int derniere_valeur = 4;


void setup()
{
  Serial.begin(9600);
  init_Ecran();
  //Serial.print("Debut de l'initialisation de l'accelerometre");
  //setup_encoder(2, 3);  // use interrupt pin 2 for channel A and pin 3 for channel B
  //JoyInit();
  //setup_LED();
  //Affichage_boss(2);
  TestDanick();
}

void loop()
{
  //setup_accelerometre();
  //setup_bouton();
  //potentiometre();
  //Serial.println(module_accelerometre());
  /*
  LED_allumer(1);
  delay(100);
  LED_eteindre(1);
  delay(100);
  LED_allumer(2);
  delay(100);
  LED_eteindre(2);
  delay(100);
  LED_allumer(3);
  delay(100);
  LED_eteindre(3);
  delay(100);
  LED_allumer(4);
  delay(100);
  LED_eteindre(4);
  delay(100);
  */

  /*int currentValue = read_encoder();
  

  
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

  delay (200);*/
}


/* endoffile */