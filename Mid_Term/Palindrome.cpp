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

void isPalindrome_Or_not(ListNode *head, ListNode *tail)
{
    for (ListNode *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev)
    {

        if (i->val != j->val)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}
int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    isPalindrome_Or_not(head, tail);
   
    return 0;
}