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

Node *input_tree()
{
    Node *root;
    int val;
    cin >> val;
    if (val == -1)
        root = nullptr;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = nullptr;
        else
            myLeft = new Node(l);

        if (r == -1)
            myRight = nullptr;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
}

int binary_tree_depth(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    int l = binary_tree_depth(root->left);
    int r = binary_tree_depth(root->right);

    return max(l, r) + 1;
}
void Perfect_Binary_Tree(Node *root, int total_nodes)
{

    int node_count = 0;
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // step-1
        Node *p = q.front();
        q.pop();

        // step-2
        node_count++;
        // step-3
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

   
    if (node_count == total_nodes)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    Node *root = input_tree();
    int ht = binary_tree_depth(root);
    int total_nodes = pow(2, ht) - 1;

    Perfect_Binary_Tree(root, total_nodes);
    return 0;
}