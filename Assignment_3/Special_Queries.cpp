#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<string> q;
    int Q, idc;
    string str;
    cin>>Q;
    while(Q--){
        cin>>idc;
        if(idc == 0){
            cin>>str;
            q.push(str);
        }else{
            if(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }else{
                cout<<"Invalid"<<endl;
            }       
        }
    }
    return 0;
}