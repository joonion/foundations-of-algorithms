#include <iostream>
#include <vector>
using namespace std;

void selectionsort(int n, vector<int>& S)
{
    for (int i = 1; i <= n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j <= n; j++)
            if (S[j] < S[smallest])
                smallest = j;
        swap(S[i], S[smallest]);
    }
}

int main() 
{
    int n;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    selectionsort(n, S);
    for (int i = 1; i <= n; i++)
        if (i != n) cout << S[i] << " ";
        else cout << S[i] << endl;
}