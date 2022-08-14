#include <iostream>
#include <cmath>
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
        NoArv *novo = new NoArv;
        novo->setEsq(NULL);
        novo->setDir(NULL);
        novo->setInfo(val);
        p = novo;
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
    if (p->getInfo() == val)
        return true;
    else if (p->getInfo() < val)
        return auxBusca(p->getDir(), val);
    else
        return auxBusca(p->getEsq(), val);
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
            NoArv *aux = menorSubArvDireita(p);
            int auxInt = aux->getInfo();
            p->setInfo(auxInt);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

NoArv *ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv *ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *filho;
    if (p->getEsq() == NULL)
        filho = p->getDir();
    else
        filho = p->getEsq();
    delete p;
    return filho;
}

NoArv *ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    if (p == NULL)
        return NULL;

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

void ArvBinBusca::montaNaoAbb()
{
    NoArv *novo1 = new NoArv;
    NoArv *novo2 = new NoArv;
    NoArv *novo3 = new NoArv;
    novo3->setEsq(NULL);
    novo3->setDir(NULL);
    novo3->setInfo(11);
    novo2->setEsq(NULL);
    novo2->setDir(NULL);
    novo2->setInfo(12);
    novo1->setEsq(novo3);
    novo1->setDir(novo2);
    novo1->setInfo(10);
    raiz = novo1;
}

// Ex01 -> 12 minutos e 45 segundos
bool ArvBinBusca::auxEABB(NoArv *p)
{
    if (p == NULL)
        return true;
    int info = p->getInfo();
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    if ((esq != NULL && esq->getInfo() >= info) || (dir != NULL && dir->getInfo() < info))
        return false;
    else
        return (auxEABB(esq) && auxEABB(dir));
}
bool ArvBinBusca::eABB()
{
    return auxEABB(raiz);
}

// Ex04 - A -> 17 minutos e 19 segundos
void ArvBinBusca::auxImprimeFilhos(NoArv *p, int val)
{
    if (p == NULL)
    {
        cout << "Nao encontrado!";
        return;
    }
    if (p->getInfo() == val)
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        if (esq == NULL)
            cout << "N";
        else
            cout << esq->getInfo();
        cout << "\t";
        if (dir == NULL)
            cout << "N";
        else
            cout << dir->getInfo();
    }
    else if (p->getInfo() < val)
        return auxImprimeFilhos(p->getDir(), val);
    else
        return auxImprimeFilhos(p->getEsq(), val);
}
void ArvBinBusca::imprimeFilhos(int x)
{
    auxImprimeFilhos(raiz, x);
}

// Ex04 - B -> 16 minutos e 04 segundos
void ArvBinBusca::auxImprimeIntervalo(NoArv *p, int x, int y)
{
    if (p == NULL)
        return;
    int info = p->getInfo();
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    auxImprimeIntervalo(esq, x, y);
    if (info >= x && info <= y)
        cout << info << "\t";
    auxImprimeIntervalo(dir, x, y);
}
void ArvBinBusca::imprimeIntervalo(int x, int y)
{
    auxImprimeIntervalo(raiz, x, y);
}

// Ex04 - C -> 03 minutos e 58 segundos
void ArvBinBusca::auxImprimeCrescente(NoArv *p)
{
    if (p == NULL)
        return;
    int info = p->getInfo();
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    auxImprimeCrescente(esq);
    cout << info << "\t";
    auxImprimeCrescente(dir);
}
void ArvBinBusca::imprimeCrescente()
{
    auxImprimeCrescente(raiz);
}

// Ex04 - D -> 01 minuto e 45 segundos
void ArvBinBusca::auxImprimeDecrescente(NoArv *p)
{
    if (p == NULL)
        return;
    int info = p->getInfo();
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    auxImprimeDecrescente(dir);
    cout << info << "\t";
    auxImprimeDecrescente(esq);
}
void ArvBinBusca::imprimeDecrescente()
{
    auxImprimeDecrescente(raiz);
}

// Ex04 - E.I -> 1 hora, 31 minutos e 40 segundos
int ArvBinBusca::auxGetNumNos(NoArv *p)
{
    if (p == NULL)
        return 0;
    int numEsq = auxGetNumNos(p->getEsq());
    int numDir = auxGetNumNos(p->getDir());
    return numEsq + numDir + 1;
}
int ArvBinBusca::getNumNos()
{
    return auxGetNumNos(raiz);
}
void ArvBinBusca::copiaNosParaVetor(NoArv *p, int *vet, int *n)
{
    if (p == NULL)
        return;
    copiaNosParaVetor(p->getEsq(), vet, n);
    vet[*n] = p->getInfo();
    (*n)++;
    copiaNosParaVetor(p->getDir(), vet, n);
}
void concatenaVetoresCrescente(int *novoVet, int numVet, int *vetAux, int numVetAux)
{
    int j = 0;
    for (int i = 0; i < numVet + j; i++)
    {
        if (vetAux[j] < novoVet[i])
        {
            for (int k = numVet + j; k > i; k--)
            {
                novoVet[k] = novoVet[k - 1];
            }
            novoVet[i] = vetAux[j];
            j++;
        }
    }
    for (int i = j; i < numVetAux; i++)
    {
        novoVet[i + numVet] = vetAux[i];
    }
}
void ArvBinBusca::insereDoVetorDegenerada(int n, int *vet)
{
    int nNosArv = getNumNos();
    int nNosVetArv = 0;
    int tamMax = n + nNosArv;
    int *novoVet = new int[tamMax];
    copiaNosParaVetor(raiz, novoVet, &nNosVetArv);
    concatenaVetoresCrescente(novoVet, nNosArv, vet, n);

    libera(raiz);
    NoArv *p = new NoArv;
    p->setEsq(NULL);
    p->setDir(NULL);
    p->setInfo(novoVet[0]);
    raiz = p;
    for (int i = 1; i < tamMax; i++)
    {
        NoArv *novo = new NoArv;
        novo->setEsq(NULL);
        novo->setDir(NULL);
        novo->setInfo(novoVet[i]);
        p->setDir(novo);
        p = novo;
    }
}

// Ex04 - E.II -> 43 minutos e 52 segundos
NoArv *ArvBinBusca::auxInsereDoVetorCompleta(int ind, int tam, int *vet)
{
    if (ind == tam - 1)
        return NULL;
    int media = tam / 2;
    NoArv *novo = new NoArv;
    novo->setInfo(vet[media]);
    novo->setEsq(auxInsereDoVetorCompleta(0, media - 1, vet));
    novo->setDir(auxInsereDoVetorCompleta(media, tam, vet));
    return novo;
}
void ArvBinBusca::insereDoVetorCompleta(int n, int *vet)
{
    int nNosArv = getNumNos();
    int nNosVetArv = 0;
    int tamMax = n + nNosArv;
    int *novoVet = new int[tamMax];
    copiaNosParaVetor(raiz, novoVet, &nNosVetArv);
    concatenaVetoresCrescente(novoVet, nNosArv, vet, n);

    libera(raiz);
    raiz = auxInsereDoVetorCompleta(0, tamMax, novoVet);
}