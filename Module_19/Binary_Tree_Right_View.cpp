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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> vec;
        if (root == nullptr)
            return vec;
        queue<pair<TreeNode *, int>> q;
        if (root)
            q.push({root, 1});
        pair<TreeNode *, int> tmp;
        while (!q.empty())
        {
            // step-1
            pair<TreeNode *, int> parent = q.front();
            q.pop();
            TreeNode *node = parent.first;
            int level = parent.second;
            // step-2

            if (tmp.first == nullptr)
                tmp = parent;
            if (tmp.second != level)
            {
                TreeNode *tp = tmp.first;
                vec.push_back(tp->val);
                tmp = parent;
            }
            else
            {
                tmp = parent;
            }

            // step-3
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        if (tmp.first != nullptr)
        {
            TreeNode *node = tmp.first;
            vec.push_back(node->val);
            tmp = {nullptr, 0};
        }

        return vec;
    }
};
