#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> vec(n), vec2;
        
        for(int i = 0; i < n; i++){
            cin>>vec[i];
        }
        vec2 = vec;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(vec[i] > vec[j]){
                    swap(vec[i], vec[j]);
                }
            }
        }
        sort(vec2.begin(), vec2.end());
        for(int i = 0; i < n; i++){
            if(vec[i] != vec2[i]){
                cout<<"No"<<endl;
                break;
            }
        }
        
        if(n != 1 && n %2 != 0){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}

