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

int mx_val;
int max_height(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    int l = max_height(root->left);
    int r = max_height(root->right);
    int d = l + r;
    mx_val = max(mx_val, d);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    mx_val = 0;
    int h = max_height(root);
    return mx_val;
}