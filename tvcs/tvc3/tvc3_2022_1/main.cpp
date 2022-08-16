#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
     ArvBinBusca arv, arvVazia, arv1No, arv1Folha;

     cout << "Criando uma Arvore Binaria de Busca (ABB)" << endl;
     arv.insere(15);
     arv.insere(9);
     arv.insere(20);
     arv.insere(7);
     arv.insere(11);
     arv.insere(18);
     arv.insere(24);
     arv.insere(6);
     arv.insere(8);
     arv.insere(10);
     arv.insere(12);
     arv.insere(17);
     arv.insere(-19);
     arv.imprime();
     cout << endl;

     arv1No.insere(-14);

     arv1Folha.insere(15);
     arv1Folha.insere(14);

     cout << "TESTES PARA A QUESTAO 1 ------------------------------------------------" << endl;
     cout << "Padrao" << endl;
     cout << "Valor esperado: Quant. nos pares: 7" << endl;
     cout << "Valor esperado: Quant. folhas nao negativas: 5" << endl;
     arv.contaElegante();
     cout << endl;
     // cout << "Vazia" << endl;
     // cout << "Valor esperado: Quant. nos pares: 0" << endl;
     // cout << "Valor esperado: Quant. folhas nao negativas: 0" << endl;
     // arvVazia.contaElegante();
     // cout << endl;
     // cout << "1 no" << endl;
     // cout << "Valor esperado: Quant. nos pares: 1" << endl;
     // cout << "Valor esperado: Quant. folhas nao negativas: 0" << endl;
     // arv1No.contaElegante();
     // cout << endl;
     // cout << "1 folha" << endl;
     // cout << "Valor esperado: Quant. nos pares: 2" << endl;
     // cout << "Valor esperado: Quant. folhas nao negativas: 1" << endl;
     // arv1Folha.contaElegante();
     // cout << endl;
     cout << endl;

     // -----------------------------------------------------------------------------
     cout << "TESTES PARA A QUESTAO 2 ------------------------------------------------" << endl;
     cout << "Padrao" << endl;
     cout << "Valor esperado: 83,   "
          << "Valor obtido: " << arv.somaIntervalo(10, 19) << endl;
     cout << "Valor esperado:  0,   "
          << "Valor obtido: " << arv.somaIntervalo(25, 30) << endl;
     cout << "Valor esperado: 55,   "
          << "Valor obtido: " << arv.somaIntervalo(16, 22) << endl
          << endl;

     // cout << "Vazia" << endl;
     // cout << "Valor esperado: 0,   "
     //      << "Valor obtido: " << arvVazia.somaIntervalo(10, 19) << endl;
     // cout << "Valor esperado:  0,   "
     //      << "Valor obtido: " << arvVazia.somaIntervalo(25, 30) << endl;
     // cout << "Valor esperado: 0,   "
     //      << "Valor obtido: " << arvVazia.somaIntervalo(16, 22) << endl
     //      << endl;

     // cout << "1 no" << endl;
     // cout << "Valor esperado: 0,   "
     //      << "Valor obtido: " << arv1No.somaIntervalo(10, 19) << endl;
     // cout << "Valor esperado:  -14,   "
     //      << "Valor obtido: " << arv1No.somaIntervalo(-14, -14) << endl;
     // cout << "Valor esperado: -14,   "
     //      << "Valor obtido: " << arv1No.somaIntervalo(-54, 22) << endl
     //      << endl;

     // cout << "1 folha" << endl;
     // cout << "Valor esperado: 28,   "
     //      << "Valor obtido: " << arv1Folha.somaIntervalo(10, 19) << endl;
     // cout << "Valor esperado:  0,   "
     //      << "Valor obtido: " << arv1Folha.somaIntervalo(25, 30) << endl;
     // cout << "Valor esperado: 28,   "
     //      << "Valor obtido: " << arv1Folha.somaIntervalo(14, 14) << endl
     //      << endl;

     cout << endl
          << endl;
     // -----------------------------------------------------------------------------

     cout << "TESTES PARA A QUESTAO 3 ------------------------------------------------" << endl;
     cout << "Padrao" << endl;
     arv.removeNo(24);
     arv.removeNo(20);
     arv.removeNo(15);
     arv.removeNo(12);
     arv.removeNo(11);
     arv.removeNo(-19);
     arv.removeNo(4);
     cout << "ABB em ordem esperada: 6 7 8 9 10 11 15 17 18 20."
          << "   ABB obtida: ";
     arv.imprime();
     cout << endl;

     // cout << "Vazia" << endl;
     // arvVazia.removeNo(24);
     // arvVazia.removeNo(20);
     // arvVazia.removeNo(15);
     // arvVazia.removeNo(-14);
     // arvVazia.removeNo(12);
     // arvVazia.removeNo(11);
     // arvVazia.removeNo(-19);
     // arvVazia.removeNo(4);
     // cout << "ABB em ordem esperada: ."
     //      << "   ABB obtida: ";
     // arvVazia.imprime();
     // cout << endl;

     // cout << "1 no" << endl;
     // arv1No.removeNo(24);
     // arv1No.removeNo(20);
     // arv1No.removeNo(15);
     // arv1No.removeNo(-14);
     // arv1No.removeNo(12);
     // arv1No.removeNo(11);
     // arv1No.removeNo(-19);
     // arv1No.removeNo(4);
     // cout << "ABB em ordem esperada: ."
     //      << "   ABB obtida: ";
     // arv1No.imprime();
     // cout << endl;

     cout << "1 folha" << endl;
     // arv1Folha.removeNo(24);
     // arv1Folha.removeNo(20);
     arv1Folha.removeNo(15);
     // arv1Folha.removeNo(14);
     // arv1Folha.removeNo(12);
     // arv1Folha.removeNo(11);
     // arv1Folha.removeNo(-19);
     // arv1Folha.removeNo(4);
     cout << "ABB em ordem esperada: 14."
          << "   ABB obtida: ";
     arv1Folha.imprime();
     cout << endl;
     cout << endl;

     // -----------------------------------------------------------------------------
     return 0;
}
