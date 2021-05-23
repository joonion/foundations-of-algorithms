#include <iostream>
#include <vector>
using namespace std;

void siftup(int n, vector<int>& heap)
{
    int i = n;
    while (i != 1) {
        int p = i / 2;
        if (heap[p] >= heap[i])
            break;
        swap(heap[p], heap[i]);
        i = p;
    }
}

void siftdown(int n, vector<int>& heap)
{
    int i = 1;
    while (2 * i <= n) {
        int c = 2 * i;
        if (c + 1 <= n && heap[c] < heap[c + 1])
            c++; // pick right child if it is larger
        if (heap[i] >= heap[c])
            break;
        swap(heap[i], heap[c]);
        i = c;
    }
}

void heapsort(int n, vector<int>& heap)
{
    for (int i = 2; i <= n; i++)
        siftup(i, heap);
    for (int i = n; i >= 2; i--) {
        swap(heap[1], heap[i]);
        siftdown(i - 1, heap);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> heap(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> heap[i];
    heapsort(n, heap);
    for (int i = 1; i <= n; i++)
        cout << heap[i] << " ";
    cout << endl;
}
