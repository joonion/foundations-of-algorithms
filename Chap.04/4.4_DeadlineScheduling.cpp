#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> sequence_of_integer;

bool is_feasible(sequence_of_integer& K, sequence_of_integer& deadline) {
    for (int i = 1; i < K.size(); i++)
        if (i > deadline[K[i]])
            return false;
    return true;
}

void schedule(int n, sequence_of_integer& deadline, sequence_of_integer &J) {
    sequence_of_integer K;

    J.clear();
    J.push_back(0); // for an empty job
    J.push_back(1);
    for (int i = 2; i <= n; i++) {
        // K = J with i added according to nondecreasing values of deadline[i];
        K.resize(J.size());
        copy(J.begin(), J.end(), K.begin());
        int j = 1;
        while (j < K.size() && deadline[K[j]] <= deadline[i])
            j++;
        K.insert(K.begin() + j, i);

        if (is_feasible(K, deadline)) {
            // J = K
            J.resize(K.size());
            copy(K.begin(), K.end(), J.begin());
        }
    }
}

int main() 
{
    int n;
    cin >> n;
    sequence_of_integer deadline(n + 1), profit(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> deadline[i];
    for (int i = 1; i <= n; i++)
        cin >> profit[i];

    sequence_of_integer jobs;
    schedule(n, deadline, jobs);

    int maxprofit = 0;
    for (int i = 1; i < jobs.size(); i++)
        maxprofit += profit[jobs[i]];
    cout << maxprofit << endl;
}
