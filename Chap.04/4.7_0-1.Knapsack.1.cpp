#include <iostream>
#include <map>
#include <utility>
using namespace std;

#define MAX 256

int n, W, w[MAX], p[MAX];

/* Enhanced dynamic programming for the 0-1 Knapsack Problem */
int knapsack3(int i, int W, map<pair<int, int>, int> &P) {
    if (i == 0 || W <= 0) {
        return 0;
    }
    int lvalue = (P.find(make_pair(i-1, W)) != P.end()) ?
        P[make_pair(i-1, W)] : knapsack3(i-1, W, P);
    int rvalue = (P.find(make_pair(i-1, W-w[i])) != P.end()) ?
        P[make_pair(i-1, W)] : knapsack3(i-1, W-w[i], P);
    P[make_pair(i, W)] = (w[i] > W) ? lvalue : max(lvalue, p[i] + rvalue);
    return P[make_pair(i, W)];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> W;
        map<pair<int, int>, int> P;
        int maxprofit = knapsack3(n, W, P);
        cout << maxprofit << " ";
        // for (const auto [key, value]: P)
        //     cout << "(" << key.first << "," << key.second << "): " << value << " ";
        // cout << endl;
        cout << P[make_pair(n - 1, W)] << " " << P[make_pair(n - 1, W - w[n])] << endl;
    }
}
