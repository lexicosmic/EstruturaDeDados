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
     ArvBin arvCompleta = *criaArvCompleta();
     ArvBin arvVazia;
     ArvBin arv1No;
     ArvBin arv1Folha;
     ArvBin arvCheia = *criaArvCheia();
     ArvBin arvTorta = *criaArvTorta();

     arv1No.insere(14);
     arv1Folha.insere(67);
     arv1Folha.insere(20);

     cout << "Vazia: " << endl;
     arvVazia.imprime();
     cout << endl
          << "1 no: " << endl;
     arv1No.imprime();
     cout << endl
          << "1 folha: " << endl;
     arv1Folha.imprime();
     cout << endl
          << "Completa: " << endl;
     arvCompleta.imprime();
     cout << endl
          << "Cheia: " << endl;
     arvCheia.imprime();
     cout << endl
          << "Torta: " << endl;
     arvTorta.imprime();
     cout << endl;

     // // Ex01 - A
     // cout << "CONTA IMPARES" << endl;
     // cout << "Vazia: " << arvVazia.impares() << endl;
     // cout << "1 no: " << arv1No.impares() << endl;
     // cout << "1 folha: " << arv1Folha.impares() << endl;
     // cout << "Completa: " << arvCompleta.impares() << endl;
     // cout << "Cheia: " << arvCheia.impares() << endl;
     // cout << "Torta: " << arvTorta.impares() << endl;
     // cout << endl;

     // // Ex01 - B
     // cout << "SOMA" << endl;
     // cout << "Vazia: " << arvVazia.soma() << endl;
     // cout << "1 no: " << arv1No.soma() << endl;
     // cout << "1 folha: " << arv1Folha.soma() << endl;
     // cout << "Completa: " << arvCompleta.soma() << endl;
     // cout << "Cheia: " << arvCheia.soma() << endl;
     // cout << "Torta: " << arvTorta.soma() << endl;
     // cout << endl;

     // // Ex01 - C
     // cout << "MEDIA" << endl;
     // cout << "Vazia: " << arvVazia.media() << endl;
     // cout << "1 no: " << arv1No.media() << endl;
     // cout << "1 folha: " << arv1Folha.media() << endl;
     // cout << "Completa: " << arvCompleta.media() << endl;
     // cout << "Cheia: " << arvCheia.media() << endl;
     // cout << "Torta: " << arvTorta.media() << endl;
     // cout << endl;

     // // Ex01 - D
     // cout << "MEDIA PARES" << endl;
     // cout << "Vazia: " << arvVazia.mediaPares() << endl;
     // cout << "1 no: " << arv1No.mediaPares() << endl;
     // cout << "1 folha: " << arv1Folha.mediaPares() << endl;
     // cout << "Completa: " << arvCompleta.mediaPares() << endl;
     // cout << "Cheia: " << arvCheia.mediaPares() << endl;
     // cout << "Torta: " << arvTorta.mediaPares() << endl;
     // cout << endl;

     // // Ex01 - E
     // cout << "MAIOR VALOR" << endl;
     // cout << "Vazia: " << arvVazia.maiorValor() << endl;
     // cout << "1 no: " << arv1No.maiorValor() << endl;
     // cout << "1 folha: " << arv1Folha.maiorValor() << endl;
     // cout << "Completa: " << arvCompleta.maiorValor() << endl;
     // cout << "Cheia: " << arvCheia.maiorValor() << endl;
     // cout << "Torta: " << arvTorta.maiorValor() << endl;
     // cout << endl;

     // // Ex01 - F
     // cout << "MENOR VALOR" << endl;
     // cout << "Vazia: " << arvVazia.menorValor() << endl;
     // cout << "1 no: " << arv1No.menorValor() << endl;
     // cout << "1 folha: " << arv1Folha.menorValor() << endl;
     // cout << "Completa: " << arvCompleta.menorValor() << endl;
     // cout << "Cheia: " << arvCheia.menorValor() << endl;
     // cout << "Torta: " << arvTorta.menorValor() << endl;
     // cout << endl;

     // // Ex01 - G
     // cout << "MAIORES QUE 10" << endl;
     // cout << "Vazia: " << arvVazia.maiores(10) << endl;
     // cout << "1 no: " << arv1No.maiores(10) << endl;
     // cout << "1 folha: " << arv1Folha.maiores(10) << endl;
     // cout << "Completa: " << arvCompleta.maiores(10) << endl;
     // cout << "Cheia: " << arvCheia.maiores(10) << endl;
     // cout << "Torta: " << arvTorta.maiores(10) << endl;
     // cout << endl;

     // // Ex01 - H
     // cout << "MEDIA NO NIVEL 2" << endl;
     // cout << "Vazia: " << arvVazia.mediaNivel(2) << endl;
     // cout << "1 no: " << arv1No.mediaNivel(2) << endl;
     // cout << "1 folha: " << arv1Folha.mediaNivel(2) << endl;
     // cout << "Completa: " << arvCompleta.mediaNivel(2) << endl;
     // cout << "Cheia: " << arvCheia.mediaNivel(2) << endl;
     // cout << "Torta: " << arvTorta.mediaNivel(2) << endl;
     // cout << endl;

     // // Ex01 - I
     // cout << "IMPRIME NIVEL 2 E ACIMA" << endl;
     // cout << "Vazia: ";
     // arvVazia.imprimirNivel(2);
     // cout << endl;
     // cout << "1 no: ";
     // arv1No.imprimirNivel(2);
     // cout << endl;
     // cout << "1 folha: ";
     // arv1Folha.imprimirNivel(2);
     // cout << endl;
     // cout << "Completa: ";
     // arvCompleta.imprimirNivel(2);
     // cout << endl;
     // cout << "Cheia: ";
     // arvCheia.imprimirNivel(2);
     // cout << endl;
     // cout << "Torta: ";
     // arvTorta.imprimirNivel(2);
     // cout << endl;
     // cout << endl;

     // // Ex01 - J
     // cout << "SUCESSOR DE 10" << endl;
     // cout << "Vazia: " << arvVazia.sucessor(10) << endl;
     // cout << "1 no: " << arv1No.sucessor(10) << endl;
     // cout << "1 folha: " << arv1Folha.sucessor(10) << endl;
     // cout << "Completa: " << arvCompleta.sucessor(10) << endl;
     // cout << "Cheia: " << arvCheia.sucessor(10) << endl;
     // cout << "Torta: " << arvTorta.sucessor(10) << endl;
     // cout << endl;

     // // Ex02
     // cout << "E CHEIA" << endl;
     // cout << "Vazia: " << boolalpha << arvVazia.eCheia() << endl;
     // cout << "1 no: " << boolalpha << arv1No.eCheia() << endl;
     // cout << "1 folha: " << boolalpha << arv1Folha.eCheia() << endl;
     // cout << "Completa: " << boolalpha << arvCompleta.eCheia() << endl;
     // cout << "Cheia: " << boolalpha << arvCheia.eCheia() << endl;
     // cout << "Torta: " << boolalpha << arvTorta.eCheia() << endl;
     // cout << endl;

     // Ex03
     cout << "E COMPLETA" << endl;
     cout << "Vazia: " << boolalpha << arvVazia.eCompleta() << endl;
     cout << "1 no: " << boolalpha << arv1No.eCompleta() << endl;
     cout << "1 folha: " << boolalpha << arv1Folha.eCompleta() << endl;
     cout << "Completa: " << boolalpha << arvCompleta.eCompleta() << endl;
     cout << "Cheia: " << boolalpha << arvCheia.eCompleta() << endl;
     cout << "Torta: " << boolalpha << arvTorta.eCompleta() << endl;
     cout << endl;

     return 0;
}