#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct item *item_ptr;
typedef struct item {
    int id;
    int weight;
    int profit;
    int profit_per_unit; // = profit / weight
} item_t;

int n, W;
vector<item_t> items;

/* Greedy Algorithm for the Fractional Knapsack Problem */
void knapsack1(int& maxprofit, int& totweight) {
    maxprofit = totweight = 0;
    for (int i = 1; i <= n; i++) {
        if (totweight + items[i].weight <= W) {
            maxprofit += items[i].profit;
            totweight += items[i].weight;
        } else {
            maxprofit += (W - totweight) * items[i].profit_per_unit;
            totweight += (W - totweight);
            break; // Need not to continue.
        }
    }
}

bool compare_item(item_t i, item_t j) {
    if (i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
};

void print_items(vector<item_t>& items) {
    for (item_t i: items)
        cout << i.id << "," << i.weight << "," << i.profit << "," << i.profit_per_unit << endl;
}

int main() {
    cin >> n;
    items.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> items[i].weight;
    for (int i = 1; i <= n; i++)
        cin >> items[i].profit;
    for (int i = 1; i <= n; i++) {
        items[i].id = i;
        items[i].profit_per_unit = items[i].profit / items[i].weight;
    }
    sort(items.begin() + 1, items.end(), compare_item);
    // print_items(items);
    
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> W;
        int maxprofit, totweight;
        knapsack1(maxprofit, totweight);
        cout << totweight << " " << maxprofit << endl;
    }
}
