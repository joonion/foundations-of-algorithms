#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long LongInteger;

LongInteger bin2(int n, int k)
{
    vector<vector<LongInteger>> B(n + 1, vector<LongInteger>(n + 1));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            if (j == 0 || j == i)
                B[i][j] = 1;
            else
                B[i][j] = B[i - 1][j] + B[i - 1][j - 1];
    return B[n][k];
}

int main()
{
    int T, n, k;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> k;
        cout << bin2(n, k) << endl;
    }
}
