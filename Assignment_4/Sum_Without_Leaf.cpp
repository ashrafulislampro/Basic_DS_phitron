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

long long Sum_Without_leaf(Node *root)
{
    long long sum = 0;
    if (root == nullptr)
        return 0;
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // step-1
        Node *p = q.front();
        q.pop();

        // step-2
        if ((p->left != nullptr && p->right != nullptr) || (p->left != nullptr && p->right == nullptr) || (p->left == nullptr && p->right != nullptr))
        {

            sum += p->val;
        }

        // step-3
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return sum;
};

int main()
{
    Node *root = input_tree();

    long long res = Sum_Without_leaf(root);
    cout << res << endl;
    return 0;
}