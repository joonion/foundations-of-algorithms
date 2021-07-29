#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n + 1), distance(n + 1);

    F.clear(); // 𝐹=∅;
    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    for (int t = 1; t <= n - 1; t++) {
        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= distance[i] && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }
        // e = edge connecting vertices indexed by vnear and nearest[vnear];
        // add e to F;
        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++)
            if (distance[i] > W[i][vnear]) {
                distance[i] = W[i][vnear];
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
    for (edge_t e: F) {
        u = e.first; v = e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }
}