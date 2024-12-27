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

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->Next;
    }
}
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->Next = newnode;
    tail = newnode;
};
void remove_duplicates(Node *head)
{
    for (Node *i = head; i->Next != nullptr;)
    {
        if (i->val == i->Next->val)
        {
            Node *deletenode = i->Next;
            i->Next = deletenode->Next;
            delete deletenode;
        }
        else
        {
            i = i->Next;
        }
    }
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
    remove_duplicates(head);
    print_linked_list(head);

    return 0;
}