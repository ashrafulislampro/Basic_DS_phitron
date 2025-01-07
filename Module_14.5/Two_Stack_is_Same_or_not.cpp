#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st1;
    stack<int> st2;
    int n, m, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st1.push(val);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        st2.push(val);
    }
    int st1_len = st1.size();
    int st2_len = st2.size();

    if (st1_len != st2_len)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        while (!st1.empty() && !st2.empty())
        {
            if (st1.top() != st2.top())
            {
                cout << "NO" << endl;
                return 0;
            }
            st1.pop();
            st2.pop();
        }
    }
    cout << "YES" << endl;
    return 0;
}