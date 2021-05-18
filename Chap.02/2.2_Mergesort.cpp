#include <iostream>
#include <vector>
using namespace std;

void merge(int h, int m, vector<int>& U, vector<int>& V, vector<int>& S)
{
    int i = 1, j = 1, k = 1;
    while (i <= h && j <= m)
        S[k++] = (U[i] < V[j]) ? U[i++] : V[j++];
    if (i > h)
        for (int t = j; t <= m; t++)
            S[k++] = V[t];
    else // j > m 
        for (int t = i; t <= h; t++)
            S[k++] = U[t];
}

void mergesort(int n, vector<int>& S)
{
    if (n > 1) {
        int h = n / 2, m = n - h;
        cout << h << " " << m << endl;
        vector<int> U(h + 1), V(m + 1);
        for (int i = 1; i <= h; i++)
            U[i] = S[i];
        for (int i = 1; i <= m; i++)
            V[i] = S[h + i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

int main() 
{
    int n;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    mergesort(n, S);
    for (int i = 1; i <= n; i++)
        if (i != n) 
            cout << S[i] << " ";
        else 
            cout << S[i] << endl;
}