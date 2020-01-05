
#ifndef _CODEUR
#define _CODEUR
#include <iostream>

class Codeur {
private:
  int8_t *Vinit;
  int8_t *etage;
  int n;
  int size;

public:
  Codeur(int8_t *, int8_t *);
  int8_t *lm();
  int getSize();
};

#endif
