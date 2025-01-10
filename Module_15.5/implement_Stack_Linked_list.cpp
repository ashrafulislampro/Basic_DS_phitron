#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack
{

private:
    Node *head;

public:
    Stack()
    {

        head = NULL;
    }
    int sz = 0;
    int getSize()
    {

        return sz;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        sz++;
        Node *newnode = new Node(data);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void pop()
    {
        
        if (head != nullptr)
        {
            sz--;
            Node *del_node = head;
            head = head->next;
            delete del_node;
        }
    }

    int getTop()
    {
        if (head == nullptr)
            return -1;
        else
            return head->data;
    }
};

int main()
{
    int q, idx, val;

    Stack obj; // New queue for each test case
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> idx;
        if (idx == 1)
        {
            cout << obj.getSize() << endl;
        }
        else if (idx == 2)
        {
            if(obj.isEmpty()){
                cout<<"true"<<endl;
            }else{
                cout << "false" << endl;
            }
            
        }
        else if (idx == 3)
        {
            cin >> val;
            obj.push(val);
        }
        else if (idx == 4)
        {
            obj.pop();
        }
        else if (idx == 5)
        {
            cout << obj.getTop() << endl;
        }
    }

    return 0;
}
