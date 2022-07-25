#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    // 10 18 16 NULL NULL 19 NULL NULL 25 38 NULL NULL 14 NULL NULL e d e d d d e d d
    // arv.insere(15);
    // arv.insere(25);
    // arv.insere(10);
    arv.preOrdem();
    cout << endl;
    cout << "Num Nos: " << arv.contaNos() << endl;
    cout << "Num Folhas: " << arv.contaNosFolhas() << endl;
    cout << "Altura: " << arv.altura() << endl;

    return 0;
}
