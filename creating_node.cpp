#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *Next;
};
int main()
{
    Node a, b, c;
    a.val = 10;
    b.val = 20;
    c.val = 30;

    a.Next = &b;
    b.Next = &c;
    c.Next = NULL;

    // cout << a.val << " " << b.val << " " << c.val << endl;
    cout << a.val << " " << a.Next->val << " " << a.Next->Next->val << endl;
    
    return 0;
}