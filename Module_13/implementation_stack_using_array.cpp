#include <bits/stdc++.h>
using namespace std;
class myStack
{
public:
    vector<int> v;
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int size()
    {
        return v.size();
    }
    int top()
    {
        return v.back();
    }
    bool empty()
    {
        return v.empty();
    }
};
int main()
{
    myStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Stack Size = " << st.size() << endl;
    cout << "Top = " << st.top() << endl;
    st.pop();
    cout << "Top = " << st.top() << endl;
    st.pop();
    if (!st.empty())
    {
        cout << "Top = " << st.top() << endl;
    }
    if (st.empty() == false)
    {
        st.pop();
    }

    return 0;
}