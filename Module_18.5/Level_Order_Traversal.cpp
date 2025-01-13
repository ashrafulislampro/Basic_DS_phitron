#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void level_order_traverse(vector<int> &arr, BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        // step-1
        BinaryTreeNode<int> *p = q.front();
        q.pop();

        // step-2
        arr.push_back(p->val);

        // step-3
        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
};
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{

    vector<int> arr;
    level_order_traverse(arr, root);
    return arr;
}