#include <iostream>
#include <vector>
using namespace std;

typedef struct heap {
    int heapsize;
    vector<int> S;
} heap_t;

void siftdown(int i, heap_t& H)
{
    int siftkey = H.S[i];
    int parent = i;
    bool spotfound = false;
    while (2 * parent <= H.heapsize && !spotfound) {
        int largerchild;
        if (2 * parent < H.heapsize && H.S[2 * parent] < H.S[2*parent + 1])
            largerchild = 2 * parent + 1;
        else
            largerchild = 2 * parent;
        if (siftkey < H.S[largerchild]) {
            H.S[parent] = H.S[largerchild];
            parent = largerchild;
        }
        else 
            spotfound = true;
    }
    H.S[parent] = siftkey;
}

int root (heap_t& H)
{
    int keyout = H.S[1];
    H.S[1] = H.S[H.heapsize];
    H.heapsize -= 1;
    siftdown(1, H);
    return keyout;
}

void makeheap(int n, heap_t& H, vector<int>& keys)
{
    H.heapsize = n;
    H.S.resize(n + 1);
    copy(keys.begin() + 1, keys.end(), H.S.begin() + 1);
    for (int i = n / 2; i >= 1; i--)
        siftdown(i, H);
}

void removekeys(int n, heap_t& H, vector<int>& S)
{
    for (int i = n; i >= 1; i--)
        S[i] = root(H);
}

void heapsort(int n, heap_t& H, vector<int>& S)
{
    makeheap(n, H, S);
    removekeys(n, H, H.S);
}

int main() 
{
    int n;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    
    heap_t H;
    heapsort(n, H, S);

    for (int i = 1; i <= n; i++)
        cout << H.S[i] << " ";
    cout << endl;
}
