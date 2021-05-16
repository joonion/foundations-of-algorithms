#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node node_t;
struct node {
    int level;
    int profit;
    int weight;
    int bound;
};

struct node_compare {
    bool operator()(node_t u, node_t v) {
        if (u.bound < v.bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_t, vector<node_t>, node_compare> priority_queue_of_node;

int n, W;
vector<int> p, w;

int bound(node_t u)
{
    if (u.weight >= W)
        return 0;
    else {
        int result = u.profit;
        int j = u.level + 1;
        int totweight = u.weight;
        while (j <= n && totweight + w[j] <= W) {
            totweight += w[j];
            result += p[j];
            j++;
        }
        int k = j;
        if (k <= n)
            result += (W - totweight) * p[k] / w[k]; 
        return result;
    }
}

void knapsack3(int& maxprofit) {
    priority_queue_of_node PQ;
    maxprofit = 0;
    node_t v;
    v.level = 0; v.profit = 0; v.weight = 0;
    v.bound = bound(v);
    PQ.push(v);
    while (!PQ.empty()) {
        node_t v = PQ.top(); PQ.pop();
        if (v.bound > maxprofit) {
            node_t u1;
            u1.level = v.level + 1;
            u1.weight = v.weight + w[u1.level];
            u1.profit = v.profit + p[u1.level];
            if (u1.weight <= W && u1.profit > maxprofit)
                maxprofit = u1.profit;
            u1.bound = bound(u1);
            if (u1.bound > maxprofit)
                PQ.push(u1);
            node_t u2;
            u2.level = v.level + 1;
            u2.weight = v.weight;
            u2.profit = v.profit;
            u2.bound = bound(u2);
            if (u2.bound > maxprofit)
                PQ.push(u2);
       }
    }
}

int main() 
{
    cin >> n;
    w.resize(n + 1); 
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> W;
        int maxprofit;
        knapsack3(maxprofit);
        cout << W << " " << maxprofit << endl;
    }
}
