/*
 * Consider only positive inputs as a string.
 * Note that 0 should be given as a string "0".
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> large_integer;

const int threshold = 1;

void print_large_integer(large_integer& v) {
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
    cout << endl;
}

void assign_value(large_integer& u, string s) 
{
    u.resize(0);
    for (int i = s.size() - 1; i >= 0; i--)
        u.push_back(s[i] - '0');
}

bool is_zero(large_integer& u)
{
    if (u.size() == 1 && u[0] == 0)
        return true;
    return false;
}

void roundup_carry(large_integer& a)
{
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        a[i] += carry;
        carry = a[i] / 10;
        a[i] = a[i] % 10;
    }
    if (carry != 0)
        a.push_back(carry);
}

void ladd(large_integer& a, large_integer& b, large_integer& c)
{
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < c.size(); i++) {
        if (i < a.size()) c[i] += a[i];
        if (i < b.size()) c[i] += b[i];
    }
    roundup_carry(c);
}

void lmult(large_integer& a, large_integer& b, large_integer& c)
{
    c.resize(a.size() + b.size() - 1);
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    roundup_carry(c);
}

void pow_by_exp(large_integer& u, int m, large_integer &v)
{
    if (is_zero(u)) {
        v.resize(1); v[0] = 0;
    }
    else {
        v.resize(u.size() + m);
        fill(v.begin(), v.end(), 0);
        copy(u.begin(), u.end(), v.begin() + m);
    }
}

void div_by_exp(large_integer& u, int m, large_integer &v)
{
    if (is_zero(u) || u.size() <= m) {
        v.resize(1); v[0] = 0;
    }
    else {
        v.resize(u.size() - m);
        copy(u.begin() + m, u.end(), v.begin());
    }
}

void rem_by_exp(large_integer& u, int m, large_integer &v)
{
    if (is_zero(u)) {
        v.resize(1); v[0] = 0;
    }
    else {
        v.resize(m);
        copy(u.begin(), u.begin() + m, v.begin());
        // remove leading zeros
        while (v.size() > 1 && v.back() == 0)
            v.pop_back();
    }
}

void prod(large_integer& u, large_integer& v, large_integer &r)
{
    large_integer x, y, w, z;
    large_integer t1, t2, t3, t4, t5, t6, t7, t8;

    int n = max(u.size(), v.size());
    if (is_zero(u) || is_zero(v)) {
        r.resize(1); r[0] = 0;
    }
    else if (min(u.size(), v.size()) <= threshold)
        lmult(u, v, r);
    else {
        int m = n / 2;
        div_by_exp(u, m, x); rem_by_exp(u, m, y);
        print_large_integer(x);
        print_large_integer(y);        
        div_by_exp(v, m, w); rem_by_exp(v, m, z);
        // t2 <- prod(x,w) * 10^(2*m)
        prod(x, w, t1); pow_by_exp(t1, 2 * m, t2); 
        // t6 <- (prod(x,z)+prod(w,y)) * 10^m
        prod(x, z, t3); prod(w, y, t4); ladd(t3, t4, t5); pow_by_exp(t5, m, t6); 
        // r <- t2 + t6 + prod(y, z)
        prod(y, z, t7); ladd(t2, t6, t8); ladd(t8, t7, r);
    }
}

int main() 
{
    string s1, s2;
    cin >> s1 >> s2;
    large_integer u, v;
    assign_value(u, s1);
    assign_value(v, s2);
    print_large_integer(u);
    print_large_integer(v);
    large_integer r;
    prod(u, v, r);
    print_large_integer(r);
}
