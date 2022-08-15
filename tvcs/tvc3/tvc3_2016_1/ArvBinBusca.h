#ifndef TVC3_ARVBINBUSCA_H
#define TVC3_ARVBINBUSCA_H

#include <iostream>
#include <cstdlib>
#include <math.h>
#include "No.h"

using namespace std;

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    void imprime();
    void insere(int x);
    int consultaRaiz();
    bool vazia();
    bool busca(int x);
    int altura();
    int numNos();
    int maiorDistanciaNos();

    // Questao 1  ------------------------------------------------------------
    bool ehEstritamente();
    bool auxEhEstritamente(No * p);

    // Questao 2 --------------------------------------------------------------
    void maisProximo(int ch);
    void auxMaisProximo(No *p, int ch, int *dif, int *val);

    // Questao 3 --------------------------------------------------------------
    int * criaVetCaminho(int x, int *num);

private:
    No * raiz;

    // funcoes auxiliares
    No * auxInsere(No * p, int x);
    bool auxBusca(No * p, int x);
    void auxImprime(No * p, int nivel);
    int auxNumNos(No * p);
    int auxAltura(No * p);

};


#endif //TVC3_ARVBINBUSCA_H
