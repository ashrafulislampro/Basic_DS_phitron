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
    void leaf_nodes(TreeNode *root, vector<int> &leaves)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            leaves.push_back(root->val);
            return;
        }

        leaf_nodes(root->left, leaves);
        leaf_nodes(root->right, leaves);
    };
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaves1, leaves2;
        leaf_nodes(root1, leaves1);
        leaf_nodes(root2, leaves2);

        return leaves1 == leaves2;
    }
};