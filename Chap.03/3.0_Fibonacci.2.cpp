#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long longint;
vector<longint> F;

longint fib2(int n) {
    if (n >= F.size()) {
        int start = F.size();
        F.resize(n + 1);
        if (n < 2)
            F[n] = n;
        else {
            for (int i = start; i <= n; i++)
                F[i] = F[i - 1] + F[i - 2];
        }
    }
    return F[n];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++)
        cout << fib2(i) << endl;
}
