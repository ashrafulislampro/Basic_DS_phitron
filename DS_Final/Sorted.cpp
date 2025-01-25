#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int val = arr[i];
            st.insert(val);
        }

        for (auto it = st.begin(); it != st.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
       
        st.clear();
    }
    return 0;
}