#ifndef ECRAN_H
#define ECRAN_H
#define Pin_Pot A4

#define BLACK      0x0000
#define BLUE       0x002d00ff

#define BCKG_Color 0xe193f2


#define BCKG_Bouton  0xb4ffdf
#define BCKG_Mod_Acc 0xf8ff00
#define BCKG_Rot_Acc 0xffbd00
#define BCKG_Val_Pot 0x8e4bc4

enum Ecran{

    BOUTON,
    MODULE_ACC,
    MOUV_MAN,
    VAL_POT
};

void init_Ecran(void);
void Afficher_titres(void);
void fill_Stats(int regen, int degats, int vitesse, int resistance, int HP, int crits, int XpGain, int qteEnnemi, int qteAmi);

void ecran_boutons(void);
void update_boutons( int boutonSel );

void ecran_module_acc(void);
void update_module_acc(float module);

void ecran_rotation_acc(void);
void update_rotation_acc(int rotation);

void ecran_val_pot(void);
void update_val_pot(float valeur);

void Affichage_boss(int boss);

void TestDanick();
#endif
