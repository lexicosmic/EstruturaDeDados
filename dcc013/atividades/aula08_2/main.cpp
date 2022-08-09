#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
     ArvBinBusca arvCompleta;
     ArvBinBusca arvVazia;
     ArvBinBusca arv1No;
     ArvBinBusca arv1Folha;
     ArvBinBusca arvCheia;
     ArvBinBusca arvTorta;
     ArvBinBusca arvNaoAbb;

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
     // arvCompleta.imprime();
     // cout << endl;

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

     arvNaoAbb.montaNaoAbb();

     // cout << "Busca o valor 20: " << boolalpha << arvCompleta.busca(20) << endl;
     // cout << "Busca o valor  5: " << boolalpha << arvCompleta.busca(5) << endl;
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
     cout << endl
          << "Nao ABB: " << endl;
     arvNaoAbb.imprime();
     cout << endl;

     // // Ex01
     // cout << "MAIOR" << endl;
     // cout << "Vazia: " << arvVazia.maior() << endl;
     // cout << "1 no: " << arv1No.maior() << endl;
     // cout << "1 folha: " << arv1Folha.maior() << endl;
     // cout << "Completa: " << arvCompleta.maior() << endl;
     // cout << "Cheia: " << arvCheia.maior() << endl;
     // cout << endl;

     // // Ex02
     // cout << "MENOR" << endl;
     // cout << "Vazia: " << arvVazia.menor() << endl;
     // cout << "1 no: " << arv1No.menor() << endl;
     // cout << "1 folha: " << arv1Folha.menor() << endl;
     // cout << "Completa: " << arvCompleta.menor() << endl;
     // cout << "Cheia: " << arvCheia.menor() << endl;
     // cout << endl;

     // // Ex03
     // cout << "REMOVE MAIOR" << endl;
     // arvVazia.removeMaior();
     // arv1No.removeMaior();
     // arv1Folha.removeMaior();
     // arvCompleta.removeMaior();
     // arvCheia.removeMaior();
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
     // cout << endl;

     // // Ex04
     // cout << "REMOVE MENOR" << endl;
     // arvVazia.removeMenor();
     // arv1No.removeMenor();
     // arv1Folha.removeMenor();
     // arvCompleta.removeMenor();
     // arvCheia.removeMenor();
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
     // cout << endl;

     // // Ex05
     // cout << "REMOVE SUBSTITUINDO COM O MAIOR NO A ESQUERDA" << endl;
     // arvVazia.removeSubstEsq(20);
     // arv1No.removeSubstEsq(20);
     // arv1Folha.removeSubstEsq(20);
     // arvCompleta.removeSubstEsq(20);
     // arvCheia.removeSubstEsq(20);
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
     // cout << endl;

     // // Extra
     // cout << "ALTURA" << endl;
     // cout << "Vazia: " << arvVazia.getAltura() << endl;
     // cout << "1 no: " << arv1No.getAltura() << endl;
     // cout << "1 folha: " << arv1Folha.getAltura() << endl;
     // cout << "Completa: " << arvCompleta.getAltura() << endl;
     // cout << "Cheia: " << arvCheia.getAltura() << endl;
     // cout << endl;

     // // Ex06
     // cout << "BALANCEADA" << endl;
     // cout << "Vazia: " << boolalpha << arvVazia.ehBalanceada() << endl;
     // cout << "1 no: " << boolalpha << arv1No.ehBalanceada() << endl;
     // cout << "1 folha: " << boolalpha << arv1Folha.ehBalanceada() << endl;
     // cout << "Completa: " << boolalpha << arvCompleta.ehBalanceada() << endl;
     // cout << "Cheia: " << boolalpha << arvCheia.ehBalanceada() << endl;
     // cout << "Torta: " << boolalpha << arvTorta.ehBalanceada() << endl;
     // cout << endl;

     // Ex07
     cout << "Eh ABB" << endl;
     cout << "Vazia: " << boolalpha << arvVazia.ehABB() << endl;
     cout << "1 no: " << boolalpha << arv1No.ehABB() << endl;
     cout << "1 folha: " << boolalpha << arv1Folha.ehABB() << endl;
     cout << "Completa: " << boolalpha << arvCompleta.ehABB() << endl;
     cout << "Cheia: " << boolalpha << arvCheia.ehABB() << endl;
     cout << "Torta: " << boolalpha << arvTorta.ehABB() << endl;
     cout << "Nao ABB: " << boolalpha << arvNaoAbb.ehABB() << endl;
     cout << endl;

     return 0;
}
