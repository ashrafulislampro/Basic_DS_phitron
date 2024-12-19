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
void insert_at_any_pos(Node *&head, int idx, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;

    for (int i = 0; i < idx-1; i++)
    {

        temp = temp->Next;
    }
    newnode->Next = temp->Next;
    temp->Next = newnode;
}
void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->Next;
    }
};
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);

    head->Next = a;
    a->Next = b;
    b->Next = c;

    insert_at_any_pos(head, 2, 100);
    print_linked_list(head);
    return 0;
}