#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    stack<int> pushAtBottom(stack<int> &myStack, int x)
    {

        stack<int> st;
        while (!myStack.empty())
        {
            st.push(myStack.top());
            myStack.pop();
        }
        st.push(x);
        while (!st.empty())
        {
            myStack.push(st.top());
            st.pop();
        }
        return myStack;
    }
};
int main()
{
    Solution obj;
    int t, n, x, vl;
    cin >> t;

    while (t--)
    {
        cin >> n >> x;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> vl;
            st.push(vl);
        }
        stack<int> st2 = obj.pushAtBottom(st, x);
        while (!st2.empty())
        {
            cout << st2.top() << " ";
            st2.pop();
        }
        cout<<endl;
    }
    return 0;
}