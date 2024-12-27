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
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->Next = newnode;
    tail = newnode;
}
void print_list(Node *head)
{
    Node *tmp = head;
    list<int> l;
    while (tmp != nullptr)
    {
        l.push_back(tmp->val);
        tmp = tmp->Next;
    }

    // check for palindrome using two iterators
    auto frontIt = l.begin();
    auto backIt = l.rbegin();

    while (frontIt != l.end() && backIt != l.rend())
    {

        if (*frontIt != *backIt)
        {
            cout << "NO" << endl;
            return;
        }
        ++frontIt;
        ++backIt;
        if(distance(l.begin(), frontIt) >= distance(l.rbegin(), backIt)){
            break;
        }
    }
    
    cout << "YES" << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    print_list(head);
    return 0;
}