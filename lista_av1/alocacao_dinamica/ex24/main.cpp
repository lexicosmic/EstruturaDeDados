// 8 minutos e 40 segundos
#include <iostream>

using namespace std;

float **alocaMatrizF(int m, int n)
{
    float **mat;

    // Verifica se tamanho é válido
    if (n <= 0 || m <= 0)
    {
        cout << "ERRO: Nao e possivel alocar a matriz com numero de linhas ou colunas nulo ou negativo!" << endl;
        exit(1);
    }

    // Aloca vetor de ponteiros dinamicamente
    mat = new float *[m];

    // Verifica se foi alocado com sucesso
    if (mat == NULL)
    {
        cout << "ERRO: A matriz nao pode ser alocada!" << endl;
        exit(1);
    }

    for (int i = 0; i < m; i++)
    {
        // Aloca vetor de float dinamicamente
        mat[i] = new float[n];
        // Verifica se foi alocado com sucesso
        if (mat[i] == NULL)
        {
            cout << "ERRO: A matriz nao pode ser alocada!" << endl;
            exit(1);
        }
    }

    return mat;
}

void preencheMatrizF(int m, int n, float **mat)
{
    cout << "Preenchendo a matriz" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "a linha" << endl;
        for (int j = 0; j < n; j++)
        {
            float val;
            cout << j + 1 << "o num: ";
            cin >> val;
            mat[i][j] = val;
        }
    }
}

float **transposta(int m, int n, float **mat)
{
    float **transp;
    transp = alocaMatrizF(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            transp[i][j] = mat[j][i];
        }
    }
    return transp;
}

int main()
{
    float **mat, **transp;
    int m, n;

    cout << "No linhas: ";
    cin >> m;
    cout << "No colunas: ";
    cin >> n;

    // Testes
    // mat = alocaMatrizF(0, 0);
    // mat = alocaMatrizF(-2, 0);
    // mat = alocaMatrizF(2.5, 3.5);

    mat = alocaMatrizF(m, n);

    preencheMatrizF(m, n, mat);

    cout << "IMPRESSAO" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    transp = transposta(m, n, mat);

    cout << endl;
    cout << "IMPRESSAO TRANSPOSTA" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << transp[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;

    for (int i = 0; i < n; i++)
    {
        delete[] transp[i];
    }
    delete[] transp;

    return 0;
}