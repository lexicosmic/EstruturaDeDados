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
    else if (matricula < p->getMatricula())
        p->setEsq(auxInsere(p->getEsq(), matricula, nome, disciplina, turma, media));
    else
        p->setDir(auxInsere(p->getDir(), matricula, nome, disciplina, turma, media));
    return p;
}

bool ArvBinBusca::busca(int matricula)
{
    return auxBusca(raiz, matricula);
}

bool ArvBinBusca::auxBusca(NoArv *p, int matricula)
{
    if (p == NULL)
        return false;
    if (p->getMatricula() == matricula)
        return true;
    else if (p->getMatricula() < matricula)
        return auxBusca(p->getDir(), matricula);
    else
        return auxBusca(p->getEsq(), matricula);
}

void ArvBinBusca::remove(int matricula)
{
    raiz = auxRemove(raiz, matricula);
}

NoArv *ArvBinBusca::auxRemove(NoArv *p, int matricula)
{
    if (p == NULL)
        return NULL;
    else if (p->getMatricula() < matricula)
        p->setDir(auxRemove(p->getDir(), matricula));
    else if (p->getMatricula() > matricula)
        p->setEsq(auxRemove(p->getEsq(), matricula));
    else
    {
        if (p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if (p->getEsq() == NULL || p->getDir() == NULL)
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int auxInt = aux->getMatricula();
            p->setMatricula(auxInt);
            p->setNome(aux->getNome());
            p->setDisciplina(aux->getDisciplina());
            p->setTurma(aux->getTurma());
            p->setMedia(aux->getMedia());
            aux->setMatricula(matricula);
            p->setDir(auxRemove(p->getDir(), matricula));
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
void ArvBinBusca::auxImprimeAluno(NoArv *p, int matricula)
{
    if (p == NULL)
    {
        cout << "Aluno nao encontrado" << endl;
        return;
    }
    if (p->getMatricula() == matricula)
    {
        cout << matricula << "_" << p->getTurma() << " " << p->getNome() << " - " << p->getDisciplina() << ": " << p->getMedia() << endl;
    }
    else if (p->getMatricula() < matricula)
        return auxImprimeAluno(p->getDir(), matricula);
    else
        return auxImprimeAluno(p->getEsq(), matricula);
}
void ArvBinBusca::imprimeAluno(int matricula)
{
    return auxImprimeAluno(raiz, matricula);
}

// 18 minutos e 22 segundos
void ArvBinBusca::auxImprimeMaiorMedia(NoArv *p, NoArv **maior)
{
    if (p == NULL)
        return;
    if (p->getMedia() > (*maior)->getMedia())
        *maior = p;
    auxImprimeMaiorMedia(p->getEsq(), maior);
    auxImprimeMaiorMedia(p->getDir(), maior);
}
void ArvBinBusca::imprimeMaiorMedia()
{
    if (raiz == NULL)
    {
        rotinaErro(1);
        return;
    }
    NoArv **maior = &raiz;
    auxImprimeMaiorMedia(raiz, maior);

    cout << (*maior)->getMatricula() << "_" << (*maior)->getTurma() << " " << (*maior)->getNome()
         << " - " << (*maior)->getDisciplina() << ": " << (*maior)->getMedia() << endl;
}

// 02 minutos e 16 segundos
void ArvBinBusca::auxImprimeMenorMedia(NoArv *p, NoArv **menor)
{
    if (p == NULL)
        return;
    if (p->getMedia() < (*menor)->getMedia())
        *menor = p;
    auxImprimeMenorMedia(p->getEsq(), menor);
    auxImprimeMenorMedia(p->getDir(), menor);
}
void ArvBinBusca::imprimeMenorMedia()
{
    if (raiz == NULL)
    {
        rotinaErro(1);
        return;
    }
    NoArv **menor = &raiz;
    auxImprimeMenorMedia(raiz, menor);

    cout << (*menor)->getMatricula() << "_" << (*menor)->getTurma() << " " << (*menor)->getNome()
         << " - " << (*menor)->getDisciplina() << ": " << (*menor)->getMedia() << endl;
}