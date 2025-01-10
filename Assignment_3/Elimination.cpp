#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    string str;
    cin >> q;
    while (q--)
    {
        cin >> str;
        stack<char> st_1;
        stack<char> st_0;
        int len = str.size();
        bool isTrue = true;
        for (int i = len - 1; i >= 0 && isTrue; i--)
        {
            if (str[i] == '0')
            {
                st_0.push(str[i]);
            }
            else
            {
                st_1.push(str[i]);
            }

            if (st_1.empty() && !st_0.empty())
            {
                isTrue = false;
            }
            if (!st_1.empty() && !st_0.empty())
            {
                st_1.pop();
                st_0.pop();
            }
        }
        if (isTrue && st_1.empty() && st_0.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}