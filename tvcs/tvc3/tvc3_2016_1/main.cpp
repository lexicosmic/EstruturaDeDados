// ############################################################################
// TVC 3 de ESTRUTURA DE DADOS e LABORATORIO DE PROGRAMACAO 2
// DATA: 07/03/2016 - PROF.: BERNARDO MARTINS ROCHA
// PREENCHER ESTE CABECALHO COM SUAS INFORMACOES
// ALUNO:
// MATRICULA:
// ############################################################################

#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    cout << "TVC3 de ESTRUTURA DE DADOS e LAB. PROG. II" << endl;
    cout << "FAVOR PREENCHER OS SEUS DADOS" << endl;
    cout << "Exemplo de ABB: " << endl;
    ArvBinBusca abb;
    abb.insere(25);
    abb.insere(15);
    abb.insere(35);
    abb.insere(3);
    abb.insere(16);
    abb.insere(33);
    abb.insere(45);
    abb.imprime();

    // TESTE DA QUESTAO 1 -----------------------------------------------------
    cout << endl
         << "TESTE DA QUESTAO 1" << endl;
    bool q1 = abb.ehEstritamente();
    if (q1)
        cout << "ABB eh estritamente binaria" << endl;
    else
        cout << "ABB nao eh estritamente binaria" << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 2 -----------------------------------------------------
    cout << endl
         << "TESTE DA QUESTAO 2" << endl;
    abb.imprime();

    int prox = 47;
    cout << "Valor mais proximo de " << prox << ":\n";
    abb.maisProximo(prox);
    cout << endl;

    prox = 45;
    cout << "Valor mais proximo de " << prox << ":\n";
    abb.maisProximo(prox);
    cout << endl;

    prox = 7;
    cout << "Valor mais proximo de " << prox << ":\n";
    abb.maisProximo(prox);
    cout << endl;

    prox = 14;
    cout << "Valor mais proximo de " << prox << ":\n";
    abb.maisProximo(prox);
    cout << endl;

    prox = 34;
    cout << "Valor mais proximo de " << prox << ":\n";
    abb.maisProximo(prox);
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 3 -----------------------------------------------------
    cout << endl
         << "TESTE DA QUESTAO 3" << endl;
    abb.imprime();
    int n;
    int *v = abb.criaVetCaminho(25, &n);
    if (v != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        delete[] v;
    }
    // ------------------------------------------------------------------------

    return 0;
}
