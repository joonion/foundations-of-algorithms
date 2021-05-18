#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long LongInteger;

LongInteger bin(int n, int k)
{
    if (k == 0 || n == k)
        return 1;
    else
        return bin(n - 1, k) + bin(n - 1, k - 1);
}

int main()
{
    int T, n, k;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> k;
        cout << bin(n, k) << endl;
    }
}
