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
void print_asc_or_not(Node *head)
{
    Node *temp = head;
    while (temp->Next != NULL)
    {
        if (temp->val > temp->Next->val)
        {
            cout << "NO" << endl;
            return;
        }
        temp = temp->Next;
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
        insert_to_tail(head, tail, val);
    }
    print_asc_or_not(head);
    return 0;
}