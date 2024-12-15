#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, l, r;
    cin >> n >> q;
    vector<long long int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<long long int> pre(n + 1);
    pre[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }

    while (q--)
    {
        cin >> l >> r;
        long long int sum = 0;
        if (l == 1)
        {
            sum = pre[r];
        }
        else
        {
            sum = pre[r] - pre[l - 1];
        }
        cout << sum << endl;
    }
    return 0;
}
