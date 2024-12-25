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
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->Next = newnode;
    newnode->Prev = tail;
    tail = newnode;
}
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->Next;
    }
    cout << endl;
};
int main()
{
    Node *head = nullptr;
    // Node *a = new Node(20);
    Node *tail = nullptr;

    // head->Next = a;
    // a->Prev = head;
    // a->Next = tail;
    // tail->Prev = a;
    insert_at_tail(head, tail, 100);
    insert_at_tail(head, tail, 200);
    print_linked_list(head);
    return 0;
}