#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> col;

bool promising(int i)
{
    int k = 1, flag = true;
    while (k < i && flag) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            flag = false;
        k++;
    }
    return flag;
}

void print_solution()
{
    for (int j = 1; j <= n; j++)
        if (j != n)
            cout << col[j] << " ";
        else 
            cout << col[j] << endl;
}

void queens(int i)
{
    if (promising(i)) {
        if (i == n)
            print_solution();
        else 
            for (int j = 1; j <= n; j++) {
                col[i + 1] = j;
                queens(i + 1);
            }
    }
}

int main() 
{
    cin >> n;
    col.resize(n + 1, 0);
    queens(0);
}