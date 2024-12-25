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
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->Next = newnode;
    tail = newnode;
};

void reverse_linked_list(Node *&head, Node *&tail, Node *tmp)
{

    while (tmp->Next == NULL)
    {
        head = tmp;
        return;
    }

    reverse_linked_list(head, tail, tmp->Next);
    tmp->Next->Next = tmp;
    tmp->Next = NULL;
    tail = tmp;
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
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    reverse_linked_list(head, tail, head);
    print_linked_list(head);
    cout << head->val << " " << tail->val << endl;
    return 0;
}