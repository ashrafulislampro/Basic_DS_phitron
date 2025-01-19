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
        // step-1
        Node *p = q.front();
        q.pop();

        // step-2
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
void level_wise(Node *root)
{
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
bool search(Node *root, int value)
{
    if (root == NULL)
        return false;
    if (root->val == value)
        return true;

    if (root->val > value)
        return search(root->left, value);
    else
        return search(root->right, value);
}
int main()
{
    Node *root = input_tree();
    level_wise(root);
    int val;
    cin >> val;
    if (search(root, val))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}