#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long largeint;
const int threshold = 1;

int digits(largeint v) {
    return (v == 0) ? 0 : to_string(v).length();
}

largeint div_by_exp(largeint v, int m) {
    for (int i = 0; i < m; i++)
        v /= 10;
    return v;
}

largeint rem_by_exp(largeint v, int m) {
    int exp = 1;
    for (int i = 0; i < m; i++)
        exp *= 10;
    return v % exp;
}

largeint pow_by_exp(largeint v, int m) {
    for (int i = 0; i < m; i++)
        v *= 10;
    return v;
}

largeint karatsuba(largeint u, largeint v) {
    largeint x, y, w, z, p, q, r;
    int n = max(digits(u), digits(v));
    if (u == 0 || v == 0)
        return 0;
    else if (n <= threshold)
        return u * v;
    else {
        int m = n / 2;
        x = div_by_exp(u, m); y = rem_by_exp(u, m);
        w = div_by_exp(v, m); z = rem_by_exp(v, m);
        r = karatsuba(x + y, w + z);
        p = karatsuba(x, w);
        q = karatsuba(y, z);
        return pow_by_exp(p, 2*m) + pow_by_exp(r - p - q, m) + q;
    }
}

int main() {
    largeint a, b; cin >> a >> b;
    largeint c = karatsuba(a, b);
    cout << "  answer: " << c << endl;
    cout << "solution: " << a * b << endl;
}
