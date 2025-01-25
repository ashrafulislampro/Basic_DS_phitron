#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        getline(cin, str);
        map<string, int> mp;
        stringstream ss(str);
        string word;
        string name = "";
        int max_count = 0;
        while (ss >> word)
        {
            mp[word]++;

            if ((mp[word] > max_count) || (mp[word] == max_count && name == ""))
            {
                name = word;
                max_count = mp[word];
            }
        }
        cout << name << " " << max_count << endl;
    }
    return 0;
}