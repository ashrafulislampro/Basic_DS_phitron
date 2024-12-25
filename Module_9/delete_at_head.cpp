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

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->Next;
    }
    cout << endl;
}

void delete_at_head_node(Node *&head, Node *&tail)
{
    Node *deletenode = head;
    head = deletenode->Next;
    delete deletenode;

    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    head->Prev = NULL;
};
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = new Node(50);

    head->Next = a;
    a->Prev = head;
    a->Next = b;
    b->Prev = a;
    b->Next = c;
    c->Prev = b;
    c->Next = tail;
    tail->Prev = c;

    delete_at_head_node(head, tail);
    print_linked_list(head);
    return 0;
}