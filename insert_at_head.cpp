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
void insert_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->Next = head;
    head->Prev = newnode;
    head = newnode;
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
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->Next = a;
    a->Prev = head;

    a->Next = tail;
    tail->Prev = a;
    insert_at_head(head, 100);
    print_linked_list(head);
    return 0;
}