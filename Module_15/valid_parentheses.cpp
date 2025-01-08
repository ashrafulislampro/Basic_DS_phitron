#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> st;

        for (char ch : str)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                else
                {
                    if (ch == ')' && st.top() == '(')
                    {
                        st.pop();
                    }
                    else if (ch == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                    else if (ch == ']' && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return (st.empty() ? true : false);
    }
};
int main()
{
    Solution obj;
    string str;
    cin >> str;

    cout << (obj.isValid(str) ? "YES" : "NO") << endl;
    return 0;
}