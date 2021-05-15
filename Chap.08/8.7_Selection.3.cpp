#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<int> S;

/*
 * returns a random integer between low and high inclusive
 * chosen according to a uniform distribution.
 */
int randint(int low, int high)
{
    mt19937 generator(time(NULL));
    uniform_int_distribution<int> range(low, high);
    return range(generator);
}

void partition3(int low, int high, int& pivotpoint)
{
    int randspot = randint(low, high);
    swap(S[low], S[randspot]);
    int pivotitem = S[low];
    int j = low;
    for (int i = low + 1; i <= high; i++)
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
        }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
}

int selection3(int low, int high, int k)
{
    int pivotpoint;
    if (low == high)
        return S[low];
    else {
        partition3(low, high, pivotpoint);
        if (k == pivotpoint)
            return S[pivotpoint];
        else if (k < pivotpoint)
            return selection3(low, pivotpoint -1, k);
        else // k > pivotpoint
            return selection3(pivotpoint + 1, high, k);
    }
}

int main()
{
    int n, k, T, kth;
    cin >> n;
    S.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];

    cin >> T;
    while (T-- > 0) {
        cin >> k;
        kth = selection3(1, n, k);
        cout << kth << endl;
    }    
}
