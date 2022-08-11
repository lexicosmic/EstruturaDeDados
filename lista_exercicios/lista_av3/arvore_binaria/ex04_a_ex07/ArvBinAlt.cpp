#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <random>
#include "ArvBinAlt.h"

using namespace std;

bool randomBool()
{
    return rand() > (RAND_MAX / 2);
}

ArvBinAlt::ArvBinAlt()
{
    raiz = NULL;
}

ArvBinAlt::~ArvBinAlt()
{
    raiz = libera(raiz);
}

NoArv *ArvBinAlt::libera(NoArv *p)
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

int ArvBinAlt::atualizaAltura(NoArv *p, int h)
{
    if (p != NULL)
    {
        int hEsq = atualizaAltura(p->getEsq(), h + 1);
        int hDir = atualizaAltura(p->getDir(), h + 1);
        p->setAltura(max(hEsq, hDir));
    }
    return h - 1;
}

// Ex04 -> 23 minutos e 05 segundos
void ArvBinAlt::cria(int valRaiz, ArvBinAlt *sae, ArvBinAlt *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(valRaiz);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    atualizaAltura(p, 0);
    raiz = p;
}

void ArvBinAlt::imprime()
{
    if (raiz == NULL)
        cout << "Arvore vazia!" << endl;
    else
        imprimePorNivel(raiz);
}
void ArvBinAlt::imprimePorNivel(NoArv *p)
{
    if (p == NULL)
        return;
    int nivel = p->getAltura();
    imprimePorNivel(p->getDir());
    cout << "(" << nivel << ")";
    for (int i = 0; i < nivel; i++)
        cout << "\t";
    cout << p->getInfo() << endl;
    imprimePorNivel(p->getEsq());
}

// Ex05 -> 5 minutos e 31 segundos
void ArvBinAlt::alturaNos()
{
    atualizaAltura(raiz, 0);
    return;
}

// Ex06 -> 11 minutos e 31 segundos
NoArv *ArvBinAlt::auxNoAlt(NoArv *p, int alt)
{
    if (p == NULL)
        return NULL;

    int altura = p->getAltura();
    if (altura == alt)
        return p;

    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    NoArv *encEsq = auxNoAlt(esq, alt);
    if (encEsq != NULL)
        return encEsq;
    else
    {
        NoArv *encDir = auxNoAlt(dir, alt);
        return encDir;
    }
}
NoArv *ArvBinAlt::noAlt(int alt)
{
    return auxNoAlt(raiz, alt);
}
int ArvBinAlt::noAltInfo(int alt)
{
    NoArv *p = auxNoAlt(raiz, alt);
    if (p == NULL)
        return 0;
    else
        return p->getInfo();
}

// Ex07 -> 40 minutos e 37 segundos
bool ArvBinAlt::auxEAVL(NoArv *p, int *anterior, bool *primeiro, int *alt)
{
    if (p == NULL)
    {
        *alt = -1;
        return true;
    }

    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    int info = p->getInfo();

    int altEsq = 0;
    bool esqEAVL = auxEAVL(esq, anterior, primeiro, &altEsq);

    if (*primeiro)
    {
        *anterior = info;
        *primeiro = false;
    }

    if (*anterior > info)
        return false;

    *anterior = info;

    int altDir = 0;
    bool dirEAVL = auxEAVL(dir, anterior, primeiro, &altDir);

    (*alt) = max(altEsq, altDir) + 1;

    int diferenca = altEsq - altDir;
    bool diferencaPermitida = -1 <= diferenca && diferenca <= 1;

    return esqEAVL && dirEAVL && diferencaPermitida;
}
bool ArvBinAlt::eAVL()
{
    if (raiz == NULL)
        return true;
    int anterior = raiz->getInfo();
    bool primeiro = true;
    int alt = 0;
    return auxEAVL(raiz, &anterior, &primeiro, &alt);
}