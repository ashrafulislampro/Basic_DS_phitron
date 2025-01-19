#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

void level_order(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->val << " ";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}

Node* converter(int arr[], int low, int high){
    if(low> high) return NULL;
    int mid =(low + high) /  2;

    Node* root = new Node(arr[mid]);
    Node* leftroot = converter(arr, low, mid-1);
    Node* rightroot = converter(arr, mid+1, high);
    root->left = leftroot;
    root->right = rightroot;
    return root;
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    Node* root = converter(arr, 0, n-1);
    level_order(root);
    return 0;
}