#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[4] = {12, 13, 14, 15};
    vector<int> v = {12, 13, 14, 15};
    // v.resize(2);
    // v.resize(4);
    v.insert(v.begin()+3, 20);
    for (int n : v)
    {
        cout << n << " ";
    }
    return 0;
}