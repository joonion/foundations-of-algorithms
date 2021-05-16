#include <iostream>
#include <vector>
using namespace std;

int n, solution_count;
vector<vector<int>> W;
vector<int> vindex;

bool promising(int i)
{
    bool flag = true;
    if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
        flag = false;
    else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
        flag = false;
    else {
        int j = 1;
        while (j < i && flag) {
            if (vindex[i] == vindex[j])
                flag = false;
            j++;
        }
    }
    return flag;
}

void print_solution() 
{
    for (int j = 0; j <= n - 1; j++)
        if (j != n - 1)
            cout << vindex[j] << " ";
        else 
            cout << vindex[j] << endl;
}

void hamiltonian(int i)
{
    if (i <= n && promising(i)) {
        if (i == n - 1) {
            solution_count++;
            print_solution();
        }
        else {
            for (int j = 2; j <= n; j++) {
                vindex[i + 1] = j;
                hamiltonian(i + 1);
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

    vindex.resize(n + 1, 0);
    vindex[0] = 1;
    solution_count = 0;
    hamiltonian(0);
    cout << solution_count << endl;
}