/**
 * Definition for singly-linked list.
 */
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reverse_list(ListNode *&head, ListNode *&tail, ListNode *tmp)
    {
        if (tmp->next == nullptr)
        {
            head = tmp;
            tail = tmp;
            return;
        }
        reverse_list(head, tail, tmp->next);
        tmp->next->next = tmp;
        tmp->next = NULL;
    }
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *tail = nullptr;
        int forward_val;
        int backward_val;
        ListNode *tmp = head;
        for (int i = 1; i < k; i++)
        {
            tmp = tmp->next;
        }
        forward_val = tmp->val;

        reverse_list(head, tail, head);

        tmp = head;
        for (int i = 1; i < k; i++)
        {
            tmp = tmp->next;
        }
        backward_val = tmp->val;
        tmp->val = forward_val;

        reverse_list(head, tail, head);
        tmp = head;
        for (int i = 1; i < k; i++)
        {
            tmp = tmp->next;
        }
        tmp->val = backward_val;

        return head;
    }
};