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
void print_middle_ele(Node *head)
{
    Node *temp = head;
    Node *tmp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    if (count % 2 == 0)
    {
        int mid = count / 2;
        for (int i = 0; i <= mid; i++)
        {

            if (i == mid - 1 || i == mid)
            {
                cout << tmp->val << " ";
            }
            tmp = tmp->Next;
        }
    }
    else
    {
        int mid = count / 2;
        for (int i = 0; i <= mid; i++)
        {

            if (i == mid)
            {
                cout << tmp->val << endl;
            }
            tmp = tmp->Next;
        }
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    };
    print_middle_ele(head);
    return 0;
}