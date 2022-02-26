#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int key;
    cout << "Input a key: ";
    cin >> key;

    vector<int>::iterator it;
    it = find(v.begin(), v.end(), key);
    if (it != v.end())
        cout << "I have found it!" << endl;
    else
        cout << "I cannot find it!" << endl;

}