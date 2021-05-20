#include <iostream>
#include <vector>
using namespace std;

void insertionsort(int n, vector<int>& S)
{
    for (int i = 2; i <= n; i++) {
        int x = S[i];
        int j = i - 1;
        while (j > 0 && S[j] > x) {
            S[j + 1] = S[j];
            j--;
        }
        S[j + 1] = x;
    }
}

int main() 
{
    int n;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    insertionsort(n, S);
    for (int i = 1; i <= n; i++)
        if (i != n) cout << S[i] << " ";
        else cout << S[i] << endl;
}