#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long longint;
map<int, longint> F;

longint fib3(int n) {
    if (F.find(n) != F.end())
        return F[n];
    else {
        if (n < 2)
            F[n] = n;
        else
            F[n] = fib3(n - 1) + fib3(n - 2);
        return F[n];
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++)
        cout << fib3(i) << endl;
}
