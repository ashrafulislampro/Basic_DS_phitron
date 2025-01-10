#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{

public:
    class ListNode
    {
    public:
        string val;
        ListNode *next;
        ListNode *prev;
        ListNode(string str)
        {
            this->val = str;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    ListNode *current = NULL;

    BrowserHistory(string homepage)
    {
        ListNode *newnode = new ListNode(homepage);
        current = newnode;
    }

    void visit(string url)
    {
        ListNode *newnode = new ListNode(url);
        current->next = newnode;
        newnode->prev = current;
        current = newnode;
    }

    string back(int steps)
    {
        while (steps-- && current->prev != NULL)
        {
            current = current->prev;
        }
        return current->val;
    }
    string forward(int steps)
    {
        while (steps-- && current->next != NULL)
        {
            current = current->next;
        }
        return current->val;
    }
};
