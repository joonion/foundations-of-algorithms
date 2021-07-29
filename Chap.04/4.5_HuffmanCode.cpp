#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

typedef struct node *node_ptr;
typedef struct node {
    char symbol;    // the value of a character.
    int frequency;  // the number of times the character is in the file.
    node_ptr left;
    node_ptr right;
} node_t;

struct compare {
    bool operator()(node_ptr p, node_ptr q) {
        return p->frequency > q->frequency;
    }
};

typedef priority_queue<node_ptr, vector<node_ptr>, compare> PriorityQueue;

node_ptr create_node(char symbol, int frequency) {
    node_ptr node = (node_ptr)malloc(sizeof(node_t));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

void huffman(int n, PriorityQueue& PQ) 
{
    for (int i = 1; i <= n - 1; i++) {
        node_ptr p = PQ.top(); PQ.pop();
        node_ptr q = PQ.top(); PQ.pop();
        node_ptr r = create_node('-', p->frequency + q->frequency);
        r->left = p;
        r->right = q;
        PQ.push(r);
    }
}

void preorder(node_ptr root)
{
    if (root != NULL) {
        cout << " " << root->symbol << ":" << root->frequency;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node_ptr root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << " " << root->symbol << ":" << root->frequency;
        inorder(root->right);
     }
}

int main() {
    int n;
    cin >> n;
    vector<int> freq(n);
    vector<char> symbol(n);
    for (int i = 0; i < n; i++)
        cin >> symbol[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    PriorityQueue PQ;
    for (int i = 0; i < n; i++)
        PQ.push(create_node(symbol[i], freq[i]));

    huffman(n, PQ);
    node_ptr root = PQ.top();

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
}
