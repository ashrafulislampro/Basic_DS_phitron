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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((q == nullptr && p != nullptr) || (q != nullptr && p == nullptr))
            return false;
        queue<pair<TreeNode *, string>> p_que;
        queue<pair<TreeNode *, string>> q_que;

        if (p)
            p_que.push({p, "ro"});
        if (q)
            q_que.push({q, "ro"});
        int level = 1;
        while (!p_que.empty() && !q_que.empty())
        {
            // step-1
            pair<TreeNode *, string> parent_1 = p_que.front();
            p_que.pop();
            pair<TreeNode *, string> parent_2 = q_que.front();
            q_que.pop();

            // step-2
            TreeNode *node_1 = parent_1.first;
            string node_side_1 = parent_1.second;
            TreeNode *node_2 = parent_2.first;
            string node_side_2 = parent_2.second;

            if (node_1->val != node_2->val)
            {
                return false;
            }
            if (node_side_1 != node_side_2)
            {
                return false;
            }

            // step-3
            if (node_1->left)
            {

                p_que.push({node_1->left, "l" + to_string(level + 1)});
            }
            if (node_1->right)
            {

                p_que.push({node_1->right, "r" + to_string(level + 1)});
            }

            if (node_2->left)
            {

                q_que.push({node_2->left, "l" + to_string(level + 1)});
            }
            if (node_2->right)
            {
                ;
                q_que.push({node_2->right, "r" + to_string(level + 1)});
            }
            level++;
        }

        if (p_que.empty() && q_que.empty())
        {

            return true;
        }
        else
        {
            return false;
        }
    }
};

TreeNode *input_tree()
{
    TreeNode *root;
    int val;
    cin >> val;
    if (val == -1)
        root = nullptr;
    else
        root = new TreeNode(val);

    queue<TreeNode *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // step-1 ber kre nia asha
        TreeNode *p = q.front();
        q.pop();

        // step-2 oi TreeNode nia kaj kra
        int l, r;
        cin >> l >> r;
        TreeNode *myLeft, *myRight;
        if (l == -1)
            myLeft = nullptr;
        else
            myLeft = new TreeNode(l);

        if (r == -1)
            myRight = nullptr;
        else
            myRight = new TreeNode(r);

        p->left = myLeft;
        p->right = myRight;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

int main()
{
    Solution obj;
    TreeNode *p = input_tree();
    TreeNode *q = input_tree();

    // level_order(p);

    // cout << endl
    //      << endl;

    // level_order(q);

    // TreeNode *p = new TreeNode(10);
    // p->left = new TreeNode(5);
    // p->right = new TreeNode(15);

    // TreeNode *q = new TreeNode(10);
    // q->left = new TreeNode(5);
    // q->right = new TreeNode(NULL);
    // TreeNode * a = new TreeNode(15);
    // TreeNode * b = new TreeNode(15);
    // TreeNode* q = {10,5,NULL,NULL,15};

    cout << endl;
    if (obj.isSameTree(p, q))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
