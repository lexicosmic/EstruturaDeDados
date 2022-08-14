#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    void montaNaoAbb();
    bool eABB();
    void imprimeFilhos(int x);
    void imprimeIntervalo(int x, int y);
    void imprimeCrescente();
    void imprimeDecrescente();
    void insereDoVetorDegenerada(int n, int *vet);
    void insereDoVetorCompleta(int n, int *vet);
    int getNumNos();

private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore
    bool auxBusca(NoArv *p, int val);
    NoArv *auxInsere(NoArv *p, int val);
    NoArv *auxRemove(NoArv *p, int val);
    NoArv *menorSubArvDireita(NoArv *p);
    NoArv *removeFolha(NoArv *p);
    NoArv *remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv *p, int nivel);
    NoArv *libera(NoArv *p);
    bool auxEABB(NoArv *p);
    void auxImprimeFilhos(NoArv *p, int x);
    void auxImprimeIntervalo(NoArv *p, int x, int y);
    void auxImprimeCrescente(NoArv *p);
    void auxImprimeDecrescente(NoArv *p);
    int auxGetNumNos(NoArv *p);
    void copiaNosParaVetor(NoArv *p, int *vet, int *n);
    NoArv *auxInsereDoVetorCompleta(int ind, int tam, int *vet);
};

#endif // ARVBINBUSCA_H_INCLUDED
