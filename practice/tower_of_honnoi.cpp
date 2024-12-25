#include <bits/stdc++.h>
using namespace std;
void honai(int n, char sor, char aux, char des)
{
    if (n == 1)
    {
        cout << sor << "->" << des << endl;
    }
    else
    {
        honai(n - 1, sor, des, aux);
        honai(1, sor, aux, des);
        honai(n - 1, aux, sor, des);
    }
};
int main()
{
    int n, moves;
    cin >> n;
    moves = pow(2, n) - 1;
    cout << "Total Moves: " << moves << endl;
    honai(n, 'A', 'B', 'C');
    return 0;
}