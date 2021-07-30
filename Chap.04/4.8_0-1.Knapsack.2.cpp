/*
[Input]
3 30
5 10 20
50 60 140
[Output]
*/
#include <iostream>
#include <map>
#include <utility>
using namespace std;

#define MAX 256

/* Enhanced dynamic programming for the 0-1 Knapsack Problem */
int knapsack3(int n, int W, int w[], int p[], map<pair<int, int>, int> &P) {
    if (n == 0 || W <= 0)
        return 0;

    int lvalue = (P.find(make_pair(n-1, W)) != P.end()) ?
        P[make_pair(n-1, W)] : knapsack3(n-1, W, w, p, P);
    int rvalue = (P.find(make_pair(n-1, W-w[n])) != P.end()) ?
        P[make_pair(n-1, W)] : knapsack3(n-1, W-w[n], w, p, P);
    P[make_pair(n, W)] = (w[n] > W) ? lvalue : max(lvalue, p[n] + rvalue);
    return P[make_pair(n, W)];
}

int main() {
    int n, W, weight[MAX], profit[MAX];
    map<pair<int, int>, int> P;

    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> weight[i];
    for (int i = 1; i <= n; i++)
        cin >> profit[i];
    int maxprofit = knapsack3(n, W, weight, profit, P);
    cout << maxprofit << endl;

    map<pair<int, int>, int>::iterator it;
    for (it = P.begin(); it != P.end(); it++)
        cout << "(" << it->first.first << "," << it->first.second << "): " << it->second << " " << endl;
}
