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

void print_linked_list(Node *tmp)
{
    if (tmp == NULL)
    {
        return;
    }
    print_linked_list(tmp->Next);
    cout << tmp->val << " ";
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

    print_linked_list(head);
    return 0;
}
