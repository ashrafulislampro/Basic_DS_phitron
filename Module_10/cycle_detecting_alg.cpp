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

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    head->Next = a;
    a->Next = b;
    b->Next = c;
    c->Next = d;
    d->Next = b;

    Node *slow = head;
    Node *fast = head;

    bool flag = false;
    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;

        if (slow == fast)
        {
            flag = true;
            break;
        }
    }
    cout << (flag ? "Cycle Detecting" : "Not Cycle Detecting") << endl;
    return 0;
}