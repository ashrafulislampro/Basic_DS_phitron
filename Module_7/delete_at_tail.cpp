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
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->Next;
    }
}
void delete_at_tail(Node *head, Node *&tail)
{
    Node *tmp = head;
    while (tmp->Next->Next != NULL)
    {
        tmp = tmp->Next;
    }

    Node *deletenode = tmp->Next;
    tmp->Next = deletenode->Next;
    tail = tmp;
    delete deletenode;
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
    delete_at_tail(head, tail);
    print_linked_list(head);
    return 0;
}