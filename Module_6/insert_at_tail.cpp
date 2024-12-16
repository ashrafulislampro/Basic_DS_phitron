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
void insert_at_tail(Node *&head, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *tmp = head;
    while (tmp->Next != NULL)
    {
        tmp = tmp->Next;
    }
    tmp->Next = newnode;
};
int main()
{
    Node *head = NULL;
    // Node* a = new Node(20);

    // head->Next = a;
    insert_at_tail(head, 40);
    insert_at_tail(head, 50);
    print_linked_list(head);
    return 0;
}