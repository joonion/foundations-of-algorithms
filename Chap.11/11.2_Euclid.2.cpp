#include <iostream>
using namespace std;

void Euclid(int n, int m, int& gcd, int& i, int& j)
{
    if (m == 0) {
        gcd = n; i = 1; j = 0;
    }
    else {
        int _i, _j, _gcd;
        Euclid(m, n % m, _gcd, _i, _j);
        gcd = _gcd; i = _j; j = _i - (n / m) * _j;
    }
}

int main()
{
    int n, m, gcd, i, j;
    cin >> n >> m;
    Euclid(n, m, gcd, i, j);
    cout << gcd << " " << i << " " << j << endl;
}
