#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    // Input Element
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    };
    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    };
    return 0;
}