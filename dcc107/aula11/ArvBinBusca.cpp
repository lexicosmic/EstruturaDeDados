#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

void rotinaErro(int erro)
{
    switch (erro)
    {
    case 1:
        cout << "Arvore vazia!" << endl;
        break;
    default:
        break;
    }
    if (erro < 0)
        exit(erro * -1);
}

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
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

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == val)
        return true;
    else if (val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

NoArv *ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv *ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if (p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv *ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while (aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    if (raiz == NULL)
        rotinaErro(1);
    else
        imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if (p == NULL)
        return;
    imprimePorNivel(p->getDir(), nivel + 1);
    cout << "(" << nivel << ")";
    for (int i = 0; i < nivel; i++)
        cout << "\t";
    cout << p->getInfo() << endl;
    imprimePorNivel(p->getEsq(), nivel + 1);
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
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

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while (p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if (ch == p->getInfo())
            break;
        else if (ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma / cont;
}

// Ex01
int ArvBinBusca::auxMaior(NoArv *p)
{
    NoArv *dir = p->getDir();
    if (dir == NULL)
        return p->getInfo();
    else
        return auxMaior(dir);
}
int ArvBinBusca::maior()
{
    if (raiz == NULL)
        return 0;
    else
        return auxMaior(raiz);
}

// Ex02
int ArvBinBusca::auxMenor(NoArv *p)
{
    NoArv *esq = p->getEsq();
    if (esq == NULL)
        return p->getInfo();
    else
        return auxMenor(esq);
}
int ArvBinBusca::menor()
{
    if (raiz == NULL)
        return 0;
    else
        return auxMenor(raiz);
}

// Ex03
NoArv *ArvBinBusca::auxRemoveMaior(NoArv *p)
{
    NoArv *dir = p->getDir();
    if (dir == NULL)
    {
        delete p;
        p = NULL;
    }
    else
        p->setDir(auxRemoveMaior(dir));
    return p;
}
void ArvBinBusca::removeMaior()
{
    if (raiz == NULL)
    {
        rotinaErro(1);
        return;
    }
    NoArv *esq = raiz->getEsq();
    NoArv *p = auxRemoveMaior(raiz);
    if (p == NULL)
        raiz = esq;
}

// Ex04
NoArv *ArvBinBusca::auxRemoveMenor(NoArv *p)
{
    NoArv *esq = p->getEsq();
    if (esq == NULL)
    {
        delete p;
        p = NULL;
    }
    else
        p->setEsq(auxRemoveMenor(esq));
    return p;
}
void ArvBinBusca::removeMenor()
{
    if (raiz == NULL)
    {
        rotinaErro(1);
        return;
    }
    NoArv *dir = raiz->getDir();
    NoArv *p = auxRemoveMenor(raiz);
    if (p == NULL)
        raiz = dir;
}

// Ex05
int ArvBinBusca::contaParesCaminho(int x)
{
    int qtdPares = 0;
    NoArv *p = raiz;
    int info = 0;
    while (p != NULL)
    {
        info = p->getInfo();
        if (info % 2 == 0)
            qtdPares++;
        if (info == x)
            break;
        else if (info > x)
            p = p->getEsq();
        else
            p = p->getDir();
    }
    return qtdPares;
}

// Ex06
NoArv *ArvBinBusca::maiorSubArvEsquerda(NoArv *p)
{
    if (p == NULL)
        return NULL;
    NoArv *aux = p->getEsq();
    while (aux->getDir() != NULL)
        aux = aux->getDir();
    return aux;
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv *ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if (p == NULL)
        return NULL;
    else if (p->getInfo() < val)
        p->setDir(auxRemove(p->getDir(), val));
    else if (p->getInfo() > val)
        p->setEsq(auxRemove(p->getEsq(), val));
    else
    {
        if (p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if (p->getEsq() == NULL || p->getDir() == NULL)
            p = remove1Filho(p);
        else
        {
            NoArv *aux = maiorSubArvEsquerda(p);
            int auxInt = aux->getInfo();
            p->setInfo(auxInt);
            aux->setInfo(val);
            p->setEsq(auxRemove(p->getEsq(), val));
        }
    }
    return p;
}