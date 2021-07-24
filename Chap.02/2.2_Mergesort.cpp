#include <iostream>
#include <vector>
using namespace std;

void merge(int h, int m, vector<int>& U, vector<int>& V, vector<int>& S)
{
    int i = 1, j = 1, k = 1;
    while (i <= h && j <= m)
        S[k++] = (U[i] < V[j]) ? U[i++] : V[j++];
    if (i > h)
        // copy V[j] through V[m] to S[k] through S[h+m]
        while (j <= m)
            S[k++] = V[j++];
    else // j > m 
        // copy U[i] through U[h] to S[k] through S[h+m]
        while (i <= h)
            S[k++] = U[i++];
}


void mergesort(int n, vector<int>& S)
{
    if (n > 1) {
        int h = n / 2, m = n - h;
        vector<int> U(h + 1), V(m + 1);
        // copy S[1] through S[h] to U[1] through U[h]
        for (int i = 1; i <= h; i++) 
            U[i] = S[i];
        // copy S[h+1] through S[n] to V[1] through V[m]
        for (int i = h + 1; i <= n; i++) 
            V[i - h] = S[i];
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
        cout << S[i] << " ";
    cout << endl;
}