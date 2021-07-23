#include <iostream>
#include <vector>
using namespace std;

typedef int keytype;
typedef int index;

void seqsearch(int n, const keytype S[], keytype x, index& location) 
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
    cin >> x;
    int *pS = &S[0];
    seqsearch(n, pS, x, location);
    cout << location << endl;
}
