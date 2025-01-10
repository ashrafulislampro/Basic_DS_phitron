#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int n)
    {
        this->val = n;
        this->next = NULL;
        this->prev = NULL;
    }
};

void push(Node *&head, Node *&tail, int val, int &sz)
{
    sz++;
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void pop(Node *&head, Node *&tail, int &st_size)
{
    st_size--;
    Node *del_node = tail;
    tail = tail->prev;
    delete del_node;
    if (tail == NULL)
    {
        head = NULL;
        return;
    }
    tail->next = NULL;
}
void dequeue(Node *&head, Node *&tail, int &q_size)
{
    q_size--;
    Node *del_node = head;
    head = head->next;
    delete del_node;
    if (head == nullptr)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}
int top(Node *tail)
{
    return tail->val;
}
int front(Node *head)
{
    return head->val;
}
bool isEmpty(int sz)
{
    return sz == 0;
}

int main()
{
    Node *head_st = NULL;
    Node *tail_st = NULL;
    Node *head_q = NULL;
    Node *tail_q = NULL;

    int st_size = 0;
    int q_size = 0;

    int n, m, val;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        push(head_st, tail_st, val, st_size);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        push(head_q, tail_q, val, q_size);
    }

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        while (!isEmpty(st_size) && !isEmpty(q_size))
        {
            
            if (top(tail_st) != front(head_q))
            {
                cout << "NO" << endl;
                return 0;
            }
            pop(head_st, tail_st, st_size);
            dequeue(head_q, tail_q, q_size);
        }
    }
    cout << "YES" << endl;
    return 0;
}