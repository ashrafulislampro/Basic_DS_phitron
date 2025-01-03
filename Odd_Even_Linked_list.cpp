#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int v)
    {
        this->val = v;
        this->next = NULL;
    }
};
void insert_at_tail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *newnode = new ListNode(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = newnode;
}

void print_list(ListNode *head)
{
    ListNode *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void reordered_list(ListNode *&head, ListNode *&tail)
{
    ListNode *list_1 = head;
    ListNode *list_2 = head;
    int j = 0;
    for (ListNode *i = list_1; i != nullptr; i = i->next)
    {
        ++j;
        if (j % 2 != 0)
        {
            ListNode *aux = list_1->next;
            list_1->next = aux->next;

            list_1 = list_1->next;
            // list_1 = nullptr;
        }
        else
        {
            list_1 = list_1->next;
        }
    }
    print_list(head);
}
int main()
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int val;
    while (cin >> val)
    {
        insert_at_tail(head, tail, val);
    }
    // print_list(head);
    return 0;
}