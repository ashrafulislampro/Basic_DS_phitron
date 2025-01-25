#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *convert(int arr[], int low, int high)
{
    if (low > high)
        return NULL;
    int mid = (low + high) / 2;
    Node *root = new Node(arr[mid]);
    Node *leftroot = convert(arr, low, mid - 1);
    Node *rightroot = convert(arr, mid + 1, high);
    root->left = leftroot;
    root->right = rightroot;
    return root;
}

void level_tree(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->val << " ";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = convert(arr, 0, n - 1);
    level_tree(root);

    return 0;
}
