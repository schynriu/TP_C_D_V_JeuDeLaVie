#include <stdio.h>
#include <stdlib.h>
#ifndef JEU_DE_LA_VIE_H_INCLUDED
#define JEU_DE_LA_VIE_H_INCLUDED
#define TAILLEM  7


/***************** PROTOTYPES ***********************/

void init(int MonTableau [TAILLEM][TAILLEM]);
int nombre_voisins (int MonTableau [TAILLEM][TAILLEM],int ligne, int colonne);
void affiche_MonTableau(int MonTableau [TAILLEM][TAILLEM]);
void ligne(int largeur);
#endif // JEU_DE_LA_VIE_H_INCLUDED
