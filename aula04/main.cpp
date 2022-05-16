#include <iostream>
#include "Aluno.h"

using namespace std;

int main()
{
    Aluno aluno("Andre", "2022010005");
    aluno.leNotas();

    cout << "Media: " << aluno.calculaMedia() << endl;




    return 0;
}
