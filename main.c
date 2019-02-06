/***************************************
            JEU DE LA VIE
***************************************/

#include "Jeu_de_la_vie.h"
#define TAILLES 10

#define TAILLEM  7



FILE* fopen(const char* MonSuperFicher, const char* Ouverture);

void mise_a_jour(int MonTableau[TAILLEM][TAILLEM], FILE* fichier);


/*****************************************************/
int main( ){
   int i;
   int nbr_cycles;
   int MonTableau[TAILLEM] [TAILLEM];
   char s[2];

    FILE *fichier = NULL;

    printf("Nombre de cycles : ");
    scanf("%i",&nbr_cycles);
    init(MonTableau);
    printf("La population au départ : \n");

    affiche_MonTableau(MonTableau);
    printf("Pressez sur ENTER pour continuer...\n");
    gets(s);

    for(i=0; i<nbr_cycles; i++) {
        mise_a_jour (MonTableau,fichier);
        printf("La population après %d cycles: \n", i+1);
        affiche_MonTableau (MonTableau);
        printf("Pressez sur ENTER pour continuer...\n");
        gets(s);
   }
   return 0;
}


