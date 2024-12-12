#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++)
    {
        C.push_back(B[i]);
    }
    for (int i = 0; i < n; i++)
    {
        C.push_back(A[i]);
    }
    cout<<C[0];
    for (int i = 1; i < n + n; i++)
    {
        cout << " " << C[i];
    }

    return 0;
}
