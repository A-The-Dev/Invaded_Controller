#include <Arduino.h>

#define Pin_D1  35
#define Pin_D2  33
#define Pin_D3  31
#define Pin_D4  29

#define Pin_A   49
#define Pin_B   47
#define Pin_C   45  
#define Pin_D   43
#define Pin_E   39  //
#define Pin_F   41  //
#define Pin_G   37  

void init_Timer5(void);
void init_7seg(void);
void AfficherUnDigit(int digitSel, int nombre);
void Affichage7Seg(int digitSel, int valeur);
