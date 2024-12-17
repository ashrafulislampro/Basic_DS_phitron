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

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->Next = newnode;
    tail = newnode;
}

bool hashDuplicate(Node *head)
{
    unordered_set<int> seen;
    Node *temp = head;
    while (temp != nullptr)
    {
        // cout << (seen.find(temp->val) != seen.end()) << " " << temp->val << " = " << seen.end() << endl;

        if (seen.find(temp->val) != seen.end())
        {
            return true; // duplicate found
        }
        seen.insert(temp->val);
        temp = temp->Next;
    }
    return false;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    };
    if (hashDuplicate(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}