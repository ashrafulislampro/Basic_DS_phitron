#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    stack<int> st2;
    int n, val;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>val;
        st.push(val);
    }
    int vl;
    while(!st.empty()){
        vl = st.top();
        st.pop();
        st2.push(vl);
    }
    while(!st2.empty()){
        cout<<st2.top()<< " ";
        st2.pop();
    }
    return 0;
}