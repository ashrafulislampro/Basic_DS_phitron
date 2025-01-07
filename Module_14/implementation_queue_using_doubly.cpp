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
class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val) // O(1)
    {
        sz++;
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
    void pop() // O(1)
    {
        sz--;
        Node *deletenode = head;
        head = head->Next;
        delete deletenode;
        if (head == nullptr)
        {
            tail = NULL;
            return;
        }
        head->Prev = NULL;
    }
    int front() // O(1)
    {
        return head->val;
    }
    int back() // O(1)
    {
        return tail->val;
    }
    int size() // O(1)
    {
        return sz;
    }
    bool empty() // O(1)
    {
        return head == NULL;
    }
};
int main()
{
    myQueue q;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        q.push(val);
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}