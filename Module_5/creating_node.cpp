#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *Next;
    Node(int n){
        this->val = n;
        this->Next = NULL;
    }
};
int main()
{
    Node a(100), b(200), c(300);
   

    a.Next = &b;
    b.Next = &c;
    

    // cout << a.val << " " << b.val << " " << c.val << endl;
    cout << a.val << " " << a.Next->val << " " << a.Next->Next->val << endl;

    return 0;
}