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
    Node *C = new Node(40);

    head->Next = A;
    A->Next = B;
    B->Next = C;

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->Next;
    }
    temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->Next;
    }

    return 0;
}