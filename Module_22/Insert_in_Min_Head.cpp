#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int val;
    cin >> val;
    arr.push_back(val);
    int curr_idx = arr.size() - 1;
    while (curr_idx != 0)
    {
        int par_idx = (curr_idx - 1) / 2;
        if (arr[par_idx] > arr[curr_idx])
        {
            swap(arr[par_idx], arr[curr_idx]);
        }
        else
        {
            break;
        }
        curr_idx = par_idx;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}