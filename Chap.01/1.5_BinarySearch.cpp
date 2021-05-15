#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binsearch(int n, vector<int>& S, int x, int& location) 
{
    int low, high, mid;
    low = 1; high = n; location = 0;
    while (low <= high && location == 0) {
        mid = (low + high) / 2;
        if (x == S[mid])
            location = mid;
        else if (x < S[mid])
            high = mid - 1;
        else // x > S[mid]
            low = mid + 1;
    }
}

int main()
{
    int n, x, location, T;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    sort(S.begin() + 1, S.end());
    for (int i = 1; i <= n; i++)
        if (i != n)
            cout << S[i] << " ";
        else 
            cout << S[i] << endl;
    cin >> T;
    while (T-- > 0) {
        cin >> x;
        binsearch(n, S, x, location);
        cout << location << endl;
    }
}