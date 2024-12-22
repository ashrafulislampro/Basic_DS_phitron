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
void max_min(Node *head)
{
    Node *tmp = head;
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    while (tmp != NULL)
    {

        if (tmp->val > max_val)
        {
            max_val = tmp->val;
        }
        if (tmp->val < min_val)
        {
            min_val = tmp->val;
        }

        tmp = tmp->Next;
    }

    int result = max_val - min_val;
    cout << result << endl;
};

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    max_min(head);

    return 0;
}