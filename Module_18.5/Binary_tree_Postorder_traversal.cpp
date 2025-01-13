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
    void postorder_traverse(vector<int> &arr, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postorder_traverse(arr, root->left);
        postorder_traverse(arr, root->right);
        arr.push_back(root->val);
    };
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> arr;
        postorder_traverse(arr, root);
        return arr;
    }
};