#include "ArvBinBusca.h"
#include <cmath>

// ----------------------------------------------------------------------------
// Q1 -> 14 minutos e 44 segundos

void ArvBinBusca::auxNosImpares02Filhos(NoArv *p, int *nImp, int *n02F)
{
    if (p == NULL)
        return;
    int info = p->getInfo();
    if (info % 2 != 0)
        (*nImp)++;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    if ((esq == NULL && dir == NULL) || (esq != NULL && dir != NULL))
        (*n02F)++;
    auxNosImpares02Filhos(esq, nImp, n02F);
    auxNosImpares02Filhos(dir, nImp, n02F);
}

void ArvBinBusca::nosImpares02Filhos(int *nImp, int *n02F)
{
    *nImp = 0;
    *n02F = 0;
    auxNosImpares02Filhos(raiz, nImp, n02F);
}

//-Q1

// ----------------------------------------------------------------------------
// Q2 -> 16 minutos e 32 segundos

void ArvBinBusca::insNaoRec(int val)
{
    NoArv *p = raiz;
    bool inserirEsq = true;
    while (p != NULL)
    {
        int info = p->getInfo();
        NoArv *esq = p->getEsq();
        if (val < info)
        {
            if (esq != NULL)
                p = esq;
            else
                break;
        }
        else if (val > info)
        {
            NoArv *dir = p->getDir();
            if (dir != NULL)
                p = dir;
            else
            {
                inserirEsq = false;
                break;
            }
        }
        else // Encontrou igual
        {
            cout << "ERRO: Ja existe no com este valor!" << endl;
            return;
        }
    }

    NoArv *novo = new NoArv;
    novo->setInfo(val);
    novo->setEsq(NULL);
    novo->setDir(NULL);

    if (p == NULL)
        raiz = novo;
    else
    {
        if (inserirEsq)
            p->setEsq(novo);
        else
            p->setDir(novo);
    }
}

//-Q2

// ----------------------------------------------------------------------------
// Q3 -> Sem eficiência de ABB: 30 minutos e 43 segundos
//       Com eficiência de ABB: 36 minutos e 31 segundos
//       Considerando raiz nula: 44 minutos e 29 segundos
void ArvBinBusca::auxImprimePorNivel(NoArv *p, int k)
{
    if (p == NULL)
        return;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    int info = p->getInfo();

    auxImprimePorNivel(esq, k + 1);
    cout << "(" << k << ")";
    for (int i = 0; i < k; i++)
    {
        cout << "\t";
    }
    cout << info << endl;
    auxImprimePorNivel(dir, k + 1);
}
void ArvBinBusca::imprimePorNivel()
{
    auxImprimePorNivel(raiz, 0);
}

void ArvBinBusca::auxVetIntervalo(NoArv *p, int a, int b, int k, int *vet, int *numVet)
{
    if (p == NULL)
        return;
    int info = p->getInfo();
    if (a <= info)
        auxVetIntervalo(p->getEsq(), a, b, k - 1, vet, numVet);
    if (k == 0)
    {
        if (a <= info && info <= b)
        {
            vet[*numVet] = info;
            (*numVet)++;
        }
    }
    if (b >= info)
        auxVetIntervalo(p->getDir(), a, b, k - 1, vet, numVet);
}
int *ArvBinBusca::vetIntervalo(int a, int b, int k)
{
    int *vet = NULL;
    if (raiz != NULL)
    {
        int tamMaxVet = 1 + pow(2, k);
        vet = new int[tamMaxVet];
        int *numVet = new int(0);
        auxVetIntervalo(raiz, a, b, k, vet, numVet);

        for (int i = *numVet; i < tamMaxVet; i++)
        {
            vet[i] = -1;
        }
        delete numVet;
    }
    else
    {
        vet = new int[1];
        vet[0] = -1;
    }

    return vet;
}

//-Q3

// ----------------------------------------------------------------------------
// Restante da classe ArvBinBusca
// ----------------------------------------------------------------------------

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    /// destrutor vazio (s� para avalia��o)
}

void ArvBinBusca::cria(int c, ArvBinBusca *sae, ArvBinBusca *sad)
{ /// S� para a avalia��o.
    NoArv *p = new NoArv();
    p->setInfo(c);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBinBusca::addValores1()
{ // adiciona valores em uma ABB
    ArvBinBusca *arvRaizNula = new ArvBinBusca(), a1, a2;

    a1.cria(-35, arvRaizNula, arvRaizNula);
    this->cria(-19, arvRaizNula, arvRaizNula);
    this->cria(-20, &a1, this);

    a1.cria(-5, arvRaizNula, arvRaizNula);
    a1.cria(10, &a1, arvRaizNula);
    this->cria(-15, this, &a1);

    a1.cria(45, arvRaizNula, arvRaizNula);
    a2.cria(60, arvRaizNula, arvRaizNula);
    a1.cria(50, &a1, &a2);

    a2.cria(80, arvRaizNula, arvRaizNula);
    a1.cria(75, &a1, &a2);

    this->cria(40, this, &a1);
}

void ArvBinBusca::addValores2()
{ // adiciona valores em uma ABB
    ArvBinBusca *arvRaizNula = new ArvBinBusca(), a1, a2;

    this->cria(-35, arvRaizNula, arvRaizNula);
    this->cria(-20, this, arvRaizNula);

    a1.cria(-5, arvRaizNula, arvRaizNula);
    a1.cria(10, &a1, arvRaizNula);
    this->cria(-15, this, &a1);

    a1.cria(60, arvRaizNula, arvRaizNula);
    a1.cria(50, arvRaizNula, &a1);
    this->cria(40, this, &a1);
}

void ArvBinBusca::imprime()
{
    auxImprime(raiz);
    cout << endl;
}

void ArvBinBusca::auxImprime(NoArv *p)
{
    if (p != NULL)
    {
        auxImprime(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprime(p->getDir());
    }
}
