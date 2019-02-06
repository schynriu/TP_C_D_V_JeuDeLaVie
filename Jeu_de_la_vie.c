#include "Jeu_de_la_vie.h"
#define TAILLES 10
/* On peut avoir 7 * 7 cellules vivantes */
#define TAILLEM 7
/****************************************/
/* Initialisation de la MonTableau */
/****************************************/
void init(int MonTableau [TAILLEM][TAILLEM]){
int i,j;

   for(i=0; i<TAILLEM; i++){
      for(j=0; j<TAILLEM; j++){
         if (i<=j && i>0 && j<=10)
            MonTableau[i][j]=1;
         else
            MonTableau[i][j]=0;
      }
   }
}
/****************************************/
/* Calcul du nombre de voisins vivants */
/***************************************/
int nombre_voisins (int MonTableau[TAILLEM][TAILLEM],int ligne,int colonne){
int compteur=0; /* compteurur de cellules */
int i,j;

/* On additionne les 9 cellules centrées en ligne,colonne */
   for (i=ligne-1;i<=ligne+1;i++)
      for(j=colonne-1;j<=colonne+1;j++)
         compteur=compteur+MonTableau[i][j];

         /* Puis on retire celle du milieu... */
         compteur -= MonTableau[ligne][colonne];
         return compteur;
}

void mise_a_jour(int MonTableau[TAILLEM][TAILLEM],FILE* fichier){
int i,j;
int nbr_voisins;
int MonTableau_densite[TAILLES][TAILLES];
   /* MonTableau qui comptabilise le nombre de voisins */
   /*  case par case */

   for(i=0; i< TAILLES; i++)
         for(j=0; j< TAILLES; j++)
            MonTableau_densite[i][j]=nombre_voisins(MonTableau,i+1,j+1);

     fichier = fopen("Jeu_de_la_vie.txt", "w+");
   for(i=0; i< TAILLES; i++)
      for(j=0; j< TAILLES; j++){
            nbr_voisins=MonTableau_densite[i][j];

            if(nbr_voisins==2){
                  MonTableau[i+1][j+1]=1;
                  //creation

                 fichier = fopen("Jeu_de_la_vie.txt", "a+");
                 fprintf(fichier, " la cellule en position %d %d est née",i,j);

                if (fichier != NULL){
                fputc('\n', fichier);
                fclose(fichier);
                }
            }
            else if (nbr_voisins==0 || nbr_voisins==4){
                  MonTableau[i+1][j+1]=0;
                    // fichier mort
                 fichier = fopen("Jeu_de_la_vie.txt", "a+ ");
                 fprintf(fichier, " la cellule en position %d %d est morte",i,j);

                if (fichier != NULL){
                fputc('\n', fichier);
                fclose(fichier);
                }
            }
    }
}
/****************************************/
/* Affichage à l'écran des cellules vivantes */
/****************************************/
void affiche_MonTableau(int MonTableau[TAILLEM][TAILLEM]){
int i,j;

   for(i=1; i<=TAILLES; i++){
      ligne(7);
      for(j=1; j<= TAILLES; j++)
         if (MonTableau[i][j]==1)
            printf("|%c",'1');
         else
            printf("|%c",'0');
      printf("|\n");
   }
   ligne(TAILLES);
}
/****************************************/
/* Tracé d'une ligne */
/****************************************/
void ligne(int largeur){
int i;

   for(i=0; i<largeur; i++)
      printf("+-");
   printf("+\n");
}
