#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;

void dijkstra(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> touch(n + 1), length(n + 1);
    F.clear();
    for (int i = 2; i <= n; i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }
    for (int t = 1; t <= n - 1; t++) {
        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= length[i] && length[i] < min) {
                min = length[i];
                vnear = i;
            }
        
        // e = edge from vertex indexed by touch[vnear];
        // add e to F;
        F.push_back(make_pair(touch[vnear], vnear));

        for (int i = 2; i <= n; i++)
            if (length[i] > length[vnear] + W[vnear][i]) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        length[vnear] = -1;
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
        W[u][v] = w; // a directed graph.
    }

    set_of_edges F;
    dijkstra(n, W, F);
    for (auto e: F)
        cout << e.first << " " << e.second << " " << W[e.first][e.second] << endl;
}