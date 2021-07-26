#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF 0xFFFF

typedef vector<vector<int>> matrix_t;

bool isIn(int i, int A) {
    return (A & (1 << (i - 2))) != 0;
}

int diff(int A, int j) {
    return (A & ~(1 << (j - 2)));
}

int count(int A) {
    int cnt = 0;
    for (; A != 0; A >>= 1)
        if (A & 1) cnt++;
    return cnt;
}

int minimum(int n, int i, int &minJ, int A, matrix_t& W, matrix_t& D) {
    int minV = INF;
    for (int j = 2; j <= n; j++) {
        if (!isIn(j, A)) continue;
        int value = W[i][j] + D[j][diff(A, j)];
        if (minV > value) {
            minV = value; 
            minJ = j;
        }
    }
    return minV;
}

void travel(int n, matrix_t& W, matrix_t& D, matrix_t& P, int &minlength) {
    int i, j, k;

    int subset_size = pow(2, n - 1);
    for (i = 2; i <= n; i++)
        D[i][0] = W[i][1];
    for (k = 1; k <= n - 2; k++)
        for (int A = 0; A < subset_size; A++) {
            if (count(A) != k) continue;
            for (i = 2; i <= n; i++) {
                if (isIn(i, A)) continue;
                D[i][A] = minimum(n, i, j, A, W, D);
                P[i][A] = j;
            }
        }
    int A = subset_size - 1;
    D[1][A] = minimum(n, 1, j, A, W, D);
    P[1][A] = j;
    minlength = D[1][A];
}

void tour(int v, int A, matrix_t& P) {
    if (A == 0)
        cout << "1";
    else {
        cout << P[v][A] << " ";
        tour(P[v][A], diff(A, P[v][A]), P);
    }
}

int dist(vector<pair<int, int>>& p, int i, int j) 
{
    if (i == j)
        return 0;
    else
        return (int)pow(p[i].first - p[j].first, 2) + (int)pow(p[i].second - p[j].second, 2);
}

int main() 
{
    int n, m, u, v, w, minlength;
    cin >> n;
    matrix_t W(n + 1, vector<int>(n + 1, INF));
    matrix_t D(n + 1, vector<int>(pow(2, n - 1), 0));
    matrix_t P(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    travel(n, W, D, P, minlength);

    cout << "D = " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < pow(2, n-1); j++)
            cout << D[i][j] << "\t";
        cout << endl;
    }    
    cout << "P = " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < pow(2, n-1); j++)
            cout << P[i][j] << " ";
        cout << endl;
    }

    cout << "1 ";
    tour(1, pow(2, n - 1) - 1, P);
    cout << " " << minlength << endl;
}
