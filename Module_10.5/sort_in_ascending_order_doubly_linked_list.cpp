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
void sort_ascending_order(Node *head, Node *tail)
{
    for (Node *i = head; i->Next != nullptr; i = i->Next)
    {
        for (Node *j = i->Next; j != nullptr; j = j->Next)
            if (i->val > j->val)
            {
                swap(i->val, j->val);
            }
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
    sort_ascending_order(head, tail);
    print_doubly_linked_list(head);
    return 0;
}