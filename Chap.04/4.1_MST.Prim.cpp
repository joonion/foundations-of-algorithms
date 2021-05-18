#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n + 1), dist(n + 1);
    F.clear();
    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        dist[i] = W[1][i];
    }
    for (int t = 1; t <= n - 1; t++) {
        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= dist[i] && dist[i] < min) {
                min = dist[i];
                vnear = i;
            }
        F.push_back(make_pair(vnear, nearest[vnear]));
        dist[vnear] = -1;
        for (int i = 2; i <= n; i++)
            if (dist[i] > W[i][vnear]) {
                dist[i] = W[i][vnear];
                nearest[i] = vnear;
            }
    }
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    matrix_t W(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = W[v][u] = w;
    }

    set_of_edges F;
    prim(n, W, F);
    for (auto e: F)
        cout << e.first << " " << e.second << endl;
}