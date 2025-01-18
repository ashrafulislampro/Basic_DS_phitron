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
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
        {
            return false;
        }
        queue<TreeNode *> qu;
        if (root)
            qu.push(root);
        int value = root->val;
        while (!qu.empty())
        {
            // step-1
            TreeNode *p = qu.front();
            qu.pop();

            // step-2
            if (value != p->val)
                return false;

            value = p->val;
            // step-3
            if (p->left)
                qu.push(p->left);
            if (p->right)
                qu.push(p->right);
        }
        return true;
    }
};