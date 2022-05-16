#include <iostream>
#include "Aluno.h"

using namespace std;

int main()
{
    int idade;
    string matricula;

    Aluno aluno("Andre", "2022010005");
    //aluno.leNotas();

    //cout << "Media: " << aluno.calculaMedia() << endl;

    cout << "Digite a idade: ";
    cin >> idade;
    cout << "Digite a matricula: ";
    cin >> matricula;

    aluno.setIdade(idade);
    aluno.setMatricula(matricula);

    cout << "Idade = " << aluno.getIdade() << endl;
    cout << "Matricula = " << aluno.getMatricula() << endl;

    return 0;
}
