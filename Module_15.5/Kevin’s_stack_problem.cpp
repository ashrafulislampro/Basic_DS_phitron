#include <bits/stdc++.h>
using namespace std;

string kevinStackProblem(string &s)
{
    // Write your code here.
    stack<char> st;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        st.push(s[i]);
    }
    int idx = 0;
    while (!st.empty() && len--)
    {
        s[idx] = st.top();
        idx++;
        st.pop();
    }
    return s;
}
