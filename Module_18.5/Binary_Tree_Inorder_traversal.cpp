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
    void inorder_traverse(vector<int> &arr, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder_traverse(arr, root->left);
        arr.push_back(root->val);
        inorder_traverse(arr, root->right);
    };
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> arr;
        inorder_traverse(arr, root);
        return arr;
    }
};