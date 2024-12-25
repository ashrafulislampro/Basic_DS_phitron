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
    newnode->Prev = tail;
    tail = newnode;
}

void palindrome(Node *head, Node *tail)
{

    for (Node *i = head, *j = tail; i != j && i->Prev != j; i = i->Next, j = j->Prev)
    {

        if (i->val != j->val)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }

    palindrome(head, tail);

    return 0;
}