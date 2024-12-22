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
bool same_or_not(Node *head, Node *head2)
{
    Node *tmp = head;
    Node *tmp2 = head2;
    int size_1 = linked_list_size(tmp);
    int size_2 = linked_list_size(tmp2);

    if (size_1 != size_2)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size_1; i++)
        {
            if (tmp->val != tmp2->val)
            {
                return false;
            }
            tmp = tmp->Next;
            tmp2 = tmp2->Next;
        }
    }
    return true;
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

    if (same_or_not(head, head2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}