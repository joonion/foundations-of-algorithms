#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct mycmp {
    bool operator() (string s1, string s2) {
        return s1.length() > s2.length(); 
    }
};

int main() {
    int n;
    cin >> n;

    priority_queue<string, vector<string>, mycmp> pq;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        pq.push(x);
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

}