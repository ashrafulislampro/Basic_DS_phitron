#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> q;
    int n, m, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st.push(val);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        q.push(val);
    }
    int st_len = st.size();
    int q_len = q.size();

    if (st_len != q_len)
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