#include <iostream>
#include "ArvBinAlt.h"

using namespace std;

ArvBinAlt *criaArvCheia()
{
     ArvBinAlt *arv = new ArvBinAlt;
     ArvBinAlt *esq = new ArvBinAlt;
     ArvBinAlt *dir = new ArvBinAlt;
     ArvBinAlt *esqP = new ArvBinAlt;
     ArvBinAlt *dirP = new ArvBinAlt;

     esq->cria(16, new ArvBinAlt, new ArvBinAlt);
     dir->cria(19, new ArvBinAlt, new ArvBinAlt);
     esqP->cria(18, esq, dir);

     esq = new ArvBinAlt;
     dir = new ArvBinAlt;
     esq->cria(38, new ArvBinAlt, new ArvBinAlt);
     dir->cria(14, new ArvBinAlt, new ArvBinAlt);
     dirP->cria(25, esq, dir);

     arv->cria(10, esqP, dirP);

     return arv;
}

ArvBinAlt *criaArvCompleta()
{
     ArvBinAlt *arv = new ArvBinAlt;
     ArvBinAlt *esq = new ArvBinAlt;
     ArvBinAlt *dir = new ArvBinAlt;
     ArvBinAlt *arve2 = new ArvBinAlt;
     ArvBinAlt *arvd2 = new ArvBinAlt;
     ArvBinAlt *arve3 = new ArvBinAlt;
     ArvBinAlt *arvd3 = new ArvBinAlt;

     arve3->cria(24, new ArvBinAlt, new ArvBinAlt);
     arvd3->cria(12, new ArvBinAlt, new ArvBinAlt);

     esq->cria(16, new ArvBinAlt, new ArvBinAlt);
     dir->cria(19, new ArvBinAlt, new ArvBinAlt);
     arve2->cria(18, esq, dir);

     esq = new ArvBinAlt;
     dir = new ArvBinAlt;
     esq->cria(38, arve3, arvd3);
     dir->cria(14, new ArvBinAlt, new ArvBinAlt);
     arvd2->cria(25, esq, dir);

     arv->cria(10, arve2, arvd2);

     return arv;
}

ArvBinAlt *criaArvTorta()
{
     ArvBinAlt *arv = new ArvBinAlt;
     ArvBinAlt *esq = new ArvBinAlt;
     ArvBinAlt *dir = new ArvBinAlt;
     ArvBinAlt *arve2 = new ArvBinAlt;
     ArvBinAlt *arvd2 = new ArvBinAlt;
     ArvBinAlt *arvd3 = new ArvBinAlt;

     arvd3->cria(12, new ArvBinAlt, new ArvBinAlt);

     esq->cria(16, new ArvBinAlt, new ArvBinAlt);
     dir->cria(19, new ArvBinAlt, new ArvBinAlt);
     arve2->cria(18, esq, dir);

     esq = new ArvBinAlt;
     dir = new ArvBinAlt;
     esq->cria(38, new ArvBinAlt, arvd3);
     arvd2->cria(25, esq, new ArvBinAlt);

     arv->cria(10, arve2, arvd2);

     return arv;
}

ArvBinAlt *criaArvABB()
{
     ArvBinAlt *arv = new ArvBinAlt;
     ArvBinAlt *esq = new ArvBinAlt;
     ArvBinAlt *dir = new ArvBinAlt;
     ArvBinAlt *esqP = new ArvBinAlt;
     ArvBinAlt *dirP = new ArvBinAlt;
     ArvBinAlt *dir3 = new ArvBinAlt;

     dir3->cria(42, new ArvBinAlt, new ArvBinAlt);

     esq->cria(6, new ArvBinAlt, new ArvBinAlt);
     dir->cria(9, new ArvBinAlt, new ArvBinAlt);
     esqP->cria(8, esq, dir);

     esq = new ArvBinAlt;
     dir = new ArvBinAlt;
     dir->cria(38, new ArvBinAlt, dir3);
     dirP->cria(25, new ArvBinAlt, dir);

     arv->cria(10, esqP, dirP);

     return arv;
}

ArvBinAlt *criaArvAVL()
{
     ArvBinAlt *arv = new ArvBinAlt;
     ArvBinAlt *esq = new ArvBinAlt;
     ArvBinAlt *dir = new ArvBinAlt;
     ArvBinAlt *esqP = new ArvBinAlt;
     ArvBinAlt *dirP = new ArvBinAlt;

     esq->cria(6, new ArvBinAlt, new ArvBinAlt);
     dir->cria(9, new ArvBinAlt, new ArvBinAlt);
     esqP->cria(8, esq, dir);

     esq = new ArvBinAlt;
     dir = new ArvBinAlt;
     dir->cria(38, new ArvBinAlt, new ArvBinAlt);
     dirP->cria(25, new ArvBinAlt, dir);

     arv->cria(10, esqP, dirP);

     return arv;
}

int main()
{
     ArvBinAlt arvCompleta = *criaArvCompleta();
     ArvBinAlt arvVazia;
     ArvBinAlt arv1No;
     ArvBinAlt arv1Folha;
     ArvBinAlt *arv1Folha1 = new ArvBinAlt;
     ArvBinAlt arvCheia = *criaArvCheia();
     ArvBinAlt arvTorta = *criaArvTorta();
     ArvBinAlt arvABB = *criaArvABB();
     ArvBinAlt arvAVL = *criaArvAVL();

     arv1No.cria(14, new ArvBinAlt, new ArvBinAlt);
     arv1Folha1->cria(20, new ArvBinAlt, new ArvBinAlt);
     arv1Folha.cria(67, arv1Folha1, new ArvBinAlt);

     // // Ex05
     // cout << "ATUALIZA ALTURA" << endl;
     // arvVazia.alturaNos();
     // arv1No.alturaNos();
     // arv1Folha.alturaNos();
     // arvCompleta.alturaNos();
     // arvCheia.alturaNos();
     // arvTorta.alturaNos();
     // cout << endl;

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
     cout << endl;
     cout << endl
          << "ABB: " << endl;
     arvABB.imprime();
     cout << endl;
     cout << endl
          << "AVL: " << endl;
     arvAVL.imprime();
     cout << endl;

     // // Ex06
     // cout << "ALTURA IGUAL A 3" << endl;
     // cout << "Vazia: " << arvVazia.noAltInfo(3) << endl;
     // cout << "1 no: " << arv1No.noAltInfo(3) << endl;
     // cout << "1 folha: " << arv1Folha.noAltInfo(3) << endl;
     // cout << "Completa: " << arvCompleta.noAltInfo(3) << endl;
     // cout << "Cheia: " << arvCheia.noAltInfo(3) << endl;
     // cout << "Torta: " << arvTorta.noAltInfo(3) << endl;
     // cout << endl;

     // Ex07
     cout << "E AVL" << endl;
     cout << "Vazia: " << boolalpha << arvVazia.eAVL() << endl;
     cout << "1 no: " << boolalpha << arv1No.eAVL() << endl;
     cout << "1 folha: " << boolalpha << arv1Folha.eAVL() << endl;
     cout << "Completa: " << boolalpha << arvCompleta.eAVL() << endl;
     cout << "Cheia: " << boolalpha << arvCheia.eAVL() << endl;
     cout << "Torta: " << boolalpha << arvTorta.eAVL() << endl;
     cout << "ABB: " << boolalpha << arvABB.eAVL() << endl;
     cout << "AVL: " << boolalpha << arvAVL.eAVL() << endl;
     cout << endl;

     return 0;
}