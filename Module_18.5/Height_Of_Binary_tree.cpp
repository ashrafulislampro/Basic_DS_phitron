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

int height_of_tree(TreeNode<int> *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    int l = height_of_tree(root->left);
    int r = height_of_tree(root->right);
    return max(l, r) + 1;
};
int heightOfBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    int height = height_of_tree(root);
    return height;
}
