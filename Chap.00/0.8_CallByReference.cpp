#include <iostream>
#include <vector>
using namespace std;

void get_input(vector<int> v) {
    for (int i = 0; i < v.size(); i++) 
        cin >> v[i];
}

int main() {
    int n; cin >> n;
    vector<int> v(n, 0);
    get_input(v);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}