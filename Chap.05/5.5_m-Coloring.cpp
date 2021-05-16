#include <iostream>
#include <vector>
using namespace std;

int m, n, solution_count;
vector<vector<int>> W;
vector<int> vcolor;

bool promising(int i)
{
    bool flag = true;
    int j = 1;
    while (j < i && flag) {
        if (W[i][j] && vcolor[i] == vcolor[j])
            flag = false;
        j++;
    }
    return flag;
}

void print_solution() 
{
    for (int j = 1; j <= n; j++)
        if (j != n)
            cout << vcolor[j] << " ";
        else 
            cout << vcolor[j] << endl;
}

void m_coloring(int i)
{
    if (i <= n && promising(i)) {
        if (i == n) {
            solution_count++;
            print_solution();
        }
        else {
            for (int color = 1; color <= m; color++) {
                vcolor[i + 1] = color;
                m_coloring(i + 1);
            }
        }
    }
}

int main() 
{
    int e, u, v;
    cin >> n >> e;
    W.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= e; i++) {
        cin >> u >> v;
        W[u][v] = W[v][u] = 1;
    }

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> m;
        vcolor.resize(n + 1, 0);
        solution_count = 0;
        m_coloring(0);
        cout << solution_count << endl;
    }
}