#include <iostream>
#include <vector>
using namespace std;

void seqsearch(int n, vector<int>& S, int x, int& location) 
{
    location = 1;
    while (location <= n && S[location] != x)
        location++;
    if (location > n)
        location = 0;
}

int main()
{
    int n, x, location, T;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    cin >> T;
    while (T-- > 0) {
        cin >> x;
        seqsearch(n, S, x, location);
        cout << location << endl;
    }
}