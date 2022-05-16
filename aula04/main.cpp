#include <iostream>
#include "Aluno.h"

using namespace std;

int main()
{
    int idade;
    string matricula, nome;

    //Aluno aluno("Andre", "2022010005");
    //aluno.leNotas();

    //cout << "Media: " << aluno.calculaMedia() << endl;

    // INTERFACE
    cout << "== CADASTRO DO ALUNO ==" << endl;
    cout << "Digite o nome: ";
    cin >> nome;
    cout << "Digite a idade: ";
    cin >> idade;
    cout << "Digite a matricula: ";
    cin >> matricula;

    Aluno aluno(nome, matricula);
    aluno.setIdade(idade);
    aluno.setMatricula(matricula);

    cout << endl << "== REGISTRO DO ALUNO ==" << endl;
    cout << "Nome: " << aluno.getNome() << endl;
    cout << "Idade: " << aluno.getIdade() << endl;
    cout << "Matricula: " << aluno.getMatricula() << endl;

    return 0;
}
