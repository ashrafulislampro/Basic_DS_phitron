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
void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->Next = head;
    head->Prev = newnode;
    head = newnode;
}
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
void reverse_doubly_list(Node *head, Node *tail)
{
    for (Node *i = head, *j = tail; i != j && i->Prev != j; i = i->Next, j = j->Prev)
    {
        swap(i->val, j->val);
    }
}
int list_size(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != nullptr)
    {
        count++;
        tmp = tmp->Next;
    }
    return count;
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
void insert_at_any_pos(Node *head, int idx, int val)
{
    Node *tmp = head;
    Node *newnode = new Node(val);
    for (int i = 1; i < idx; i++)
    {
        tmp = tmp->Next;
    }
    newnode->Next = tmp->Next;
    tmp->Next->Prev = newnode;
    tmp->Next = newnode;
    newnode->Prev = tmp;
};

void insert_node(Node *&head, Node *&tail, int idx, int val)
{

    int size_of = list_size(head);

    if (idx == 0)
    {
        insert_at_head(head, tail, val);
        print_linked_list(head);
        reverse_doubly_list(head, tail);
        print_linked_list(head);
    }
    else if (size_of == idx)
    {
        insert_at_tail(head, tail, val);
        print_linked_list(head);
        reverse_doubly_list(head, tail);
        print_linked_list(head);
    }

    else if (size_of > idx)
    {
        insert_at_any_pos(head, idx, val);
        print_linked_list(head);
        reverse_doubly_list(head, tail);
        print_linked_list(head);
    }
    else
    {
        cout << "Invalid" << endl;
    }
};

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int q, x, v;
    cin >> q;
    while (q--)
    {
        cin >> x >> v;
        insert_node(head, tail, x, v);
    }
    return 0;
}