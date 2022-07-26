#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
public:
  ArvBin();
  ~ArvBin();
  int getRaiz();
  void cria(int x, ArvBin *sae, ArvBin *sad);
  void anulaRaiz();
  bool vazia(); // verifica se a �rvore est� vazia
  bool busca(int x);
  void preOrdem();
  void montaArvore();
  void insere(int x);
  int contaNos();
  int contaNosFolhas();
  int altura();
  int contaImpar();
  int contaFolhaImpar();
  void imprimeNivel(int kp);
  float mediaNivel(int kp);
  int min();
  int max();
  void inverte();
  void imprimePorNivel();
  int noMaisEsquerda();
  int noMaisDireita();
  int minSubArvore(NoArv *p);
  int maxSubArvore(NoArv *p);
  NoArv *getNoRaiz();
  bool ehABB();

private:
  NoArv *raiz; // ponteiro para o No raiz da �rvore

  NoArv *libera(NoArv *p);
  bool auxBusca(NoArv *p, int x);
  void auxPreOrdem(NoArv *p);
  NoArv *auxMontaArvore();
  // void auxImpNivel(NoArv *p, int atual, int k);
  NoArv *auxInsere(NoArv *p, int x);
  int auxContaNos(NoArv *p);
  int auxContaNosFolhas(NoArv *p);
  int auxAltura(NoArv *p);
  int auxContaImpar(NoArv *p);
  int auxContaFolhaImpar(NoArv *p);
  void auxImprimeNivel(NoArv *p, int kp, int k);
  void auxMediaNivel(NoArv *p, int kp, int k, int *nNos, int *soma);
  void auxMin(NoArv *p, int *min);
  void auxMax(NoArv *p, int *max);
  void auxInverte(NoArv *p);
  void auxImprimePorNivel(NoArv *p, int k);
  int auxNoMaisEsquerda(NoArv *p);
  int auxNoMaisDireita(NoArv *p);
  void auxMinSubArvore(NoArv *p, int *min);
  void auxMaxSubArvore(NoArv *p, int *max);
  bool auxEhABB(NoArv *p);
};

#endif // ARVBIN_H_INCLUDED
