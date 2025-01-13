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

int count_leaf_nodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    int l = count_leaf_nodes(root->left);
    int r = count_leaf_nodes(root->right);

    return l + r;
}
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    return count_leaf_nodes(root);
}