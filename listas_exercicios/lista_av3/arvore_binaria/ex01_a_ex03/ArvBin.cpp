#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <random>
#include "ArvBin.h"

using namespace std;

bool randomBool()
{
    return rand() > (RAND_MAX / 2);
}

ArvBin::ArvBin()
{
    raiz = NULL;
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv *ArvBin::libera(NoArv *p)
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

void ArvBin::insere(int val)
{
    raiz = auxInsereAleatorio(raiz, val);
}
NoArv *ArvBin::auxInsereAbb(NoArv *p, int val)
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
        p->setEsq(auxInsereAbb(p->getEsq(), val));
    else
        p->setDir(auxInsereAbb(p->getDir(), val));
    return p;
}
NoArv *ArvBin::auxInsereAleatorio(NoArv *p, int val)
{
    if (p == NULL)
    {
        NoArv *novo = new NoArv;
        novo->setEsq(NULL);
        novo->setDir(NULL);
        novo->setInfo(val);
        p = novo;
    }
    else if (randomBool())
        p->setEsq(auxInsereAbb(p->getEsq(), val));
    else
        p->setDir(auxInsereAbb(p->getDir(), val));
    return p;
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::imprime()
{
    if (raiz == NULL)
        cout << "Arvore vazia!" << endl;
    else
        imprimePorNivel(raiz, 0);
}
void ArvBin::imprimePorNivel(NoArv *p, int nivel)
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

// Ex01 - A -> 5 minutos e 55 segundos
int ArvBin::auxImpares(NoArv *p)
{
    if (p == NULL)
        return 0;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    int imparesEsq = auxImpares(esq);
    int imparesDir = auxImpares(dir);
    int ehImpar = 0;
    if (p->getInfo() % 2 != 0)
        ehImpar++;
    return imparesEsq + imparesDir + ehImpar;
}
int ArvBin::impares() { return auxImpares(raiz); }

// Ex01 - B -> 3 minutos e 31 segundos
int ArvBin::auxSoma(NoArv *p)
{
    if (p == NULL)
        return 0;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    int somaEsq = auxSoma(esq);
    int somaDir = auxSoma(dir);
    int info = p->getInfo();
    return somaEsq + somaDir + info;
}
int ArvBin::soma() { return auxSoma(raiz); }

// Ex01 - C -> 4 minutos
int ArvBin::auxMedia(NoArv *p, int *nNos)
{
    if (p == NULL)
        return 0;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    int somaEsq = auxMedia(esq, nNos);
    int somaDir = auxMedia(dir, nNos);
    int info = p->getInfo();
    (*nNos)++;
    return somaEsq + somaDir + info;
}
float ArvBin::media()
{
    if (raiz == NULL)
        return 0;
    int nNos = 0;
    int soma = auxMedia(raiz, &nNos);
    return soma / (float)nNos;
}

// Ex01 - D -> 6 minutos
int ArvBin::auxMediaPares(NoArv *p, int *nNosPares)
{
    if (p == NULL)
        return 0;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    int somaParesEsq = auxMediaPares(esq, nNosPares);
    int somaParesDir = auxMediaPares(dir, nNosPares);
    int info = p->getInfo();
    int infoRetorno = 0;
    if (info % 2 == 0)
    {
        infoRetorno = info;
        (*nNosPares)++;
    }
    return somaParesEsq + somaParesDir + infoRetorno;
}
float ArvBin::mediaPares()
{
    if (raiz == NULL)
        return 0;
    int nNosPares = 0;
    int somaPares = auxMediaPares(raiz, &nNosPares);
    if (nNosPares > 0)
        return somaPares / (float)nNosPares;
    else
        return 0;
}

// Ex01 - E -> 6 minutos e 25 segundos
void ArvBin::auxMaiorValor(NoArv *p, int *maior)
{
    if (p == NULL)
        return;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    auxMaiorValor(esq, maior);
    auxMaiorValor(dir, maior);
    int info = p->getInfo();
    if (info > *maior)
        *maior = info;
}
int ArvBin::maiorValor()
{
    if (raiz == NULL)
        return 0;
    int maior = raiz->getInfo();
    auxMaiorValor(raiz, &maior);
    return maior;
}

// Ex01 - F -> 2 minutos e 19 segundos
void ArvBin::auxMenorValor(NoArv *p, int *menor)
{
    if (p == NULL)
        return;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    auxMenorValor(esq, menor);
    auxMenorValor(dir, menor);
    int info = p->getInfo();
    if (info < *menor)
        *menor = info;
}
int ArvBin::menorValor()
{
    if (raiz == NULL)
        return 0;
    int menor = raiz->getInfo();
    auxMenorValor(raiz, &menor);
    return menor;
}

// Ex01 - G -> 8 minutos e 14 segundos
int ArvBin::auxMaiores(NoArv *p, int chave)
{
    if (p == NULL)
        return 0;
    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    int maioresEsq = auxMaiores(esq, chave);
    int maioresDir = auxMaiores(dir, chave);
    int info = p->getInfo();
    int retorno = 0;
    if (info > chave)
        retorno++;
    return maioresEsq + maioresDir + retorno;
}
int ArvBin::maiores(int chave)
{
    if (raiz == NULL)
        return 0;
    return auxMaiores(raiz, chave);
}

// Ex01 - H -> 10 minutos e 47 segundos
int ArvBin::auxMediaNivel(NoArv *p, int *nNosNivel, int nivel)
{
    if (p == NULL)
        return 0;
    else if (nivel == 0)
    {
        int info = p->getInfo();
        (*nNosNivel)++;
        return info;
    }
    else
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        int somaNivelEsq = auxMediaNivel(esq, nNosNivel, nivel - 1);
        int somaNivelDir = auxMediaNivel(dir, nNosNivel, nivel - 1);
        return somaNivelEsq + somaNivelDir;
    }
}
float ArvBin::mediaNivel(int nivel)
{
    if (raiz == NULL)
        return 0;
    int nNosNivel = 0;
    int somaNivel = auxMediaNivel(raiz, &nNosNivel, nivel);
    if (nNosNivel > 0)
        return somaNivel / (float)nNosNivel;
    else
        return 0;
}

// Ex01 - I -> 24 minutos e 10 segundos
void ArvBin::auxImprimirNivelPreOrdem(NoArv *p, int nivel)
{
    if (p != NULL && nivel >= 0)
    {
        int info = p->getInfo();
        cout << info << "\t";
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        auxImprimirNivelPreOrdem(esq, nivel - 1);
        auxImprimirNivelPreOrdem(dir, nivel - 1);
    }
}
void ArvBin::auxImprimirNivelEmOrdem(NoArv *p, int nivel)
{
    if (p != NULL && nivel >= 0)
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        auxImprimirNivelEmOrdem(esq, nivel - 1);
        int info = p->getInfo();
        cout << info << "\t";
        auxImprimirNivelEmOrdem(dir, nivel - 1);
    }
}
void ArvBin::auxImprimirNivelPosOrdem(NoArv *p, int nivel)
{
    if (p != NULL && nivel >= 0)
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        auxImprimirNivelPosOrdem(esq, nivel - 1);
        auxImprimirNivelPosOrdem(dir, nivel - 1);
        int info = p->getInfo();
        cout << info << "\t";
    }
}
void ArvBin::imprimirNivel(int nivel)
{
    if (raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return;
    }
    cout << endl
         << "Pre-ordem:" << endl;
    auxImprimirNivelPreOrdem(raiz, nivel);
    cout << endl
         << "Em-ordem:" << endl;
    auxImprimirNivelEmOrdem(raiz, nivel);
    cout << endl
         << "Pos-ordem:" << endl;
    auxImprimirNivelPosOrdem(raiz, nivel);
    cout << endl;
}

// Ex01 - J -> 45 minutos e 03 segundos
void ArvBin::auxSucessor(NoArv *p, int val, int *sucessor, bool *encontrado)
{
    if (p == NULL)
        return;

    int info = p->getInfo();
    if (info > val)
    {
        if (*encontrado)
        {
            if (info < *sucessor)
            {
                *sucessor = info;
            }
        }
        else
        {
            *sucessor = info;
            *encontrado = true;
        }
    }

    NoArv *esq = p->getEsq();
    NoArv *dir = p->getDir();
    auxSucessor(esq, val, sucessor, encontrado);
    auxSucessor(dir, val, sucessor, encontrado);
}
int ArvBin::sucessor(int val)
{
    if (raiz == NULL)
        return val;
    bool encontrado = false;
    int valSucessor = val;
    auxSucessor(raiz, val, &valSucessor, &encontrado);
    return valSucessor;
}

// Ex02 -> 19 minutos e 45 segundos
int ArvBin::auxECheia(NoArv *p, int *nNos)
{
    if (p == NULL)
        return -1;
    (*nNos)++;
    int hEsq = auxECheia(p->getEsq(), nNos);
    int hDir = auxECheia(p->getDir(), nNos);
    return max(hEsq, hDir) + 1;
}
bool ArvBin::eCheia()
{
    int nNos = 0;
    int h = auxECheia(raiz, &nNos);
    int esperado = pow(2, h + 1) - 1;
    return nNos == esperado;
}

// Ex03 -> 11 minutos e 08 segundos
int ArvBin::getAltura(NoArv *p)
{
    if (p == NULL)
        return -1;
    int hEsq = getAltura(p->getEsq());
    int hDir = getAltura(p->getDir());
    return max(hEsq, hDir) + 1;
}
int ArvBin::getNumNosAteNivel(NoArv *p, int nivel)
{
    if (p != NULL && nivel >= 0)
    {
        int nNosEsq = getNumNosAteNivel(p->getEsq(), nivel - 1);
        int nNosDir = getNumNosAteNivel(p->getDir(), nivel - 1);
        return nNosEsq + nNosDir + 1;
    }
    else
        return 0;
}
bool ArvBin::eCompleta()
{
    int h = getAltura(raiz);
    int nNos = getNumNosAteNivel(raiz, h - 1);
    int esperado = pow(2, h) - 1;
    return nNos == esperado;
}