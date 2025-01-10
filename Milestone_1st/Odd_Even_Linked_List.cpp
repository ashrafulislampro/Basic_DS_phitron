#include <bits/stdc++.h>
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
    ListNode *oddEvenList(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *even = new ListNode(0);
        ListNode *even_ptr = even;
        ListNode *odd = new ListNode(0);
        ListNode *odd_ptr = odd;
        int idx = 1;
        while (head != nullptr)
        {
            if (idx % 2 == 0)
            {
                even_ptr->next = head;
                even_ptr = even_ptr->next;
            }
            else
            {
                odd_ptr->next = head;
                odd_ptr = odd_ptr->next;
            }
            head = head->next;
            idx++;
        }
        even_ptr->next = NULL;
        odd_ptr->next = even->next;

        return odd->next;
    }
};