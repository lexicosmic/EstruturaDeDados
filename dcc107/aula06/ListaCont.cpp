#include <iostream>
#include <cstdlib>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;
    n = 0;
    vet = new Ponto[max];
}

ListaCont::~ListaCont()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete[] vet;
}

Ponto ListaCont::get(int k)
{
    if (k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, Ponto pt)
{
    if (k >= 0 && k < n)
        vet[k] = pt;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereFinal(Ponto pt)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = pt;
    n = n + 1;
}

void ListaCont::removeFinal()
{
    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaCont::insereK(int k, Ponto pt)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if (k >= 0 && k < n)
    {
        for (int i = n - 1; i >= k; i--)
            vet[i + 1] = vet[i];
        vet[k] = pt;
        n = n + 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::removeK(int k)
{
    if (k >= 0 && k < n)
    {
        for (int i = k; i < n - 1; i++)
            vet[i] = vet[i + 1];
        n = n - 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereInicio(Ponto pt)
{
    if (n == 0)
    { // lista vazia. Sera o unico no da lista
        vet[n] = pt;
        n = n + 1;
    }
    else
        insereK(0, pt);
}

void ListaCont::removeInicio()
{
    removeK(0);
}

int ListaCont::numNos()
{
    return n;
}

void ListaCont::limpar()
{
    n == 0;
}

void ListaCont::insereValores(int tam)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    else if (n + tam > max)
    {
        cout << "ERRO: Vetor nao comporta todos os valores lidos!" << endl;
        exit(1);
    }
    cout << "Digite " << tam << " coordenadas:" << endl;
    for (int i = 0; i < tam; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        insereFinal(Ponto(x, y));
    }
}

void ListaCont::imprime()
{
    cout << "== Impressão da lista ==" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": (" << vet[i].getX() << ", " << vet[i].getY() << ")" << endl;
    }
}