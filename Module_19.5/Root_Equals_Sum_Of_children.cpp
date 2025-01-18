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
    void sum_child_nodes(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            sum += root->val;
            return;
        }
        sum_child_nodes(root->left, sum);
        sum_child_nodes(root->right, sum);
    }
    bool checkTree(TreeNode *root)
    {
        int sum = 0;
        sum_child_nodes(root, sum);

        return sum == root->val;
    }
};