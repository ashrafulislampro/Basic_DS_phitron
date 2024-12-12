#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> m;
    vector<int> B(A);
    B.resize(m);
    for (int i = n; i < m; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << B[i] << " ";
    }

    return 0;
}