#include <bits/stdc++.h>
using namespace std;
int equilibrium_ind(vector<int> arr){
    int total_sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total_sum += arr[i];
    }
    int left_sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        
        int right_sum = total_sum - arr[i] - left_sum;
       
        if (left_sum == right_sum)
        {
            return i;
        }
        left_sum += arr[i];
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int index = equilibrium_ind(v);
    if( index != -1){
        cout<<"Expected Index is " <<index<<endl;
    }else{
         cout << "Expected Index is not found" << endl;
    }
   
    return 0;
}