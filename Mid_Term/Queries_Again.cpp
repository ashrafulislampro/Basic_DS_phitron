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
void insert_at_tail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *newnode = new ListNode(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void insert_at_head(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *newnode = new ListNode(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
int list_size(ListNode *head)
{
    ListNode *tmp = head;
    int count = 0;
    while (tmp != nullptr)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
void print_list(ListNode *head, ListNode *tail)
{
    ListNode *tmp = head;
    ListNode *tmp2 = tail;
    cout << "L ->";
    while (tmp != nullptr)
    {
        cout << " " << tmp->val;
        tmp = tmp->next;
    }
    cout << endl
         << "R ->";
    while (tmp2 != nullptr)
    {
        cout << " " << tmp2->val;
        tmp2 = tmp2->prev;
    }
    cout << endl;
}
void insert_at_any_pos(ListNode *head, int idx, int val)
{
    ListNode *newnode = new ListNode(val);
    ListNode *tmp = head;
    for (int i = 1; i < idx; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next->prev = newnode;
    tmp->next = newnode;
    newnode->prev = tmp;
};
void insert_node(ListNode *&head, ListNode *&tail, int idx, int val)
{

    int list_len = list_size(head);
    if (idx < 0 || idx > list_len)
    {
        cout << "Invalid" << endl;
        return;
    }
    else if (idx == 0)
    {
        insert_at_head(head, tail, val);
        print_list(head, tail);
    }
    else if (idx == list_len)
    {
        insert_at_tail(head, tail, val);
        print_list(head, tail);
    }
    else
    {
        insert_at_any_pos(head, idx, val);
        print_list(head, tail);
    }
}
int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int q, idx, val;
    cin >> q;
    while (q--)
    {
        cin >> idx >> val;
        insert_node(head, tail, idx, val);
    }
    return 0;
}