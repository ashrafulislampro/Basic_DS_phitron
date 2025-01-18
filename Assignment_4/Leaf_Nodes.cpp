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

void leaf_nodes(Node *root)
{
    vector<int> vec;

    if (root == nullptr)
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
        if ((p->left == nullptr && p->right == nullptr))
        {
            vec.push_back(p->val);
        }

        // step-3
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    sort(vec.begin(), vec.end(), greater<int>());
    int len = vec.size();
    cout<<vec[0];
    for(int i = 1; i < len; i++){
        cout<<" "<<vec[i];
    }
};

int main()
{
    Node *root = input_tree();
    leaf_nodes(root);    
    return 0;
}