#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p;
    // p = make_pair(2, 4);
    p = {3, 4};
    cout << p.first << endl;
    cout << p.second << endl;
    int n;
    cin>>n;
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i].first>>vec[i].second;
    }
    for(int i = 0; i < n; i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    return 0;
}