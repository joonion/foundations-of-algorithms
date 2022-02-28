#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    vector<vector<int>> w(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            w[i][j] = v[j][i];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << w[i][j] << " ";
        cout << endl;
    }
}