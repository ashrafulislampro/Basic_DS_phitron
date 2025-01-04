#include <bits/stdc++.h>
using namespace std;
class myStack
{
public:
    list<int> l;
    void push(int val)  // O(1)
    {
        l.push_back(val);
    }
    void pop()      // O(1)
    {
        l.pop_back();
    }
    int size()      // O(1)
    {
        return l.size();
    }
    int top()       // O(1)
    {
        return l.back();
    }
    bool empty()    // O(1)
    {
        return l.empty();
    }
};
int main()
{
    myStack st;
    int n, x;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        st.push(x);
    }

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}