#include <iostream>
#include <vector>
using namespace std;

void find_largest(int n, vector<int>& S, int& largest)
{
    largest = S[1];
    for (int i = 2; i <= n; i++)
        if (largest < S[i])
            largest = S[i];
}

int main()
{
    int n, largest;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    find_largest(n, S, largest);
    cout << largest << endl;
}
