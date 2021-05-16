#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0xFFFF

typedef struct node node_t;
struct node {
    int level;
    int bound;
    vector<int> path;
};

struct node_compare {
    bool operator()(node_t u, node_t v) {
        if (u.bound > v.bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_t, vector<node_t>, node_compare> priority_queue_of_node;

int n;
vector<vector<int>> W;

/*
 * returns the length of the tour
 */
int length(vector<int> path) {
    int len = 0;
    for (int i = 0; i < path.size() - 1; i++)
        len += W[path[i]][path[i + 1]];
    return len;
}

bool hasOutgoing(int v, vector<int>& path) {
    for (int i = 0; i < path.size() - 1; i++)
        if (v == path[i]) return true;
    return false;
}

bool hasIncoming(int v, vector<int>& path) {
    for (int i = 1; i < path.size(); i++)
        if (v == path[i]) return true;
    return false;
}

/*
 * returns the bound for a node using the considerations 
 * in the textbook (Refer to Section 6.2).
 */
int bound(node_t u)
{
    // start from the length of current path
    int lowerbound = length(u.path);
    for (int i = 1; i <= n; i++) {
        // Do not consider vertices already visited.
        if (hasOutgoing(i, u.path)) continue;
        int min = INF;
        for (int j = 1; j <= n; j++) {
            // Do not include self-loops.
            if (i == j) continue;
            // Do not include edges already in the path.
            if (hasIncoming(j, u.path)) continue;
            // Do not include an edge to which i cannot returns.
            if (j == 1 && i == u.path[u.path.size() - 1]) continue;
            if (min > W[i][j]) min = W[i][j];
        }
        lowerbound += min;
    }
    return lowerbound;
}

/*
 * returns the missing node in the given path.
 */
int remaining(vector<int> path) {
    int s = 0;
    for (int i: path)
        s += i;
    return n * (n + 1) / 2 - s;
}

bool isIn(int v, vector<int> path) 
{
    for (int i = 0; i < path.size(); i++)
        if (v == path[i]) return true;
    return false;
}

void travel2(vector<int>& opttour, int& minlength)
{
    priority_queue_of_node PQ;
    minlength = INF;
    node_t v;
    v.level = 0; v.path.push_back(1); v.bound = bound(v);
    PQ.push(v);
    while (!PQ.empty()) {
        node_t v = PQ.top(); PQ.pop();
        if (v.bound < minlength) {
            for (int i = 2; i <= n; i++) {
                if (isIn(i, v.path)) continue;
                node_t u;
                u.level = v.level + 1;
                // u.path = v.path; deepcopy v.path to u.path
                u.path.resize(v.path.size());
                copy(v.path.begin(), v.path.end(), u.path.begin());
                u.path.push_back(i);
                if (u.level == n - 2) {
                    u.path.push_back(remaining(u.path));
                    u.path.push_back(1);
                    if (length(u.path) < minlength) {
                        minlength = length(u.path);
                        // opttour = u.path; deepcopy u.path to opttour
                        opttour.resize(u.path.size());
                        copy(u.path.begin(), u.path.end(), opttour.begin());
                    }
                } else {
                    u.bound = bound(u);
                    if (u.bound < minlength)
                        PQ.push(u);
                }
            }
        }
    }
}

int main()
{
    int m, u, v, w, minlength;
    cin >> n >> m;
    W.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }
    vector<int> opttour;
    travel2(opttour, minlength);
    cout << minlength << endl;
    for (int i = 0; i < opttour.size(); i++)
        if (i != opttour.size() - 1)
            cout << opttour[i] << " ";
        else 
            cout << opttour[i] << endl;
}

