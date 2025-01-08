#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        stack<char> st2;

        for (char ch : s)
        {
            if (ch != '#')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
        }

        for (char ch : t)
        {
            if (ch != '#')
            {
                st2.push(ch);
            }
            else
            {
                if (!st2.empty())
                {
                    st2.pop();
                }
            }
        }

        while (!st.empty() && !st2.empty())
        {
            if (st.top() != st2.top())
            {
                return false;
            };
            st.pop();
            st2.pop();
        }

        return (st.empty() && st2.empty() ? true : false);
    }
};
int main()
{
    Solution obj;
    string str, str2;
    cin >> str >> str2;
    bool isTrue = obj.backspaceCompare(str, str2);
    cout << (isTrue ? "true" : "false");
    return 0;
}