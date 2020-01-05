#include "codeur.h"
#include <iostream>
#include <stdarg.h>

#define MAX 10

void Gold(int8_t *etage1, int8_t *etage2, int8_t *Vinit) {
  Codeur c1 = Codeur(etage1, Vinit);
  Codeur c2 = Codeur(etage2, Vinit);

  int8_t *l1 = c1.lm();
  int8_t *l2 = c2.lm();
  int8_t L[c1.getSize()];
  for (int i = 0; i < c1.getSize(); i++) {
    L[i] = l1[i] ^ l2[i];
  }

  printf("l1 : ");
  for (int i = 0; i < c1.getSize(); i++) {
    printf("%2d ", l1[i]);
  }
  printf("\n");

  printf("l2 : ");
  for (int i = 0; i < c2.getSize(); i++) {
    printf("%2d ", l2[i]);
  }
  printf("\n");

  printf("L  : ");
  for (int i = 0; i < c1.getSize(); i++) {
    printf("%2d ", L[i]);
  }
  printf("\n");
}

int PGCD(int a, int b){
    if(a==b)
            return a;
    else
        if(a>b)
           return PGCD(a-b, b);
        else
           return PGCD(a, b-a);
}

void JPL(int8_t *Vinit, int8_t *etage1, int8_t *etage2, ...){
  int tabPremier[MAX];
  int nb = 0;
  nb++;
  tabPremier[0] = etage1[0];
  if(PGCD(tabPremier[0], etage2[0]) == 1)
    tabPremier[nb++] = etage2[0];
  else{
    printf("Erreur chiffre non premier entre eux\n");
    return;
  }

  int8_t *l[MAX];

  Codeur c1 = Codeur(etage1, Vinit);
  l[0] = c1.lm();

  printf("l0 : ");
  for (int i = 0; i < c1.getSize(); i++) {
    printf("%2d ", l[0][i]);
  }
  printf("\n");
  Codeur c2 = Codeur(etage2, Vinit);
  l[1] = c2.lm();
  printf("l1 : ");

  for (int i = 0; i < c2.getSize(); i++) {
    printf("%2d ", l[1][i]);
  }
  printf("\n");

  int tailleR1 = c1.getSize() * c2.getSize();
  int calculNb = 0;
  int8_t *result[MAX];
  result[calculNb] = new int8_t[tailleR1];

  printf("Calcul : %d \n",calculNb+1);
  printf("Taille : %d\n", tailleR1);

  for(int i; i < tailleR1; i++){
    result[calculNb][i] = l[0][i%c1.getSize()] ^ l[1][i%c2.getSize()];
    printf("%d ", result[calculNb][i]);
  }
  printf("\n");
  calculNb++;

  va_list vl;
  va_start( vl, etage2 );
  int8_t *etage;
  ;
  while((etage = va_arg(vl, int8_t *)) != NULL){
    int j;
    for(j = 0; j < MAX && j < nb; j++){
      if(PGCD(tabPremier[j], etage[0]) != 1){
        printf("Erreur %d non premier avec les autres chiffres \n", etage[0]);
        return;
      }
    }
    if(j == nb){
      Codeur c3 = Codeur(etage, Vinit);
      l[nb] = c3.lm();
      printf("\n---------------------------------------------------------\n" );
      printf("l%d : ",nb);

      for (int i = 0; i < c3.getSize(); i++) {
        printf("%2d ", l[nb][i]);
      }
      printf("\n");
      result[calculNb] = new int8_t[tailleR1*c3.getSize()];


      printf("Calcul : %d \n",calculNb+1);
      printf("Taille : %d\n", tailleR1*c3.getSize());
      printf("Etage %d : [",nb);
      for(int i = 0; etage[i] != -1; i++)
        printf("%d, ",etage[i]);
      printf("] \n\n\n");

      printf("Resultat : \n");
      for(int i; i < tailleR1*c3.getSize(); i++){
        result[calculNb][i] = result[calculNb-1][i%tailleR1] ^ l[nb][i%c3.getSize()];
        printf("%d ",result[calculNb][i]);
      }
      printf("\n\n\n");

      calculNb++;
      tailleR1 *= c3.getSize();
      tabPremier[nb++] = etage[0];
    }else{
      printf("Erreur %d non premier avec les autres chiffres \n", etage[0]);
      return;
    }


  }

  va_end( vl );

}


int main(int argc, char const *argv[]) {

  int8_t etage[3] = {5, 2, -1};
  int8_t etage1[5]= {5, 4, 2, 1,-1};
  int8_t Vinit[15] = {1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1};

  printf("Longeur Maximal : \n");

  Codeur c1 = Codeur(etage1, Vinit);

  int8_t *l1 = c1.lm();

  printf("l1 : ");

  for (int i = 0; i < c1.getSize(); i++) {
    printf("%2d ", l1[i]);
  }

  printf("\n");

  printf("\n\n------ Code Pseudo Aléatoire Gold -------\n");

  Gold(etage, etage1, Vinit);


  printf("\n\n\n------ Code Pseudo Aléatoire JPL -------\n");
  int8_t e[3] = {2, 1, -1};
  int8_t e1[3] = {3, 1, -1};
  int8_t e2[3] = {1, 1, -1};
  int8_t e3[3] = {5, 2, -1};
  JPL(Vinit,e,e1,e2,e3,NULL);

  return 0;
}
