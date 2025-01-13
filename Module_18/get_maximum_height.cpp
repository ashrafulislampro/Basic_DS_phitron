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
        // step-1 ber kra
        Node *p = q.front();
        q.pop();

        // step-2 node nia kaj
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
int get_maximum_height(Node* root){
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return 0;

    int l = get_maximum_height(root->left);
    int r = get_maximum_height(root->right);

    return max(l,r) + 1;
}

int main(){
    Node* root = input_tree();
    cout<<get_maximum_height(root)<<endl;
    return 0;
}