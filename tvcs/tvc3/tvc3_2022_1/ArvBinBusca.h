#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca() { raiz = NULL; }

    void insere(int val) { raiz = auxInsere(raiz, val); }

    void imprime();

    void imprimePorNivel();

    // Q1
    void contaElegante();
    // Q2
    int somaIntervalo(int a, int b);
    // Q3
    void removeNo(int val);

private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore

    NoArv *auxInsere(NoArv *p, int val);
    void imprimeEmOrdem(NoArv *p);
    bool ehFolha(NoArv *p);
    void auxImprimePorNivel(NoArv *p, int k);
    void auxContaElegante(NoArv *p, int *numPares, int *numFolhaNNeg);
    void auxSomaIntervalo(NoArv *p, int a, int b, int *soma);
};

#endif // ARVBINBUSCA_H_INCLUDED
