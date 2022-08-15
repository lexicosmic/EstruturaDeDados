#include "ArvBinBusca.h"
#include <cmath>

// ----------------------------------------------------------------------------
// Q1 -> 22 minutos e 51 segundos
void ArvBinBusca::auxContaIntervalo(No *p, int a, int b, int *num)
{
    if (p == NULL)
        return;
    int info = p->getInfo();
    if (a <= info)
        auxContaIntervalo(p->getEsq(), a, b, num);
    if (a <= info && info <= b)
        (*num)++;
    if (b >= info)
        auxContaIntervalo(p->getDir(), a, b, num);
}
int ArvBinBusca::contaIntervalo(int a, int b)
{
    if (raiz == NULL)
        return 0;
    int num = 0;
    auxContaIntervalo(raiz, a, b, &num);
    return num;
}
//-Q1
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Q2 -> 08 minutos e 41 segundos
No *ArvBinBusca::buscaPai(int x)
{
    if (raiz == NULL)
        return NULL;
    No *p = raiz;
    No *pai = NULL;
    bool encontrado = false;
    while (p != NULL)
    {
        int info = p->getInfo();
        if (x < info)
        {
            pai = p;
            p = p->getEsq();
        }
        else if (x > info)
        {
            pai = p;
            p = p->getDir();
        }
        else
        {
            encontrado = true;
            break;
        }
    }
    if (encontrado)
        return pai;
    else
        return NULL;
}
//-Q2
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Q3 -> 14 minutos e 40 segundos
void ArvBinBusca::auxCriaVetNivel(No *p, int *vet, int *num, int k)
{
    if (p == NULL)
        return;
    if (k >= 0)
    {
        auxCriaVetNivel(p->getEsq(), vet, num, k - 1);
        if (k == 0)
        {
            vet[*num] = p->getInfo();
            (*num)++;
        }
        auxCriaVetNivel(p->getDir(), vet, num, k - 1);
    }
}
int *ArvBinBusca::criaVetNivel(int k)
{
    int tamMax = pow(2, k);
    int *vet = new int[tamMax];
    int *num = new int(0);
    if (raiz != NULL)
        auxCriaVetNivel(raiz, vet, num, k);
    for (int i = *num; i < tamMax; i++)
        vet[i] = -1;
    delete num;
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
        auxImprime(p->getDir(), nivel + 1);
        cout << "(" << nivel << ")";
        for (int i = 1; i <= nivel; i++)
            cout << "\t";
        cout << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel + 1);
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
