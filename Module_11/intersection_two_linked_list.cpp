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

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tmp = headA;
        ListNode *tmp2 = headB;
        int n_A = 0;
        int n_B = 0;
        int d = 0;
        while (tmp != nullptr)
        {
            n_A++;
            tmp = tmp->next;
        }
        while (tmp2 != nullptr)
        {
            n_B++;
            tmp2 = tmp2->next;
        }
        tmp = headA;
        tmp2 = headB;
        if (n_A > n_B)
        {
            d = n_A - n_B;
            for (int i = 0; i < d; i++)
            {
                tmp = tmp->next;
            }
        }
        else
        {
            d = n_B - n_A;

            for (int i = 0; i < d; i++)
            {
                tmp2 = tmp2->next;
            }
        }

        while (tmp != nullptr && tmp2 != nullptr)
        {
            if (tmp == tmp2)
                return tmp;
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    ListNode *headA = NULL;
    ListNode *tailA = NULL;
    ListNode *headB = NULL;
    ListNode *tailB = NULL;

    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(headA, tailA, val);
    }
    while (cin >> val && val != -1)
    {
        insert_at_tail(headB, tailB, val);
    }
    ListNode *node = sol.getIntersectionNode(headA, headB);
    node != nullptr ? node->val : 0;
    return 0;
}