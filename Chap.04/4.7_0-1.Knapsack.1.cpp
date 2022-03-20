#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

typedef vector<vector<int>> matrix_t;

int n, W;
vector<int> w, p;

/* Simple dynamic programming for the 0-1 Knapsack Problem */
int knapsack2(matrix_t &P) {
    for (int i = 0; i <= n; i++)
        P[i][0] = 0;
    for (int j = 1; j <= W; j++)
        P[0][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++)
            P[i][j] = (w[i] > j) ? P[i - 1][j] : 
                                   max(P[i - 1][j], p[i] + P[i - 1][j - w[i]]);
    
    return P[0][W];
}

int main() {
    cin >> n;
    w.resize(n + 1);
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> W;
        matrix_t P(n, vector<int>(W));
        int maxprofit = knapsack2(P);
        cout << maxprofit << " ";
        cout << P[n][W] << " " << P[n][W] << endl;
    }
}
