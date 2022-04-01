#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, string> m;
    string sin;
    for (int i = 0; i < n; i++) {
        cin >> sin;
        m[i] = sin;
    }

    for (int i = 0; i < n; i++)
        cout << i << ": " << m[i] << endl;
}
