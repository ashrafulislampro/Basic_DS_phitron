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

int nodeLevel(TreeNode<int> *root, int searchedValue)
{
    if (root == nullptr)
        return 0; // Tree is empty

    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        // Step-1
        pair<TreeNode<int> *, int> parent = q.front();
        q.pop();
        // Step-2
        TreeNode<int> *node = parent.first;
        int level = parent.second;

        if (node->val == searchedValue)
            return level;

        // Step-3
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }

    return 0; // Value not found in the tree
}