#include <bits/stdc++.h>
using namespace std;
// int Ack(int m, int n)
// {
//     if (m == 0)
//     {
//         return n + 1;
//     }
//     else if (n == 0 && m > 0)
//     {
//         return Ack(m - 1, 1);
//     }
//     else
//     {
//         return Ack(m - 1, Ack(m, n - 1));
//     }
// }
int main()
{
    int m, n;
    cout << "Enter Two number: " << endl;
    cin >> m >> n;
    cout << m << n << endl;
    // cout << "Output: " << Ack(m, n) << endl;
    return 0;
}