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
void tree_print(Node *root)
{

    if (!root)
        return;
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // step-1
        Node *p = q.front();
        q.pop();
        // step-2
        cout << p->val << " ";
        // step-3
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}
void search_in_BST(Node *root, int item)
{
    if (!root)
        return;
    if (root->val == item)
    {
        cout << root->val << " ";
        if (root->left)
        {
            cout << root->left->val << " ";
            search_in_BST(root->left, item);
        }
        if (root->right)
        {
            cout << root->right->val << " ";
            search_in_BST(root->right, item);
        }
    }
    else if (root->val > item)
    {
        search_in_BST(root->left, item);
    }
    else
    {
        search_in_BST(root->right, item);
    }
}
int main()
{
    Node *root = input_tree();
    int item;
    cin >> item;
    search_in_BST(root, item);

    return 0;
}