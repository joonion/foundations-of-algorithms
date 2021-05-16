#include <iostream>
#include <vector>
using namespace std;

int n, W, solution_count;
vector<int> w, include;

bool promising(int i, int weight, int total)
{
    return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

void print_solution()
{
    for (int j = 1; j <= n; j++)
        if (j != n)
            cout << include[j] << " ";
        else 
            cout << include[j] << endl;
}

void sum_of_subsets(int i, int weight, int total)
{
    if (i <= n && promising(i, weight, total)) {
        if (weight == W) {
            solution_count++;
        }
        else {
            include[i + 1] = 1;
            sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
            include[i + 1] = 0;
            sum_of_subsets(i + 1, weight, total - w[i + 1]);
        }
    }
}

int main() 
{
    cin >> n;
    w.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += w[i];

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> W;
        include.resize(n + 1, 0);
        solution_count = 0;
        sum_of_subsets(0, 0, total);
        cout << solution_count << endl;
    }
}