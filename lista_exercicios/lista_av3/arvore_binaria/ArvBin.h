#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
private:
  NoArv *raiz; // ponteiro para o No raiz da �rvore
  NoArv *auxInsereAbb(NoArv *p, int x);
  NoArv *auxInsereAleatorio(NoArv *p, int x);
  void imprimePorNivel(NoArv *p, int nivel);
  NoArv *libera(NoArv *p);
  int auxImpares(NoArv *p);
  int auxSoma(NoArv *p);
  int auxMedia(NoArv *p, int *nNos);
  int auxMediaPares(NoArv *p, int *nNos);
  void auxMaiorValor(NoArv *p, int *maior);
  void auxMenorValor(NoArv *p, int *menor);
  int auxMaiores(NoArv *p, int chave);
  int auxMediaNivel(NoArv *p, int *nNos, int nivel);
  void auxImprimirNivelPreOrdem(NoArv *p, int nivel);
  void auxImprimirNivelEmOrdem(NoArv *p, int nivel);
  void auxImprimirNivelPosOrdem(NoArv *p, int nivel);
  void auxSucessor(NoArv *p, int val, int *sucessor, bool *encontrado);

public:
  ArvBin();
  ~ArvBin();
  void insere(int x);
  void imprime();
  int impares();
  int soma();
  float media();
  float mediaPares();
  int maiorValor();
  int menorValor();
  int maiores(int chave);
  float mediaNivel(int nivel);
  void imprimirNivel(int nivel);
  int sucessor(int val);
};

#endif // ARVBIN_H_INCLUDED
