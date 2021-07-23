#include <iostream>
using namespace std;

typedef unsigned long long LongInt;

LongInt fib(LongInt n) 
{
    if (n <= 1)
        return n;
    else 
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    LongInt n;
    cin >> n;
    cout << fib(n);
}