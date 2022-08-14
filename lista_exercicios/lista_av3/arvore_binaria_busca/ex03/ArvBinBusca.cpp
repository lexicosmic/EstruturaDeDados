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

void ArvBinBusca::insere(int matricula, string nome, string disciplina, string turma, float media)
{
    raiz = auxInsere(raiz, matricula, nome, disciplina, turma, media);
}

NoArv *ArvBinBusca::auxInsere(NoArv *p, int matricula, string nome, string disciplina, string turma, float media)
{
    if (p == NULL)
    {
        NoArv *novo = new NoArv;
        novo->setEsq(NULL);
        novo->setDir(NULL);
        novo->setMatricula(matricula);
        novo->setNome(nome);
        novo->setDisciplina(disciplina);
        novo->setTurma(turma);
        novo->setMedia(media);
        p = novo;
    }
    else if (media < p->getMedia())
        p->setEsq(auxInsere(p->getEsq(), matricula, nome, disciplina, turma, media));
    else
        p->setDir(auxInsere(p->getDir(), matricula, nome, disciplina, turma, media));
    return p;
}

bool ArvBinBusca::busca(float media)
{
    return auxBusca(raiz, media);
}

bool ArvBinBusca::auxBusca(NoArv *p, float media)
{
    if (p == NULL)
        return false;
    if (p->getMedia() == media)
        return true;
    else if (p->getMedia() < media)
        return auxBusca(p->getDir(), media);
    else
        return auxBusca(p->getEsq(), media);
}

void ArvBinBusca::remove(float media)
{
    raiz = auxRemove(raiz, media);
}

NoArv *ArvBinBusca::auxRemove(NoArv *p, float media)
{
    if (p == NULL)
        return NULL;
    else if (p->getMedia() < media)
        p->setDir(auxRemove(p->getDir(), media));
    else if (p->getMedia() > media)
        p->setEsq(auxRemove(p->getEsq(), media));
    else
    {
        if (p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if (p->getEsq() == NULL || p->getDir() == NULL)
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            float auxFloat = aux->getMedia();
            p->setMedia(auxFloat);
            p->setNome(aux->getNome());
            p->setDisciplina(aux->getDisciplina());
            p->setTurma(aux->getTurma());
            p->setMatricula(aux->getMatricula());
            aux->setMedia(media);
            p->setDir(auxRemove(p->getDir(), media));
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
    cout << p->getMatricula() << "_" << p->getTurma() << " " << p->getNome() << " - " << p->getDisciplina() << ": " << p->getMedia() << endl;
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

// 51 minutos e 24 segundos (implementação anterior e esta função)
void ArvBinBusca::auxImprimeAluno(NoArv *p, float media)
{
    if (p == NULL)
    {
        cout << "Aluno nao encontrado" << endl;
        return;
    }
    if (p->getMedia() == media)
    {
        cout << p->getMedia() << "_" << p->getTurma() << " " << p->getNome() << " - " << p->getDisciplina() << ": " << media << endl;
    }
    else if (p->getMedia() < media)
        return auxImprimeAluno(p->getDir(), media);
    else
        return auxImprimeAluno(p->getEsq(), media);
}
void ArvBinBusca::imprimeAluno(float media)
{
    return auxImprimeAluno(raiz, media);
}

// 13 minutos e 10 segundos
NoArv *ArvBinBusca::auxImprimeMaiorMedia(NoArv *p)
{
    if (p == NULL)
        return NULL;
    while (p->getDir() != NULL)
    {
        p = auxImprimeMaiorMedia(p->getDir());
    }
    return p;
}
void ArvBinBusca::imprimeMaiorMedia()
{
    NoArv *maior = auxImprimeMaiorMedia(raiz);
    if (maior == NULL)
    {
        rotinaErro(1);
        return;
    }
    cout << (maior)->getMatricula() << "_" << (maior)->getTurma() << " " << (maior)->getNome()
         << " - " << (maior)->getDisciplina() << ": " << (maior)->getMedia() << endl;
}

// 02 minutos e 05 segundos
NoArv *ArvBinBusca::auxImprimeMenorMedia(NoArv *p)
{
    if (p == NULL)
        return NULL;
    while (p->getDir() != NULL)
    {
        p = auxImprimeMenorMedia(p->getEsq());
    }
    return p;
}
void ArvBinBusca::imprimeMenorMedia()
{
    NoArv *menor = auxImprimeMenorMedia(raiz);
    if (menor == NULL)
    {
        rotinaErro(1);
        return;
    }
    cout << (menor)->getMatricula() << "_" << (menor)->getTurma() << " " << (menor)->getNome()
         << " - " << (menor)->getDisciplina() << ": " << (menor)->getMedia() << endl;
}
