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
     arvTorta.insere(6);
     arvTorta.insere(4);
     arvTorta.insere(3);
     arvTorta.insere(12);
     arvTorta.insere(17);
     arvTorta.insere(19);

     arvNaoAbb.montaNaoAbb();

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
     // cout << "Eh ABB" << endl;
     // cout << "Vazia: " << boolalpha << arvVazia.eABB() << endl;
     // cout << "1 no: " << boolalpha << arv1No.eABB() << endl;
     // cout << "1 folha: " << boolalpha << arv1Folha.eABB() << endl;
     // cout << "Completa: " << boolalpha << arvCompleta.eABB() << endl;
     // cout << "Cheia: " << boolalpha << arvCheia.eABB() << endl;
     // cout << "Torta: " << boolalpha << arvTorta.eABB() << endl;
     // cout << "Nao ABB: " << boolalpha << arvNaoAbb.eABB() << endl;
     // cout << endl;

     // // Ex04 - A
     // cout << "Imprime filhos" << endl;
     // cout << "Vazia: " << endl;
     // arvVazia.imprimeFilhos(10);
     // cout << endl
     //      << "1 no: " << endl;
     // arv1No.imprimeFilhos(67);
     // cout << endl
     //      << "1 folha: " << endl;
     // arv1Folha.imprimeFilhos(20);
     // cout << endl
     //      << "Completa: " << endl;
     // arvCompleta.imprimeFilhos(20);
     // cout << endl
     //      << "Cheia: " << endl;
     // arvCheia.imprimeFilhos(20);
     // cout << endl
     //      << "Torta: " << endl;
     // arvTorta.imprimeFilhos(10);
     // cout << endl
     //      << "Nao ABB: " << endl;
     // arvNaoAbb.imprimeFilhos(10);
     // cout << endl;

     // // Ex04 - B
     // cout << "Imprime intervalo" << endl;
     // cout << "Vazia: " << endl;
     // arvVazia.imprimeIntervalo(10, 20);
     // cout << endl
     //      << "1 no: " << endl;
     // arv1No.imprimeIntervalo(10, 20);
     // cout << endl
     //      << "1 folha: " << endl;
     // arv1Folha.imprimeIntervalo(10, 20);
     // cout << endl
     //      << "Completa: " << endl;
     // arvCompleta.imprimeIntervalo(10, 20);
     // cout << endl
     //      << "Cheia: " << endl;
     // arvCheia.imprimeIntervalo(10, 20);
     // cout << endl
     //      << "Torta: " << endl;
     // arvTorta.imprimeIntervalo(10, 20);
     // cout << endl
     //      << "Nao ABB: " << endl;
     // arvNaoAbb.imprimeIntervalo(10, 20);
     // cout << endl;

     // // Ex04 - C
     // cout << "Imprime crescente" << endl;
     // cout << "Vazia: " << endl;
     // arvVazia.imprimeCrescente();
     // cout << endl
     //      << "1 no: " << endl;
     // arv1No.imprimeCrescente();
     // cout << endl
     //      << "1 folha: " << endl;
     // arv1Folha.imprimeCrescente();
     // cout << endl
     //      << "Completa: " << endl;
     // arvCompleta.imprimeCrescente();
     // cout << endl
     //      << "Cheia: " << endl;
     // arvCheia.imprimeCrescente();
     // cout << endl
     //      << "Torta: " << endl;
     // arvTorta.imprimeCrescente();
     // cout << endl
     //      << "Nao ABB: " << endl;
     // arvNaoAbb.imprimeCrescente();
     // cout << endl;

     // // Ex04 - D
     // cout << "Imprime decrescente" << endl;
     // cout << "Vazia: " << endl;
     // arvVazia.imprimeDecrescente();
     // cout << endl
     //      << "1 no: " << endl;
     // arv1No.imprimeDecrescente();
     // cout << endl
     //      << "1 folha: " << endl;
     // arv1Folha.imprimeDecrescente();
     // cout << endl
     //      << "Completa: " << endl;
     // arvCompleta.imprimeDecrescente();
     // cout << endl
     //      << "Cheia: " << endl;
     // arvCheia.imprimeDecrescente();
     // cout << endl
     //      << "Torta: " << endl;
     // arvTorta.imprimeDecrescente();
     // cout << endl
     //      << "Nao ABB: " << endl;
     // arvNaoAbb.imprimeDecrescente();
     // cout << endl;

     // // Ex04 - E.I
     // int vet[5] = {4, 7, 34, 67, 98};
     // int numVet = 5;
     // arvVazia.insereDoVetorDegenerada(numVet, vet);
     // arv1No.insereDoVetorDegenerada(numVet, vet);
     // arv1Folha.insereDoVetorDegenerada(numVet, vet);
     // arvCompleta.insereDoVetorDegenerada(numVet, vet);
     // arvCheia.insereDoVetorDegenerada(numVet, vet);
     // arvTorta.insereDoVetorDegenerada(numVet, vet);
     // arvNaoAbb.insereDoVetorDegenerada(numVet, vet);
     // cout << "Imprime" << endl;
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
     // cout << endl
     //      << "Nao ABB: " << endl;
     // arvNaoAbb.imprime();
     // cout << endl;

     // Ex04 - E.II
     int vet[5] = {4, 7, 34, 67, 98};
     int numVet = 5;
     arvVazia.insereDoVetorCompleta(numVet, vet);
     arv1No.insereDoVetorCompleta(numVet, vet);
     arv1Folha.insereDoVetorCompleta(numVet, vet);
     arvCompleta.insereDoVetorCompleta(numVet, vet);
     arvCheia.insereDoVetorCompleta(numVet, vet);
     arvTorta.insereDoVetorCompleta(numVet, vet);
     arvNaoAbb.insereDoVetorCompleta(numVet, vet);
     cout << "Imprime" << endl;
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

     return 0;
}
