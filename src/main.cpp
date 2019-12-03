#include "codeur.h"
#include <iostream>

void Gold(int8_t *etage1, int8_t *etage2, int8_t *Vinit) {
  Codeur c1 = Codeur(etage1, Vinit, 60);
  Codeur c2 = Codeur(etage2, Vinit, 60);

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

int main(int argc, char const *argv[]) {

  int8_t etage[3] = {5, 2, -1};
  int8_t etage1[5] = {5, 4, 2, 1, -1};
  int8_t Vinit[5] = {1, 1, 1, 1, 1};

  printf("Longeur Maximal : \n");
  Codeur c1 = Codeur(etage1, Vinit, 60);
  int8_t *l1 = c1.lm();
  printf("l1 : ");
  for (int i = 0; i < c1.getSize(); i++) {
    printf("%2d ", l1[i]);
  }
  printf("\n");

  printf("Code Pseudo Aléatoire Gold : \n");

  Gold(etage, etage1, Vinit);

  return 0;
}
