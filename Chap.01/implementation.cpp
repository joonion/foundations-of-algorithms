#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x, location;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    cin >> x;
    location = 1;
    while (location <= n && S[location] != x)
        location++;
    if (location > n)
        location = 0;
    cout << location << endl;
}