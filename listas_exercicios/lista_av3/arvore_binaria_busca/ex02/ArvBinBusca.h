#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int matricula);
    void insere(int matricula, string nome, string disciplina, string turma, float media);
    void remove(int matricula);
    void imprime();
    void imprimeAluno(int matricula);
    void imprimeMaiorMedia();
    void imprimeMenorMedia();

private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore
    bool auxBusca(NoArv *p, int matricula);
    NoArv *auxInsere(NoArv *p, int matricula, string nome, string disciplina, string turma, float media);
    NoArv *auxRemove(NoArv *p, int matricula);
    NoArv *menorSubArvDireita(NoArv *p);
    NoArv *removeFolha(NoArv *p);
    NoArv *remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv *p, int nivel);
    NoArv *libera(NoArv *p);
    bool auxEABB(NoArv *p);
    void auxImprimeAluno(NoArv *p, int matricula);
    void auxImprimeMaiorMedia(NoArv *p, NoArv **maior);
    void auxImprimeMenorMedia(NoArv *p, NoArv **menor);
};

#endif // ARVBINBUSCA_H_INCLUDED
