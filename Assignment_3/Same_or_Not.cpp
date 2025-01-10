#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, val;
    stack<int> st;
    queue<int> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st.push(val);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        q.push(val);
    }
    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        while (!st.empty() && !q.empty())
        {
            if (st.top() != q.front())
            {
                cout << "NO" << endl;
                return 0;
            }
            st.pop();
            q.pop();
        }
    }
    cout << "YES" << endl;
    return 0;
}