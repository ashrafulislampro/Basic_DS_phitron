#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string str;
    while (t--)
    {
        cin >> str;
        stack<char> st_1;
        stack<char> st_0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
            {
                st_0.push(str[i]);
            }
            else
            {
                st_1.push(str[i]);
            }
        }
        if (st_1.size() != st_0.size())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        };
    }
    return 0;
}