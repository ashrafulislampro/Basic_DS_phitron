#include <bits/stdc++.h>
using namespace std;
void print_list(list<int> lst)
{
    cout << "L ->";
    for (int val : lst)
    {
        cout << " " << val;
    }
    cout << endl
         << "R ->";
    lst.reverse();
    for (int val : lst)
    {
        cout << " " << val;
    }
    cout << endl;
}
int main()
{
    list<int> lst;
    int q, x, v;
    cin >> q;
    while (q--)
    {
        cin >> x >> v;
        if (x == 0)
        {
            lst.push_front(v);
            print_list(lst);
        }
        else if (x == 1)
        {
            lst.push_back(v);
            print_list(lst);
        }
        else if (x == 2)
        {
            int len = lst.size();
            if (v < len)
            {
                lst.erase(next(lst.begin(), v));
            }
            print_list(lst);
        }
    }

    return 0;
}