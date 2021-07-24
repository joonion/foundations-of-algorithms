#include <iostream>
#include <vector>
using namespace std;

// global varaibles
int n;
vector<int> S;

void merge2(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    vector<int> U(high - low + 1);
    while (i <= mid && j <= high)
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    if (i > mid)
        // move S[j] through S[high] to U[k] through U[high]
        while (j <= high)
            U[k++] = S[j++];
    else // j > high 
        // move S[i] through S[mid] to U[k] through U[high]
        while (i <= mid)
            U[k++] = S[i++];
    // move U[0] through U[high-low+1] to S[low] through S[high]
    for (int t = low; t <= high; t++)
        S[t] = U[t - low];
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
        cout << S[i] << " ";
    cout << endl;
}