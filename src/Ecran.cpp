#include "Ecran.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

                                    //CS, DC, MOSI, SCK, RST
Adafruit_ST7789 tft = Adafruit_ST7789(48, 44, 51,   52,  46);

void init_Ecran(void)
{
  tft.init(240, 320);           // Init ST7789 320x240

  tft.setRotation(3);           //choisir orientation horizontale + PIN à gauche
  //tft.fillScreen(BCKG_Color);   //Mettre couleur en background
  tft.setTextSize(3);
  tft.setTextColor(BLACK);     //Mettre couleur du texte en noir
  tft.setTextWrap(true);       //Retour à la ligne actif

  Serial.println("Init Ecran complete!");

}

/*void Afficher_titres(void)
{
  
  tft.setTextColor(BLACK);     //Mettre couleur du texte en noir
  tft.setTextWrap(true);       //Retour à la ligne actif 

  tft.setCursor(3, 3);          //Ligne 1
  tft.print("Regen: ");

  tft.setCursor(3, 29);         //Ligne 2
  tft.print("Degats: ");

  tft.setCursor(3, 55);         //Ligne 3
  tft.print("Vitesse: ");

  tft.setCursor(3, 81);         //Ligne 4
  tft.print("Resistance: ");

  tft.setCursor(3, 107);        //Ligne 5
  tft.print("Point de vie: ");

  tft.setCursor(3, 133);        //Ligne 6
  tft.print("Criticals: ");

  tft.setCursor(3, 159);        //Ligne 7
  tft.print("Xp Gain: ");

  tft.setCursor(3, 185);        //Ligne 8
  tft.print("Nbr d'ennemis: ");

  tft.setCursor(3, 211);        //Ligne 9
  tft.print("Nbr d'amis: ");

  Serial.println("Affichage titres complete!");
}*/

/*void fill_Stats(int regen, int degats, int vitesse, int resistance, int HP, int crits, int XpGain, int qteEnnemi, int qteAmi)
{
  
  tft.setTextColor(BLUE);    //Mettre couleur du texte en bleu
    
  tft.setCursor(114, 3);         //Ligne 1 
  tft.fillRect(114, 3, 206, 26, BCKG_Color);
  tft.print(regen);

  tft.setCursor(132, 29);        //Ligne 2 
  tft.fillRect(132, 29, 206, 26, BCKG_Color);
  tft.print(degats);
  
  tft.setCursor(150, 55);        //Ligne 3 
  tft.fillRect(150, 55, 206, 26, BCKG_Color);
  tft.print(vitesse);

  tft.setCursor(204, 81);        //Ligne 4 
  tft.fillRect(204, 81, 206, 26, BCKG_Color);
  tft.print(resistance);

  tft.setCursor(240, 107);       //Ligne 5 
  tft.fillRect(240, 107, 206, 26, BCKG_Color);
  tft.print(HP);

  tft.setCursor(186, 133);       //Ligne 6 
  tft.fillRect(186, 133, 206, 26, BCKG_Color);
  tft.print(crits);

  tft.setCursor(150, 159);       //Ligne 7 
  tft.fillRect(150, 159, 206, 26, BCKG_Color);
  tft.print(XpGain);

  tft.setCursor(258, 185);       //Ligne 8 
  tft.fillRect(258, 185, 206, 26, BCKG_Color);
  tft.print(qteEnnemi);

  tft.setCursor(204, 211);       //Ligne 9 
  tft.fillRect(204, 211, 206, 26, BCKG_Color);
  tft.print(qteAmi);
}*/

/* Fonctions affichages Boutons audit #2 */
/*void ecran_boutons(void)
{
  tft.fillScreen(BCKG_Bouton);   //Mettre couleur en background

  tft.setCursor(3, 3);          //Ligne 1
  tft.print("Bouton 1: ");

  tft.setCursor(3, 29);         //Ligne 2
  tft.print("Bouton 2: ");

  tft.setCursor(3, 55);         //Ligne 3
  tft.print("Bouton 3: ");

  tft.setCursor(3, 81);         //Ligne 4
  tft.print("Bouton 4: ");

}*/

/*void update_boutons( int boutonSel )
{

  switch(boutonSel)
  {
    case 1:
      tft.setCursor(144, 3);         //Ligne 1 
      tft.fillRect(144, 3, 176, 26, BCKG_Bouton);
      tft.print("actif");
      tft.setCursor(144, 29);         //Ligne 2 
      tft.fillRect(144, 29, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 55);         //Ligne 3 
      tft.fillRect(144, 55, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 81);         //Ligne 4 
      tft.fillRect(144, 81, 176, 26, BCKG_Bouton);
      tft.print("inactif");

    break;

    case 2:
      tft.setCursor(144, 3);         //Ligne 1 
      tft.fillRect(144, 3, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 29);         //Ligne 2 
      tft.fillRect(144, 29, 176, 26, BCKG_Bouton);
      tft.print("actif");
      tft.setCursor(144, 55);         //Ligne 3 
      tft.fillRect(144, 55, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 81);         //Ligne 4 
      tft.fillRect(144, 81, 176, 26, BCKG_Bouton);
      tft.print("inactif");

    break;

    case 3:
      tft.setCursor(144, 3);         //Ligne 1 
      tft.fillRect(144, 3, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 29);         //Ligne 2 
      tft.fillRect(144, 29, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 55);         //Ligne 3 
      tft.fillRect(144, 55, 176, 26, BCKG_Bouton);
      tft.print("actif");
      tft.setCursor(144, 81);         //Ligne 4 
      tft.fillRect(144, 81, 176, 26, BCKG_Bouton);
      tft.print("inactif");

    break;

    case 4:
      tft.setCursor(144, 3);         //Ligne 1 
      tft.fillRect(144, 3, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 29);         //Ligne 2 
      tft.fillRect(144, 29, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 55);         //Ligne 3 
      tft.fillRect(144, 55, 176, 26, BCKG_Bouton);
      tft.print("inactif");
      tft.setCursor(144, 81);         //Ligne 4 
      tft.fillRect(144, 81, 176, 26, BCKG_Bouton);
      tft.print("actif");

    break;
  }
  
}*/



/* Fonctions affichages Module acceleromètre audit #2 */
/*void ecran_module_acc(void)
{
  tft.fillScreen(BCKG_Mod_Acc);   //Mettre couleur en background

  tft.setCursor(3, 3);          //Ligne 1
  tft.print("Module: ");
}*/

/*void update_module_acc(float module)
{
  tft.setCursor(126, 3);          //Ligne 1
  tft.fillRect(126, 3, 194, 26, BCKG_Mod_Acc);
  tft.print(module);
}*/

/*void ecran_rotation_acc(void)
{
  tft.fillScreen(BCKG_Rot_Acc);   //Mettre couleur en background

  tft.setCursor(3, 3);          //Ligne 1
  tft.print("Rotation: ");
}*/

/*void update_rotation_acc(int rotation)
{
  tft.setCursor(162, 3);          //Ligne 1
  tft.fillRect(162, 3, 194, 26, BCKG_Rot_Acc);
  if(rotation)
  {
    tft.print("horaire");
  }
  else
  {
    tft.print("anti-horaire");
  }
}*/

/* Fonctions affichages Valeur potentiomètre audit #2 */
/*void ecran_val_pot(void)
{
  tft.fillScreen(BCKG_Val_Pot);   //Mettre couleur en background

  tft.setCursor(3, 3);          //Ligne 1
  tft.print("Valeur pot: ");
}*/

/*void update_val_pot(float valeur)
{
  tft.setCursor(126, 3);          //Ligne 1
  tft.fillRect(126, 3, 194, 26, BCKG_Val_Pot);
  tft.print(valeur);
}*/

void Affichage_boss(int boss){
  //tft.fillScreen(0X000000);
  if (boss == 1){
    tft.setCursor(100, 110);          //Ligne 1
    tft.fillScreen(0X000000);   //Mettre couleur en background
  }
  else {

    if (boss == 2){
    tft.fillRect(0, 0, 320, 240, 0XF800);
    tft.setTextColor(0Xffffff);
    tft.setCursor(50, 110);
    tft.print("MR. PRESIDENT");
    }
    else if (boss == 3){
    tft.fillRect(0, 0, 320, 240, 0XF800);
    tft.setTextColor(0Xffffff);
    tft.setCursor(50, 110);
    tft.print("WHITE DRAGON");
    }
    else if (boss == 4){
    tft.fillRect(0, 0, 320, 240, 0XF800);
    tft.setTextColor(0Xffffff);
    tft.setCursor(50, 110);
    tft.print("DEATH STAR");
    }
  }
}
