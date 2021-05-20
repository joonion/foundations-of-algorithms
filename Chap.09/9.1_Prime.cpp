#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n)
{
    bool flag = true;
    int i = 2;
    while (flag && i <= (int)sqrt(n))
        if (n % i == 0)
            flag = false;
        else
            i++;
    return flag;
}

int main() 
{
    int n;
    cin >> n;
    if (prime(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
