#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;

void floyd(int n, matrix_t& W, matrix_t& D)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            D[i][j] = W[i][j];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    matrix_t W(n + 1, vector<int>(n + 1, INF));
    matrix_t D(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }
    floyd(n, W, D);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
}
