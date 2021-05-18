#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;

void floyd(int n, matrix_t& D)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    matrix_t W, D;
    W.resize(n + 1, vector<int>(n + 1, INF));
    D.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = D[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = D[u][v] = w;
    }
    floyd(n, D);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j != n) cout << D[i][j] << " ";
            else cout << D[i][j] << endl;
}
