#include <iostream>
#include <cmath>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    // OMITIDO
}

NoArv *ArvBinBusca::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

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

void ArvBinBusca::removeMenor(int val)
{
    raiz = auxRemoveMenor(raiz, val);
}

// ----------------------------------------------------------------------------
// Q1 -> 21 minutos e 07 segundos
void ArvBinBusca::auxImprimePorNivel(NoArv *p, int k)
{
    if (p == NULL)
        return;
    auxImprimePorNivel(p->getDir(), k + 1);
    cout << "(" << k << ")";
    for (int i = 0; i < k; i++)
    {
        cout << "\t";
    }
    cout << p->getInfo() << endl;
    auxImprimePorNivel(p->getEsq(), k + 1);
}
void ArvBinBusca::imprimePorNivel()
{
    auxImprimePorNivel(raiz, 0);
}

void ArvBinBusca::auxCriaVetFolhas(NoArv *p, int k, int *n, int *vet)
{
    if (p == NULL)
        return;
    if (k >= 0)
    {
        int info = p->getInfo();
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        if ((esq == NULL && dir == NULL))
        {
            vet[*n] = info;
            (*n)++;
        }
        auxCriaVetFolhas(esq, k - 1, n, vet);
        auxCriaVetFolhas(dir, k - 1, n, vet);
    }
}
int *ArvBinBusca::criaVetFolhas(int k, int *n)
{
    if (raiz == NULL)
        return NULL;
    int tamMaxVet = powf(2, k);
    *n = 0;
    int *vet = new int[tamMaxVet];
    auxCriaVetFolhas(raiz, k, n, vet);

    for (int i = *n; i < tamMaxVet; i++)
    {
        vet[i] = -1;
    }
    *n = tamMaxVet;
    return vet;
}
//-Q1
// ----------------------------------------------------------------------------

// ------------------------------------------------------------------------
// Q2 -> 14 minutos e 59 segundos
int ArvBinBusca::classificaFilhos(NoArv *pai)
{
    if (pai == NULL)
        return -2;
    NoArv *esq = pai->getEsq();
    NoArv *dir = pai->getDir();
    if (esq != NULL && dir != NULL)
        return 2;
    else if (esq != NULL)
        return -1;
    else if (dir != NULL)
        return 1;
    else
        return 0;
}
int ArvBinBusca::contaNos1Filho(int val)
{
    if (raiz == NULL)
        return 0;
    NoArv *p = raiz;
    int num = 0;
    while (p != NULL)
    {
        int info = p->getInfo();
        int classificacao = classificaFilhos(p);
        if (classificacao == -1 || classificacao == 1)
            num++;
        if (val < info)
            p = p->getEsq();
        else if (val > info)
            p = p->getDir();
        else
            break;
    }
    return num;
}
//-Q2
// ------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Q3 -> 1 hora, 02 minutos e 51 segundos
NoArv *ArvBinBusca::auxRemoveMenor(NoArv *p, int val)
{
    if (p == NULL)
        return NULL;
    int info = p->getInfo();
    if (info < val)
    { // A remover
        // Salva direita, pode ser maior que val
        NoArv *dir = p->getDir();
        // Separa a direita e libera p, que é menor
        p->setDir(NULL);
        libera(p);
        // Faz verificações para a direita
        dir = auxRemoveMenor(dir, val);
        return dir;
    }
    else
        p->setEsq(auxRemoveMenor(p->getEsq(), val));
    return p;
}
//-Q3
// ----------------------------------------------------------------------------
