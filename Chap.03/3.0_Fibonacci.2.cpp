#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long longint;
vector<longint> F;

longint fib2(int n) {
    if (n <= 1)
        F[n] = n;
    else if (F[n] == -1)
        F[n] = fib2(n - 1) + fib2(n - 2);
    return F[n];
}

int main() {
    int n; cin >> n;
    cout << n << endl;
    for (int i = 0; i <= n; i++) {
        F.resize(i + 1, -1);
        cout << i << ": " << fib2(i) << endl;
    }
}
