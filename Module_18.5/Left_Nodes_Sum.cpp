#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
}

long long
left_sum(BinaryTreeNode<int> *root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 0;

	long long sum = 0;
	if (root->left)
	{
		sum += root->left->data;
	}
	sum += left_sum(root->left);
	sum += left_sum(root->right);

	return sum;
};
long long leftSum(BinaryTreeNode<int> *root)
{
	// Write your code here.
	long long res = left_sum(root);
	return res;
}