#include <iostream>
using namespace std;

int fib(int n) 
{
    if (n <= 1)
        return n;
    else 
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, T;
    cin >> T;
    while (T-- > 0) {
        cin >> n;
        cout << fib(n) << endl;
    }
}