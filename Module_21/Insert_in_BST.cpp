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

        Node *myLeft, *myRight;
        int l, r;
        cin >> l >> r;
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
void level_order(Node *root)
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
}
void insert_node(Node *root, int val)
{
    if (!root)
    {
        root = new Node(val);
        return;
    };
    if (val < root->val)
    {
        if (root->left == nullptr)
            root->left = new Node(val);
        else
            insert_node(root->left, val);
    }
    else
    {
        if (root->right == nullptr)
            root->right = new Node(val);
        else
            insert_node(root->right, val);
    }
}
int main()
{
    Node *root = input_tree();
    int val;
    cin >> val;
    insert_node(root, val);
    level_order(root);
    return 0;
}