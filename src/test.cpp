#include "bouton.h"
#include "7seg.h"
#include "Ecran.h"
#include "encodeur.h"
#include "acelerometre.h"
#include "LED.h"
#include "joystick.h"

void testAffichage7Seg(){
    AfficherUnDigit(1, 322);
}

void testAffichagetft(){
    Afficher_titres();
}

void testencodeur(){
    calculzoom(); 
    printzoom();
}

void testaccelerometre(){
    module_accelerometre();
}

void testboutons(){
    int setup_bouton();
}

void testLEDs(){
    LED_allumer(1);
    LED_allumer(2);
}

void testjoystick(){
    JoyPrintTestModif();
}

