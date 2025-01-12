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
void Inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}
int main()
{
    Node *root = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    Node *d = new Node(5);
    Node *e = new Node(8);
    Node *f = new Node(6);
    Node *g = new Node(7);
    Node *h = new Node(9);
    Node *i = new Node(10);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;
    d->left = e;
    b->left = f;
    b->right = g;
    g->left = h;
    g->right = i;

    Inorder(root);

    return 0;
}