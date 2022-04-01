#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long longint;
vector<longint> F;

longint fib3(int n) {
    F.resize(n + 1);
    if (n <= 1)
        F[n] = n;
    else {
        F[0] = 0; F[1] = 1;
        for (int i = 2; i <= n; i++)
            F[n] = F[n - 1] + F[n - 2];
    }
    return F[n];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++)
        cout << i << ": " << fib3(i) << endl;
}
