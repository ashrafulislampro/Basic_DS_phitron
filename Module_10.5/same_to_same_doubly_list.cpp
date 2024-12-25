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
void same_or_not(Node *head, Node *head1)
{
    int list_1 = list_size(head);
    int list_2 = list_size(head1);

    if (list_1 != list_2)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        for (Node *j = head1, *i = head; i->Next != nullptr; i = i->Next, j = j->Next)
        {
            if (i->val != j->val)
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    while (cin >> val && val != -1)
    {
        insert_at_tail(head1, tail1, val);
    }
    same_or_not(head, head1);

    return 0;
}