#include <iostream>
#include "ArvBin.h"

using namespace std;

int main()
{
    ArvBin arvCompleta;
    ArvBin arvVazia;
    ArvBin arv1No;
    ArvBin arv1Folha;
    ArvBin arvCheia;
    ArvBin arvTorta;

    arvCompleta.insere(15);
    arvCompleta.insere(9);
    arvCompleta.insere(20);
    arvCompleta.insere(7);
    arvCompleta.insere(11);
    arvCompleta.insere(18);
    arvCompleta.insere(24);
    arvCompleta.insere(6);
    arvCompleta.insere(8);
    arvCompleta.insere(10);
    arvCompleta.insere(12);
    arvCompleta.insere(17);
    arvCompleta.insere(19);

    arv1No.insere(14);
    arv1Folha.insere(67);
    arv1Folha.insere(20);
    arvCheia.insere(15);
    arvCheia.insere(9);
    arvCheia.insere(20);
    arvCheia.insere(7);
    arvCheia.insere(11);
    arvCheia.insere(18);
    arvCheia.insere(24);

    arvTorta.insere(15);
    arvTorta.insere(9);
    arvTorta.insere(20);
    arvTorta.insere(7);
    arvTorta.insere(11);
    arvTorta.insere(10);
    arvTorta.insere(32);
    arvTorta.insere(25);
    arvTorta.insere(24);
    arvTorta.insere(5);
    arvTorta.insere(8);
    arvTorta.insere(10);
    arvTorta.insere(6);
    arvTorta.insere(4);
    arvTorta.insere(3);
    arvTorta.insere(12);
    arvTorta.insere(17);
    arvTorta.insere(19);

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

    // Ex01 - J
    cout << "SUCESSOR DE 10" << endl;
    cout << "Vazia: " << arvVazia.sucessor(10) << endl;
    cout << "1 no: " << arv1No.sucessor(10) << endl;
    cout << "1 folha: " << arv1Folha.sucessor(10) << endl;
    cout << "Completa: " << arvCompleta.sucessor(10) << endl;
    cout << "Cheia: " << arvCheia.sucessor(10) << endl;
    cout << "Torta: " << arvTorta.sucessor(10) << endl;
    cout << endl;

    return 0;
}