#include <iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int n)
    {
        this->val = n;
        this->next = NULL;
    }
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *&head, int n)
    {
        ListNode *tmp = head;
        int count = 0;
        while (tmp != nullptr)
        {
            count++;
            tmp = tmp->next;
        }
        int diff = count - n;
        tmp = head;
        for (int i = 1; i < diff; i++)
        {
            tmp = tmp->next;
        }

        if (diff > 0)
        {
            ListNode *deletenode = tmp->next;
            tmp->next = deletenode->next;
            delete deletenode;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            ListNode *deletenode = head;
            head = head->next;
            delete deletenode;
        }

        return head;
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
void print_linked_list(ListNode *head)
{
    ListNode *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    Solution sol;
    ListNode *head = NULL;
    ListNode *tail = NULL;

    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    int n = 3;
    ListNode *head2 = sol.removeNthFromEnd(head, n);
    print_linked_list(head2);
    return 0;
}