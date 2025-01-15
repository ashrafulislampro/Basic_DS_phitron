#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int tree_height(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    int l = tree_height(root->left);
    int r = tree_height(root->right);

    return max(l, r) + 1;
}
bool isSpecialBinaryTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    int ht = tree_height(root);
    int arr[ht + 1] = {0};
    if (root == nullptr)
        return false;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    if (root)
        q.push({root, 1});
    while (!q.empty())
    {
        // step-1
        pair<BinaryTreeNode<int> *, int> parent = q.front();
        q.pop();

        BinaryTreeNode<int> *node = parent.first;
        int level = parent.second;

        // step->2
        arr[level]++;
        // step-3
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 2; i < len; i++)
    {
        if (arr[i] % 2 != 0)
        {
            return false;
        }
    }
    return true;
}