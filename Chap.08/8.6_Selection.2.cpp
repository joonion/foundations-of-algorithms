#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int select(int n, vector<int>& S, int k);

int median(vector<int>& S, int first, int last)
{
    vector<int> v;
    for (int i = first; i <= last; i++)
        v.push_back(S[i]);
    sort(v.begin(), v.end());
    return v[ceil(v.size() / 2.0) - 1];
}

void partition2(vector<int>& S, int low, int high, int& pivotpoint)
{
    int first, last, mark;
    int arraysize = high - low + 1;
    int r = ceil(arraysize / 5.0);

    vector<int> T(r + 1);
    for (int i = 1; i <= r; i++) {
        first = low + 5 * i - 5;
        last = min(low + 5 * i - 1, low + arraysize) - 1;
        T[i] = median(S, first, last);
    }

    int pivotitem = select(r, T, (r + 1) / 2);
    int j = low;
    for (int i = low; i <= high; i++) {
        if (S[i] == pivotitem) {
            swap(S[i], S[j]);
            mark = j++;
        } 
        else if (S[i] < pivotitem) {
            swap(S[i], S[j]);
            j++;
        }
    }
    pivotpoint = j - 1;
    swap(S[mark], S[pivotpoint]);
}
int selection2(vector<int>& S, int low, int high, int k)
{
    int pivotpoint;
    if (low == high)
        return S[low];
    else {
        partition2(S, low, high, pivotpoint);
        if (k == pivotpoint)
            return S[pivotpoint];
        else if (k < pivotpoint)
            return selection2(S, low, pivotpoint - 1, k);
        else // k > pivotpoint
            return selection2(S, pivotpoint + 1, high, k);
    }
}

int select(int n, vector<int>& S, int k)
{
    return selection2(S, 1, n, k);
}

int main()
{
    int n, k, T, kth;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];

    cin >> T;
    while (T-- > 0) {
        cin >> k;
        kth = select(n, S, k);
        cout << kth << endl;
    }    
}
