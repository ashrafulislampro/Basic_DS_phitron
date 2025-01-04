#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int v)
    {
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack
{
public:
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int sz = 0;
    void push(int val) // O(1)
    {
        sz++;
        ListNode *newnode = new ListNode(val);
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    void pop() // O(1)
    {
        sz--;
        ListNode *deletenode = tail;
        tail = deletenode->prev;
        delete deletenode;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }
    int size() // O(1)
    {
        return sz;
    }
    int top() // O(1)
    {
        return tail->val;
    }
    bool empty() // O(1)
    {
        return head == NULL;
    }
};
int main()
{
    myStack st;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        st.push(x);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}