#include "ArvBinBusca.h"
#include <cmath>

// ----------------------------------------------------------------------------
// Q1 -> 07 minutos e 14 segundos
bool ArvBinBusca::auxEhEstritamente(No *p)
{
    if (p == NULL)
        return true;
    No *esq = p->getEsq();
    No *dir = p->getDir();
    bool estBinEsq = true;
    bool estBinDir = true;
    if ((esq == NULL && dir == NULL) || (esq != NULL && dir != NULL))
    {
        estBinEsq = auxEhEstritamente(esq);
        estBinDir = auxEhEstritamente(esq);
        return estBinEsq && estBinDir;
    }
    else
        return false;
}
bool ArvBinBusca::ehEstritamente()
{
    return auxEhEstritamente(raiz);
}

//-Q1
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Q2 -> 18 minutos e 46 segundos
void ArvBinBusca::maisProximo(int ch)
{
    if (raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return;
    }
    No *p = raiz;
    int info = p->getInfo();
    int anterior = info;
    while (p != NULL)
    {
        anterior = info;
        info = p->getInfo();
        if (ch < info)
        {
            p = p->getEsq();
        }
        else if (ch > info)
        {
            p = p->getDir();
        }
        else
        {
            cout << "encontrado, ";
            break;
        }
    }
    int maisProx = anterior;
    if (abs(info - ch) < abs(anterior - ch))
        maisProx = info;
    cout << "valor = " << maisProx << ", diferenca = " << abs(maisProx - ch) << endl;
}
//-Q2
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Q3 -> 15 minutos e 04 segundos
int *ArvBinBusca::criaVetCaminho(int x, int *num)
{
    if (raiz == NULL)
        return NULL;
    No *p = raiz;
    int h = altura();
    int tamMax = h + 1;
    int *vet = new int[tamMax];
    *num = 0;
    while (p != NULL)
    {
        int info = p->getInfo();
        vet[*num] = info;
        (*num)++;
        if (x < info)
            p = p->getEsq();
        else if (x > info)
            p = p->getDir();
        else
            break;
    }
    for (int i = *num; i < tamMax; i++)
    {
        vet[i] = -1;
    }
    *num = tamMax;
    return vet;
}
//-Q3
// ----------------------------------------------------------------------------

// Restante da classe da ABB --------------------------------------------------

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
}

int ArvBinBusca::consultaRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Erro em consultaRaiz(): arvore vazia" << endl;
        exit(1);
    }
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

int ArvBinBusca::altura()
{
    return auxAltura(raiz);
}

int ArvBinBusca::auxAltura(No *p)
{
    int he, hd;
    if (p == NULL)
        return -1;
    else
    {
        he = auxAltura(p->getEsq());
        hd = auxAltura(p->getDir());
        if (he > hd)
            return 1 + he;
        else
            return 1 + hd;
    }
}

void ArvBinBusca::insere(int x)
{
    No *p = auxInsere(raiz, x);
    if (raiz == NULL)
        raiz = p;
}

No *ArvBinBusca::auxInsere(No *p, int x)
{
    if (p == NULL)
    {
        p = new No();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if (x < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), x));
    else
        p->setDir(auxInsere(p->getDir(), x));

    return p;
}

bool ArvBinBusca::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBinBusca::auxBusca(No *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (x < p->getInfo())
        return auxBusca(p->getEsq(), x);
    else
        return auxBusca(p->getDir(), x);
}

void ArvBinBusca::imprime()
{
    auxImprime(raiz, 0);
}

void ArvBinBusca::auxImprime(No *p, int nivel)
{
    if (p != NULL)
    {
        auxImprime(p->getEsq(), nivel + 1);
        cout << "(" << nivel << ")";
        for (int i = 1; i <= nivel; i++)
            cout << "\t";
        cout << p->getInfo() << endl;
        auxImprime(p->getDir(), nivel + 1);
    }
}

int ArvBinBusca::numNos()
{
    return auxNumNos(raiz);
}

int ArvBinBusca::auxNumNos(No *p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + auxNumNos(p->getEsq()) + auxNumNos(p->getDir());
}
