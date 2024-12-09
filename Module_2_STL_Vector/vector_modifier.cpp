#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 2, 5, 2};
    // vector<int> v2;
    // vector<int> v3 = {222, 333, 444};
    // v2 = v;
    // v.push_back(100);
    // v.push_back(200);
    // v.pop_back();
    // v.insert(v.begin() + 2, 500);
    // v.insert(v.begin() + 2, v3.begin(), v3.end());
    // v.erase(v.begin() + 1, v.begin() + 9);
    // replace(v.begin(), v.end() - 1, 2, 100);
    // vector<int>::iterator it = find(v.begin(), v.end(), 5);
    auto it = find(v.begin(), v.end(), 5);
    cout << v[0] << " " << v.at(0) << " " << v.front() << endl;
    cout << v[v.size() - 1] << " " << v.back() << endl;

    for (auto its = v.begin(); its < v.end(); its++)
    {
        cout << *its << " ";
    }
    if (it == v.end())
    {
        cout << "Not found " << *it;
    }
    else
    {
        cout << "Found " << *it;
    }
    // for (int x : v)
    // {
    //     cout << x << " ";
    // }
    cout << endl;
    return 0;
}