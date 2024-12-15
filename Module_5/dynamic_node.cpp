#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *Next;
    Node(int n)
    {
        this->val = n;
        this->Next = NULL;
    }
};

int main()
{
    Node *head = new Node(10);
    Node *A = new Node(20);
    Node *B = new Node(30);

    head->Next = A;
    A->Next = B;
    cout << head->val << " " << head->Next->val << " " << head->Next->Next->val << endl;
    return 0;
}