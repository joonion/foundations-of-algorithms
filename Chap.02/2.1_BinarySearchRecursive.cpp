#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// global variables
int n, x;
vector<int> S;

int binsearch2(int low, int high) 
{
    int mid;

    if (low > high)
        return 0;
    else {
        mid = (low + high) / 2;
        if (x == S[mid])
            return mid;
        else if (x < S[mid])
            return binsearch2(low, mid - 1);
        else // x > S[mid]
            return binsearch2(mid + 1, high);
    }
}

int main() {
    int location;
    cin >> n;
    S.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    cin >> x;
    location = binsearch2(1, n);
    cout << location << endl;
}
