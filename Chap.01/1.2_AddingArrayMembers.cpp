#include <iostream>
#include <vector>
using namespace std;

int sum(int n, vector<int>& S) {
    int result = 0;
    for (int i = 1; i <= n; i++)
        result += S[i];
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    cout << sum(n, S) << endl;
}