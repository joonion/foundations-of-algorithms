#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int A[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    int B[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = A[j][i];

    cout << m << " by " << n << " matrix" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }

}