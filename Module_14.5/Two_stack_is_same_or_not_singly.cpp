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
class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
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
    void pop()
    {
        Node *deletenode = tail;
        tail = tail->Prev;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->Next = NULL;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return head == NULL;
    }
};
int main()
{
    myStack st, st2;
    int n, m, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st.push(val);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        st2.push(val);
    }

    int st_len = st.size();
    int st2_len = st2.size();

    if (st_len != st2_len)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        while (!st.empty() && !st2.empty())
        {
            if (st.top() != st2.top())
            {
                cout << "NO" << endl;
                return 0;
            }
            st.pop();
            st2.pop();
        }
    }
    cout << "YES" << endl;
    return 0;
}