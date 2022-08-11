#ifndef ARVBINALT_H_INCLUDED
#define ARVBINALT_H_INCLUDED
#include "NoArv.h"

class ArvBinAlt
{
private:
  NoArv *raiz; // ponteiro para o No raiz da �rvore
  void imprimePorNivel(NoArv *p);
  NoArv *libera(NoArv *p);
  int atualizaAltura(NoArv *p, int h);
  NoArv *auxNoAlt(NoArv *p, int alt);
  NoArv *noAlt(int alt);
  bool auxEAVL(NoArv *p, int *anterior, bool *primeiro, int *alt);

public:
  ArvBinAlt();
  ~ArvBinAlt();
  void imprime();
  void cria(int valRaiz, ArvBinAlt *sae, ArvBinAlt *sad);
  void alturaNos();
  int noAltInfo(int alt);
  bool eAVL();
};

#endif // ARVBINALT_H_INCLUDED
