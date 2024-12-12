#include <bits/stdc++.h>
using namespace std;
vector<int> get_array(int n){
    vector<int> arr(n);
    for(int i = 0;  i< n; i++){
        cin>>arr[i];
    }
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr = get_array(n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}