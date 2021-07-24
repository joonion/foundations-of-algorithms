#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix_t;

const int threshold = 2;

// global variables
matrix_t A11, A12, A21, A22;
matrix_t B11, B12, B21, B22;
matrix_t C11, C12, C21, C22;
matrix_t L, R;
matrix_t M1, M2, M3, M4, M5, M6, M7;

void print_matrix(int n, matrix_t& M)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void init_matrices(int n) {
    int m = n / 2;
    A11.resize(m, vector<int>(m));
    A12.resize(m, vector<int>(m));
    A21.resize(m, vector<int>(m));
    A22.resize(m, vector<int>(m));
    B11.resize(m, vector<int>(m));
    B12.resize(m, vector<int>(m));
    B21.resize(m, vector<int>(m));
    B22.resize(m, vector<int>(m));
    C11.resize(m, vector<int>(m));
    C12.resize(m, vector<int>(m));
    C21.resize(m, vector<int>(m));
    C22.resize(m, vector<int>(m));
    M1.resize(m, vector<int>(m));
    M2.resize(m, vector<int>(m));
    M3.resize(m, vector<int>(m));
    M4.resize(m, vector<int>(m));
    M6.resize(m, vector<int>(m));
    M7.resize(m, vector<int>(m));
    L.resize(m, vector<int>(m));
    R.resize(m, vector<int>(m));
}


void mmult(int n, matrix_t& A, matrix_t& B, matrix_t &C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void madd(int n, matrix_t& A, matrix_t& B, matrix_t& C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void msub(int n, matrix_t& A, matrix_t& B, matrix_t& C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void partition(int m, matrix_t& M, 
               matrix_t& M11, matrix_t& M12, matrix_t& M21, matrix_t& M22)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j + m];
            M21[i][j] = M[i + m][j];
            M22[i][j] = M[i + m][j + m];
        }
}

void combine(int m, matrix_t& M, 
               matrix_t& M11, matrix_t& M12, matrix_t& M21, matrix_t& M22)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            M[i][j]         = M11[i][j];
            M[i][j + m]     = M12[i][j];
            M[i + m][j]     = M21[i][j];
            M[i + m][j + m] = M22[i][j];
        }
}

void strassen(int n, matrix_t& A, matrix_t& B, matrix_t &C)
{
    if (n <= threshold) {
        mmult(n, A, B, C);
    }
    else {
        int m = n / 2;
        partition(m, A, A11, A12, A21, A22);
        partition(m, B, B11, B12, B21, B22);

        madd(m, A11, A22, L);
        madd(m, B11, B22, R);
        strassen(m, L, R, M1);
        madd(m, A21, A22, L);
        strassen(m, L, B11, M2);
        msub(m, B12, B22, R);
        strassen(m, A11, R, M3);
        if (m >= 2) {
            print_matrix(m, M3);
        }        
        msub(m, B21, B11, R);
        strassen(m, A22, R, M4);
        madd(m, A11, A12, L);
        strassen(m, L, B22, M5);
        msub(m, A21, A11, L);
        madd(m, B11, B12, R);
        strassen(m, L, R, M6);

        msub(m, A12, A22, L);
        madd(m, B21, B22, R);
        strassen(m, L, R, M7);

        madd(m, M1, M4, L);
        msub(m, L,  M5, R);
        madd(m, R,  M7, C11);
        madd(m, M3, M5, C12);
        madd(m, M2, M4, C21);
        madd(m, M1, M3, L);
        msub(m, L,  M2, R);
        madd(m, R,  M6, C22);

        combine(m, C, C11, C12, C21, C22);
        if (m >= 2) {
            print_matrix(2 * m, C);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    init_matrices(n);
    matrix_t A(n, vector<int>(n));
    matrix_t B(n, vector<int>(n));
    matrix_t C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    strassen(n, A, B, C);
    print_matrix(n, C);
}