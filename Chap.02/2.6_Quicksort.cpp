#include <iostream>
#include <vector>
using namespace std;

// global variables
int n;
vector<int> S;

void partition(int low, int high, int& pivotpoint)
{
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

void quicksort(int low, int high)
{
    int pivotpoint;

    if (low < high) {
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}

int main() 
{
    cin >> n;
    S.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    quicksort(1, n);
    for (int i = 1; i <= n; i++)
        cout << S[i] << " ";
    cout << endl;
}
