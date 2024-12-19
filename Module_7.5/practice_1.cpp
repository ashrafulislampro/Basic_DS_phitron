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

int linked_list_size(Node *head)
{
    int count = 0;
    Node *tmp = head;
    while (tmp != nullptr)
    {
        count++;
        tmp = tmp->Next;
    }
    return count;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    while (cin >> val && val != -1)
    {
        insert_at_tail(head2, tail2, val);
    }
    int list_1 = linked_list_size(head);
    int list_2 = linked_list_size(head2);

    if (list_1 == list_2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}