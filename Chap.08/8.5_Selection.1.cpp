#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> S;

void partition(int low, int high, int& pivotpoint)
{
    int pivotitem = S[low];
    int j = low;
    for (int i = low + 1; i <= high; i++)
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
        }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
}

int selection(int low, int high, int k)
{
    int pivotpoint;
    if (low == high)
        return S[low];
    else {
        partition(low, high, pivotpoint);
        if (k == pivotpoint)
            return S[pivotpoint];
        else if (k < pivotpoint)
            return selection(low, pivotpoint -1, k);
        else // k > pivotpoint
            return selection(pivotpoint + 1, high, k);
    }
}

int main()
{
    int n, k, T, kth;
    cin >> n;
    S.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];

    cin >> T;
    while (T-- > 0) {
        cin >> k;
        kth = selection(1, n, k);
        cout << kth << endl;
    }    
}
