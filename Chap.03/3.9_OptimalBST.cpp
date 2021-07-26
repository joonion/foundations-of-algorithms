#include <iostream>
#include <vector>
using namespace std;

#define INF 0xFFFF

typedef struct node *node_ptr;
typedef struct node {
    int key;
    node_ptr left;
    node_ptr right;
} node_t;

typedef vector<vector<int>> matrix_t;

void search(node_ptr tree, int keyin, node_ptr& p)
{
    bool found;

    p = tree;
    found = false;
    while (!found) {
        if (p->key == keyin) 
            found = true;
        else if (keyin < p->key)
            p = p->left;
        else //  keyin > p->key
            p = p->right;
    }
}

void print_matrix(int n, matrix_t& M)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j != n) cout << M[i][j] << " ";
            else cout << M[i][j] << endl;
}

node_ptr create_node(int key)
{
    node_ptr node = (node_ptr)malloc(sizeof(node_t));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R)
{
    int k = R[i][j];
    if (k == 0)
        return NULL;
    else {
        node_ptr node = create_node(keys[k]);
        node->left = tree(i, k - 1, keys, R);
        node->right = tree(k + 1, j, keys, R);
        return node;
    }
}

void preorder(node_ptr node, vector<int>& v)
{
    if (node != NULL) {
        v.push_back(node->key);
        preorder(node->left, v);
        preorder(node->right, v);
    }
}

void inorder(node_ptr node, vector<int>& v)
{
    if (node != NULL) {
        preorder(node->left, v);
        v.push_back(node->key);
        preorder(node->right, v);
    }
}

int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A)
{
    int minValue = INF, value, psum;
    for (int k = i; k <= j; k++) {
        psum = 0;
        for (int m = i; m <= j; m++)
            psum += p[m];
        value = A[i][k - 1] + A[k + 1][j] + psum;
        if (minValue > value) {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R)
{
    for (int i = 1; i <= n; i++) {
        A[i][i - 1] = 0; A[i][i] = p[i];
        R[i][i - 1] = 0; R[i][i] = i;
    }
    A[n + 1][n] = R[n + 1][n] = 0;

    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal, k;
            A[i][j] = minimum(i, j, k, p, A);
            R[i][j] = k;
        }
}

int main()
{
    int n;
    cin >> n;
    vector<int> keys(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> keys[i];
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    matrix_t A, R;
    A.resize(n + 2, vector<int>(n + 2, 0));
    R.resize(n + 2, vector<int>(n + 2, 0));
    optsearchtree(n, p, A, R);
    cout << A[1][n] << endl;
    node_ptr root = tree(1, n, keys, R);
    vector<int> vpre, vin;
    preorder(root, vpre);
    inorder(root, vin);
    for (int i = 0; i < vpre.size(); i++)
        cout << vpre[i] << " ";
    cout << endl;
    for (int i = 0; i < vin.size(); i++)
        cout << vin[i] << " ";
    cout << endl;
    cout << "A =" << endl;
    print_matrix(n, A);
    cout << "R =" << endl;
    print_matrix(n, R);
}
