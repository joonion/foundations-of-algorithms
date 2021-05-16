#include <iostream>
#include <vector>
using namespace std;

int n, W, numbest, maxprofit;
vector<int> w, p, include, bestset;

int bound(int i, int profit, int weight)
{
    if (weight >= W)
        return 0;
    else {
        int result = profit;
        int j = i + 1;
        int totweight = weight;
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

bool promising(int i, int profit, int weight)
{
    return bound(i, profit, weight) > maxprofit;
}

void knapsack(int i, int profit, int weight)
{
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
        numbest = i;
        // bestset = include; deepcopy include to bestset.
        bestset.resize(include.size());
        copy(include.begin(), include.end(), bestset.begin());
    }

    if (i <= n && promising(i, profit, weight)) {
        include[i + 1] = 1;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = 0;
        knapsack(i + 1, profit, weight);
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
        numbest = maxprofit = 0;
        include.resize(n + 1, 0);
        knapsack(0, 0, 0);
        cout << maxprofit << endl;
        for (int j = 1; j <= numbest; j++)
            if (j != numbest)
                cout << bestset[j] << " ";
            else 
                cout << bestset[j] << endl;
    }
}