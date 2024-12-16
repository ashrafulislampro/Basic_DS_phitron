#include <bits/stdc++.h>
using namespace std;
void fun(int* &p)
{
    int y = 20;
    p = &y;
    cout << "In fun : " << &p << endl;
}
int main()
{
    int x = 10;
    int *ptr = &x;
    fun(ptr);
    cout << "In main: " << &ptr << endl;

    return 0;
}