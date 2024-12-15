#include <bits/stdc++.h>
using namespace std;
bool binary_search(vector<int> arr, int ele, int n)
{

    int low = 0, high = n, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == ele)
        {

            return true;
        }
        if (arr[mid] > ele)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    int n, q, ele;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> q;
    sort(arr.begin(), arr.end());

    while (q--)
    {
        cin >> ele;
        if (binary_search(arr, ele, n))
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