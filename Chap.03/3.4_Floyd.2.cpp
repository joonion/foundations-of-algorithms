#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;

void floyd2(int n, matrix_t& W, matrix_t& D, matrix_t& P)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
}

void path(matrix_t& P, int u, int v, vector<int>& p)
{
    int k = P[u][v];
    if (k != 0) {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    matrix_t W(n + 1, vector<int>(n + 1, INF));
    matrix_t D(n + 1, vector<int>(n + 1, INF));
    matrix_t P(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }
    floyd2(n, W, D, P);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << P[i][j] << " ";
        cout << endl;
    }
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> u >> v;
        vector<int> shortest;
        path(P, u, v, shortest);
        cout << u;
        for (int i = 0; i < shortest.size(); i++)
            cout << " -> " << shortest[i];
        cout << " -> " << v << endl;
    }
}

