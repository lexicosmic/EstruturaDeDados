#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "�rvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if (!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv *ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if (linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv *ArvBin::auxInsere(NoArv *p, int x)
{
    if (p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if (direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
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
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

// Ex01
int ArvBin::auxContaNos(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        int nNosEsq = auxContaNos(p->getEsq());
        int nNosDir = auxContaNos(p->getDir());
        return 1 + nNosEsq + nNosDir;
    }
}
int ArvBin::contaNos() { return auxContaNos(raiz); }

// Ex02
int ArvBin::auxContaNosFolhas(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        int nFolhasEsq = auxContaNosFolhas(esq);
        int nFolhasDir = auxContaNosFolhas(dir);
        if (esq == NULL & dir == NULL)
            return 1;
        else
            return nFolhasEsq + nFolhasDir;
    }
}
int ArvBin::contaNosFolhas() { return auxContaNosFolhas(raiz); }

// Ex03
int ArvBin::auxAltura(NoArv *p)
{
    if (p == NULL)
        return -1;
    else
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        int hEsq = auxAltura(esq);
        int hDir = auxAltura(dir);
        int maximo = hEsq;
        if (hDir > hEsq)
            maximo = hDir;
        return 1 + maximo;
    }
}
int ArvBin::altura() { return auxAltura(raiz); }

// Ex04
int ArvBin::auxContaImpar(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        int nImpEsq = auxContaImpar(esq);
        int nImpDir = auxContaImpar(dir);
        int nImpTot = nImpEsq + nImpDir;
        if (p->getInfo() % 2 != 0)
            nImpTot++;
        return nImpTot;
    }
}
int ArvBin::contaImpar() { return auxContaImpar(raiz); }

// Ex05
int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        int nFolhasImpEsq = auxContaFolhaImpar(esq);
        int nFolhasImpDir = auxContaFolhaImpar(dir);
        if (esq == NULL & dir == NULL && p->getInfo() % 2 != 0)
            return 1;
        else
            return nFolhasImpEsq + nFolhasImpDir;
    }
}
int ArvBin::contaFolhaImpar() { return auxContaFolhaImpar(raiz); }

// Ex06
void ArvBin::auxImprimeNivel(NoArv *p, int kp, int k)
{
    if (p != NULL)
    {
        if (kp == k)
            cout << p->getInfo() << " ";
        auxImprimeNivel(p->getEsq(), kp, k + 1);
        auxImprimeNivel(p->getDir(), kp, k + 1);
    }
}
void ArvBin::imprimeNivel(int kp) { return auxImprimeNivel(raiz, kp, 0); }

// Ex07
void ArvBin::auxMediaNivel(NoArv *p, int kp, int k, int *nNos, int *soma)
{
    if (p == NULL)
        return;
    else
    {
        if (kp == k)
        {
            (*nNos)++;
            (*soma) += p->getInfo();
        }

        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        auxMediaNivel(esq, kp, k + 1, nNos, soma);
        auxMediaNivel(dir, kp, k + 1, nNos, soma);
    }
}
float ArvBin::mediaNivel(int kp)
{
    int nNos = 0;
    int soma = 0;
    auxMediaNivel(raiz, kp, 0, &nNos, &soma);
    float media = 0;
    if (nNos > 0)
    {
        media = soma / (float)nNos;
    }
    return media;
}

// Ex08
void ArvBin::auxMin(NoArv *p, int *min)
{
    if (p == NULL)
        return;
    else
    {
        int atual = p->getInfo();
        if (atual < *min)
            *min = atual;
        auxMin(p->getEsq(), min);
        auxMin(p->getDir(), min);
    }
}
int ArvBin::min()
{
    int min;
    if (raiz != NULL)
        min = raiz->getInfo();
    else
        return 0;
    auxMin(raiz, &min);
    return min;
}
void ArvBin::auxMax(NoArv *p, int *max)
{
    if (p == NULL)
        return;
    else
    {
        int atual = p->getInfo();
        if (atual > *max)
            *max = atual;
        auxMax(p->getEsq(), max);
        auxMax(p->getDir(), max);
    }
}
int ArvBin::max()
{
    int max;
    if (raiz != NULL)
        max = raiz->getInfo();
    else
        return 0;
    auxMax(raiz, &max);
    return max;
}

// Ex09
void ArvBin::auxInverte(NoArv *p)
{
    if (p == NULL)
        return;
    else
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        p->setEsq(dir);
        p->setDir(esq);
        auxInverte(esq);
        auxInverte(dir);
    }
}
void ArvBin::inverte() { auxInverte(raiz); }

void ArvBin::auxImprimePorNivel(NoArv *p, int k)
{
    if (p == NULL)
        return;
    else
    {
        auxImprimePorNivel(p->getDir(), k + 1);
        for (int i = 0; i < k; i++)
            cout << "\t";
        cout << p->getInfo() << endl;
        auxImprimePorNivel(p->getEsq(), k + 1);
    }
}
void ArvBin::imprimePorNivel() { auxImprimePorNivel(raiz, 0); }

// Ex10
int ArvBin::auxNoMaisEsquerda(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        int valor = p->getInfo();
        NoArv *esq = p->getEsq();
        if (esq == NULL)
            return valor;
        else
            return auxNoMaisEsquerda(p->getEsq());
    }
}
int ArvBin::noMaisEsquerda() { return auxNoMaisEsquerda(raiz); }
int ArvBin::auxNoMaisDireita(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        int valor = p->getInfo();
        NoArv *dir = p->getDir();
        if (dir == NULL)
            return valor;
        else
            return auxNoMaisDireita(p->getDir());
    }
}
int ArvBin::noMaisDireita() { return auxNoMaisDireita(raiz); }

// Ex11
void ArvBin::auxMinSubArvore(NoArv *p, int *min)
{
    if (p == NULL)
        return;
    else
    {
        int atual = p->getInfo();
        if (atual < *min)
            *min = atual;
        auxMinSubArvore(p->getEsq(), min);
        auxMinSubArvore(p->getDir(), min);
    }
}
int ArvBin::minSubArvore(NoArv *p)
{
    if (p == NULL)
        return 0;
    int min;
    min = p->getInfo();
    auxMinSubArvore(p, &min);
    return min;
}
void ArvBin::auxMaxSubArvore(NoArv *p, int *max)
{
    if (p == NULL)
        return;
    else
    {
        int atual = p->getInfo();
        if (atual > *max)
            *max = atual;
        auxMaxSubArvore(p->getEsq(), max);
        auxMaxSubArvore(p->getDir(), max);
    }
}
int ArvBin::maxSubArvore(NoArv *p)
{
    if (p == NULL)
        return 0;
    int max;
    max = p->getInfo();
    auxMaxSubArvore(p, &max);
    return max;
}

NoArv *ArvBin::getNoRaiz() { return raiz; }

// Ex12
bool ArvBin::auxEhABB(NoArv *p)
{
    if (p == NULL)
        return true;
    else
    {
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();
        if (esq != NULL)
        {
            int minEsq = minSubArvore(esq);
            if (minEsq > p->getInfo())
                return false;
            auxEhABB(esq);
        }
        if (dir != NULL)
        {
            int minDir = minSubArvore(dir);
            if (minDir < p->getInfo())
                return false;
            auxEhABB(dir);
        }
        return true;
    }
}
bool ArvBin::ehABB() { return auxEhABB(raiz); }