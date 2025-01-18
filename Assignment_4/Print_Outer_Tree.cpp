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

        // step-3
        p->left = myLeft;
        p->right = myRight;
        if (p->left)
            q.push(p->left);

        if (p->right)
            q.push(p->right);
    }
    return root;
}

void Print_left_side_Outer_Tree(Node *root)
{

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->val << " ";
    }

    if (root->left)
    {
        Print_left_side_Outer_Tree(root->left);
        cout << root->val << " ";
    }
    else if (root->right)
    {
        Print_left_side_Outer_Tree(root->right);
        cout << root->val << " ";
    }
}
void Print_right_side_Outer_Tree(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->val << " ";
    }

    if (root->right)
    {
        cout << root->val << " ";
        Print_right_side_Outer_Tree(root->right);
    }
    else if (root->left)
    {
        cout << root->val << " ";
        Print_right_side_Outer_Tree(root->left);
    }
}
int main()
{
    Node *root = input_tree();
    if (root != nullptr)
    {
        if (root->left)
        {
            Print_left_side_Outer_Tree(root->left);
        }
        cout << root->val << " ";
        if (root->right)
        {
            Print_right_side_Outer_Tree(root->right);
        }
    };

    return 0;
}