#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *Next;
    Node *Prev;
    Node(int n)
    {
        this->val = n;
        this->Next = NULL;
        this->Prev = NULL;
    }
};
void print_forward_list(Node *head)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->Next;
    }
    cout << endl;
};
void print_backward_list(Node *tail)
{
    Node *tmp = tail;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->Prev;
    }
    cout << endl;
};
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->Next = a;
    a->Prev = head;

    a->Next = tail;
    tail->Prev = a;
    print_forward_list(head);
    print_backward_list(tail);
    return 0;
}