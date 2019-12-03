#include "codeur.h"
#include <iostream>

Codeur::Codeur(int8_t *_etage, int8_t *_Vinit, int _n) {
  etage = _etage;
  Vinit = _Vinit;
  n = _n;
  size = 0;
  if (etage[0] > 0) {
    size = 2;
    for (int i = 0; i < etage[0] - 1; i++)
      size *= 2;
    size -= 1;
  }
}

int8_t *Codeur::lm() {
  int8_t *L;

  if (size > 0) {
    L = new int8_t[size];

    int encours[etage[0]];
    int bit = 0;

    for (int j = 0; j < etage[0]; j++)
      encours[j] = Vinit[j];

    for (int i = 0; i < n && i < size; i++) {

      // printf("i : %2d ------>", i);
      // for (int j = 0; j < etage[0]; j++)
      //   printf("%2d ", encours[j]); // Affichage

      bit = 0;
      for (int k = 0; etage[k] != -1; k++) {
        // printf("      %d xor %d : ",encours[etage[k]-1] , bit);
        bit = encours[etage[k] - 1] ^ bit;
        // printf("%d ----> ", bit);
      }
      // Calcul du prochain premier bit

      for (int j = etage[0] - 1; j > 0;
           j--) // On decale tout de 1 vers la droite
        encours[j] = encours[j - 1];

      encours[0] = bit; // On affecte le nouveau premier

      L[i] = encours[etage[0] - 1];
    }
  }
  return L;
}

int Codeur::getSize() { return size; }
