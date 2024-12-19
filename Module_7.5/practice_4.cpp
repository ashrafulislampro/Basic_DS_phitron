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
    tail = newnode;
}

void sort_linked_list(Node *&head)
{

    for (Node *i = head; i->Next != NULL; i = i->Next)
    {
        for (Node *j = i->Next; j != NULL; j = j->Next)
        {
            if (i->val < j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
};
void print_linked_list(Node *tmp)
{
    if (tmp == nullptr)
    {
        return;
    }
    cout << tmp->val << " ";
    print_linked_list(tmp->Next);
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    sort_linked_list(head);
    print_linked_list(head);
    return 0;
}
