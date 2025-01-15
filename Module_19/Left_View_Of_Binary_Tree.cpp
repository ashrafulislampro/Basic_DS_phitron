#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int treeHeight(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int l = treeHeight(root->left);
    int r = treeHeight(root->right);

    return max(l, r) + 1;
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> vec;
    int ht = treeHeight(root);
    // bool freq[ht+5] = {false};
    bool freq[3005] = {false};

    queue<pair<TreeNode<int> *, int>> q;
    if (root)
        q.push({root, 1});

    while (!q.empty())
    {
        // step-1
        pair<TreeNode<int> *, int> parent = q.front();
        q.pop();
        // step-2
        TreeNode<int> *node = parent.first;
        int level = parent.second;

        if (freq[level] == false)
        {
            vec.push_back(node->data);
            freq[level] = true;
        }

        // step-3
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    return vec;
}
// 33 27 12 2 3 29 25 -1 16 50 -1 -1 47 -1 -1 -1 -1 -1 -1 31 6 -1 42 1 36 -1 -1 7 -1 22 41 -1 4 48 32 -1 -1 14 21 -1 39 8 -1 -1 -1 -1 -1 -1 -1 -1 -1 
