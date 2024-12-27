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
Node *recursive(Node *&head, Node *&tail, Node *tmp)
{
    if (tmp->Next != nullptr)
    {
        head = tmp;
        tail = tmp;
        return head;
    }
    Node *newnode = recursive(head, tail, tmp->Next);
    tmp->Next->Next = tmp;
    tmp->Next = NULL;
    tail = tmp;
    return newnode;
}
void print_list(Node *head, Node *tail)
{
    Node *tmp = head;
    Node *list = recursive(head, tail, head);
    while (list != nullptr)
    {
        cout << list->val << endl;
        // tmp != nullptr &&
        // if (tmp->val != list->val)
        // {
        //     cout << "NO" << endl;
        //     return;
        // }
        // tmp = tmp->Next;
        list = list->Next;
    }

    cout << "YES" << endl;
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
    print_list(head, tail);
    return 0;
}