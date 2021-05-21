#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct bin {
    int weight;
    vector<int> items;
} bin_t;

void binpack(int n, int W, vector<int>& s, vector<bin_t>& bins)
{
    sort(s.begin() + 1, s.end());
    reverse(s.begin() + 1, s.end());

    for (int i = 1; i <= n; i++) {
        int item = s[i];
        bool is_packed = false;
        for (int j = 0; !is_packed && j < bins.size(); j++) {
            bin_t& bin = bins[j];
            if (bin.weight + item <= W) {
                bin.weight += item;
                bin.items.push_back(item);
                is_packed = true;
            }
        }
        if (!is_packed) {
            bin_t newbin;
            newbin.weight = item;
            newbin.items.push_back(item);
            bins.push_back(newbin);
        }
    }
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    vector<bin_t> bins;
    binpack(n, W, s, bins);
    cout << bins.size() << endl;
    for (int i = 0; i < bins.size(); i++) {
        for (int j = 0; j < bins[i].items.size(); j++)
            if (j != bins[i].items.size() - 1)
                cout << bins[i].items[j] << " ";
            else
                cout << bins[i].items[j] << endl;
    }
}
