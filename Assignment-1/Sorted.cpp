#include <bits/stdc++.h>
using namespace std;
bool sort_it(vector<int> arr, vector<int> arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> arr2(arr);
        sort(arr2.begin(), arr2.end());
        if (sort_it(arr,arr2, n))
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