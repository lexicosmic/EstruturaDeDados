#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
     ArvBinBusca arvCompleta;
     ArvBinBusca arvVazia;
     ArvBinBusca arv1No;
     ArvBinBusca arv1Folha;

     cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
     arvCompleta.insere(15, "Ana", "Matematica", "8C", 7.1);
     arvCompleta.insere(9, "Bruno", "Quimica", "7A", 6.4);
     arvCompleta.insere(20, "Carlos", "Portugues", "6B", 5.1);
     arvCompleta.insere(7, "Daniel", "Fisica", "8C", 8.2);
     arvCompleta.insere(11, "Eduarda", "Geografia", "8B", 4.1);
     arvCompleta.insere(18, "Felipe", "Historia", "7A", 7.9);
     arvCompleta.insere(24, "Geovana", "Matematica", "8C", 7.8);
     arvCompleta.insere(6, "Hakila", "Matematica", "9C", 9.1);
     arvCompleta.insere(8, "Italo", "Geografia", "8A", 7.4);
     arvCompleta.insere(10, "Jonas", "Matematica", "9A", 6.5);
     arvCompleta.insere(12, "Kamile", "Portugues", "8B", 6.6);
     arvCompleta.insere(17, "Lara", "Quimica", "9C", 7.0);
     arvCompleta.insere(19, "Mateus", "Historia", "8B", 5.2);

     arv1No.insere(14, "Ana", "Matematica", "8C", 7.1);
     arv1Folha.insere(67, "Ana", "Matematica", "8C", 7.1);
     arv1Folha.insere(20, "Bruno", "Quimica", "7A", 6.2);

     cout << "Arvore Binaria de Busca final:" << endl;
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
     cout << endl;

     // // Imprime aluno
     // cout << "Imprime aluno" << endl;
     // cout << "Vazia: " << endl;
     // arvVazia.imprimeAluno(3);
     // cout << endl;
     // cout << "1 no: " << endl;
     // arv1No.imprimeAluno(14);
     // cout << endl;
     // cout << "1 folha: " << endl;
     // arv1Folha.imprimeAluno(14);
     // arv1Folha.imprimeAluno(67);
     // cout << endl;
     // cout << "Completa: " << endl;
     // arvCompleta.imprimeAluno(18);
     // arvCompleta.imprimeAluno(24);
     // arvCompleta.imprimeAluno(0);
     // arvCompleta.imprimeAluno(6);
     // arvCompleta.imprimeAluno(15);
     // arvCompleta.imprimeAluno(10);
     // cout << endl;

     // // Remove aluno
     // cout << "Removendo alunos" << endl;
     // arvVazia.remove(3);
     // arv1No.remove(14);
     // arv1Folha.remove(67);
     // arvCompleta.remove(0);
     // arvCompleta.remove(6);
     // arvCompleta.remove(15);
     // arvCompleta.remove(9);

     // cout << "Arvore Binaria de Busca final:" << endl;
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
     // cout << endl;

     // // Maior média
     // cout << "Imprime maior media:" << endl;
     // cout << "Vazia: " << endl;
     // arvVazia.imprimeMaiorMedia();
     // cout << endl
     //      << "1 no: " << endl;
     // arv1No.imprimeMaiorMedia();
     // cout << endl
     //      << "1 folha: " << endl;
     // arv1Folha.imprimeMaiorMedia();
     // cout << endl
     //      << "Completa: " << endl;
     // arvCompleta.imprimeMaiorMedia();
     // cout << endl;

     // Menor média
     cout << "Imprime menor media:" << endl;
     cout << "Vazia: " << endl;
     arvVazia.imprimeMenorMedia();
     cout << endl
          << "1 no: " << endl;
     arv1No.imprimeMenorMedia();
     cout << endl
          << "1 folha: " << endl;
     arv1Folha.imprimeMenorMedia();
     cout << endl
          << "Completa: " << endl;
     arvCompleta.imprimeMenorMedia();
     cout << endl;

     return 0;
}
