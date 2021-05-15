#include <iostream>
#include <vector>
using namespace std;

void find_both2(int n, vector<int>& S, int& smallest, int& largest)
{
    if (S[1] < S[2]) {
        smallest = S[1]; largest = S[2];
    } else {
        smallest = S[2]; largest = S[1];
    }
    for (int i = 3; i <= n - 1; i += 2) {
        if (S[i] < S[i + 1]) {
            smallest = (smallest > S[i]) ? S[i] : smallest;
            largest = (largest < S[i + 1]) ? S[i + 1] : largest;
        } else {
            smallest = (smallest > S[i + 1]) ? S[i + 1] : smallest;
            largest = (largest < S[i]) ? S[i] : largest;
        }
    }
}

int main()
{
    int n, smallest, largest;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    find_both2(n, S, smallest, largest);
    cout << smallest << " " << largest << endl;
}
