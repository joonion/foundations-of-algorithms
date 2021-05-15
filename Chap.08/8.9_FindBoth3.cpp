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

void find_smallest(int n, vector<int>& S, int& smallest)
{
    smallest = S[1];
    for (int i = 2; i <= n; i++)
        if (smallest > S[i])
            smallest = S[i];
}

/*
 * n is guaranteed to be even.
 */
void find_both3(int n, vector<int>& S, int& smallest, int& largest)
{
    vector<int> winners(n / 2 + 1), losers(n / 2 + 1);
    for (int i = 1; i <= n / 2; i++) {
        if (S[2 * i - 1] >= S[2 * i]) {
            winners[i] = S[2 * i - 1]; losers[i] = S[2 * i];   
        } else {
            winners[i] = S[2 * i]; losers[i] = S[2 * i - 1];   
        }
    }
    find_largest(n / 2, winners, largest);
    find_smallest(n / 2, losers, smallest);
}

int main()
{
    int n, smallest, largest;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    find_both3(n, S, smallest, largest);
    cout << smallest << " " << largest << endl;
}
