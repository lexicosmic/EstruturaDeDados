#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(float media);
    void insere(int matricula, string nome, string disciplina, string turma, float media);
    void remove(float media);
    void imprime();
    void imprimeAluno(float media);
    void imprimeMaiorMedia();
    void imprimeMenorMedia();

private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore
    bool auxBusca(NoArv *p, float media);
    NoArv *auxInsere(NoArv *p, int matricula, string nome, string disciplina, string turma, float media);
    NoArv *auxRemove(NoArv *p, float media);
    NoArv *menorSubArvDireita(NoArv *p);
    NoArv *removeFolha(NoArv *p);
    NoArv *remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv *p, int nivel);
    NoArv *libera(NoArv *p);
    bool auxEABB(NoArv *p);
    void auxImprimeAluno(NoArv *p, float media);
    NoArv *auxImprimeMaiorMedia(NoArv *p);
    NoArv *auxImprimeMenorMedia(NoArv *p);
};

#endif // ARVBINBUSCA_H_INCLUDED
