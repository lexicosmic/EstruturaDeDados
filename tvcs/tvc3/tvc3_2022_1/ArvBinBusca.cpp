#include <iostream>
#include <cmath>
#include "ArvBinBusca.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q1
void ArvBinBusca::auxContaElegante(NoArv *p, int *numPares, int *numFolhaNNeg)
{
    if (p == NULL)
        return;

    int info = p->getInfo();
    if (info % 2 == 0) // Eh par
        (*numPares)++;

    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    if (esq == NULL && dir == NULL) // Eh folha
    {
        if (info >= 0) // Eh nao negativa
            (*numFolhaNNeg)++;
    }
    else // Se nao for folha, buscar filhos
    {
        auxContaElegante(p->getEsq(), numPares, numFolhaNNeg);
        auxContaElegante(p->getDir(), numPares, numFolhaNNeg);
    }
}
void ArvBinBusca::contaElegante()
{
    int numPares = 0;
    int numFolhaNNeg = 0;
    if (raiz != NULL)
    {
        auxContaElegante(raiz, &numPares, &numFolhaNNeg);
    }
    cout << "Quant. nos pares: " << numPares << endl;
    cout << "Quant. folhas nao negativas: " << numFolhaNNeg << endl;
}
//-Q1

// ----------------------------------------------------------------------------

// ------------------------------------------------------------------------
//Q2
void ArvBinBusca::auxSomaIntervalo(NoArv *p, int a, int b, int *soma)
{
    if (p == NULL)
        return;
    int info = p->getInfo();
    if (a <= info && info <= b)
        (*soma) += info;
    if (a < info)
        auxSomaIntervalo(p->getEsq(), a, b, soma);
    if (b >= info) // Considera arvore com valores repetidos
        auxSomaIntervalo(p->getDir(), a, b, soma);
}
int ArvBinBusca::somaIntervalo(int a, int b)
{
    int soma = 0;
    if (raiz != NULL)
        auxSomaIntervalo(raiz, a, b, &soma);
    return soma;
}
//-Q2
// ------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q3
void ArvBinBusca::removeNo(int val)
{
    NoArv *p = raiz;
    NoArv *pai = NULL;
    bool removerEsq = true; // Decidir de que lado atualizar o pai
    while (p != NULL)
    {
        int info = p->getInfo();
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();

        if (val < info) // Chave esta a esquerda
        {
            pai = p;
            p = esq;
            removerEsq = true;
        }
        else if (val > info) // Chave esta a direita
        {
            pai = p;
            p = dir;
            removerEsq = false;
        }
        else // Foi encontrado
        {
            if (esq == NULL && dir == NULL) // Eh folha
            {
                delete p;
                if (pai == NULL) // Eh raiz e folha
                    raiz = NULL;
                else // Eh apenas folha
                {
                    if (removerEsq)
                        pai->setEsq(NULL);
                    else
                        pai->setDir(NULL);
                }
            }
            else
                cout << "NAO REMOVIDO: No " << val << " nao e folha!" << endl;
            return;
        }
    }
    cout << "NAO REMOVIDO: No " << val << " nao encontrado!" << endl;
}
//-Q3
// ----------------------------------------------------------------------------

NoArv *ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if (p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if (val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

void ArvBinBusca::imprime()
{
    cout << "ABB em ordem: ";
    imprimeEmOrdem(raiz);
    cout << endl;
}

void ArvBinBusca::imprimeEmOrdem(NoArv *p)
{
    if (p != NULL)
    {
        imprimeEmOrdem(p->getEsq());
        cout << p->getInfo() << " ";
        imprimeEmOrdem(p->getDir());
    }
}

void ArvBinBusca::imprimePorNivel()
{
    cout << "ABB em nivel: " << endl;
    auxImprimePorNivel(raiz, 0);
}

void ArvBinBusca::auxImprimePorNivel(NoArv *p, int k)
{
    if (p != NULL)
    {
        auxImprimePorNivel(p->getDir(), k + 1);
        cout << "(" << k << ")";
        for (int i = 0; i < k; i++)
            cout << "\t";
        cout << p->getInfo() << endl;
        auxImprimePorNivel(p->getEsq(), k + 1);
    }
}