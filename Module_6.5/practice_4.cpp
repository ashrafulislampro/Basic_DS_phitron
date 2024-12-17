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
void insert_to_tail(Node *&head, Node *&tail, int val)
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
void print_linked_list(Node *&head, Node *&tail, int idx, int item)
{
    Node *newnode = new Node(item);
    Node *tmp = head;

    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->Next;
    }
    if (idx > count)
    {
        cout << "Invalid" << endl;
    }
    else if (idx == 0)
    {
        newnode->Next = head;
        head = newnode;
        Node *temp1 = head;
        while (temp1 != NULL)
        {
            cout << temp1->val << " ";
            temp1 = temp1->Next;
        }
        cout << endl;
    }
    else if (idx < count)
    {
        Node *temp = head;
        for (int i = 1; i < idx; i++)
        {
            temp = temp->Next;
        }
        newnode->Next = temp->Next;
        temp->Next = newnode;
        Node *temp2 = head;
        while (temp2 != NULL)
        {
            cout << temp2->val << " ";
            temp2 = temp2->Next;
        }
        cout << endl;
    }
    else
    {
        tail->Next = newnode;
        tail = newnode;
        Node *temp3 = head;
        while (temp3 != NULL)
        {
            cout << temp3->val << " ";
            temp3 = temp3->Next;
        }
        cout << endl;
    }
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_to_tail(head, tail, val);
    }

    int idx, item;
    while (cin >> idx >> item)
    {
        print_linked_list(head, tail, idx, item);
    }
    return 0;
}