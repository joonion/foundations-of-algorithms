#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> S;

void merge2(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    vector<int> U(high - low + 1);
    while (i <= mid && j <= high)
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    if (i > mid)
        for (int t = j; t <= high; t++)
            U[k++] = S[t];
    else // j > high 
        for (int t = i; t <= mid; t++)
            U[k++] = S[t];
    for (int t = 0; t < U.size(); t++)
        S[low + t] = U[t];
}

void mergesort2(int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort2(low, mid);
        mergesort2(mid + 1, high);
        merge2(low, mid, high);
    }
}

int main() 
{
    cin >> n;
    S.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    mergesort2(1, n);
    for (int i = 1; i <= n; i++)
        if (i != n) 
            cout << S[i] << " ";
        else 
            cout << S[i] << endl;
}