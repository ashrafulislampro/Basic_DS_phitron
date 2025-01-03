#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<long long int> pre_sum(n);
    pre_sum[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre_sum[i] = pre_sum[i - 1] + v[i];
    }

    cout<<pre_sum[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        cout << " " << pre_sum[i];
    }

    return 0;
}