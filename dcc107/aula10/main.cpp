#include <iostream>
#include "ArvBin.h"
using namespace std;

ArvBin criaArvCheia()
{
    ArvBin *arv = new ArvBin;
    ArvBin *esq = new ArvBin;
    ArvBin *dir = new ArvBin;
    ArvBin *esqP = new ArvBin;
    ArvBin *dirP = new ArvBin;

    esq->cria(6, new ArvBin, new ArvBin);
    dir->cria(9, new ArvBin, new ArvBin);
    esqP->cria(8, esq, dir);

    esq = new ArvBin;
    dir = new ArvBin;
    esq->cria(22, new ArvBin, new ArvBin);
    dir->cria(27, new ArvBin, new ArvBin);
    dirP->cria(25, esq, dir);

    arv->cria(10, esqP, dirP);

    return *arv;
}

ArvBin criaArvCompleta()
{
    ArvBin *arv = new ArvBin;
    ArvBin *esq = new ArvBin;
    ArvBin *dir = new ArvBin;
    ArvBin *arve2 = new ArvBin;
    ArvBin *arvd2 = new ArvBin;
    ArvBin *arve3 = new ArvBin;
    ArvBin *arvd3 = new ArvBin;

    arve3->cria(17, new ArvBin, new ArvBin);
    arvd3->cria(19, new ArvBin, new ArvBin);

    esq->cria(7, new ArvBin, new ArvBin);
    dir->cria(15, new ArvBin, new ArvBin);
    arve2->cria(14, esq, dir);

    esq = new ArvBin;
    dir = new ArvBin;
    esq->cria(18, arve3, arvd3);
    dir->cria(38, new ArvBin, new ArvBin);
    arvd2->cria(25, esq, dir);

    arv->cria(16, arve2, arvd2);

    return *arv;
}

ArvBin criaArvTorta()
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

    return *arv;
}

int main()
{
    ArvBin arvCheia = criaArvCheia();
    ArvBin arvCompleta = criaArvCompleta();
    ArvBin arvTorta = criaArvTorta();
    ArvBin arvVazia;
    ArvBin arv1No;
    ArvBin arv1Folha;
    ArvBin *arv1NoAux = new ArvBin;
    arv1No.cria(13, new ArvBin, new ArvBin);
    arv1NoAux->cria(17, new ArvBin, new ArvBin);
    arv1Folha.cria(9, arv1NoAux, new ArvBin);

    // 10 18 16 NULL NULL 19 NULL NULL 25 38 NULL NULL 14 NULL NULL
    // arvCheia->montaArvore();

    // // Impressão em pré-ordem
    // cout << "VAZIA   \t";
    // arvVazia.preOrdem();
    // cout << endl;
    // cout << "1 NO    \t";
    // arv1No.preOrdem();
    // cout << endl;
    // cout << "1 FOLHA \t";
    // arv1Folha.preOrdem();
    // cout << endl;
    // cout << "TORTA   \t";
    // arvTorta.preOrdem();
    // cout << endl;
    // cout << "CHEIA   \t";
    // arvCheia.preOrdem();
    // cout << endl;
    // cout << "COMPLETA \t";
    // arvCompleta.preOrdem();
    // cout << endl;
    // cout << endl;

    // Imprime por nível
    cout << "VAZIA      : " << endl;
    arvVazia.imprimePorNivel();
    cout << endl;
    cout << "1 NO       : " << endl;
    arv1No.imprimePorNivel();
    cout << endl;
    cout << "1 FOLHA    : " << endl;
    arv1Folha.imprimePorNivel();
    cout << endl;
    cout << "TORTA      : " << endl;
    arvTorta.imprimePorNivel();
    cout << endl;
    cout << "CHEIA      : " << endl;
    arvCheia.imprimePorNivel();
    cout << endl;
    cout << "COMPLETA   : " << endl;
    arvCompleta.imprimePorNivel();
    cout << endl;
    cout << endl;

    // // Ex01
    // cout << "VAZIA      Num nos: " << arvVazia.contaNos() << endl;
    // cout << "1 NO       Num nos: " << arv1No.contaNos() << endl;
    // cout << "1 FOLHA    Num nos: " << arv1Folha.contaNos() << endl;
    // cout << "TORTA      Num nos: " << arvTorta.contaNos() << endl;
    // cout << "CHEIA      Num nos: " << arvCheia.contaNos() << endl;
    // cout << "COMPLETA   Num nos: " << arvCompleta.contaNos() << endl;
    // cout << endl;

    // // Ex02
    // cout << "VAZIA      Num folhas: " << arvVazia.contaNosFolhas() << endl;
    // cout << "1 NO       Num folhas: " << arv1No.contaNosFolhas() << endl;
    // cout << "1 FOLHA    Num folhas: " << arv1Folha.contaNosFolhas() << endl;
    // cout << "TORTA      Num folhas: " << arvTorta.contaNosFolhas() << endl;
    // cout << "CHEIA      Num folhas: " << arvCheia.contaNosFolhas() << endl;
    // cout << "COMPLETA   Num folhas: " << arvCompleta.contaNosFolhas() << endl;
    // cout << endl;

    // // Ex03
    // cout << "VAZIA      Altura: " << arvVazia.altura() << endl;
    // cout << "1 NO       Altura: " << arv1No.altura() << endl;
    // cout << "1 FOLHA    Altura: " << arv1Folha.altura() << endl;
    // cout << "TORTA      Altura: " << arvTorta.altura() << endl;
    // cout << "CHEIA      Altura: " << arvCheia.altura() << endl;
    // cout << "COMPLETA   Altura: " << arvCompleta.altura() << endl;
    // cout << endl;

    // // Ex04
    // cout << "VAZIA      Num valores impares: " << arvVazia.contaImpar() << endl;
    // cout << "1 NO       Num valores impares: " << arv1No.contaImpar() << endl;
    // cout << "1 FOLHA    Num valores impares: " << arv1Folha.contaImpar() << endl;
    // cout << "TORTA      Num valores impares: " << arvTorta.contaImpar() << endl;
    // cout << "CHEIA      Num valores impares: " << arvCheia.contaImpar() << endl;
    // cout << "COMPLETA   Num valores impares: " << arvCompleta.contaImpar() << endl;
    // cout << endl;

    // // Ex05
    // cout << "VAZIA      Num folhas impares: " << arvVazia.contaFolhaImpar() << endl;
    // cout << "1 NO       Num folhas impares: " << arv1No.contaFolhaImpar() << endl;
    // cout << "1 FOLHA    Num folhas impares: " << arv1Folha.contaFolhaImpar() << endl;
    // cout << "TORTA      Num folhas impares: " << arvTorta.contaFolhaImpar() << endl;
    // cout << "CHEIA      Num folhas impares: " << arvCheia.contaFolhaImpar() << endl;
    // cout << "COMPLETA   Num folhas impares: " << arvCompleta.contaFolhaImpar() << endl;
    // cout << endl;

    // // Ex06
    // cout << "VAZIA      : ";
    // arvVazia.imprimeNivel(0);
    // cout << endl;
    // cout << "1 NO       : ";
    // arv1No.imprimeNivel(0);
    // cout << endl;
    // cout << "1 FOLHA    : ";
    // arv1Folha.imprimeNivel(1);
    // cout << endl;
    // cout << "TORTA      : ";
    // arvTorta.imprimeNivel(1);
    // cout << endl;
    // cout << "CHEIA      : ";
    // arvCheia.imprimeNivel(2);
    // cout << endl;
    // cout << "COMPLETA   : ";
    // arvCompleta.imprimeNivel(3);
    // cout << endl;
    // cout << endl;

    // // Ex07
    // cout << "VAZIA      Media nivel: " << arvVazia.mediaNivel(0) << endl;
    // cout << "1 NO       Media nivel: " << arv1No.mediaNivel(0) << endl;
    // cout << "1 FOLHA    Media nivel: " << arv1Folha.mediaNivel(1) << endl;
    // cout << "TORTA      Media nivel: " << arvTorta.mediaNivel(1) << endl;
    // cout << "CHEIA      Media nivel: " << arvCheia.mediaNivel(2) << endl;
    // cout << "COMPLETA   Media nivel: " << arvCompleta.mediaNivel(3) << endl;
    // cout << endl;

    // // Ex08
    // cout << "VAZIA      Minimo: " << arvVazia.min() << endl;
    // cout << "1 NO       Minimo: " << arv1No.min() << endl;
    // cout << "1 FOLHA    Minimo: " << arv1Folha.min() << endl;
    // cout << "TORTA      Minimo: " << arvTorta.min() << endl;
    // cout << "CHEIA      Minimo: " << arvCheia.min() << endl;
    // cout << "COMPLETA   Minimo: " << arvCompleta.min() << endl;
    // cout << endl;
    // cout << "VAZIA      Maximo: " << arvVazia.max() << endl;
    // cout << "1 NO       Maximo: " << arv1No.max() << endl;
    // cout << "1 FOLHA    Maximo: " << arv1Folha.max() << endl;
    // cout << "TORTA      Maximo: " << arvTorta.max() << endl;
    // cout << "CHEIA      Maximo: " << arvCheia.max() << endl;
    // cout << "COMPLETA   Maximo: " << arvCompleta.max() << endl;
    // cout << endl;

    // // Ex09
    // // Imprime por nível
    // cout << "VAZIA      : " << endl;
    // arvVazia.imprimePorNivel();
    // cout << endl;
    // cout << "1 NO       : " << endl;
    // arv1No.imprimePorNivel();
    // cout << endl;
    // cout << "1 FOLHA    : " << endl;
    // arv1Folha.imprimePorNivel();
    // cout << endl;
    // cout << "TORTA      : " << endl;
    // arvTorta.imprimePorNivel();
    // cout << endl;
    // cout << "CHEIA      : " << endl;
    // arvCheia.imprimePorNivel();
    // cout << endl;
    // cout << "COMPLETA   : " << endl;
    // arvCompleta.imprimePorNivel();
    // cout << endl;
    // cout << " == INVERSAO == " << endl;
    // arvVazia.inverte();
    // arv1No.inverte();
    // arv1Folha.inverte();
    // arvTorta.inverte();
    // arvCheia.inverte();
    // arvCompleta.inverte();
    // cout << "VAZIA      : " << endl;
    // arvVazia.imprimePorNivel();
    // cout << endl;
    // cout << "1 NO       : " << endl;
    // arv1No.imprimePorNivel();
    // cout << endl;
    // cout << "1 FOLHA    : " << endl;
    // arv1Folha.imprimePorNivel();
    // cout << endl;
    // cout << "TORTA      : " << endl;
    // arvTorta.imprimePorNivel();
    // cout << endl;
    // cout << "CHEIA      : " << endl;
    // arvCheia.imprimePorNivel();
    // cout << endl;
    // cout << "COMPLETA   : " << endl;
    // arvCompleta.imprimePorNivel();
    // cout << endl;

    // // Ex10
    // cout << "VAZIA      No mais a esquerda: " << arvVazia.noMaisEsquerda() << endl;
    // cout << "1 NO       No mais a esquerda: " << arv1No.noMaisEsquerda() << endl;
    // cout << "1 FOLHA    No mais a esquerda: " << arv1Folha.noMaisEsquerda() << endl;
    // cout << "TORTA      No mais a esquerda: " << arvTorta.noMaisEsquerda() << endl;
    // cout << "CHEIA      No mais a esquerda: " << arvCheia.noMaisEsquerda() << endl;
    // cout << "COMPLETA   No mais a esquerda: " << arvCompleta.noMaisEsquerda() << endl;
    // cout << endl;
    // cout << "VAZIA      No mais a direita: " << arvVazia.noMaisDireita() << endl;
    // cout << "1 NO       No mais a direita: " << arv1No.noMaisDireita() << endl;
    // cout << "1 FOLHA    No mais a direita: " << arv1Folha.noMaisDireita() << endl;
    // cout << "TORTA      No mais a direita: " << arvTorta.noMaisDireita() << endl;
    // cout << "CHEIA      No mais a direita: " << arvCheia.noMaisDireita() << endl;
    // cout << "COMPLETA   No mais a direita: " << arvCompleta.noMaisDireita() << endl;
    // cout << endl;

    // // Ex11
    // cout << "VAZIA      Minimo na subarvore: " << arvVazia.minSubArvore(arvVazia.getNoRaiz()) << endl;
    // cout << "1 NO       Minimo na subarvore: " << arv1No.minSubArvore(arv1No.getNoRaiz()) << endl;
    // cout << "1 FOLHA    Minimo na subarvore: " << arv1Folha.minSubArvore(arv1Folha.getNoRaiz()) << endl;
    // cout << "TORTA      Minimo na subarvore: " << arvTorta.minSubArvore(arvTorta.getNoRaiz()) << endl;
    // cout << "CHEIA      Minimo na subarvore: " << arvCheia.minSubArvore(arvCheia.getNoRaiz()) << endl;
    // cout << "COMPLETA   Minimo na subarvore: " << arvCompleta.minSubArvore(arvCompleta.getNoRaiz()) << endl;
    // cout << endl;
    // cout << "VAZIA      Maximo na subarvore: " << arvVazia.maxSubArvore(arvVazia.getNoRaiz()) << endl;
    // cout << "1 NO       Maximo na subarvore: " << arv1No.maxSubArvore(arv1No.getNoRaiz()) << endl;
    // cout << "1 FOLHA    Maximo na subarvore: " << arv1Folha.maxSubArvore(arv1Folha.getNoRaiz()) << endl;
    // cout << "TORTA      Maximo na subarvore: " << arvTorta.maxSubArvore(arvTorta.getNoRaiz()) << endl;
    // cout << "CHEIA      Maximo na subarvore: " << arvCheia.maxSubArvore(arvCheia.getNoRaiz()) << endl;
    // cout << "COMPLETA   Maximo na subarvore: " << arvCompleta.maxSubArvore(arvCompleta.getNoRaiz()) << endl;
    // cout << endl;

    // Ex12
    cout << "VAZIA      Eh ABB?: " << boolalpha << arvVazia.ehABB() << endl;
    cout << "1 NO       Eh ABB?: " << boolalpha << arv1No.ehABB() << endl;
    cout << "1 FOLHA    Eh ABB?: " << boolalpha << arv1Folha.ehABB() << endl;
    cout << "TORTA      Eh ABB?: " << boolalpha << arvTorta.ehABB() << endl;
    cout << "CHEIA      Eh ABB?: " << boolalpha << arvCheia.ehABB() << endl;
    cout << "COMPLETA   Eh ABB?: " << boolalpha << arvCompleta.ehABB() << endl;
    cout << endl;

    return 0;
}
