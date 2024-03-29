#include <iostream>
#include "ArvBin.h"

using namespace std;

ArvBin *criaArvCheia()
{
    ArvBin *arv = new ArvBin;
    ArvBin *esq = new ArvBin;
    ArvBin *dir = new ArvBin;
    ArvBin *esqP = new ArvBin;
    ArvBin *dirP = new ArvBin;

    esq->cria(16, new ArvBin, new ArvBin);
    dir->cria(19, new ArvBin, new ArvBin);
    esqP->cria(18, esq, dir);

    esq = new ArvBin;
    dir = new ArvBin;
    esq->cria(38, new ArvBin, new ArvBin);
    dir->cria(14, new ArvBin, new ArvBin);
    dirP->cria(25, esq, dir);

    arv->cria(10, esqP, dirP);

    return arv;
}

ArvBin *criaArvCompleta()
{
    ArvBin *arv = new ArvBin;
    ArvBin *esq = new ArvBin;
    ArvBin *dir = new ArvBin;
    ArvBin *arve2 = new ArvBin;
    ArvBin *arvd2 = new ArvBin;
    ArvBin *arve3 = new ArvBin;
    ArvBin *arvd3 = new ArvBin;

    arve3->cria(24, new ArvBin, new ArvBin);
    arvd3->cria(12, new ArvBin, new ArvBin);

    esq->cria(16, new ArvBin, new ArvBin);
    dir->cria(19, new ArvBin, new ArvBin);
    arve2->cria(18, esq, dir);

    esq = new ArvBin;
    dir = new ArvBin;
    esq->cria(38, arve3, arvd3);
    dir->cria(14, new ArvBin, new ArvBin);
    arvd2->cria(25, esq, dir);

    arv->cria(10, arve2, arvd2);

    return arv;
}

ArvBin *criaArvTorta()
{
    ArvBin *arv = new ArvBin;
    ArvBin *esq = new ArvBin;
    ArvBin *dir = new ArvBin;
    ArvBin *arve2 = new ArvBin;
    ArvBin *arvd2 = new ArvBin;
    ArvBin *arvd3 = new ArvBin;

    arvd3->cria(12, new ArvBin, new ArvBin);

    esq->cria(16, new ArvBin, new ArvBin);
    dir->cria(19, new ArvBin, new ArvBin);
    arve2->cria(18, esq, dir);

    esq = new ArvBin;
    dir = new ArvBin;
    esq->cria(38, new ArvBin, arvd3);
    arvd2->cria(25, esq, new ArvBin);

    arv->cria(10, arve2, arvd2);

    return arv;
}

int main()
{
    ArvBin *arvCheia = criaArvCheia();
    ArvBin *arvCompleta = criaArvCompleta();
    ArvBin *arvTorta = criaArvTorta();
    ArvBin *arvVazia = new ArvBin;
    ArvBin *arv1No = new ArvBin;
    ArvBin *arv1Folha = new ArvBin;
    ArvBin *arv1NoAux = new ArvBin;
    arv1No->cria(13, new ArvBin, new ArvBin);
    arv1NoAux->cria(17, new ArvBin, new ArvBin);
    arv1Folha->cria(9, arv1NoAux, new ArvBin);

    // 10 18 16 NULL NULL 19 NULL NULL 25 38 NULL NULL 14 NULL NULL
    // arvCheia->montaArvore();

    arvVazia->preOrdem();
    cout << endl;
    arv1No->preOrdem();
    cout << endl;
    arv1Folha->preOrdem();
    cout << endl;
    arvTorta->preOrdem();
    cout << endl;
    arvCompleta->preOrdem();
    cout << endl;
    arvCheia->preOrdem();
    cout << endl;

    // Ex07
    // cout << boolalpha << arvVazia->ehCheia() << endl;
    // cout << boolalpha << arv1No->ehCheia() << endl;
    // cout << boolalpha << arv1Folha->ehCheia() << endl;
    // cout << boolalpha << arvCheia->ehCheia() << endl;
    // cout << boolalpha << arvCompleta->ehCheia() << endl;

    // Ex08
    // arvVazia->preOrdemNivel();
    // cout << endl;
    // arv1No->preOrdemNivel();
    // cout << endl;
    // arv1Folha->preOrdemNivel();
    // cout << endl;
    // arvTorta->preOrdemNivel();
    // cout << endl;
    // arvCheia->preOrdemNivel();
    // cout << endl;
    // arvCompleta->preOrdemNivel();
    // cout << endl;

    // Ex09
    // cout << arvVazia->nNosK(1) << endl;
    // cout << arv1No->nNosK(1) << endl;
    // cout << arv1Folha->nNosK(1) << endl;
    // cout << arvCheia->nNosK(2) << endl;
    // cout << arvCompleta->nNosK(3) << endl;

    // Ex10
    // cout << boolalpha << arvVazia->ehCompleta() << endl;
    // cout << boolalpha << arv1No->ehCompleta() << endl;
    // cout << boolalpha << arv1Folha->ehCompleta() << endl;
    // cout << boolalpha << arvTorta->ehCompleta() << endl;
    // cout << boolalpha << arvCheia->ehCompleta() << endl;
    // cout << boolalpha << arvCompleta->ehCompleta() << endl;

    // Ex11
    // cout << boolalpha << arvVazia->ehEstritBin() << endl;
    // cout << boolalpha << arv1No->ehEstritBin() << endl;
    // cout << boolalpha << arv1Folha->ehEstritBin() << endl;
    // cout << boolalpha << arvTorta->ehEstritBin() << endl;
    // cout << boolalpha << arvCheia->ehEstritBin() << endl;
    // cout << boolalpha << arvCompleta->ehEstritBin() << endl;

    return 0;
}