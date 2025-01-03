#include <iostream>
using namespace std;
class ListNode
{
public:
    string val;
    ListNode *next;
    ListNode *prev;
    ListNode(string st)
    {
        this->val = st;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_tail(ListNode *&head, ListNode *&tail, string str)
{

    ListNode *newnode = new ListNode(str);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
};
ListNode *tmp;
void browser_history(ListNode *head, string s1)
{
    
    ListNode *tmp2 = head;
    if (s1 == "visit")
    {
        string s2;
        cin >> s2;
        while (tmp2 != nullptr)
        {
            if (tmp2->val == s2)
            {
                cout << s2 << endl;
                tmp = tmp2;
                return;
            }
            tmp2 = tmp2->next;
        }
        cout << "Not Available" << endl;
    }

    else
    {
        tmp2 = tmp;
        if (s1 == "next")
        {
            if (tmp2->next == nullptr)
            {
                cout << "Not Available" << endl;
            }
            else
            {
                cout << tmp2->next->val << endl;
                tmp = tmp2->next;
            }
        }
        else if (s1 == "prev")
        {
            if (tmp2->prev == nullptr)
            {
                cout << "Not Available" << endl;
            }
            else
            {
                cout << tmp2->prev->val << endl;
                tmp = tmp2->prev;
            }
        }
    }
}
void print(ListNode *head)
{
    ListNode *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    string str, s1;
    while (cin >> str && str != "end")
    {
        insert_at_tail(head, tail, str);
    }
   
    int q;
    cin >> q;
    while (q--)
    {
        cin >> s1;
        browser_history(head, s1);
    }
    return 0;
}