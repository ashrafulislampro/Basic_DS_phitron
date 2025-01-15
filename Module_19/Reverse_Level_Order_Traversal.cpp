#include <bits/stdc++.h>
using namespace std;
template <typename T>

class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> reverseLevelOrder(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> vec;
    queue<TreeNode<int> *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // step-1
        TreeNode<int> *parent = q.front();
        q.pop();
        // step-2
        vec.push_back(parent->val);
        // step-3
        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
    reverse(vec.begin(), vec.end());
    return vec;
}