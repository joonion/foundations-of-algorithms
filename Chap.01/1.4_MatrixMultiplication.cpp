#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix_t;

void matrixmult(int n, matrix_t& A, matrix_t& B, matrix_t& C) 
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main()
{
    int n;
    cin >> n;
    matrix_t A(n + 1, vector<int>(n + 1));
    matrix_t B(n + 1, vector<int>(n + 1));
    matrix_t C(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> A[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> B[i][j];
    matrixmult(n, A, B, C);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j != n)
                cout << C[i][j] << " ";
            else
                cout << C[i][j] << endl;
}