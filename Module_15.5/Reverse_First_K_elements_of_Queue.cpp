#include <bits/stdc++.h>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    queue<int> q2;
    stack<int> st;

    while (!q.empty() && k--)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q2.push(st.top());
        st.pop();
    }
    while (!q.empty())
    {
        q2.push(q.front());
        q.pop();
    }
    return q2;
}
