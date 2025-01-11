#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[105];
    int indices[105];
    int n, k, i;
    cin >> n >> k;

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        indices[i] = i + 1;
    }
    sort(arr, arr + n);
    sort(indices, indices + n);
    for (i = 0; i < n; i++)
    {
        k -= arr[i];

        if (k < 0)
            break;
    }
    cout << i << endl;

    while (i--)
    {
        // cout << i << endl;
        cout << indices[i];
        if (i > 0)
        {
            cout << " ";
        }
    }
    return 0;
}