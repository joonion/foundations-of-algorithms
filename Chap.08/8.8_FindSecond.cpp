#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef map<int, vector<int>> map_t;

int tournament(int low, int high, vector<int>& S, map_t& M)
{
    cout << low << " " << high << endl;
    if (low == high)
        return S[low];
    else {
        int mid = (low + high) / 2;
        int left = tournament(low, mid, S, M);
        int right = tournament(mid + 1, high, S, M);
        int winner = left, loser = right;
        if (winner < loser) swap(winner, loser);
        cout << "winner is " << winner << " loser is " << loser << endl;
        M.find(winner)->second.push_back(loser);
        return winner;
    }
}

int find_largest(int n, vector<int>& S, map_t&M)
{
    return tournament(1, n, S, M);
}

int main()
{
    int n, largest;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];

    map_t loser_map;
    for (int i = 1; i <= n; i++)
        loser_map.insert(make_pair(S[i], vector<int>()));

    largest = find_largest(n, S, loser_map);
    for (int loser: loser_map.find(largest)->second)
        cout << loser << " ";
    cout << endl;
}
