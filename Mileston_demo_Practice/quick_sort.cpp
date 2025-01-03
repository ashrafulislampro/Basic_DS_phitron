#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(i <= high && arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
};
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
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
    quick_sort(arr, 0, n - 1);
    cout << "Final Array after sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    };

    return 0;
}