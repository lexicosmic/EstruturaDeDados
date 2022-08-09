#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

// Ex07
void preencheABB(ArvBinBusca *arv, int inicio, int fim)
{
    int media = (inicio + fim) / 2;
    if (media != fim)
    {
        arv->insere(media);
        preencheABB(arv, inicio, media);
        preencheABB(arv, media + 1, fim);
    }
}

int main()
{
    ArvBinBusca arvCompleta;
    ArvBinBusca arvVazia;
    ArvBinBusca arv1No;
    ArvBinBusca arv1Folha;
    ArvBinBusca arvCheia;
    ArvBinBusca arvTorta;

    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
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

    // cout << "Media do caminho ate o no com valor 18: " << arvCompleta.mediaCaminho(18) << endl;

    // cout << "Busca o valor 20: " << arvCompleta.busca(20) << endl;
    // cout << "Busca o valor  5: " << arvCompleta.busca(5) << endl;
    // cout << endl;

    // cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    // arvCompleta.remove(24);
    // arvCompleta.remove(6);
    // arvCompleta.remove(7);
    // arvCompleta.remove(12);
    // arvCompleta.remove(18);
    // arvCompleta.remove(5);
    // cout << endl;

    // cout << "Arvore Binaria de Busca final:" << endl;
    // arvCompleta.imprime();

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

    // // Ex01
    // cout << "MAIOR" << endl;
    // cout << "Vazia: " << arvVazia.maior() << endl;
    // cout << "1 no: " << arv1No.maior() << endl;
    // cout << "1 folha: " << arv1Folha.maior() << endl;
    // cout << "Completa: " << arvCompleta.maior() << endl;
    // cout << "Cheia: " << arvCheia.maior() << endl;
    // cout << "Torta: " << arvTorta.maior() << endl;
    // cout << endl;

    // // Ex02
    // cout << "MENOR" << endl;
    // cout << "Vazia: " << arvVazia.menor() << endl;
    // cout << "1 no: " << arv1No.menor() << endl;
    // cout << "1 folha: " << arv1Folha.menor() << endl;
    // cout << "Completa: " << arvCompleta.menor() << endl;
    // cout << "Cheia: " << arvCheia.menor() << endl;
    // cout << "Torta: " << arvTorta.menor() << endl;
    // cout << endl;

    // // Ex03
    // cout << "REMOVE MAIOR" << endl;
    // arvVazia.removeMaior();
    // arv1No.removeMaior();
    // arv1Folha.removeMaior();
    // arvCompleta.removeMaior();
    // arvCheia.removeMaior();
    // arvTorta.removeMaior();
    // cout << "Vazia: " << endl;
    // arvVazia.imprime();
    // cout << endl
    //      << "1 no: " << endl;
    // arv1No.imprime();
    // cout << endl
    //      << "1 folha: " << endl;
    // arv1Folha.imprime();
    // cout << endl
    //      << "Completa: " << endl;
    // arvCompleta.imprime();
    // cout << endl
    //      << "Cheia: " << endl;
    // arvCheia.imprime();
    // cout << endl
    //      << "Torta: " << endl;
    // arvTorta.imprime();
    // cout << endl;

    // // Ex04
    // cout << "REMOVE MENOR" << endl;
    // arvVazia.removeMenor();
    // arv1No.removeMenor();
    // arv1Folha.removeMenor();
    // arvCompleta.removeMenor();
    // arvCheia.removeMenor();
    // arvTorta.removeMenor();
    // cout << "Vazia: " << endl;
    // arvVazia.imprime();
    // cout << endl
    //      << "1 no: " << endl;
    // arv1No.imprime();
    // cout << endl
    //      << "1 folha: " << endl;
    // arv1Folha.imprime();
    // cout << endl
    //      << "Completa: " << endl;
    // arvCompleta.imprime();
    // cout << endl
    //      << "Cheia: " << endl;
    // arvCheia.imprime();
    // cout << endl
    //      << "Torta: " << endl;
    // arvTorta.imprime();
    // cout << endl;

    // // Ex05
    // cout << "PARES NO CAMINHO" << endl;
    // cout << "Vazia: " << arvVazia.contaParesCaminho(20) << endl;
    // cout << "1 no: " << arv1No.contaParesCaminho(20) << endl;
    // cout << "1 folha: " << arv1Folha.contaParesCaminho(20) << endl;
    // cout << "Completa: " << arvCompleta.contaParesCaminho(17) << endl;
    // cout << "Cheia: " << arvCheia.contaParesCaminho(11) << endl;
    // cout << "Torta: " << arvTorta.contaParesCaminho(3) << endl;
    // cout << endl;

    // // Ex06
    // cout << "REMOVE SUBSTITUINDO PELO MAIOR A ESQUERDA" << endl;
    // arvVazia.remove(0);
    // arv1No.remove(1);
    // arv1Folha.remove(67);
    // arvCompleta.remove(18);
    // arvCheia.remove(15);
    // arvTorta.remove(5);
    // cout << "Vazia: " << endl;
    // arvVazia.imprime();
    // cout << endl
    //      << "1 no: " << endl;
    // arv1No.imprime();
    // cout << endl
    //      << "1 folha: " << endl;
    // arv1Folha.imprime();
    // cout << endl
    //      << "Completa: " << endl;
    // arvCompleta.imprime();
    // cout << endl
    //      << "Cheia: " << endl;
    // arvCheia.imprime();
    // cout << endl
    //      << "Torta: " << endl;
    // arvTorta.imprime();
    // cout << endl;

    // Ex07
    ArvBinBusca arvMontada;
    preencheABB(&arvMontada, 10, 26);
    cout << endl
         << "Montada: " << endl;
    arvMontada.imprime();
    cout << endl;

    return 0;
}
