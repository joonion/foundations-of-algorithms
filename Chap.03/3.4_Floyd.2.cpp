#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;

void floyd2(int n, matrix_t& D, matrix_t& P)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
}

void shortest_path(int s, int t, matrix_t& P, vector<int>& path)
{
    int k = P[s][t];
    if (k != 0) {
        shortest_path(s, k, P, path);
        path.push_back(k);
        shortest_path(k, t, P, path);
    }
}

int path_length(vector<int>& path, matrix_t& W)
{
    int length = 0;
    for (int i = 0; i < path.size() - 1; i++)
        length += W[path[i]][path[i + 1]];
    return length;
}

int main()
{
    int n, m, u, v, w, T;
    cin >> n >> m;
    matrix_t W, D, P;
    W.resize(n + 1, vector<int>(n + 1, INF));
    D.resize(n + 1, vector<int>(n + 1, INF));
    P.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        W[i][i] = D[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = D[u][v] = w;
    }
    floyd2(n, D, P);
    cout << "D = " << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j != n) cout << D[i][j] << " ";
            else cout << D[i][j] << endl;
    cout << "P = " << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j != n) cout << P[i][j] << " ";
            else cout << P[i][j] << endl;
    cin >> T;
    while (T-- > 0) {
        cin >> u >> v;
        vector<int> path;
        path.push_back(u);
        shortest_path(u, v, P, path);
        path.push_back(v);
        cout << u << " -> " << v << " : ";
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << "(" << path_length(path, W) << ")" << endl;
    }
}
