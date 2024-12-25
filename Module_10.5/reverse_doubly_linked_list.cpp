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

void print_doubly_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << endl;
        tmp = tmp->Next;
    }
};
void reverse_list(Node *head, Node *tmp)
{
    for (Node *i = head, *j = tmp; i != j && i->Prev != j; i = i->Next, j = j->Prev)
    {
        swap(j->val, i->val);
    }
};
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    reverse_list(head, tail);
    print_doubly_linked_list(head);

    return 0;
}