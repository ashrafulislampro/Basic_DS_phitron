#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    Node *root;
    int val;
    cin >> val;
    if (val == -1)
        root = nullptr;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // step-1
        Node *p = q.front();
        q.pop();
        // step-2
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = nullptr;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = nullptr;
        else
            myRight = new Node(r);

        // step-3
        p->left = myLeft;
        p->right = myRight;
        if (p->left)
            q.push(p->left);

        if (p->right)
            q.push(p->right);
    }
    return root;
}
int binary_tree_height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    int l = binary_tree_height(root->left);
    int r = binary_tree_height(root->right);

    return max(l, r) + 1;
}
void Level_Nodes(Node* root, int x){
    queue<pair<Node*, int>> q;
    if(root) q.push({root, 0});
    while(!q.empty()){
        // step-1
        pair<Node*, int> parent = q.front();
        q.pop();

        // step-2
        Node* node = parent.first;
        int level = parent.second;
        if(level == x){
            cout<<node->val<<" ";
        }
        // step-3
        if(node->left){
            q.push({node->left, level+1});
        }
        if(node->right){
            q.push({node->right, level+1});
        }

    }

};
int main()
{
    Node *root = input_tree();
    int ht = binary_tree_height(root);
    int x;
    cin>>x;
    if(x >= 0 && x <= ht){
        Level_Nodes(root, x);
    }else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}