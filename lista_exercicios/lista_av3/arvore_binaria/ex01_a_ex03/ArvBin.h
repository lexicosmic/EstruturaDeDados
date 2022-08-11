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
  int auxECheia(NoArv *p, int *nNos);
  int getAltura(NoArv *p);
  int getNumNosAteNivel(NoArv *p, int nivel);

public:
  ArvBin();
  ~ArvBin();
  void insere(int x);
  void imprime();
  void cria(int x, ArvBin *sae, ArvBin *sad);
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
  bool eCheia();
  bool eCompleta();
};

#endif // ARVBIN_H_INCLUDED
