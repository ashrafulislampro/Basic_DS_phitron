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
void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->Next = head;
    head = newnode;
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
}

void delete_node(Node *&head, Node *&tail, int idx)
{
    Node *tmp = head;
    Node *tmp2 = head;

    int list_size = 0;
    while (tmp != NULL)
    {
        list_size++;
        tmp = tmp->Next;
    }
    if (idx < 0 || idx >= list_size)
    {
        return;
    }
    else if (idx == 0)
    {
        Node *deletenode = head;
        head = head->Next;
        delete deletenode;
    }
    else if (idx == list_size - 1)
    {

        while (tmp2->Next->Next != NULL)
        {
            tmp2 = tmp2->Next;
        }
        Node *deletenode = tmp2->Next;
        tmp2->Next = deletenode->Next;
        tail = tmp2;
        delete deletenode;
    }
    else if (idx < list_size)
    {
        for (int i = 0; i < idx - 1; i++)
        {
            tmp2 = tmp2->Next;
        }
        Node *deletenode = tmp2->Next;
        tmp2->Next = deletenode->Next;
        delete deletenode;
    }
};

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->Next;
    }
    cout << endl;
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q, x, val;
    cin >> q;
    while (q--)
    {
        cin >> x >> val;
        if (x == 0)
        {
            insert_at_head(head, tail, val);
            print_linked_list(head);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, val);
            print_linked_list(head);
        }
        else
        {
            delete_node(head, tail, val);
            print_linked_list(head);
        }
    }

    return 0;
}