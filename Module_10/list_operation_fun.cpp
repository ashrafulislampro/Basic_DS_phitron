#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {200, 30, 40, 50, 20, 20, 10, 50, 1000, 20, 40};
    // l.remove(10);
    // l.sort();
    // l.sort(greater<int>());

    // l.unique();
    // l.reverse();
    // cout << l.front() << endl;
    // cout << l.back() << endl;
    // cout << *next(l.begin(), 3) << endl;
    cout << *l.begin() << endl;
    cout << *l.end() << endl;
    for (int val : l)
    {
        // cout << val << endl;
    }
    return 0;
}