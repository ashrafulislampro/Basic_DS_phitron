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
void insert_node(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->Next = head;
    head = newnode;
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

    insert_node(head, 100);
    insert_node(head, 200);
    insert_node(head, 300);
    print_linked_list(head);
    return 0;
}