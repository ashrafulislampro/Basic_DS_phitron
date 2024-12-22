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

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->Next = newnode;
    tail = newnode;
}

void remove_duplicate(Node *head, Node *&tail)
{
    Node *tmp = head;
    
    for (Node *i = tmp; i != nullptr; i = i->Next)
    {
        for (Node *j = i; j->Next != nullptr;)
        {

            if (i->val == j->Next->val)
            {

                Node *deletenode = j->Next;
                j->Next = deletenode->Next;
                delete deletenode;
            }else{
                j = j->Next;
            }
        }
    }
}
void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->Next;
    }
    cout << endl;
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    remove_duplicate(head, tail);
    print_linked_list(head);
    return 0;
}