#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> LargeInteger;
const int threshold = 1;

void print_large_integer(LargeInteger v) {
    if (v.size() == 0)
        cout << 0;
    else
        for (int i = 1; i <= v.size(); i++)
            cout << v[v.size() - i];
    cout << endl;
}

void make_large_integer(string s, LargeInteger& v) {
    v.resize(s.size());
    for (int i = 1; i <= v.size(); i++)
        v[v.size() - i] = s[i - 1] - '0';
}

void remove_leading_zeros(LargeInteger& v) {
    while (v.back() == 0)
        v.pop_back();
}

void roundup_carry(LargeInteger& v) {
    int carry = 0;
    for (int i = 0; i < v.size(); i++) {
        v[i] += carry;
        carry = v[i] / 10;
        v[i] = v[i] % 10;
    }
    if (carry != 0)
        v.push_back(carry);
}

void ladd(LargeInteger a, LargeInteger b, LargeInteger& c) {
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < c.size(); i++) {
        if (i < a.size()) c[i] += a[i];
        if (i < b.size()) c[i] += b[i];
    }
    roundup_carry(c);
}

void lmult(LargeInteger a, LargeInteger b, LargeInteger& c) {
    c.resize(a.size() + b.size() - 1);
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    roundup_carry(c);
}

void pow_by_exp(LargeInteger u, int m, LargeInteger &v) {
    if (u.size() == 0)
        v.resize(0);
    else {
        v.resize(u.size() + m);
        fill(v.begin(), v.end(), 0);
        copy(u.begin(), u.end(), v.begin() + m);
    }
}

void div_by_exp(LargeInteger& u, int m, LargeInteger &v) {
    if (u.size() <= m)
        v.resize(0);
    else {
        v.resize(u.size() - m);
        copy(u.begin() + m, u.end(), v.begin());
    }
}

void rem_by_exp(LargeInteger u, int m, LargeInteger &v) {
    if (u.size() == 0)
        v.resize(0);
    else {
        // Note that u.size() can be smaller than m.
        int k = m < u.size() ? m : u.size();
        v.resize(k);
        copy(u.begin(), u.begin() + k, v.begin());
        remove_leading_zeros(v);
    }
}

void prod(LargeInteger u, LargeInteger v, LargeInteger &r) {
    LargeInteger x, y, w, z;
    LargeInteger t1, t2, t3, t4, t5, t6, t7, t8;
    int n = max(u.size(), v.size());
    if (u.size() == 0 || v.size() == 0)
        r.resize(0);
    else if (n <= threshold)
        lmult(u, v, r);
    else {
        int m = n / 2;
        div_by_exp(u, m, x); rem_by_exp(u, m, y);
        div_by_exp(v, m, w); rem_by_exp(v, m, z);
        // t2 <- prod(x,w) * 10^(2*m)
        prod(x, w, t1); pow_by_exp(t1, 2 * m, t2); 
        // t6 <- (prod(x,z)+prod(w,y)) * 10^m
        prod(x, z, t3); prod(w, y, t4); ladd(t3, t4, t5); pow_by_exp(t5, m, t6); 
        // r <- t2 + t6 + prod(y, z)
        prod(y, z, t7); ladd(t2, t6, t8); ladd(t8, t7, r);
    }
}

int main() {
    string su, sv;
    cin >> su >> sv;
    LargeInteger u, v, r;
    make_large_integer(su, u);
    make_large_integer(sv, v);
    prod(u, v, r);
    print_large_integer(r);
}
