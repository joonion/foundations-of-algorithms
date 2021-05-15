#include <iostream>
#include <vector>
using namespace std;

void find_both(int n, vector<int>& S, int& smallest, int& largest)
{
    smallest = largest = S[1];
    for (int i = 2; i <= n; i++)
        if (smallest > S[i])
            smallest = S[i];
        else if (largest < S[i])
            largest = S[i];
}

int main()
{
    int n, smallest, largest;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    find_both(n, S, smallest, largest);
    cout << smallest << " " << largest << endl;
}
