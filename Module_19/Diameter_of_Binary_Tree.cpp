#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int mx_val;
    int tree_height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int l = tree_height(root->left);
        int r = tree_height(root->right);
        int d = l + r;
        mx_val = max(d, mx_val);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        mx_val = 0;
        // int h = tree_height(root);
        tree_height(root);
        return mx_val;
    }
};