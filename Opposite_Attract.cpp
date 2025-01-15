#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    char x;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string str1 = "";
        string str2 = "";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            str1.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            if (str1[i] == '0')
            {
                str2.push_back('1');
            }
            else
            {
                str2.push_back('0');
            }
        }
        cout << str2 << endl;
    }
    return 0;
}
