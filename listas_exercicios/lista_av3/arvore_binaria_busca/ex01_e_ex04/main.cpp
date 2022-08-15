#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

void imprime(int *vet, int n)
{
     for (int i = 0; i < n; i++)
     {
          cout << vet[i] << " ";
     }
     cout << endl;
}

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

     // // Ex04 - E.II
     // int vet[5] = {2, 13, 22, 47, 66};
     // int numVet = 5;
     // arvVazia.insereDoVetorCompleta(numVet, vet);
     // arv1No.insereDoVetorCompleta(numVet, vet);
     // arv1Folha.insereDoVetorCompleta(numVet, vet);
     // arvCompleta.insereDoVetorCompleta(numVet, vet);
     // arvCheia.insereDoVetorCompleta(numVet, vet);
     // arvTorta.insereDoVetorCompleta(numVet, vet);
     // arvNaoAbb.insereDoVetorCompleta(numVet, vet);
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
     // cout << "Eh Completa" << endl;
     // cout << "Vazia: " << boolalpha << arvVazia.eCompleta() << endl;
     // cout << "1 no: " << boolalpha << arv1No.eCompleta() << endl;
     // cout << "1 folha: " << boolalpha << arv1Folha.eCompleta() << endl;
     // cout << "Completa: " << boolalpha << arvCompleta.eCompleta() << endl;
     // cout << "Cheia: " << boolalpha << arvCheia.eCompleta() << endl;
     // cout << "Torta: " << boolalpha << arvTorta.eCompleta() << endl;
     // cout << "Nao ABB: " << boolalpha << arvNaoAbb.eCompleta() << endl;
     // cout << endl;

     // // Ex04 - F
     // int numVazia, num1No, num1Folha, numCompleta, numCheia, numTorta, numNaoAbb;
     // int *vetVazia = arvVazia.insereVetorCrescente(&numVazia);
     // int *vet1No = arv1No.insereVetorCrescente(&num1No);
     // int *vet1Folha = arv1Folha.insereVetorCrescente(&num1Folha);
     // int *vetCompleta = arvCompleta.insereVetorCrescente(&numCompleta);
     // int *vetCheia = arvCheia.insereVetorCrescente(&numCheia);
     // int *vetTorta = arvTorta.insereVetorCrescente(&numTorta);
     // int *vetNaoAbb = arvNaoAbb.insereVetorCrescente(&numNaoAbb);
     // imprime(vetVazia, numVazia);
     // imprime(vet1No, num1No);
     // imprime(vet1Folha, num1Folha);
     // imprime(vetCompleta, numCompleta);
     // imprime(vetCheia, numCheia);
     // imprime(vetTorta, numTorta);
     // imprime(vetNaoAbb, numNaoAbb);
     // cout << endl;

     // // Ex04 - G
     // int numVazia, num1No, num1Folha, numCompleta, numCheia, numTorta, numNaoAbb;
     // int *vetVazia = arvVazia.insereVetorDecrescente(&numVazia);
     // int *vet1No = arv1No.insereVetorDecrescente(&num1No);
     // int *vet1Folha = arv1Folha.insereVetorDecrescente(&num1Folha);
     // int *vetCompleta = arvCompleta.insereVetorDecrescente(&numCompleta);
     // int *vetCheia = arvCheia.insereVetorDecrescente(&numCheia);
     // int *vetTorta = arvTorta.insereVetorDecrescente(&numTorta);
     // int *vetNaoAbb = arvNaoAbb.insereVetorDecrescente(&numNaoAbb);
     // imprime(vetVazia, numVazia);
     // imprime(vet1No, num1No);
     // imprime(vet1Folha, num1Folha);
     // imprime(vetCompleta, numCompleta);
     // imprime(vetCheia, numCheia);
     // imprime(vetTorta, numTorta);
     // imprime(vetNaoAbb, numNaoAbb);
     // cout << endl;

     // // Ex04 - H
     // cout << "Busca" << endl;
     // cout << "Vazia: " << boolalpha << arvVazia.buscaValorBool(0) << endl;
     // cout << "1 no: " << boolalpha << arv1No.buscaValorBool(14) << endl;
     // cout << "1 folha: " << boolalpha << arv1Folha.buscaValorBool(20) << endl;
     // cout << "Completa: " << boolalpha << arvCompleta.buscaValorBool(15) << endl;
     // cout << "Cheia: " << boolalpha << arvCheia.buscaValorBool(14) << endl;
     // cout << "Torta: " << boolalpha << arvTorta.buscaValorBool(32) << endl;
     // cout << "Nao ABB: " << boolalpha << arvNaoAbb.buscaValorBool(10) << endl;
     // cout << endl;

     // // Ex04 - I
     // cout << "Classifica no" << endl;
     // cout << "Vazia: " << arvVazia.classificaNo(0) << endl;
     // cout << "1 no: " << arv1No.classificaNo(14) << endl;
     // cout << "1 folha: " << arv1Folha.classificaNo(20) << endl;
     // cout << "Completa: " << arvCompleta.classificaNo(15) << endl;
     // cout << "Cheia: " << arvCheia.classificaNo(14) << endl;
     // cout << "Torta: " << arvTorta.classificaNo(32) << endl;
     // cout << "Nao ABB: " << arvNaoAbb.classificaNo(10) << endl;
     // cout << endl;

     // // Ex04 - J
     // cout << "Insere nao recursivo" << endl;
     // arvVazia.insereNR(15);
     // arvVazia.insereNR(16);
     // arv1No.insereNR(15);
     // arv1No.insereNR(16);
     // arv1Folha.insereNR(69);
     // arv1Folha.insereNR(21);
     // arvCompleta.insereNR(61);
     // arvCompleta.insereNR(1);
     // arvCheia.insereNR(19);
     // arvCheia.insereNR(1);
     // arvTorta.insereNR(27);
     // arvTorta.insereNR(1);
     // arvNaoAbb.insereNR(27);
     // arvNaoAbb.insereNR(1);
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

     // // Ex04 - K
     // cout << "Quantidade de nos com 1 filho" << endl;
     // cout << "Vazia: " << arvVazia.nos1Filho() << endl;
     // cout << "1 no: " << arv1No.nos1Filho() << endl;
     // cout << "1 folha: " << arv1Folha.nos1Filho() << endl;
     // cout << "Completa: " << arvCompleta.nos1Filho() << endl;
     // cout << "Cheia: " << arvCheia.nos1Filho() << endl;
     // cout << "Torta: " << arvTorta.nos1Filho() << endl;
     // cout << "Nao ABB: " << arvNaoAbb.nos1Filho() << endl;
     // cout << endl;

     // // Ex04 - L
     // cout << "Quantidade de nos com 2 filhos" << endl;
     // cout << "Vazia: " << arvVazia.nos2Filhos() << endl;
     // cout << "1 no: " << arv1No.nos2Filhos() << endl;
     // cout << "1 folha: " << arv1Folha.nos2Filhos() << endl;
     // cout << "Completa: " << arvCompleta.nos2Filhos() << endl;
     // cout << "Cheia: " << arvCheia.nos2Filhos() << endl;
     // cout << "Torta: " << arvTorta.nos2Filhos() << endl;
     // cout << "Nao ABB: " << arvNaoAbb.nos2Filhos() << endl;
     // cout << endl;

     // // Ex04 - M
     // cout << "Eh estritamente binaria" << endl;
     // cout << "Vazia: " << boolalpha << arvVazia.estritamenteBin() << endl;
     // cout << "1 no: " << boolalpha << arv1No.estritamenteBin() << endl;
     // cout << "1 folha: " << boolalpha << arv1Folha.estritamenteBin() << endl;
     // cout << "Completa: " << boolalpha << arvCompleta.estritamenteBin() << endl;
     // cout << "Cheia: " << boolalpha << arvCheia.estritamenteBin() << endl;
     // cout << "Torta: " << boolalpha << arvTorta.estritamenteBin() << endl;
     // cout << "Nao ABB: " << boolalpha << arvNaoAbb.estritamenteBin() << endl;
     // cout << endl;

     // Ex04 - N
     cout << "Transforma AB em ABB" << endl;
     arvNaoAbb.insereNR(27);
     arvNaoAbb.insereNR(1);
     arvNaoAbb.transfABemABB();
     cout << "Nao ABB: " << endl;
     arvNaoAbb.imprime();
     cout << endl;

     return 0;
}
